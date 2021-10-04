#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "ctc.h"


//#include "config_inc.h"
#include "Debug_class.h"
#include "functions.h"
#include "functions_str.h"
#include "ConfigFont_class.h"
#include "convert_string.h"
#include "fonts.h"
#include "boxs.h"

#ifndef BOX_DRIVE_CLASS_H
#define BOX_DRIVE_CLASS_H
using namespace std;
class BoxDrive_class
{
public:
    //bool c_BoxDecorator = false;
    //string c_BoxDecoratorStyle = "Reactangle X";

    
    string c_lineBox = "";
    int c_part_head = 0;
    int c_part_c_head = 0;
    int c_part_content = 0;
    int c_part_c_Foot = 0;
    int c_part_foot = 0;

    string c_str_part_head = 0;
    string c_str_part_foot = 0;

    int c_part_counter = 0;

    string c_box_style;
    string c_box_head="";
    string c_box_foot="";
    bool c_BoxDecorator = true;
    string c_BoxDecoratorStyle = "Reactangle X";


    vector <vector<string>> c_box_body;

    int c_box_width=0;
    
 
    vector<vector<string>> getBodyElements();

    void setBoxDecorator(bool value);
    void setBoxStyle(string style);
    void setBoxWidth(int width);

    void printBorderBox(string boxStyle);

    string getOneLineBox(string boxStyle);

    vector<string> getPartsFromBox(string text);

    void getParts();

    string getHeadBox();
    string getFootBox();
    

    string addHeadBoxToText(string text);
    string addBoxToText(string text);
    

    
};
#endif;

