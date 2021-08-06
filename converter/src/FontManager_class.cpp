#include "FontManager_class.h"

using namespace std;

const string HEAD_FILE = "flf2";

FontManager_class::FontManager_class()
{


}

string FontManager_class::load(string vPathToFile) {
    c_pathToFile = vPathToFile;
    c_caractersArray.clear();
    c_vecOfAllChars.clear();
    string result = "";
    if (loadFile()) {
        getConfig();
        if (configFound == (-1)) {
            cout << "No se encontro config" << endl;
        }
        else {
            cout << "Se encontro config" << endl;
        }

        getCharThatCloseLines();
        result=loadFileLinesInMemory();

        closeFile();
    }
    return result;
}

bool FontManager_class::loadFile()
{
    c_myFile_Handler.open(c_pathToFile);
    if (c_myFile_Handler.is_open())
    {
        return true;
    }
    else
    {
        cout << "Unable to open the file!";
        return false;
    }
}
void FontManager_class::closeFile() {
    c_myFile_Handler.close();

}

void FontManager_class::getConfig()
{
    vector<string> paramsArray;
    string strParam,myLine;

    getline(c_myFile_Handler, myLine);

    cout << myLine << endl;
    if ((configFound = findEndOfStr(myLine, HEAD_FILE))!=(-1))
    {
        strParam = myLine.substr(configFound);
        paramsArray = splitStr(strParam, ' ');

        ConfigFont_class::found = configFound;
        ConfigFont_class::p1 = paramsArray[0][0];
        ConfigFont_class::p2 = paramsArray[0][1];
        ConfigFont_class::p3_Height = stoi(paramsArray[1]);
        ConfigFont_class::p4_Height_nd = stoi(paramsArray[2]);
        ConfigFont_class::p5_maxLinLen = stoi(paramsArray[3]);
        ConfigFont_class::p6_defSmuMod = stoi(paramsArray[4]);
        ConfigFont_class::p7_numComm = stoi(paramsArray[5]);

    }
    
}
void FontManager_class::getCharThatCloseLines()
{
    // Keep reading the file
    int characterFound = -1;
  
    string strVectorToOutputInFile;
    string myLine, caracterStr, strChar;
    vector<string> caracterArray;
    try {
        while (getline(c_myFile_Handler, myLine) && characterFound == (-1))
        {
            countline++; 

            if ((characterFound = findStr(myLine, "@@")) != (-1)) {
                finalChar = '@';
                cout << "Se encontro @";
            }else if ((characterFound = findStr(myLine, "##")) != (-1)) {
                finalChar = '#';
                cout << "Se encontro #";
            }


        }
    } catch (int e) {
        cout << "Entre al catch" << endl;        
    }

}
    

string FontManager_class::loadFileLinesInMemory()
{
    // Keep reading the file
    int characterFound = 0;
    int countline = 0;
    string strVectorToOutputInFile;

    string myLine, caracterStr, strChar;

    vector<string> caracterArray;


    
    while (getline(c_myFile_Handler, myLine))
    {
        countline++;
        if ((configFound==(-1)) || (countline > ConfigFont_class::p7_numComm))
        {
            //cout << "entro aquí" << endl;
                if ((characterFound = findStr(myLine, "@@")) != (-1))
                {
                    strChar = myLine.substr(0, characterFound);
                    caracterStr = caracterStr + strChar;
                    caracterArray = splitStr(caracterStr, '@');
                    c_caractersArray.push_back(caracterArray);
                    for (string data : caracterArray) {
                        strVectorToOutputInFile += data + "\n";
                    }
                    caracterStr = "";
                }
                else
                {
                    if (findStr(myLine, "@") != (-1)) {
                        caracterStr = caracterStr + myLine;
                    }
                }
        }
        
    }
    /*
    vectorFonts.push_back("3D Diagonal");
    if(font=="3D Diagonal"){
        nl = "#"
        conf = "p1:a,p2:$,p3_Height:16,p4_Height_nd:15,p5_maxLinLen:19,p6_defSmuMod:63,p7_numComm:20"
        if ((charNumber==0) || (character=="!")){ oneChar=

    */
    //cout << strVectorToOutputInFile;
    return strVectorToOutputInFile;

}

vector<vector<string>> FontManager_class::getCaractersArray() {
    return c_caractersArray;
}

int FontManager_class::getPosOfCharInFile(string chartoSearch) {
    int valRet = (-1);
    vector<string> strCharArray;
    string charOrder = "  ! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~ Ä Ö Ü ä ö ü ß ";
    valRet = charOrder.find(chartoSearch);
    valRet = (valRet / 2);
    return valRet;

}


vector<string> FontManager_class::getCharFromFile(string charToSearch) {
    return c_caractersArray[FontManager_class::getPosOfCharInFile(charToSearch)];
}

void FontManager_class::concStrVector(vector<string> vecOfAChar) {
    //cout << vecOfAChar.size() << endl;

    if (c_vecOfAllChars.size() == 0) {
        for (string data : vecOfAChar) {
            c_vecOfAllChars.push_back(data);
        }
    }
    else {
        //cout << "pase 2" << endl;
        for (unsigned int i = 0; i < vecOfAChar.size(); i++) {
            //cout << vecOfAChar[i] << endl;
            c_vecOfAllChars[i] = c_vecOfAllChars[i] + vecOfAChar[i];
        }
    }

}

vector<string> FontManager_class::getFullStringOfChars() {
    return c_vecOfAllChars;
}

void FontManager_class::convStrToStrOfAscciChar(string strToconvert)
{
    string charTemp = "";
    for (unsigned i = 0; i < strToconvert.length(); i++) {
        charTemp = strToconvert.at(i);
        concStrVector(getCharFromFile(charTemp));
    }

}


void convStrToStrOfAscciChar(string strToconvert) {


}