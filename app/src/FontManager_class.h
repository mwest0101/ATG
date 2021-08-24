#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
    
    string c_pathToFile;
    ifstream c_myFile_Handler;
    char c_charType = ' ';
    bool c_smush = false;
    vector<string> c_allContent;
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;
    char finalChar = '\n';

    string resultAsciiArtString;
    vector<string> resultAsciiArtVector;


    int configFound = (-1);
    FontManager_class();
    string load(string fontName, string stringToPrint);

    void getConfig(string data);

    vector<string> getVectorfromOnechar(string data);
    void concatenateChar(vector<string> oneChar);
   
    void generateVectorOfStrings(string fontName,string sourceString);

    void generateStringResult();

    string getStringResult();

    void setSmush(bool value);

    string reformatString(string data);

    string doubleChar;
    string singleChar;

    string c_fileEncoding;
   
 

    int countline = 0;
    
    void getCharThatCloseLines();


    string getCharlines();
    vector<vector<string>> getCaractersArray();

    vector<string> getCharFromFile(string charToSearch);
    string fileNameToStorageResult;
    void concStrVector(vector<string> vecOfAChar);

    vector<string> getFullStringOfChars();

    void convStrToStrOfAscciChar(string strToconvert);
 
};
#endif
