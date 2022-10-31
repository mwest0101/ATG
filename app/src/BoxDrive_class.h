#pragma once
#include <string>
#include <vector>
#include "boxs.h"
#include "ctc.h"

#ifndef BOX_DRIVE_CLASS_H
#define BOX_DRIVE_CLASS_H
using namespace std;

class BoxDrive_class
{
public:
    
    string c_lineBox ;
    int c_part_head ;
    int c_part_c_head ;
    int c_part_content;
    int c_part_c_Foot;
    int c_part_foot;
    int c_box_height;


    unsigned int countLines = 0;
    int countPass = 0;

    string c_str_part_head;
    string c_str_part_foot;
    //int c_part_counter_body;
    int c_part_counter_body_main;
    int c_part_counter_body_sub;
    int c_part_counter;

    string c_box_style;
    vector<string> c_box_head;
    vector<string> c_box_foot;
  

    vector<string> c_allNameBox;
    
    bool c_BoxDecorator;
    string c_BoxDecoratorStyle;

    vector <vector<string>> c_box_body;

    int c_box_width;
    //-----------functions----------------------
    BoxDrive_class();
    void resetVars();
    void setBoxs();
    vector<vector<string>> getBodyElements();
    void setBoxDecorator(bool value);
    bool getBoxDecorator();

    void setBoxStyle(string style);
    void setBoxWidth(int width);
    void setBoxHigh(int height);

    void printBorderBox(string boxStyle);
    string getOneLineBox(string boxStyle);
    vector<string> getPartsFromBox();
    void getParts();
    string addBorderBodyBox(string text);
   
    vector<string> getHeadBox();

    vector<string> getFootBox();

    bool addNumIfNotExisInArray(int num);
    void showListOfBox();
    string getStyleNameFromNumber(int number);
    vector<string> getAllNameBox();
};
#endif;