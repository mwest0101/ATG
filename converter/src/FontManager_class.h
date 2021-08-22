#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "config_inc.h"
#include "Debug_class.h"
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
    vector<string> c_allContent;
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;
    char finalChar = '\n';

    int configFound = (-1);
    FontManager_class();
    string load(string vPathToFile, string fileName);
    bool loadFile();
    string doubleChar;
    string singleChar;
   
    void closeFile();
    vector<string> getVectorOfChars();
    int countline = 0;
    void getConfig();
    void getCharThatCloseLines();
    string getCharlines();
    vector<vector<string>> getCaractersArray();
    int getPosOfCharInFile(string chartoSearch);
    string getCharFromPosInFile(int chartoSearch);
    string getCharOfPosInFile(int posChar);
    vector<string> getCharFromFile(string charToSearch);
    string fileNameToStorageResult;
    void concStrVector(vector<string> vecOfAChar);
    vector<string> getFullStringOfChars();

    void convStrToStrOfAscciChar(string strToconvert);
 
};
#endif
