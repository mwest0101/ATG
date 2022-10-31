#include "BoxDrive_class.h"



BoxDrive_class::BoxDrive_class(){
    resetVars();
    setBoxs();

}
void BoxDrive_class::resetVars() {
    unsigned int countLines = 0;
    int countPass = 0;
}

void BoxDrive_class::setBoxs() {
    vector<string> listOfChars;
    vector<string> onechar;

    string fontName = "allRectangles";
    string result = showRectangle(fontName, -100, " ");
    listOfChars = splitStr(result, ';');

    for (string font : listOfChars) {
        if (font.size() > 0) {
            onechar = splitStr(font, ':');
            c_allNameBox.push_back(onechar[1]);
            //cout << onechar[1] << endl;
        }

    }
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

vector<string> BoxDrive_class::getPartsFromBox() {
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


    strBoxTemp = getPartsFromBox();
    while (strBoxTemp[0] != "" || strBoxTemp[1] != "" || strBoxTemp[2] != "") {
        strTemp="";
            if ((strBoxTemp[1] != "c" && strBoxTemp[1] != "C") && partCounter <= 1) {

                strTemp += strBoxTemp[0];

                numSpaces = c_box_width-1;
                //cout << "head--->"<<numSpaces << endl;
                for (int i = 0; i < numSpaces; i++) {
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
 
                numSpaces = c_box_width-1;
                //cout << "foot--->" << numSpaces << endl;
                for ( int i = 0; i < numSpaces; i++) {
                    strTemp += strBoxTemp[1];
                    //c_str_part_foot += "/";
                }

                strTemp += strBoxTemp[2];
                c_box_foot.push_back(strTemp);

                c_part_foot++;                
                c_part_counter++;
                partCounter = 3;
            }

            strBoxTemp = getPartsFromBox();
        

    }

}

string BoxDrive_class::addBorderBodyBox(string text) {

    vector<string> tempStr;
    string strReturn = "";
    size_t numSpaces = 0;
    int countBodyMain = c_box_height - c_part_counter_body_sub; // 8
    int countBodySub= c_part_counter_body_sub; //2  

    //cout << to_string(countLines) << endl;
    //cout << to_string(countPass) << endl;
    
    //cout << "--> body size --> "<< to_string(c_box_body.size()) << endl;
    //cout << "c_part_counter_body_sub " << to_string(c_part_counter_body_sub) << endl;
    //cout << "c_part_counter_body_main " << to_string(c_part_counter_body_main) << endl;
    
    if (countLines < c_box_body.size()) {

        tempStr = c_box_body[countLines];
        //cout << " countLines -> " << countLines << endl;
        //numSpaces = c_box_width - (strLenght(tempStr[0]) + strLenght(tempStr[2]));
        numSpaces = c_box_width;
        //cout << "----->" << numSpaces << " < -----" << endl;
        if (tempStr[1] == "c") {
            //strReturn = tempStr[0] + compWithCenterSpaces(text, numSpaces) + tempStr[2];
            strReturn = tempStr[0] + text + tempStr[2];
            countLines++;
        }

        if (tempStr[1] == "C") {
            //strReturn = tempStr[0] + compWithCenterSpaces(text, numSpaces) + tempStr[2];
            strReturn = tempStr[0] + text + tempStr[2];
            countPass++;   
           // cout << " countPass -> " << countPass << endl;
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

bool BoxDrive_class::addNumIfNotExisInArray(int num) {
    static vector<int> vectorNumeros;
    if (find(vectorNumeros.begin(), vectorNumeros.end(), num) != vectorNumeros.end()) {
        return false;
    }
    else {
        vectorNumeros.push_back(num);
        return true;
    }


}


void BoxDrive_class::showListOfBox() {

    vector<string> listOfChars;
    string onechar;
    string strToPrint;
    string oneStrToPrint;
    int sizeColNum = 3;
    int sizeColName = 35;
    int maxCountCols = 2;
    int countFont = 0;
    int countCols = 1;

    oneStrToPrint = "";

    countCols = 0;
    int maxElements = ((int)c_allNameBox.size() - 1);
    int columElements = (int)((((float)maxElements / (float)maxCountCols)));
    columElements = columElements + 1;

    int element = 0;

    for (int i = 0; i < columElements; i++) {
         //cout << i << endl;
        for (int j = 0; j < maxCountCols; j++) {

            element = (columElements * j) + i;

            if ((element <= maxElements) && addNumIfNotExisInArray(element)) {
                onechar = c_allNameBox[element];
                SetColor(0, 15);
                cout << "[ ";
                SetColor(0, 9);
                cout << compWithLeftSpaces(to_string(element), sizeColNum);
                SetColor(0, 4);
                cout << " : ";
                SetColor(0, 11);
                cout << compWithRightSpaces(onechar, sizeColName);
                SetColor(0, 15);
                cout << " ] ";
            }

        }

        cout << endl;
        oneStrToPrint = "";

    }

}

vector<string> BoxDrive_class::getAllNameBox() {
    return c_allNameBox;
}


/*
void BoxDrive_class::showListOfBox() {

    vector<string> listOfChars;
    string onechar;
    string strToPrint;
    string oneStrToPrint;
    int sizeColNum = 3;
    int sizeColName = 35;
    int maxCountCols = 2;
    int countFont = 0;
    int countCols = 1;

    oneStrToPrint = "";

    countCols = 0;
    int maxElements = (c_allNameBox.size() - 1);
    int columElements = (int)((((float)maxElements / (float)maxCountCols)));
    columElements = columElements + 1;

    int element = 0;


    for (string strBox : c_allNameBox) {

    }

    for (int i = 0; i < columElements; i++) {
        //cout << i << endl;
        for (int j = 0; j < maxCountCols; j++) {

            element = (columElements * j) + i;

            if ((element <= maxElements) && addNumIfNotExisInArray(element)) {
                onechar = c_allNameBox[element];
                SetColor(0, 15);
                cout << "[ ";
                SetColor(0, 9);
                cout << compWithLeftSpaces(to_string(element), sizeColNum);
                SetColor(0, 4);
                cout << " : ";
                SetColor(0, 11);
                cout << compWithRightSpaces(onechar, sizeColName);
                SetColor(0, 15);
                cout << " ] ";
            }

        }

        cout << endl;
        oneStrToPrint = "";

    }

}
*/
string BoxDrive_class::getStyleNameFromNumber(int num){
    if (num > 0 && ((unsigned)num < c_allNameBox.size())) {
        return c_allNameBox[num];
    }
    else {
        return "";
    }

}


