#include "LibraryUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

void loadBooks(vector<Book>& books, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "無法開啟檔案：" << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cat, t, a, b;
        getline(ss, cat, ',');
        getline(ss, t, ',');
        getline(ss, a, ',');
        getline(ss, b);
        books.emplace_back(t, a, cat, b == "1");
    }
}

void saveBooks(const vector<Book>& books, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "無法寫入檔案：" << filename << endl;
        return;
    }
    for (const auto& book : books)
        file << book.toString() << endl;
}

void displayBooks(const vector<Book>& books) {
    cout << "\n編號 | 分類       | 書名                 | 作者           | 狀態" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (size_t i = 0; i < books.size(); ++i)
        books[i].display(i);
}

void searchByCategory(const vector<Book>& books, const string& target) {
    cout << "\n分類「" << target << "」的書籍如下：" << endl;
    int count = 0;
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getCategory() == target) {
            books[i].display(i);
            ++count;
        }
    }
    if (count == 0) cout << "找不到此分類的書籍。" << endl;
}