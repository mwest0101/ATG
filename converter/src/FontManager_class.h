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
    char c_charType = ' ';
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;
    char finalChar = '\"';
    int configFound = (-1);
    FontManager_class();
    string load(string vPathToFile);
    bool loadFile();
   
    void closeFile();
    int countline = 0;
    void getConfig();
    void getCharThatCloseLines();
    string loadFileLinesInMemory();
    vector<vector<string>> getCaractersArray();
    int getPosOfCharInFile(string chartoSearch);
    string getCharOfPosInFile(int posChar);
    vector<string> getCharFromFile(string charToSearch);

    void concStrVector(vector<string> vecOfAChar);
    vector<string> getFullStringOfChars();

    void convStrToStrOfAscciChar(string strToconvert);
    void writeFile(string filename,string text);
};
#endif
