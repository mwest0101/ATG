#include <string>
#include <vector>


#ifndef CONFIG_FONT_CLASS_H
#define CONFIG_FONT_CLASS_H
using namespace std;

class ConfigFont_class
{

public:
    static string nl;
    static int found;
    static string p1;
    static string p2;
    static int p3_Height;
    static int p4_Height_nd;
    static int p5_maxLinLen;
    static int p6_defSmuMod;
    static int p7_numComm;
    //static string charOrder[];
    static vector<string> charOrder[];
    
};
#endif