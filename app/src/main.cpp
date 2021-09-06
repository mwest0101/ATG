#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
#include "FontManager_class.h"
#include "ConfigFont_class.h"
#include "Debug_class.h"



using namespace std;





int main(int argc, char* argv[], char* envp[])
{
    string strResult;
    string param1;
    string param2;

    FontManager_class fontsLoader;
    fontsLoader.setFonts();

    vector<string> params;
    for (int i = 0; i < argc; i++) {
        cout << " P" << i << "=" << argv[i];
        params.push_back(argv[i]);
        

    }
    int countParam = 0;
    for (string param : params) {

        if (param == "-s") {
            
            fontsLoader.setSmush(true);
        } else if (param == "-l") {
            
            param1 = "listAllFontNames";
        } else if (param == "-d") {

            param1 = "listAllFontsdemo";
        }else {
            if (countParam == 1) {
                param1 = param;
            } else if (countParam >= 2) {
                if (param2 != "") param2 += " "+param;
                else param2 += param;                                
            }
        }
        countParam++;
    }
   


   // cout << param1 << endl;
   // cout << param2 << endl;

    strResult = fontsLoader.load(param1, param2);
    cout << strResult << endl;

    return 0;
}


