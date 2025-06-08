#include <iostream>
#include <vector>
#include <limits>
#include "Book.h"
#include "LibraryUtils.h"
#include "Member.h"
#include "MemberUtils.h"

using namespace std;

int main() {
    vector<Book> library;
    vector<Member> members;

    const string bookFile = "C:\\Users\\bryan\\Desktop\\物件導向\\圖書館系統\\圖書館系統\\x64\\Debug\\books.txt";
    const string memberFile = "C:\\Users\\bryan\\Desktop\\物件導向\\圖書館系統\\圖書館系統\\x64\\Debug\\members.txt";

    loadBooks(library, bookFile);
    loadMembers(members, memberFile);

    for (auto& member : members) {
        for (const auto& borrowedTitle : member.getBorrowedList()) {
            for (auto& book : library) {
                if (book.getTitle() == borrowedTitle) {
                    book.borrow();
                    break;
                }
            }
        }
    }

    cout << "請輸入會員編號登入：";
    int memberId;
    cin >> memberId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Member* current = findMemberById(members, memberId);
    if (!current) {
        cout << "查無此會員。\n";
        return 1;
    }

    cout << "歡迎，" << current->getName() << (current->getVIP() ? "（VIP）" : "") << "！\n";

    int choice;
    do {
        cout << "\n========= 圖書館管理系統 =========\n";
        cout << "1. 顯示所有書籍\n2. 分類查詢\n3. 借書\n4. 還書\n5. 顯示會員資料\n0. 離開並儲存\n請輸入選項：";

        if (!(cin >> choice)) {
            cout << "請輸入有效的數字！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            displayBooks(library);
        } else if (choice == 2) {
            string cat;
            cout << "輸入分類名稱：";
            getline(cin, cat);
            searchByCategory(library, cat);
        } else if (choice == 3) {
            int index;
            displayBooks(library);
            cout << "請輸入要借的書籍編號：";
            if (!(cin >> index)) {
                cout << "請輸入有效的數字！" << endl;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue;
            }
            if (index >= 0 && index < (int)library.size()) {
                if (!library[index].getStatus()) {
                    if (current->borrowBook(library[index].getTitle())) {
                        library[index].borrow();
                        cout << "成功借出！" << endl;
                    } else {
                        cout << "已達借書上限。" << endl;
                    }
                } else {
                    cout << "此書已被借出。" << endl;
                }
            } else {
                cout << "無效的書籍編號。" << endl;
            }
        } else if (choice == 4) {
            int index;
            displayBooks(library);
            cout << "請輸入要歸還的書籍編號：";
            if (!(cin >> index)) {
                cout << "請輸入有效的數字！" << endl;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue;
            }
            if (index >= 0 && index < (int)library.size()) {
                if (library[index].getStatus()) {
                    if (current->returnBook(library[index].getTitle())) {
                        library[index].returnBook();
                        cout << "已成功歸還。" << endl;
                    } else {
                        cout << "您沒有借這本書。" << endl;
                    }
                } else {
                    cout << "此書原本就可借。" << endl;
                }
            } else {
                cout << "無效的書籍編號。" << endl;
            }
        } else if (choice == 5) {
            current->display();
        }

    } while (choice != 0);

    saveBooks(library, bookFile);
    saveMembers(members, memberFile);
    cout << "資料已儲存，感謝使用！\n";

    return 0;
}