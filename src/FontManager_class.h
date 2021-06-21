#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include "functions_str.h"
#include "ConfigFont_class.h"

#ifndef FONT_MANAGER_CLASS_H
#define FONT_MANAGER_CLASS_H
using namespace std;

class FontManager_class
{

public:
    
    string c_pathToFile;
    ifstream c_myFile_Handler;
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;

    FontManager_class();
    void load(string vPathToFile, string strToPrint);
    bool loadFile();
    void closeFile();
    
    void getConfig(string myLine);
    void loadFileLinesInMemory();
    vector<vector<string>> getCaractersArray();
    int getPosOfCharInFile(string chartoSearch);
    vector<string> getCharFromFile(string charToSearch);

    void concStrVector(vector<string> vecOfAChar);
    vector<string> getFullStringOfChars();

    void convStrToStrOfAscciChar(string strToconvert);
};
#endif