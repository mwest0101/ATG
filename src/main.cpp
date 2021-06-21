#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include "functions_str.h"
#include "FontManager_class.h"
#include "ConfigFont_class.h"
using namespace std;







int main()
{
    vector<string> vecOfAllChars;
    vector<string> vecOfAChar;

    FontManager_class fontsLoder("fonts\\Speed.flf");
    /*
    vecOfAChar = fontsLoder.getCharFromFile("M");
    //printStrVector(vecOfAChar);
    fontsLoder.concStrVector(vecOfAChar);
    
    vecOfAChar = fontsLoder.getCharFromFile("a");
    //printStrVector(vecOfAChar);
    fontsLoder.concStrVector(vecOfAChar);
    */
    fontsLoder.convStrToStrOfAscciChar("Mauricio");
    printStrVector(fontsLoder.getFullStringOfChars());
    

/*
    struct TextConfig tc;
    ifstream myFile_Handler;
    string myLine;
    int countline = 0;
    int confFound = 0;
    int characterFound = 0;
    string strParam;
    
    vector<vector <string>> caractersArray;
    vector<string> caracterArray;
    
    string caracterStr = "";
    string strChar = "";
    
    myFile_Handler.open("fonts\\Speed.flf");

    if (myFile_Handler.is_open())
    {
        // Keep reading the file
        characterFound = 0;       
        
        while (getline(myFile_Handler, myLine)) {
            countline++;  
            if (tc.found==(-1)) {
                tc=getInitConfig(myLine);                
            }else{                    
                if (countline > tc.p7_numComm) {                    
                    if ((characterFound = findStr(myLine, "@@"))!=(-1)) {
                        strChar = myLine.substr(0, characterFound);
                        caracterStr = caracterStr + strChar;
                        caracterArray = splitStr(caracterStr, '@');
                        caractersArray.push_back(caracterArray);
                        caracterStr = "";                      
                    } else {
                        caracterStr = caracterStr+ myLine;                        
                    }                
                }                 
            }         
        }
        


        myFile_Handler.close();



    }else{
        cout << "Unable to open the file!";
    }
    
    //cout << getPosOfCharInFile("!") << endl;
    //cout << getPosOfCharInFile("\"") << endl;
    //cout << getPosOfCharInFile("A") << endl;
    //cout << getPosOfCharInFile("a") << endl;

    vector<string> vecOfAllChars;
    vector<string> vecOfAChar;

    vecOfAChar =getCharFromFile(caracters, "M");
     //printStrVector(vecOfAChar);
    
    vecOfAllChars=concStrVector(vecOfAllChars,vecOfAChar);
    printStrVector(vecOfAllChars);

    vecOfAChar = getCharFromFile(caracters, "a");
 //   printStrVector(vecOfAChar);
    vecOfAllChars = concStrVector(vecOfAllChars, vecOfAChar);
    printStrVector(vecOfAllChars);

    vecOfAChar = getCharFromFile(caracters, "u");
  //  printStrVector(vecOfAChar);
    vecOfAllChars = concStrVector(vecOfAllChars, vecOfAChar);
    printStrVector(vecOfAllChars);
    
    //printStrVector(vecOfAllChars);
    //printStrVector(caracters[0]);
    
    printStrVector(caracters[0]);   
    printStrVector(caracters[1]);
    printStrVector(caracters[2]);
    printStrVector(caracters[3]);
    printStrVector(caracters[4]);
    printStrVector(caracters[5]);
    printStrVector(caracters[6]);
    printStrVector(caracters[7]);
    printStrVector(caracters[8]);
    
    //getNumOfListOfCharsInFiles('a');
    */

    return 0;
}

