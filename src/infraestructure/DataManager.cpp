#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DataManager.h"
 
using namespace std;

namespace tdc::infraestructure { 
    DataManager::DataManager() {
        filename = "";
    };
    DataManager::DataManager(string _filename) {
        filename = _filename;
    };

    void DataManager::loadData() {
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        fstream file (filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();
                stringstream str(line);
                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
        else
            throw "No se pudo abrir el archivo";

        for(int i=0;i<content.size();i++)
        {
            for(int j=0;j<content[i].size();j++)
            {
                cout<<content[i][j]<<" ";
            }
            cout<<"\n";
        }
    };
}