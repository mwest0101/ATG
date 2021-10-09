#include "FontManager_class.h"

using namespace std;

const string HEAD_FILE = "flf2";

FontManager_class::FontManager_class()
{


}

void FontManager_class::setSmush(bool value) {
    c_smush = value;
}
void FontManager_class::setRainbowColor(int numLine) {
    static int color = 0;
    static int count = 0;
    if (numLine != 0) {
        count++;
        color = (int)((float)(15.0f / (float)numLine) * (float)count);
        if (count >= numLine) count = 0;
    }
    else {
        color++;
        if (color >= 15)  color = 1;
    }

    SetColor(0, color);


}

string FontManager_class::getStrRainbowColor(int numLine) {
    static int color = 0;
    static int count = 0;
    int col1 = 0;
    int col2 = 0;
    string strReturn = "";

    if (numLine != 0) {
        count++;
        color = (int)((float)(15.0f / (float)numLine) * (float)count);
        if (count >= numLine) count = 0;
    }
    else {
        color++;
        if (color >= 15)  color = 1;
    }
    col1 = 0;
    col2 = color;
    strReturn = "[(" + to_string(col1) + "," + to_string(col2) + ")]";

    

    return strReturn;
}





void FontManager_class::setRainbowTotalColors(bool value) {
    c_vRainbowTotalColors = value;
}
void FontManager_class::setDemoColor(bool value) {
    c_vDemoColor = value;
}
void FontManager_class::setVerticalRainbow(bool value) {
    c_vRainbow = value;
}

void FontManager_class::setHorizontRainbow(bool value) {
    c_hRainbow = value;
}



void FontManager_class::setFonts() {
    vector<string> listOfChars;
    vector<string> onechar;

    string fontName = "allNameFonts";
    string result = showfonts(fontName, -100, " ");
    listOfChars = splitStr(result, ';');

    for (string font : listOfChars) {
        if (font.size() > 0) {
            onechar = splitStr(font, ':');
            c_allNameFonts.push_back(onechar[1]);
        }

    }
}



void FontManager_class::getConfig(string data)
{
    vector<string> paramsArray = splitStr(data, ',');
    vector<vector<string>> aparam;
    for (string data : paramsArray) {
        aparam.push_back(splitStr(data, '='));
    }
    /*
    cout << aparam[0][0] << endl;
    cout << aparam[0][1] << endl;*/


    if (aparam[1][1] != "")
    {
        ConfigFont_class::nl = aparam[0][1];
        ConfigFont_class::found = stoi(aparam[1][1]);
        ConfigFont_class::p1 = aparam[2][1];
        ConfigFont_class::p2 = aparam[3][1];
        ConfigFont_class::p3_Height = stoi(aparam[4][1]);
        ConfigFont_class::p4_Height_nd = stoi(aparam[5][1]);
        ConfigFont_class::p5_maxLinLen = stoi(aparam[6][1]);
        ConfigFont_class::p6_defSmuMod = stoi(aparam[7][1]);
        ConfigFont_class::p7_numComm = stoi(aparam[8][1]);

    }


}
string FontManager_class::getFontNameByNum(int num) {

    if (num > 0 && ((unsigned)num < c_allNameFonts.size())) {
        return c_allNameFonts[num];
    }
    else {
        return "";
    }

}
string  FontManager_class::getFontName(string font) {
    int count = 0;
    string fontName = "";

    for (string name : c_allNameFonts) {
        if (convStrToUpper(font) == convStrToUpper(name)) {
            return name;
        }
        else if (font == intToStr(count)) {
            return name;
        }
        count++;
    }

    return fontName;
}
string FontManager_class::getStringResult() {
    c_resultAsciiArtString = reformatString(c_resultAsciiArtString);
    return c_resultAsciiArtString;
}
vector<string> FontManager_class::getVectorfromOnechar(string data) {
    return splitStr(data, strTochar(ConfigFont_class::nl));
}


