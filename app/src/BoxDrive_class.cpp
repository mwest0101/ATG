#include "BoxDrive_class.h"




void BoxDrive_class::setBoxDecorator(bool value) {
    c_BoxDecorator = value;
}

void BoxDrive_class::setBoxStyle(string style) {
    c_BoxDecoratorStyle = style;
}

void BoxDrive_class::setBoxWidth(int width) {
    c_box_width = width;
}

void BoxDrive_class::printBorderBox(string boxStyle) {
    string strResult = " ";
    string strSectionOfBox = " ";
    int contLine = 1;

    while ((strResult = showRectangle(boxStyle, contLine, "")) != "") {

        cout << strResult << endl;
        contLine++;
    }
}

string BoxDrive_class::getOneLineBox(string boxStyle) {
    string strResult = "";
    string strSectionOfBox = " ";
    static int contLine = 1;

    if ((strResult = showRectangle(boxStyle, contLine, "")) != "") {
        c_lineBox = strResult;
        cout << strResult << endl;
        contLine++;
    }
    else {
        contLine = 1;
    }
    return strResult;
}

vector<string> BoxDrive_class::getPartsFromBox(string text) {
    vector<string> strFill;
    int pos1, pos2;
    string strBox = "";

    if (((strBox = getOneLineBox(c_BoxDecoratorStyle)) != "") &&
       ((pos1 = findStr(strBox, "[(")) != (-1)) &&
       ((pos2 = findStr(strBox, ")]")) != (-1))) {
        strFill.push_back(strBox.substr(0, pos1));
        strFill.push_back(strBox.substr(pos1 + 2, pos2));
        strFill.push_back(strBox.substr(pos2 + 2, strBox.size()));
    }
    else {
        strFill.push_back("");
        strFill.push_back("");
        strFill.push_back("");

    }
    return strFill;

}

void  BoxDrive_class::getParts() {
    vector<string>strBoxTemp;
    vector<string>strBox;

    
    int partCounter = 0;
    int partHead = 0;
    int partcHead = 0;
    int partContent = 0;
    int partcFoot = 0;
    int partFoot = 0;


    bool execWhile = true;
    string strTemp;
    string strReturn;

    strBoxTemp = getPartsFromBox(c_box_style);
    while (strBoxTemp[0] != "" || strBoxTemp[1] != "" || strBoxTemp[2] != "") {

            if ((strBoxTemp[1] != "c" && strBoxTemp[1] != "C") && partCounter <= 1) {
                c_str_part_head += strBoxTemp[0];                
                for (int i = 0; i < c_box_width; i++) {
                    c_str_part_head += strBoxTemp[1];
                }

                c_str_part_head += strBoxTemp[2]+"\n";
                c_part_head++;
                partCounter = 1;

            }else if  ((strBoxTemp[1] == "c" || strBoxTemp[1] == "C") && partCounter <= 2) {
                
                c_box_body.push_back(strBoxTemp);
                partContent++;
                partCounter = 2;

            }else if ((strBoxTemp[1] != "c" && strBoxTemp[1] != "C") && partCounter >= 2) {

                c_str_part_foot += strBoxTemp[0];
                for (int i = 0; i < c_box_width; i++) {
                    c_str_part_foot += strBoxTemp[1];
                }
                c_str_part_foot += strBoxTemp[2] + "\n";
                c_part_foot++;                
                partContent++;
                partCounter = 3;
            }

            strBoxTemp = getPartsFromBox(c_box_style);
        

    }
}

string BoxDrive_class::getHeadBox() {
    return c_str_part_head;
}

string BoxDrive_class::getFootBox() {
    return c_str_part_foot;
}

vector<vector<string>> BoxDrive_class::getBodyElements() {
    return c_box_body;
}


string  BoxDrive_class::addHeadBoxToText(string text) {
    string strFill = "";
    string resulStr = "";
    int numSpaces = 100;
    int sizeBox = 40;
    vector<string> strBox;
    strBox = getPartsFromBox(text);

    while (strBox[1] != "c" || strBox[1] != "C") {
        resulStr += strBox[0];
        for (int i = 0; i < sizeBox; i++) {
            resulStr += strFill;
        }
        resulStr += strBox[2];
    }

    return resulStr;
}


string  BoxDrive_class::addBoxToText(string text) {

    string strOfChar;


    string strFill = "";
    string resulStr = "";
    int numSpaces = 100;
    int sizeBox = 40;
    vector<string> strBox;
    strBox = getPartsFromBox(text);


    while (strBox[1] != "c" || strBox[1] != "C") {
        resulStr += strBox[0];
        for (int i = 0; i < sizeBox; i++) {
            resulStr += strFill;
        }
        resulStr += strBox[2];
    }

    if (c_BoxDecorator) {
        strBox = getPartsFromBox(text);
        if (strBox[1] != "c" && strBox[1] != "C") {
            resulStr += strBox[0];
            resulStr += compWithCenterSpaces(text, numSpaces);
            resulStr += strBox[2];
        }
        else {
            resulStr += strBox[0];
            for (int i = 0; i < sizeBox; i++) {
                resulStr += strFill;
            }
            resulStr += strBox[2];
        }


        //(findStr(strBox, "[(") != (-1))) {

    }
    return resulStr;
}