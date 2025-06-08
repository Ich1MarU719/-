#include "Member.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Member::Member(string n, int id, bool vip)
    : name(n), memberId(id), isVIP(vip) {
}

string Member::getName() const { return name; }
int Member::getId() const { return memberId; }
bool Member::getVIP() const { return isVIP; }
const vector<string>& Member::getBorrowedList() const { return borrowedTitles; }

bool Member::borrowBook(const string& title) {
    int limit = isVIP ? 5 : 3;
    if (borrowedTitles.size() >= limit) return false;
    borrowedTitles.push_back(title);
    return true;
}

bool Member::returnBook(const string& title) {
    auto it = find(borrowedTitles.begin(), borrowedTitles.end(), title);
    if (it != borrowedTitles.end()) {
        borrowedTitles.erase(it);
        return true;
    }
    return false;
}

string Member::toString() const {
    stringstream ss;
    ss << name << "," << memberId << "," << isVIP << ",";
    for (size_t i = 0; i < borrowedTitles.size(); ++i) {
        ss << borrowedTitles[i];
        if (i != borrowedTitles.size() - 1)
            ss << ";";
    }
    return ss.str();
}

void Member::display() const {
    cout << "會員名稱: " << name << "\n會員編號: " << memberId
        << "\nVIP: " << (isVIP ? "是" : "否") << "\n目前借閱: ";
    if (borrowedTitles.empty()) cout << "無";
    else for (const auto& t : borrowedTitles) cout << t << " ";
    cout << endl;
}