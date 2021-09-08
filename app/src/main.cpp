#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"
#include "FontManager_class.h"
#include "ConfigFont_class.h"
#include "Debug_class.h"
#include <io.h>
#include <fcntl.h>

using namespace std;





int main(int argc, char* argv[], char* envp[])
{
    string strResult;
    string param1="";
    string param2="";
    setlocale(LC_ALL, "en_US.UTF-8");
    FontManager_class fontsLoader;
   

    vector<string> params;
    for (int i = 1; i < argc; i++) {
        cout << " P (" << i << ")=" << argv[i] << endl;
        params.push_back(argv[i]);
        

    }
    int countParam = 0;
    for (string param : params) {
        //cout << "Param= " << param << endl;
        if (param == "-s") {
            
            fontsLoader.setSmush(true);
        } else if (param == "-l") {
            
            param1 = "listAllFontNames";
            countParam++;
        } else if (param == "-dn") {

            param1 = "listAllFontsExampleWithName";
            countParam++;
        } else if (param == "-dc") {

            param1 = "listAllFontsExampleWithCustom";
            countParam++;
        } else if (param == "-d") {

            param1 = "listAllFontsExampleWithDemo";
            countParam++;
        }else {
            if (countParam == 0) {
                param1 = param;
                countParam++;
            } else if (countParam >= 1 && param2 == "") {
                if (param2 != "") param2 += " "+param;
                else param2 += param;     
                countParam++;
            }
            
        }
        
    }
   

    //cout << "param1= " << param1 << endl;
   // cout << "param2= " << param2 << endl;
   // cout << param1 << endl;
   // cout << param2 << endl;

    strResult = fontsLoader.load(param1, param2);
    //_setmode(_fileno(stdout), _O_U8TEXT);
    
    cout << strResult << endl;
    

    //cout << convStrToUpper("prueba de texto _ para convertiRRRasdAA") << endl;

    return 0;
}


