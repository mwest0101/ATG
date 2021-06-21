#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include "functions_str.h"

#ifndef FONT_MANAGER_CLASS_H
#define FONT_MANAGER_CLASS_H
using namespace std;

class FontManager_class
{

public:
    const string HEAD_FILE;
    string c_pathToFile;
    ifstream c_myFile_Handler;

    vector<vector<string>> c_caractersArray;

    struct TextConfig
    {
        int found;
        string p1;
        string p2;
        int p3_Height;
        int p4_Height_nd;
        int p5_maxLinLen;
        int p6_defSmuMod;
        int p7_numComm;
    };
    

    

    FontManager_class(string vPathToFile);

    bool loadFile();
    void closeFile();
    
    struct TextConfig getConfig(string myLine);
    void loadFileLinesInMemory();
    vector<vector<string>> getCaractersArray();
    
};
#endif