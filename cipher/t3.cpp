#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define fdebug 1    //0 versão release    1 versão de produção

using namespace std;

int main()
{
    vector < pair < char, size_t > > table;   //lockuptable

    
    if(fdebug) cout << "enter with a alphabet: "; //1.read alphabet
    string pathfile;
    cin >> pathfile;
    
    ifstream pfile(pathfile); //tipo para leitura de arquivos
    if(!pfile.is_open())
    {
        if(fdebug) cout << "Error, alphabet file not found..." << endl;
        return 1;
    }
    
    char ch;
    while(pfile.get(ch))
    {
        if(ch == '\n') continue;
        pair<char, size_t> p;
        p.first = ch;
        p.second = 0;
        table.push_back(p);
        //cout << table.at(table.size()-1).first << endl;
    }
    //cout << table.size() << endl;
    pfile.close();
    
    
    //etapa 2 - leitura do manuscrito
    if(fdebug) cout << "enter with a manuscript: "; //1.read alphabet
    string pathfileman;
    cin >> pathfileman;
    
    pfile.open(pathfileman); //tipo para leitura de arquivos
    if(!pfile.is_open())
    {
        if(fdebug) cout << "Error, manuscript file not found..." << endl;
        return 1;
    }    

    stringstream manuscript;
    string tmpstr;
    while(getline(pfile, tmpstr))
    {
        manuscript << tmpstr;
    }
    //cout << manuscript.str() << endl;
    
    pfile.close();


    //criar table para calcular as frequencias dos caracteres ASC II Table
    //vector < pair < char, size_t > > table(256);  //#***
    for(size_t i=0; i<256; i++)
    {
        //table.at(i).first = i;
        //table[i].second = 0;

        pair <char , size_t> p;         //#***
        p = make_pair(i, 0);          //#***
        //p.first = i;
        //p.second = i+5;        
        table.push_back(p);             //#***
        
        cout << table[i].first << " -> " << table[i].second << endl;
    }    

    //cout << table.size() << endl;

    char ch2;     
    stringstream sst;
    while(pfile.get(ch2))    //realizando leitura e display em tela
    {
        //cout << ch2;
        sst << ch2;
        table.at(ch).second++;
    }
    //cout << sst.str() << endl;        
    /*
    cout << endl;
    for(size_t i=0; i<sst.str().length(); i++)
    {
        char index = sst.str().at(i);
        
        cout << (char)table.at(index).second;
    }
    cout << endl;*/
    
    pfile.close();
    
    return 0;
}