string FontManager_class::load(string fontName, string stringToPrint) {
    string result = "";

    //cout << "entre a load " << endl;

    setFonts();

    //cout << fontName << endl;
    if (fontName == "listAllFontNames") {

        showListOfFonts();
        SetColor(0, 7);

    }
    else if (fontName == "listAllFontsExampleWithName" ||
        fontName == "listAllFontsExampleWithCustom" ||
        fontName == "listAllFontsExampleWithDemo") {

        // SetColor(0, 2);
        showDemoOfAllFonts(fontName, stringToPrint);
        // SetColor(0, 7);
    }
    else if (fontName != "" && stringToPrint != "") {

        //   cout << "Interpretar fuente " << fontName << endl;

        result = mainGeneratorOfStr(fontName, stringToPrint);
    }

    SetColor(0, 7);
    return result;
}
void FontManager_class::showListOfFonts() {

    vector<string> listOfChars;
    string onechar;
    string strToPrint;
    string oneStrToPrint;
    int sizeColNum = 3;
    int sizeColName = 15;
    int maxCountCols = 4;
    int countFont = 0;
    int countCols = 1;

    oneStrToPrint = "";

    countCols = 0;
    int maxElements = (c_allNameFonts.size() - 1);
    int columElements = (int)((((float)maxElements / (float)maxCountCols)));
    columElements = columElements + 1;

    int element = 0;

    for (int i = 0; i < columElements; i++) {
        //  cout << i << endl;
        for (int j = 0; j < maxCountCols; j++) {

            element = (columElements * j) + i;

            if ((element <= maxElements) && addNumIfNotExisInArray(element)) {
                onechar = c_allNameFonts[element];
                SetColor(0, 15);
                cout << "[ ";
                SetColor(0, 6);
                cout << compWithLeftSpaces(to_string(element), sizeColNum);
                SetColor(0, 4);
                cout << " : ";
                SetColor(0, 2);
                cout << compWithRightSpaces(onechar, sizeColName);
                SetColor(0, 15);
                cout << " ] ";
            }

        }

        cout << endl;
        oneStrToPrint = "";

    }

}

void FontManager_class::concatenateChar(vector<string> oneChar) {

    for (unsigned int i = 0; i < oneChar.size(); i++) {

        if (c_resultAsciiArtVector.size() < oneChar.size()) {
            c_resultAsciiArtVector.push_back(applyHorizontalRainbow(oneChar[i]));
        }
        else {
            c_resultAsciiArtVector[i] += applyHorizontalRainbow(oneChar[i]);

        }


    }
    c_hColor++;


}
string FontManager_class::applyHorizontalRainbow(string data) {
    int bcolor = 0;


    if (c_hRainbow) {
        data = "[(" + to_string(bcolor) + "," + to_string(c_hColor) + ")]" + data;

    }

    if (c_hColor == 15) { c_hColor = 1; }
    return data;
}

// TO DO: Pasar despues a archivo aparte

void FontManager_class::printStringWithColorsCode(string data) {
    int pos1 = 0;
    int pos2 = 0;
    bool found = true;
    vector<string> colors;
    while (found) {
        if ((pos1 = findStr(data, "[(")) != (-1)) {
            if ((pos2 = findStr(data, ")]")) != (-1)) {
                
                cout << data.substr(0, pos1);
                
                colors = splitStr(data.substr(pos1 + 2, pos2), ',');

                SetColor(strToInt(colors[0]), strToInt(colors[1]));

                data = data.substr(pos2 + 2, data.size());

                found = true;
            }

        }
        else {
            //cout << data;
            cout << data << endl;
            found = false;
        }
    }

}

void FontManager_class::cleanArrayAndString() {
    c_resultAsciiArtVector.clear();
    c_resultAsciiArtString = "";

}
void FontManager_class::generateVectorOfStrings(string fontName, string sourceString) {
    string strOfChar;
    for (unsigned int i = 0; i < sourceString.length(); i++) {
        string charToSeek(1, sourceString[i]);
        strOfChar = showfonts(fontName, -100, charToSeek);
        concatenateChar(getVectorfromOnechar(strOfChar));
    }
}
int FontManager_class::getMaxWidthLine() {
    string strOfChar;
    unsigned int max = 0;
    for (string data : c_resultAsciiArtVector) {
        if (data.size() > max) {
            max = data.size();
        }
    
    }
    //cout << " - > "<< max << endl;
    return max;
}


void FontManager_class::genStringAndResult() {
    string strOfChar;
    c_resultAsciiArtString = "";

    for (string data : c_resultAsciiArtVector) {
        c_resultAsciiArtString += data + "\n";
    }

}

void FontManager_class::printString() {
    if (c_hRainbow || c_vRainbow) {
        printStringWithColorsCode(c_resultAsciiArtString);
        cout << endl;
    }
    else {
        cout << c_resultAsciiArtString << endl;
    }
}


