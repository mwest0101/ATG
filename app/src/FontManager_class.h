#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "ctc.h"


//#include "config_inc.h"
#include "Debug_class.h"
#include "functions.h"
#include "functions_str.h"
#include "ConfigFont_class.h"
#include "convert_string.h"
#include "fonts.h"
#include "boxs.h"
#include "BoxDrive_class.h"

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
    string c_lineBox;
    int c_fontNumberStyle;
    
    int c_hColor=1;
    
    bool c_vRainbow=false;
    bool c_hRainbow = false;
    bool c_vRainbowTotalColors=false;
    bool c_vDemoColor = false;
    ifstream c_myFile_Handler;    
    char c_charType = ' ';    
    char c_finalChar = '\n';
    bool c_smush = false;
    bool c_insBox = false;
    
    vector<string> c_resultAsciiArtVector;
    vector<string> c_allContent;
    vector<vector<string>> c_caractersArray;
    vector<string> c_vecOfAllChars;
    vector<string> c_allNameFonts;

    FontManager_class();

    void setSmush(bool value);
    void setRainbowColor(int numLine);
    void setRainbowTotalColors(bool value);
    void setDemoColor(bool value);    
    void setVerticalRainbow(bool value);
    void setHorizontRainbow(bool value);

    void setInsertBox(bool value);
    void setStyleBox(int fontNumber);

    string getStrRainbowColor(int numLine);
    void setBoxDecorator(bool value);
    void setFonts();

    void getConfig(string data);
    string getFontNameByNum(int num);
    string getFontName(string font);
    string getStringResult();
    vector<string> getVectorfromOnechar(string data);
    
    string load(string fontName, string stringToPrint);
    void showListOfFonts();

    void concatenateChar(vector<string> oneChar);
    string applyHorizontalRainbow(string data);
    void printStringWithColorsCode(string data);
    //string strRemoveParamsEnveded(string data);
    void cleanArrayAndString();
    void generateVectorOfStrings(string fontName, string sourceString);
    //int  getMaxWidthLine();
    void InsertTextInBox(int styleBox);
    void applyParameters();
    void generateStringResult();
    void genStringAndResult();
    void printString();

   // void printHeadBox(string boxStyle, int spaces);


    void printStringResult();
    string mainGeneratorOfStr(string fontName, string stringToPrint);
    string reformatString(string data);

    bool addNumIfNotExisInArray(int num);
    void showDemoOfAllFonts(string style, string testString);
    void eraseEmptyStrLinesInVector();
  
};
#endif
