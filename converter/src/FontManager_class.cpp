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
        getCharThatCloseLines();
        closeFile();
    }
    if (loadFile()) {        
        result = getCharlines();
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
        
        Debug_class::log("Unable to open the file!");
        return false;
    }
}
void FontManager_class::closeFile() {
    c_myFile_Handler.close();

}

int FontManager_class::getPosOfCharInFile(string chartoSearch) {
    int valRet = (-1);
    vector<string> strCharArray;
    string charOrder = "  ! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~ Ä Ö Ü ä ö ü ß ";
    valRet = charOrder.find(chartoSearch);
    valRet = (valRet / 2);
    return valRet;

}

string FontManager_class::getCharFromPosInFile(int chartoSearch) {
    string valRet = "";
    vector<string> strCharArray;
    string charOrder = "  ! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~ Ä Ö Ü ä ö ü ß ";
    strCharArray = splitStr(charOrder,' ');
    valRet = strCharArray[chartoSearch];
    return valRet;

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
    if (configFound == (-1)) {
        //cout << "No se encontro config" << endl;
       // debug.log("No se encontro config");
    }else {
        Debug_class::log("Config string from File was found");        
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
                Debug_class::log("The char of end of line is : @");
            }else if ((characterFound = findStr(myLine, "##")) != (-1)) {
                finalChar = '#';
                Debug_class::log("The char of end of line is : #");
            }


        }
        if (characterFound == (-1)) {
            cout << "The char of end of line was seted by defult to : \\n" << endl;
        }
    } catch (int e) {
        cout << "Error reading file lines" << endl;        
    }

}
    

string FontManager_class::getCharlines()
{
    // Keep reading the file
    int characterFound = 0;
    int countline = 0;
    int countChar = 0;
    string strResult;
    string myLine, caracterStr, strChar;
    string strAllChars;
    string oneChar;
    string doubleChar;
    string singleChar(1, finalChar);
        
    doubleChar = singleChar+ singleChar;
    cout << " doublechar " << doubleChar << endl;
    Debug_class::log("Entre a getCharLines");

    while (getline(c_myFile_Handler, myLine))
    {
       // Debug_class::log("Entre a getCharLines 2");
        countline++;
        if ((configFound==(-1)) || (countline > ConfigFont_class::p7_numComm))
        {

            
                if ((characterFound = findStr(myLine, doubleChar)) != (-1))
                {
                    //Debug_class::log("Entre a getCharLines 2");
                    countChar++;
                    strChar = myLine.substr(0, characterFound);
                    oneChar = oneChar + strChar;
                    strAllChars += "    if ((charNumber == " + to_string(countChar) + ") || (character == \"" + getCharFromPosInFile(countChar) + "\" )) { oneChar =\"" + oneChar + "\" };\n";
                    oneChar = "";
                    
                    
                }else{
                    if (findStr(myLine, singleChar) != (-1)) {
                        oneChar += myLine;
                        //cout << oneChar << endl;
                    }
                }
        }
        
    }

    vector<string> fileNameParts = splitStr(normalizeUrl(c_pathToFile), '/');
    string nameWithoutPath= fileNameParts[fileNameParts.size()-1];
    fileNameParts = splitStr(normalizeUrl(nameWithoutPath), '.');
    string nameWithoutExt = fileNameParts[0];

    
    /*
    vector<string> fileNameParts = splitStr(fileNameParts[fileNameParts.size()-1], '.');
    cout << fileNameParts[0] << endl;
    */
    strResult += "vectorFonts.push_back(\""+ nameWithoutExt+"\");\n";
    strResult += "if(font==\""+ nameWithoutExt +"\"){\n";
    strResult += "   nl = \""+singleChar+"\"\n";
    string strConfig = "";
    strConfig += "found = " + ConfigFont_class::found;
    strConfig += "p1 = " + ConfigFont_class::p1;
    strConfig += "p2 = " + ConfigFont_class::p2;
    strConfig += "p3_Height = " + ConfigFont_class::p3_Height;
    strConfig += "p4_Height_nd = " + ConfigFont_class::p4_Height_nd;
    strConfig += "p5_maxLinLen = " + ConfigFont_class::p5_maxLinLen;
    strConfig += "p6_defSmuMod = " + ConfigFont_class::p6_defSmuMod;
    strConfig += "p7_numComm = " + ConfigFont_class::p7_numComm;


    strResult += strConfig+"\n";
    strResult += strAllChars;
    strResult += "}";
    /*
    
    
    if(font=="3D Diagonal"){
        nl = "#"
        conf = "p1:a,p2:$,p3_Height:16,p4_Height_nd:15,p5_maxLinLen:19,p6_defSmuMod:63,p7_numComm:20"
        if ((charNumber==0) || (character=="!")){ oneChar=

    */
    //cout << strVectorToOutputInFile;
    //cout << strAllChars << endl;
    return strResult;

}

vector<vector<string>> FontManager_class::getCaractersArray() {
    return c_caractersArray;
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
