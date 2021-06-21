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

    FontManager_class(string vPathToFile);

    bool loadFile();
    void closeFile();
    
    void getConfig(string myLine);
    void loadFileLinesInMemory();
    vector<vector<string>> getCaractersArray();
    
};
#endif