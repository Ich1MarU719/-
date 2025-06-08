#ifndef MEMBERUTILS_H
#define MEMBERUTILS_H

#include <vector>
#include <string>
#include "Member.h"

using namespace std;

void loadMembers(vector<Member>& members, const string& filename);
void saveMembers(const vector<Member>& members, const string& filename);
Member* findMemberById(vector<Member>& members, int id);
void displayMembers(const vector<Member>& members);

#endif#pragma once
