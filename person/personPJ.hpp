#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct PersonPJ
{
    string name;
    string company_name;
    string cnpj;
    string address;
    string birthdate;
    string share_capital;
};

void insertPJ(const string &filename);
void removePJ(const string &filename, const string &name);
vector<string> readListPJ(const string &filename);