
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
    // File Open in the Read Mode
    string caracterStr = "";
    string strChar = "";
    int vectorInd = 0;
    myFile_Handler.open("fonts\\Speed.flf");

    if (myFile_Handler.is_open())
    {
        // Keep reading the file
        characterFound = 0;

        while (getline(myFile_Handler, myLine))
        {
            countline++;
           

            //cout << "|" << confFound << "|" << endl;
            // print the line on the standard output
            characterFound = findEndOfStr(myLine, HEAD_FILE);
            //cout << " [ " << characterFound << " ] " << endl;
            if (characterFound!=(-1) && confFound==0) {
                confFound ++;
                //cout << "pase " << confFound << endl;
                //cout << myLine.substr(characterFound) << endl;
                strParam = myLine.substr(characterFound);

                params = splitStr(strParam,' ');
                tc.p1 =           params[0][0];
                tc.p2 =           params[0][1];
                tc.p3_Height =    stoi(params[1]);
                tc.p4_Height_nd = stoi(params[2]);
                tc.p5_maxLinLen = stoi(params[3]);
                tc.p6_defSmuMod = stoi(params[4]);
                tc.p7_numComm =   stoi(params[5]);

                //cout << " --> " << tc.p1 << endl;
                //cout << " --> " << tc.p7_numComm << endl;

                //printStrVector(params);
            }else if (confFound > 0) {
                    
                if (countline > tc.p7_numComm) {
                    
                    if ((characterFound = findStr(myLine, "@@"))!=(-1)) {
                        strChar = myLine.substr(0, characterFound);
                        //cout << caracterStr << endl;
                        caracter = splitStr(caracterStr, '@');

                        caracters.push_back(caracter);
                        vectorInd++;
                        //printStrVector(caracter);
                    } else {
                        caracterStr = caracterStr+ myLine;
                        
                    }

                    //caracters = splitStr(myLine, ' ');
                }
                    /*
                    if ((characterFound = findStr(myLine, "-")) != (-1)) {
                        confFound++;
                        myLine = trimString(myLine.substr(0, characterFound)," ");
                        
                        
                        
                        switch (confFound) {
                            case 2:
                                tc.p1 = myLine;
                                break;
                            case 3:
                                tc.p2 = myLine;
                                break;
                            case 4:
                                tc.p3_Height = stoi(myLine);
                                break;
                            case 5:
                                tc.p4_Height_nd = stoi(myLine);
                                break;
                            case 6:
                                tc.p5_maxLinLen = stoi(myLine);
                                break;
                            case 7:
                                tc.p6_defSmuMod = stoi(myLine);
                                break;
                            case 8:
                                tc.p6_numComm = stoi(myLine);
                                break;
                            default:
                              //  cout << tc.p1;
                              //  cout << tc.p6_numComm;
                                break;


                        }
                    }
                    */
                
                   
            }

           //cout << myLine << endl;
        }
        //printStrVector(caracters);
        // File Close
        myFile_Handler.close();
    }
    else
    {
        cout << "Unable to open the file!";
    }
    
    printStrVector(caracters[0]);
    printStrVector(caracters[1]);
    /*
    printStrVector(caracters[1]);
    printStrVector(caracters[2]);
    printStrVector(caracters[3]);
    printStrVector(caracters[5]);
    printStrVector(caracters[6]);
    printStrVector(caracters[7]);
    printStrVector(caracters[8]);
    
    */
    return 0;
}

