
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include "functions_str.h"

using namespace std;
const string HEAD_FILE = "flf2";

struct TextConfig {
    string p1;
    string p2;
    int  p3_Height = 0;
    int  p4_Height_nd = 0;
    int  p5_maxLinLen = 0;
    int  p6_defSmuMod = 0;
    int  p7_numComm = 0;
};

struct TextConfig tc;
int main()
{
    
    ifstream myFile_Handler;
    string myLine;
    int countline = 0;
    int confFound = 0;
    int characterFound = 0;
    string strParam;
    vector<string> params;
    vector<vector <string>> caracters;
    vector<string> caracter;
    
    string caracterStr = "";
    string strChar = "";
    
    myFile_Handler.open("fonts\\Speed.flf");

    if (myFile_Handler.is_open())
    {
        // Keep reading the file
        characterFound = 0;

        while (getline(myFile_Handler, myLine)) {
            countline++;
            characterFound = findEndOfStr(myLine, HEAD_FILE);            
            if (characterFound!=(-1) && confFound==0) {
                confFound ++;
                strParam = myLine.substr(characterFound);
                params = splitStr(strParam,' ');
                tc.p1 =           params[0][0];
                tc.p2 =           params[0][1];
                tc.p3_Height =    stoi(params[1]);
                tc.p4_Height_nd = stoi(params[2]);
                tc.p5_maxLinLen = stoi(params[3]);
                tc.p6_defSmuMod = stoi(params[4]);
                tc.p7_numComm =   stoi(params[5]);

            }else if (confFound > 0) {                    
                if (countline > tc.p7_numComm) {                    
                    if ((characterFound = findStr(myLine, "@@"))!=(-1)) {
                        strChar = myLine.substr(0, characterFound);
                        caracter = splitStr(caracterStr, '@');
                        caracters.push_back(caracter);                        
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
    /*
    printStrVector(caracters[0]);   
    printStrVector(caracters[1]);
    printStrVector(caracters[2]);
    printStrVector(caracters[3]);
    printStrVector(caracters[4]);
    printStrVector(caracters[5]);
    printStrVector(caracters[6]);
    printStrVector(caracters[7]);
    printStrVector(caracters[8]);
    */
    //getNumOfListOfCharsInFiles('a');
    
    return 0;
}

