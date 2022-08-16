#include <iostream>
#include "personPF.hpp"
#include "personPJ.hpp"

using namespace std;

#define fdebug 1      // quando 0 - release   /    1 - produção

int main()
{
    vector<PersonPF> pflist;
    
    for(;;)
    {/*
        if(fdebug) cout << pflist.size() << endl;
        if(fdebug) cout << "Digite uma opcao: " << endl;
        if(fdebug) cout << "1. Inserir PF" << endl;
        if(fdebug) cout << "2. Inserir PJ" << endl;
        if(fdebug) cout << "3. Remover" << endl;
        if(fdebug) cout << "4. Pesquisar" << endl;
        if(fdebug) cout << "5. Imprimir Lista" << endl;
        if(fdebug) cout << "6. Imprimir Grupos" << endl;
        if(fdebug) cout << "7. Sair" << endl;*/
        
        char ch;
        cin >> ch;
        
        //fflush();
        cin.ignore(); //limpando buffer 
        
        if(ch == '1')
        {

            if(fdebug) {
                insertPF("list.txt");
                exit;
            }
        }        

        if(ch == '2')
        {
            if(fdebug) {
                insertPJ("list.txt");
                exit;
            }
        }   

        if(ch == '3')
        {
            string type;
            string name;
            int position;
            cin >> type;
            cin >> position;

            vector<string> listPF = readListPF("list.txt");
            vector<string> listPJ = readListPJ("list.txt");

            if(fdebug) {
                if(type == "F") {
                    for(size_t i=0; i<listPF.size(); i++)
                    {
                        if(i == position) {
                            name = listPF.at(i);
                        }
                    }
                    removePF("list.txt", name);
                }
                if(type == "J") {
                    for(size_t i=0; i<listPJ.size(); i++)
                    {
                        if(i == position) {
                            name = listPJ.at(i);
                        }
                    }
                    removePJ("list.txt", name);
                }
            }
        } 

        if(ch == '4')
        {
            string name;
            cin >> name;
            vector<string> listPF = readListPF("list.txt");
            vector<string> listPJ = readListPJ("list.txt");
            vector<string> list;

            for(size_t i=0; i<listPF.size(); i++)
            {
                listPF.at(i) =  listPF.at(i) + " -> PF pos: " + to_string(i);
                list.push_back(listPF.at(i));
            }

            for(size_t i=0; i<listPJ.size(); i++)
            {
                listPJ.at(i) =  listPJ.at(i) + " -> PJ pos: " + to_string(i);
                list.push_back(listPJ.at(i));
            }

            vector<string> resultList = search(list, name);

            for(size_t i=0; i<resultList.size(); i++)
            {
                cout << resultList.at(i) << endl;
            }
        }

        if(ch == '5')
        {
            vector<string> listPF = readListPF("list.txt");
            vector<string> listPJ = readListPJ("list.txt");
            vector<string> list;

            for(size_t i=0; i<listPF.size(); i++)
            {
                listPF.at(i) =  listPF.at(i) + " -> PF pos: " + to_string(i); 
                list.push_back(listPF.at(i));
            }

            for(size_t i=0; i<listPJ.size(); i++)
            {
                listPJ.at(i) =  listPJ.at(i) + " -> PJ pos: " + to_string(i); 
                list.push_back(listPJ.at(i));
            }
            
            sort(list.begin(), list.end());

            for(size_t i=0; i<list.size(); i++)
            {
                cout << list.at(i) << endl; // " -> " << list.at(i).cpf << endl; 
            }
            exit;
        }     

        if(ch == '6') 
        {
            vector<string> listPF = readListPF("list.txt");
            vector<string> listPJ = readListPJ("list.txt");

            cout << "Pessoa Fisica:" << endl;
            for(size_t i=0; i<listPF.size(); i++)
            {
                cout << listPF.at(i) << " -> " << "PF" << " Pos: " << i << endl; 
            }
            cout << endl;

            cout << "Pessoa Juridica:" << endl;
            for(size_t i=0; i<listPJ.size(); i++)
            {
                cout << listPJ.at(i) << " -> " << "PF" << " Pos: " << i << endl; 
            }

            cout << endl;
        }

        if(ch == '7') {
            deleteList("list.txt");
            break;
        } 
        
        //system("clear"); //windows eh 'cls'
    }    
    return 0;
}
