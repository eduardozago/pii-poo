#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary
{
private:    
    vector<string> m_list;
    string m_path;
    
public:
    Dictionary(); //constructor
    Dictionary(string path); //constructor
    ~Dictionary(); //destrutor
    
    bool LoadDictionary(string path);
    
    //Getters
    string GetPath() const { return m_path; }
    size_t GetSize() const { return m_list.size(); }
    string GetWord(size_t i) const { return m_list.at(i); }

    //Setter
    void Insert(string newword) { m_list.push_back(newword); }
    
};
