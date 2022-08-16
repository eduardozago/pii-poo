#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> LoadDictionary(const char* path);

bool searchWord(const vector<string>& list, string query, size_t& index);

vector< pair<size_t, string > > searchSubstring(const vector<string>& list, string query);
