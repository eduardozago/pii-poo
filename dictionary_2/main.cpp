#include "dict.hpp"

#define fdebug 1

int main()
{
    vector<Dictionary> listdict;
    
    while(true)
    {
        if(fdebug) cout << "Insert an option: " << endl;
        if(fdebug) cout << "1.Insert Dictionary" << endl;
        if(fdebug) cout << "2.Show dictionaries (all)" << endl;
        if(fdebug) cout << "3.Search (substring from everywhere)" << endl;
        if(fdebug) cout << "4.Insert word (in the last dictionary)" << endl;
        if(fdebug) cout << "5.Remove word (substring all from everywhere)" << endl;
        if(fdebug) cout << "6.Remove duplicates (all from everywhere)" << endl;
        if(fdebug) cout << "0.Quit" << endl;
        
        char ch;
        cin >> ch;
        
        //fflush()
        cin.ignore();
        
        if(ch == '1')
        {
            if(fdebug) cout << "Enter a dictionary path: ";
            string path;
            cin >> path;
            
            Dictionary a(path);
            if(a.GetSize() > 0) listdict.push_back(a);

            //Dictionary a;
            //if(a.LoadDictionary(path))  listdict.push_back(a);            
            //continue;
        }
        if(ch == '2')
        {
            for(size_t i=0; i<listdict.size(); i++)
            {
                cout << "Dictionary path : " << listdict.at(i).GetPath() << endl;
                for(size_t j=0; j<listdict.at(i).GetSize(); j++)
                {
                    cout << " -> " << listdict.at(i).GetWord(j) << endl;
                }
            }
        }
        if(ch == '4')
        {
            if(fdebug) cout << "Enter with a new word : ";
            string newword;
            cin >> newword;
            
            listdict.at(listdict.size()-1).Insert(newword);
        }
        
        if(ch == '0') break;       
        
        if(fdebug) cout << "Loaded dictionaries: " << listdict.size() << endl; 
    }
    return 0;
}
