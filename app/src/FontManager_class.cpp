#include "FontManager_class.h"

using namespace std;

const string HEAD_FILE = "flf2";

FontManager_class::FontManager_class()
{


}

string FontManager_class::load(string fontName,string stringToPrint) {
    string result = "";
   
    //cout << "entre a load " << endl;
    
    setFonts();
    
    cout << fontName << endl;
    if (fontName == "listAllFontNames") {
                     
        showListOfFonts();
    }else if (fontName == "listAllFontsExampleWithName" ||
              fontName == "listAllFontsExampleWithCustom" ||
              fontName == "listAllFontsExampleWithDemo") {
    

        showDemoOfAllFonts(fontName, stringToPrint);
    }else if (fontName!="" && stringToPrint!=""){
       
        cout << "Interpretar fuente " << fontName << endl;

        result = mainGeneratorOfStr(fontName, stringToPrint);
    }

    
    return result;
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
        /*
        if (onechar[1] != "") {
            
        }*/
    }
}

string  FontManager_class::getFontName(string font) {
    int count = 0;
    string fontName = "";

    for (string name : c_allNameFonts) {
        if (convStrToUpper(font) == convStrToUpper(name)) {
            return name;
        }
        else if(font== intToStr(count)){
            return name;
        }
        count++;
    }

    return fontName;
}


string FontManager_class::getFontNameByNum(int num) {

    if (num>0 && ((unsigned)num < c_allNameFonts.size())){
       return c_allNameFonts[num];
    }
    else {
        return "";
    }
        
}
vector<string> FontManager_class::getVectorfromOnechar(string data) {
    return splitStr(data, strTochar(ConfigFont_class::nl));
}

void FontManager_class::concatenateChar(vector<string> oneChar) {

    for (unsigned int i = 0; i < oneChar.size(); i++) {
        if (c_resultAsciiArtVector.size() < oneChar.size()) {
            c_resultAsciiArtVector.push_back(oneChar[i]);
        } else {
            c_resultAsciiArtVector[i] += oneChar[i];

        }


    }


}
void FontManager_class::cleanArrayAndString() {
    c_resultAsciiArtVector.clear();
    c_resultAsciiArtString = "";

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
    c_resultAsciiArtString = "";
    for (string data : c_resultAsciiArtVector) {
        c_resultAsciiArtString += data + "\n";
    }
}

string FontManager_class::mainGeneratorOfStr(string fontName, string stringToPrint) {
    string conf = "";
    fontName = getFontName(fontName);

    conf = showfonts(fontName, -1000, "conf");
    getConfig(conf);
    cleanArrayAndString();
    generateVectorOfStrings(fontName, stringToPrint);
    generateStringResult();

    return getStringResult();
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
    c_resultAsciiArtString = reformatString(c_resultAsciiArtString);
    return c_resultAsciiArtString;
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

    //string fontName = "allNameFonts";
   // string result = showfonts("allNameFonts", -100, " ");
    vector<string> listOfChars;
    string onechar;
    string strToPrint;
    string oneStrToPrint;
    int sizeColNum = 3;
    int sizeColName = 15;
    int maxCountCols = 4;
    int countFont = 0;
    int countCols = 1;

    //cout << "entre a listoffount" << endl;
    //cout << endl;
    //listOfChars = splitStr(result, ';');
    
    oneStrToPrint = "";

    countCols = 0;
    int maxElements = (c_allNameFonts.size()-1);
    int columElements = (int)( ( ((float)maxElements / (float)maxCountCols) ) );
    columElements = columElements+1;
    
    int element = 0;

    for (int i = 0; i < columElements; i++) {
      //  cout << i << endl;
        for (int j = 0; j < maxCountCols; j++) {          

            element = (columElements * j) + i;
            
            if ((element < maxElements) && addNumIfNotExisInArray(element)) {
                onechar = c_allNameFonts[element];

                oneStrToPrint += "[ " + compWithLeftSpaces(to_string(element), sizeColNum) + " : " + compWithRightSpaces(onechar, sizeColName) + " ] ";
            } 
            
        }

        cout << oneStrToPrint << endl;
        oneStrToPrint = "";

    }
    //cout << strToPrint << endl;

}


void FontManager_class::showDemoOfAllFonts(string style,string testString) {

    
    string result = showfonts("allNameFonts", -100, " ");
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


        if (style == "listAllFontsExampleWithName") {

            result = mainGeneratorOfStr(onechar[1], onechar[1]);

        }else if (style == "listAllFontsExampleWithCustom") {

            result = mainGeneratorOfStr(onechar[1], testString);

        } else {
           result = mainGeneratorOfStr(onechar[1], "Demo");
        }
        cout << result << endl << endl;
        

    }
    //cout << strToPrint << endl;

}

