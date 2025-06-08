#include "MemberUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>

void loadMembers(vector<Member>& members, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "�o���_�����T�n����" << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, idStr, vipStr, borrowedStr;
        getline(ss, name, ',');
        getline(ss, idStr, ',');
        getline(ss, vipStr, ',');
        getline(ss, borrowedStr);

        int id = stoi(idStr);
        bool vip = (vipStr == "1");

        Member m(name, id, vip);
        stringstream bss(borrowedStr);
        string book;
        while (getline(bss, book, ';')) {
            if (!book.empty()) m.borrowBook(book);
        }

        members.push_back(m);
    }
}

void saveMembers(const vector<Member>& members, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "�o��������T�n����" << filename << endl;
        return;
    }
    for (const auto& m : members)
        file << m.toString() << endl;
}

Member* findMemberById(vector<Member>& members, int id) {
    for (auto& m : members)
        if (m.getId() == id)
            return &m;
    return nullptr;
}

void displayMembers(const vector<Member>& members) {
    cout << "\n==== ���Е��T ====\n";
    for (const auto& m : members)
        m.display();
}