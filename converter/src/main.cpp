#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "functions.h"
#include "functions_str.h"
#include "FontManager_class.h"
#include "ConfigFont_class.h"
#include "Debug_class.h"


using namespace std;





int main(int argc, char* argv[], char* envp[])
{
    
    vector<string> vecOfAllChars;
    vector<string> vecOfAChar;
    string strResult;
    Debug_class::log("Inicio de la conversion");
    if (argc > 1) {
        FontManager_class fontsLoder;
        //fontsLoder.load("fonts\\Speed.flf");
        
        strResult=fontsLoder.load(argv[1]);
        writeFile(argv[2],strResult);
        //printStrVector(fontsLoder.getFullStringOfChars());
    } 
    return 0;
}


