#include "personPF.hpp"

void insertPF(const string &filename)
{
    PersonPF newp;

    getline(cin, newp.name);
    getline(cin, newp.cpf);
    getline(cin, newp.address);
    getline(cin, newp.birthdate);
    getline(cin, newp.marital_status);

    ofstream file(filename.c_str(), std::ios::in | std::ios::out | std::ios::ate);

    if(!file.is_open()) {
        cout << endl << "Erro ao abrir o arquivo" << endl << endl;
        return;
    }

    if(file.is_open()) {
        file << "PF" << endl;
        file << newp.name << endl;
        file << newp.cpf << endl;
        file << newp.address << endl;
        file << newp.birthdate << endl;
        file << newp.marital_status << endl;
    }

    file.close();
}

void removePF(const string &filename, const string &name) {
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
            list.erase(list.begin()+i-1, list.begin()+i+5);
        }
    }

    ofstream file2(filename.c_str());

    for(int j=0;j<list.size();j++){
    	file2 << list.at(j) << endl;
    }
    file2.close();
}

vector<string> search(vector<string> &list, const string &query) {
    vector<string> result;
    for(size_t i=0; i<list.size(); i++)
    {
        string tmp = list.at(i);
        if(tmp.find(query) != std::string::npos) {
            result.push_back(list.at(i));
        } 
    }

    return result;
}

vector<string> readListPF(const string &filename) {
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
        if(list.at(i) == "PF") {
            newList.push_back(list.at(i+1));
        } 
    }

    return newList;
}

void deleteList(const string &filename) {
    vector<string> list; 
    ifstream file(filename.c_str());

    string tmp;
    while(getline(file, tmp))
    {
        list.push_back(tmp);
    }
    file.close();

    list.erase(list.begin(), list.end());

    ofstream file2(filename.c_str());

    file2.close();
}

