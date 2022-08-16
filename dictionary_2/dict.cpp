#include "dict.hpp"

Dictionary::Dictionary()
{
    
}

Dictionary::Dictionary(string path)
{
    LoadDictionary(path);
}

Dictionary::~Dictionary()
{
    
}

bool Dictionary::LoadDictionary(string path)
{
    m_path = path;
    
    ifstream file;
    file.open(path);
      
    if(file.is_open() == true)
    {
        string tmp;
        while(getline(file, tmp))
        {        
            m_list.push_back(tmp);
        }
        
        m_list.erase(m_list.begin()+0);
    }
    else
        return false;
    
    return true;
}

