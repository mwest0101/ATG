#include "FontManager_class.h"

using namespace std;

const string HEAD_FILE = "flf2";

FontManager_class::FontManager_class()
{


}

string FontManager_class::load(string fontName,string stringToPrint) {
    string result = "";
    string conf = "";
    cout << "entre a load " << endl;
    cout << fontName << endl;
    if (fontName == "listAllFontNames") {

        showListOfFonts();
    }else if (fontName == "listAllFontsdemo") {

        showDemoOfAllFonts();
    }else if (fontName!="" && stringToPrint!=""){
        conf = showfonts(fontName, -1000, "conf");
        getConfig(conf);    

        generateVectorOfStrings(fontName, stringToPrint);
        generateStringResult();

        result = getStringResult();
    }

    
    return result;
}

vector<string> FontManager_class::getVectorfromOnechar(string data) {
    return splitStr(data, strTochar(ConfigFont_class::nl));
}

void FontManager_class::concatenateChar(vector<string> oneChar) {

    for (unsigned int i = 0; i < oneChar.size(); i++) {
        if (resultAsciiArtVector.size() < oneChar.size()) {
            resultAsciiArtVector.push_back(oneChar[i]);
        }
        else {
            resultAsciiArtVector[i] += oneChar[i];

        }


    }


}

void FontManager_class::generateVectorOfStrings(string fontName,string sourceString) {
    string strOfChar;
    for (unsigned int i = 0; i < sourceString.length(); i++) {
        string charToSeek(1, sourceString[i]);
        strOfChar=showfonts(fontName, -100, charToSeek);
        concatenateChar(getVectorfromOnechar(strOfChar));
    }
}


void FontManager_class::generateStringResult() {
    string strOfChar;
    resultAsciiArtString = "";
    for (string data : resultAsciiArtVector) {
        resultAsciiArtString += data + "\n";
    }
}

void FontManager_class::setSmush(bool value) {
    c_smush = value;
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


string FontManager_class::getStringResult() {
    resultAsciiArtString = reformatString(resultAsciiArtString);
    return resultAsciiArtString;
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
    
    
    if (aparam[1][1]!="")
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
bool FontManager_class::addNumIfNotExisInArray(int num) {
    static vector<int> vectorNumeros;
    if (find(vectorNumeros.begin(), vectorNumeros.end(), num) != vectorNumeros.end()) {
        return false;
    }else {
        vectorNumeros.push_back(num);
        return true;
    }
    

}
void FontManager_class::showListOfFonts() {

    string fontName = "allNameFonts";
    string result = showfonts("allNameFonts", -100, " ");
    vector<string> listOfChars;
    vector<string> onechar;
    string strToPrint;
    string oneStrToPrint;
    int sizeColNum = 3;
    int sizeColName = 15;
    int maxCountCols = 4;
    int countFont = 0;
    int countCols = 1;


    //cout << endl;
    listOfChars = splitStr(result, ';');
    
    oneStrToPrint = "";

    countCols = 0;
    int maxElements = (listOfChars.size()-1);
    int columElements = (int)( ( ((float)maxElements / (float)maxCountCols) ) );
    columElements = columElements+1;
    
    int element = 0;

    for (int i = 0; i < columElements; i++) {
        //cout << i << endl;
        for (int j = 0; j < maxCountCols; j++) {          

            element = (columElements * j) + i;
            
            if ((element < maxElements) && addNumIfNotExisInArray(element)) {
                onechar = splitStr(listOfChars[element], ':');

                oneStrToPrint += "[ " + compWithLeftSpaces(onechar[0], sizeColNum) + " : " + compWithRightSpaces(onechar[1], sizeColName) + " ] ";
            } 
            
        }

        cout << oneStrToPrint << endl;
        oneStrToPrint = "";

    }
    //cout << strToPrint << endl;

}


void FontManager_class::showDemoOfAllFonts() {

    string fontName = "allNameFonts";
    string result = showfonts(fontName, -100, " ");
    vector<string> listOfChars;
    vector<string> onechar;
    string strToPrint;
    string oneStrToPrint;
    int maxCountCols = 4;

    

   

    
    int element = 0;
    listOfChars = splitStr(result, ';');
    string conf = "";
    for (string font : listOfChars) {

        onechar = splitStr(font, ':');
        cout << onechar[1] << endl;
        /*
        conf = showfonts(onechar[1], -1000, "conf");
        getConfig(conf);*/

      
        generateVectorOfStrings(onechar[1], "Example");
        generateStringResult();
        result = getStringResult();
        cout << result << endl << endl;
        

    }
    //cout << strToPrint << endl;

}

void FontManager_class::setFonts() {
    vector<string> listOfChars;
    vector<string> onechar;

    string fontName = "allNameFonts";
    string result = showfonts(fontName, -100, " ");
 
    for (string font : listOfChars) {
        onechar = splitStr(font, ':');
        c_allNameFonts.push_back(onechar[1]);
    }
}