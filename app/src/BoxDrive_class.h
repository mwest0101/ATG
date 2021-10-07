#pragma once
#include <string>
#include <vector>
#include "boxs.h"

#ifndef BOX_DRIVE_CLASS_H
#define BOX_DRIVE_CLASS_H
using namespace std;

class BoxDrive_class
{
public:
    //bool c_BoxDecorator = false;
    //string c_BoxDecoratorStyle = "Reactangle X";

    
    string c_lineBox ;
    int c_part_head ;
    int c_part_c_head ;
    int c_part_content;
    int c_part_c_Foot;
    int c_part_foot;
    int c_box_height;

    string c_str_part_head;
    string c_str_part_foot;
    //int c_part_counter_body;
    int c_part_counter_body_main;
    int c_part_counter_body_sub;
    int c_part_counter;

    string c_box_style;
    string c_box_head;
    string c_box_foot;
    
    bool c_BoxDecorator;
    string c_BoxDecoratorStyle;

    vector <vector<string>> c_box_body;

    int c_box_width;
    //-----------functions----------------------
    BoxDrive_class();

    
    vector<vector<string>> getBodyElements();
    void setBoxDecorator(bool value);
    void setBoxStyle(string style);
    void setBoxWidth(int width);
    void setBoxHigh(int height);

    void printBorderBox(string boxStyle);
    string getOneLineBox(string boxStyle);
    vector<string> getPartsFromBox(string text);
    void getParts();
    string addBorderBodyBox(string text);
    string getHeadBox();
    string getFootBox();

    
};
#endif;

