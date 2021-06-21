#include "FontManager_class.h"

using namespace std;


    
    FontManager_class::FontManager_class(string vPathToFile)
    {
        c_pathToFile = vPathToFile;
        if(loadFile()){
          loadFileLinesInMemory();
          closeFile();  
        }
    }

    //"fonts\\Speed.flf"
    bool FontManager_class::loadFile()
    {
        c_myFile_Handler.open(c_pathToFile);
        if (c_myFile_Handler.is_open())
        {
            return true;
        }
        else
        {
            cout << "Unable to open the file!";
            return false;
        }
    }
    void FontManager_class::closeFile(){
        c_myFile_Handler.close();

    }
    
    struct FontManager_class::TextConfig FontManager_class::getConfig(string myLine)
    {
        vector<string> paramsArray;
        string strParam;
        int characterFound = (-1);

        characterFound = findEndOfStr(myLine, HEAD_FILE);
        struct TextConfig tc;

        if (characterFound != (-1))
        {
            strParam = myLine.substr(characterFound);
            paramsArray = splitStr(strParam, ' ');
            tc.found = characterFound;
            tc.p1 = paramsArray[0][0];
            tc.p2 = paramsArray[0][1];
            tc.p3_Height = stoi(paramsArray[1]);
            tc.p4_Height_nd = stoi(paramsArray[2]);
            tc.p5_maxLinLen = stoi(paramsArray[3]);
            tc.p6_defSmuMod = stoi(paramsArray[4]);
            tc.p7_numComm = stoi(paramsArray[5]);
        }
    }

    void FontManager_class::loadFileLinesInMemory()
    {
        // Keep reading the file
        int characterFound = 0;
        int countline = 0;

        string myLine, caracterStr, strChar;

        vector<string> caracterArray;

        struct TextConfig tc;

        while (getline(c_myFile_Handler, myLine))
        {
            countline++;
            if (tc.found == (-1))
            {
                tc = getConfig(myLine);
            }
            else
            {
                if (countline > tc.p7_numComm)
                {
                    if ((characterFound = findStr(myLine, "@@")) != (-1))
                    {
                        strChar = myLine.substr(0, characterFound);
                        caracterStr = caracterStr + strChar;
                        caracterArray = splitStr(caracterStr, '@');
                        c_caractersArray.push_back(caracterArray);
                        caracterStr = "";
                    }
                    else
                    {
                        caracterStr = caracterStr + myLine;
                    }
                }
            }
        }

    }
    vector<vector<string>> FontManager_class::getCaractersArray() {
        return c_caractersArray;
    }