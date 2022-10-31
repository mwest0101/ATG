#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "boxs.h"
#include "functions_str.h"
#include "FontManager_class.h"
#include "ConfigFont_class.h"
#include "Debug_class.h"
#include <io.h>
#include "fonts.h"
#include "ctc.h"

#include "BoxDrive_class.h"

using namespace std;





int main(int argc, char* argv[], char* envp[])
{
    string strResult;
    string param1="";
    string param2="";
    setlocale(LC_ALL, "en_US.UTF-8");

    FontManager_class fontsLoader;
    BoxDrive_class boxDrive;
    vector<string> params;

    vector<string> boxList = boxDrive.getAllNameBox();

    cout << endl;
    for (int i = 1; i < argc; i++) {
        params.push_back(argv[i]);

    }
    int countParam = 0;
    for (string param : params) {
        //cout << "Param= " << param << endl;
        if (param == "-s") {

            fontsLoader.setSmush(true);
        }else if (param == "-ra"){
            fontsLoader.setDemoColor(true);
        }else if (param == "-rv") {

            fontsLoader.setVerticalRainbow(true);
        }
        else if (param == "-rvt") {

            fontsLoader.setVerticalRainbow(true);
            fontsLoader.setRainbowTotalColors(true);
        }
        else if (param == "-rh") {
            fontsLoader.setHorizontRainbow(true);

        }else if (findStr(param,"-b:")!=(-1)) {
            fontsLoader.setInsertBox(true);
            vector<string> paramBox = splitStr(param, ':');
            fontsLoader.setStyleBox(strToInt(paramBox[1]));

        }else if (param == "-l") {
            
            param1 = "listAllFontNames";
            
            countParam=2;
        } else if (param == "-dn") {

            param1 = "listAllFontsExampleWithName";
            countParam = 2;
        } else if (param == "-dc") {

            param1 = "listAllFontsExampleWithCustom";
            countParam = 1;
        } else if (param == "-d") {

            param1 = "listAllFontsExampleWithDemo";
            countParam=2;
        }
        else if (param == "-bl") {            
            
            boxDrive.showListOfBox();
            countParam = 2;
            param1 = "";
            param2 = "";
        }else if (param == "-db") {
         
            
            fontsLoader.setInsertBox(true);
            cout << to_string(boxList.size()) << endl;
            for (unsigned int i = 1; i < boxList.size();i++) {      
                
                cout << "===============================================================" << endl;
                BoxDrive_class boxDrive;
                
                cout << to_string((int)i) << " - " <<boxDrive.getStyleNameFromNumber((int)i) << endl;
                cout << "===============================================================" << endl << endl;
                fontsLoader.setStyleBox((int)i);
                //cout << to_string(i) << endl;
                fontsLoader.load("114", "Test");
                cout <<endl<<endl;
             
            }

            countParam = 2;
            
            param1 = "";
            param2 = "";
        }else {
            
            if (countParam == 0) {
                
                param1 = param;
                countParam = 1;
                //cout << "pase 1" << param1 << endl;
            } else if (countParam == 1) {
                
                if (param2 != "") param2 += " "+param;
                else param2 += param;     
              // cout << "pase 2" << param2 << endl;
                
            }
            
        }
        
    }


    fontsLoader.load(param1, param2);

    //cout << strResult << endl;
  
    return 0;
}


