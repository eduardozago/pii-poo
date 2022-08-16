#include "personPJ.hpp"

void insertPJ(const string &filename)
{
    PersonPJ newj;

    getline(cin, newj.name);
    getline(cin, newj.company_name);
    getline(cin, newj.cnpj);
    getline(cin, newj.address);
    getline(cin, newj.birthdate);
    getline(cin, newj.share_capital);

    ofstream file(filename.c_str(), std::ios::in | std::ios::out | std::ios::ate);

    if(!file.is_open()) {
        cout << endl << "Erro ao abrir o arquivo" << endl << endl;
        return;
    }

    if(file.is_open()) {
        file << "PJ" << endl;
        file << newj.name << endl;
        file << newj.company_name << endl;
        file << newj.cnpj << endl;
        file << newj.address << endl;
        file << newj.birthdate << endl;
        file << newj.share_capital << endl;
    }

    file.close();
    return;
}

void removePJ(const string &filename, const string &name) {
    vector<string> list; 
    ifstream file(filename.c_str());

    string tmp;
    while(getline(file, tmp))
    {
        list.push_back(tmp);
    }
    file.close();

    for(int i=0; i<list.size(); i++) {
        if(list.at(i) == name) {
            list.erase(list.begin()+i-1, list.begin()+i+6);
        }
    }

    ofstream file2(filename.c_str());

    for(int j=0;j<list.size();j++){
    	file2 << list.at(j) << endl;
    }
    file2.close();

}

vector<string> readListPJ(const string &filename) {
    vector<string> list; 
    ifstream file(filename.c_str());

    string tmp;
    while(getline(file, tmp))
    {
        list.push_back(tmp);
    }
    file.close();

    vector<string> newList;

    for(size_t i=0; i<list.size(); i++)
    {
        if(list.at(i) == "PJ") {
            newList.push_back(list.at(i+1));
        } 
    }

    return newList;
}