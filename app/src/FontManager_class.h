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
    string c_doubleChar;
    string c_singleChar;
    string c_fileEncoding;
    string c_fileNameToStorageResult;
    string c_resultAsciiArtString;

    ifstream c_myFile_Handler;
    
    char c_charType = ' ';    
    char c_finalChar = '\n';

    bool c_smush = false;
    
    vector<string> c_resultAsciiArtVector;
    vector<string> c_allContent;
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;
    vector<string> c_allNameFonts;

    FontManager_class();
    string load(string fontName, string stringToPrint);
    void setFonts();
    string getFontNameByNum(int num);
    string getFontName(string font);
    vector<string> getVectorfromOnechar(string data);
    void concatenateChar(vector<string> oneChar);
    void cleanArrayAndString();
    void generateVectorOfStrings(string fontName, string sourceString);
    void generateStringResult();
    string mainGeneratorOfStr(string fontName, string stringToPrint);
    void setSmush(bool value);
    string reformatString(string data);
    string getStringResult();
    void getConfig(string data);
    bool addNumIfNotExisInArray(int num);
    void showListOfFonts();
    void showDemoOfAllFonts(string style, string testString);
  
};
#endif