void FontManager_class::InsertTextInBox() {
    vector<string> tempVector;
    BoxDrive_class boxDrive;

    boxDrive.setBoxDecorator(true);
    boxDrive.setBoxWidth(getMaxWidthLine());
    boxDrive.setBoxHigh(c_resultAsciiArtVector.size());
    boxDrive.setBoxStyle("Reactangle Double Line");
    boxDrive.getParts();

    for (string data : boxDrive.getHeadBox()) {
        tempVector.push_back(data);
    }

    for (string data : c_resultAsciiArtVector) {
        tempVector.push_back(boxDrive.addBorderBodyBox(data));
    }

    for (string data : boxDrive.getFootBox()) {
        tempVector.push_back(data);
    }

    c_resultAsciiArtVector = tempVector;

}


void FontManager_class::applyParameters() {

    string strOfChar;
    c_resultAsciiArtString = "";
    string fontSmush = ConfigFont_class::p2;
    string strLine = "";

    int lengVec = c_resultAsciiArtVector.size();
    int maxWidth = getMaxWidthLine();

    vector<string> tempVector;    
    for (string data : c_resultAsciiArtVector) {
        
        strLine = "";
        if (c_vRainbow) {
            if (c_vRainbowTotalColors) {
                //setRainbowColor(lengVec);

                strLine += getStrRainbowColor(lengVec);
            }
            else {
                //setRainbowColor(0);
                strLine += getStrRainbowColor(0);
            }
        }

        if (!c_smush) {
            strLine += strReplace(data, fontSmush, " ");
        }
        else {
            strLine += strReplace(data, fontSmush, "");
        }


        tempVector.push_back(strLine);
    }

    c_resultAsciiArtVector = tempVector;
}

string FontManager_class::mainGeneratorOfStr(string fontName, string stringToPrint) {
    string conf = "";
    fontName = getFontName(fontName);

    conf = showfonts(fontName, -1000, "conf");
    getConfig(conf);
    cleanArrayAndString();
    generateVectorOfStrings(fontName, stringToPrint);
    applyParameters();
    InsertTextInBox();
    genStringAndResult();
    printString();

    return "";
}
string FontManager_class::reformatString(string data) {
    string fontSmush = ConfigFont_class::p2;
    if (fontSmush != "") {
        if (!c_smush) {
            data = strReplace(data, fontSmush, " ");
            //cout << "pase 1 " << endl;
        }
        else {
            data = strReplace(data, fontSmush, "");
            //cout << "pase 2 " << endl;
        }
    }
    return data;
}

bool FontManager_class::addNumIfNotExisInArray(int num) {
    static vector<int> vectorNumeros;
    if (find(vectorNumeros.begin(), vectorNumeros.end(), num) != vectorNumeros.end()) {
        return false;
    }
    else {
        vectorNumeros.push_back(num);
        return true;
    }


}
void FontManager_class::showDemoOfAllFonts(string style, string testString) {


    string result = showfonts("allNameFonts", -100, " ");
    vector<string> listOfChars;
    vector<string> onechar;
    string strToPrint;
    string oneStrToPrint;
    int maxCountCols = 4;


    int element = 0;
    listOfChars = splitStr(result, ';');
    string conf = "";
    char tecla;
    int contFont = 0;
    int color = 1;

    for (string font : listOfChars) {
        if (c_vDemoColor) {
            SetColor(0, color);
            color++;
        }
        onechar = splitStr(font, ':');
        cout << "----------------------------------------------------" << endl;
        cout << "[ " + to_string(contFont) + " ] " + onechar[1] << endl;
        cout << "----------------------------------------------------" << endl;

        if (style == "listAllFontsExampleWithName") {

            result = mainGeneratorOfStr(onechar[1], onechar[1]);

        }
        else if (style == "listAllFontsExampleWithCustom") {

            result = mainGeneratorOfStr(onechar[1], testString);

        }
        else {
            result = mainGeneratorOfStr(onechar[1], "Demo");
        }
        cout << result << endl << endl;
        cout << "Press any key to continue..." << endl;
        tecla = getchar();
        putchar(tecla);
        if (tecla == 'q' || tecla == 'Q') { return; }
        contFont++;
        if (color == 15) { color = 1; }
    }


}



