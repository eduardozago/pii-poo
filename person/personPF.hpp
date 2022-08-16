#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct PersonPF
{
    string name;
    string cpf;
    string address;
    string birthdate;
    string marital_status;
};

void insertPF(const string &filename);
void removePF(const string &filename, const string &name);
vector<string> readListPF(const string &filename);
vector<string> search(vector<string> &list, const string &query);
void deleteList(const string &filename);
