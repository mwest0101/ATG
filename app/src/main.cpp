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
    FontManager_class fontsLoder;
    fontsLoder.load("Speed","Mauricio");       
    printStrVector(fontsLoder.getFullStringOfChars());
    
   /* fontsLoder.load("fonts\\3D-ASCII.flf","Cintia");    
    printStrVector(fontsLoder.getFullStringOfChars());
    */

    return 0;
}

