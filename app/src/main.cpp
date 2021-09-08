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
    for (int i = 0; i < argc; i++) {
        cout << " P" << i << "=" << argv[i];
        params.push_back(argv[i]);
        

    }
    int countParam = 0;
    for (string param : params) {
        //cout << "Param= " << param << endl;
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
            countParam++;
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


