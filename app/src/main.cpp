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

    FontManager_class fontsLoder;
    
    for (int i = 0; i < argc; i++) {
        cout << " P" << i << "=" << argv[i];
        string param = argv[i];

        if (param == "-s") {
            fontsLoder.setSmush(true);
        }       
    }
    cout << endl;
    cout << "llegue aca " << endl;
    if (argc > 0) {
        
        param1=argv[1];        
        cout << "llegue aca 2 " << param1 << endl;
     
    }
    else { param1 = "NULL";}
    if (argc > 1) {
        
        param2 = argv[2];
        cout << "llegue aca 3 " << param2 << endl;
     
    }
    else { param2 = "NULL"; }

    cout << param1 << endl;
    cout << param2 << endl;

    strResult = fontsLoder.load(param1, param2);
    cout << strResult << endl;

    return 0;
}


