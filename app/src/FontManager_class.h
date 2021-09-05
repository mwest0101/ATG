#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


//#include "config_inc.h"
#include "Debug_class.h"
#include "functions.h"
#include "functions_str.h"
#include "ConfigFont_class.h"
#include "convert_string.h"
#include "fonts.h"
#ifndef FONT_MANAGER_CLASS_H
#define FONT_MANAGER_CLASS_H
using namespace std;

class FontManager_class
{

public:
    int countline = 0;
    int configFound = (-1);

    string c_pathToFile;
    string doubleChar;
    string singleChar;
    string c_fileEncoding;
    string fileNameToStorageResult;
    string resultAsciiArtString;

    ifstream c_myFile_Handler;
    
    char c_charType = ' ';    
    char finalChar = '\n';

    bool c_smush = false;
    
    vector<string> resultAsciiArtVector;
    vector<string> c_allContent;
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;

    FontManager_class();
    string load(string fontName, string stringToPrint);
    vector<string> getVectorfromOnechar(string data);
    void concatenateChar(vector<string> oneChar);
    void generateVectorOfStrings(string fontName, string sourceString);
    void generateStringResult();
    void setSmush(bool value);
    string reformatString(string data);
    string getStringResult();
    void getConfig(string data);
    bool addNumIfNotExisInArray(int num);
    void showListOfFonts();
 
};
#endif
