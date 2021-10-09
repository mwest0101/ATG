#include "BoxDrive_class.h"



BoxDrive_class::BoxDrive_class()
{


}

void BoxDrive_class::setBoxDecorator(bool value) {
    c_BoxDecorator = value;
}
bool BoxDrive_class::getBoxDecorator() {
    return c_BoxDecorator;
}

void BoxDrive_class::setBoxStyle(string style) {
    c_BoxDecoratorStyle = style;
}

void BoxDrive_class::setBoxWidth(int width) {
    c_box_width = width;
}
void BoxDrive_class::setBoxHigh(int height) {
    c_box_height = height;
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
       // cout << strResult << endl;
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
        strFill.push_back(strBox.substr(pos1 + 2, (pos2-(pos1 + 2)))); 
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
    size_t numSpaces = 0;


    strBoxTemp = getPartsFromBox(c_box_style);
    while (strBoxTemp[0] != "" || strBoxTemp[1] != "" || strBoxTemp[2] != "") {
        strTemp="";
            if ((strBoxTemp[1] != "c" && strBoxTemp[1] != "C") && partCounter <= 1) {

                strTemp += strBoxTemp[0];

                numSpaces = c_box_width;
                //cout << numSpaces << endl;
                for (unsigned int i = 0; i < numSpaces; i++) {
                    strTemp += strBoxTemp[1];
                   // cout << i << endl;
                }

                strTemp += strBoxTemp[2];

                c_box_head.push_back(strTemp);;

                c_part_head++;

                c_part_counter++;
                partCounter = 1;
                

            }else if  ((strBoxTemp[1] == "c" || strBoxTemp[1] == "C") && partCounter <= 2) {
                
                c_box_body.push_back(strBoxTemp);
                
                if (strBoxTemp[1] == "c") {
                    c_part_counter_body_sub++;
                }else {
                    c_part_counter_body_main++;
                }

                c_part_counter++;
                partCounter = 2;

            }else if ((strBoxTemp[1] != "c" && strBoxTemp[1] != "C") && partCounter >= 2) {

                strTemp += strBoxTemp[0];
 
                numSpaces = c_box_width;
                for (unsigned int i = 0; i < numSpaces; i++) {
                    strTemp += strBoxTemp[1];
                    //c_str_part_foot += "/";
                }

                strTemp += strBoxTemp[2];
                c_box_foot.push_back(strTemp);

                c_part_foot++;                
                c_part_counter++;
                partCounter = 3;
            }

            strBoxTemp = getPartsFromBox(c_box_style);
        

    }

}

string BoxDrive_class::addBorderBodyBox(string text) {
    static unsigned int countLines = 0;
    static int countPass = 0;
    vector<string> tempStr;
    string strReturn = "";
    size_t numSpaces = 0;
    int countBodyMain = c_box_height - c_part_counter_body_sub; // 8
    int countBodySub= c_part_counter_body_sub; //2

    if (countLines <= c_box_body.size()) {

        tempStr = c_box_body[countLines];
        numSpaces = c_box_width - (strLenght(tempStr[0]) + strLenght(tempStr[2]));
        numSpaces = c_box_width;
        if (tempStr[1] == "c") {
            strReturn = tempStr[0] + compWithCenterSpaces(text, numSpaces) + tempStr[2];
            countLines++;
        }

        if (tempStr[1] == "C") {
            strReturn = tempStr[0] + compWithCenterSpaces(text, numSpaces) + tempStr[2];
            countPass++;                    
            if (countPass < c_part_counter_body_main) countLines++;
        }

        if (countPass==countBodyMain){
            countLines++;
        }
 
    }
    return strReturn;
}

vector<string> BoxDrive_class::getHeadBox() {
    return c_box_head;
}

vector<string> BoxDrive_class::getFootBox() {
    return c_box_foot;
}

vector<vector<string>> BoxDrive_class::getBodyElements() {
    return c_box_body;
}


