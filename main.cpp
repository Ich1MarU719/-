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

    const string bookFile = "C:\\Users\\bryan\\Desktop\\�������\\�D���^ϵ�y\\�D���^ϵ�y\\x64\\Debug\\books.txt";
    const string memberFile = "C:\\Users\\bryan\\Desktop\\�������\\�D���^ϵ�y\\�D���^ϵ�y\\x64\\Debug\\members.txt";

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

    cout << "Ոݔ����T��̖���룺";
    int memberId;
    cin >> memberId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Member* current = findMemberById(members, memberId);
    if (!current) {
        cout << "��o�˕��T��\n";
        return 1;
    }

    cout << "�gӭ��" << current->getName() << (current->getVIP() ? "��VIP��" : "") << "��\n";

    int choice;
    do {
        cout << "\n========= �D���^����ϵ�y =========\n";
        cout << "1. �@ʾ���Е���\n2. ���ԃ\n3. ���\n4. ߀��\n5. �@ʾ���T�Y��\n0. �x�_�K����\nՈݔ���x헣�";

        if (!(cin >> choice)) {
            cout << "Ոݔ����Ч�Ĕ��֣�" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            displayBooks(library);
        } else if (choice == 2) {
            string cat;
            cout << "ݔ�������Q��";
            getline(cin, cat);
            searchByCategory(library, cat);
        } else if (choice == 3) {
            int index;
            displayBooks(library);
            cout << "Ոݔ��Ҫ��ĕ�����̖��";
            if (!(cin >> index)) {
                cout << "Ոݔ����Ч�Ĕ��֣�" << endl;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue;
            }
            if (index >= 0 && index < (int)library.size()) {
                if (!library[index].getStatus()) {
                    if (current->borrowBook(library[index].getTitle())) {
                        library[index].borrow();
                        cout << "�ɹ������" << endl;
                    } else {
                        cout << "���_������ޡ�" << endl;
                    }
                } else {
                    cout << "�˕��ѱ������" << endl;
                }
            } else {
                cout << "�oЧ�ĕ�����̖��" << endl;
            }
        } else if (choice == 4) {
            int index;
            displayBooks(library);
            cout << "Ոݔ��Ҫ�w߀�ĕ�����̖��";
            if (!(cin >> index)) {
                cout << "Ոݔ����Ч�Ĕ��֣�" << endl;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue;
            }
            if (index >= 0 && index < (int)library.size()) {
                if (library[index].getStatus()) {
                    if (current->returnBook(library[index].getTitle())) {
                        library[index].returnBook();
                        cout << "�ѳɹ��w߀��" << endl;
                    } else {
                        cout << "���]�н��@������" << endl;
                    }
                } else {
                    cout << "�˕�ԭ���Ϳɽ衣" << endl;
                }
            } else {
                cout << "�oЧ�ĕ�����̖��" << endl;
            }
        } else if (choice == 5) {
            current->display();
        }

    } while (choice != 0);

    saveBooks(library, bookFile);
    saveMembers(members, memberFile);
    cout << "�Y���у��棬���xʹ�ã�\n";

    return 0;
}