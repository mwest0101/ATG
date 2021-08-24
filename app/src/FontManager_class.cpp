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
    if (fontName == "names") {
        fontName = "allNameFonts";
        result = showfonts(fontName, -100, stringToPrint);
    }else if (fontName!="" && stringToPrint!=""){
        conf = showfonts(fontName, -100, "conf");        
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