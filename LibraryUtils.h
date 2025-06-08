#ifndef LIBRARYUTILS_H
#define LIBRARYUTILS_H

#include <vector>
#include <string>
#include "Book.h"

using namespace std;

void loadBooks(vector<Book>& books, const string& filename);
void saveBooks(const vector<Book>& books, const string& filename);
void displayBooks(const vector<Book>& books);
void searchByCategory(const vector<Book>& books, const string& category);

#endif