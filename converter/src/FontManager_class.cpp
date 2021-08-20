#include "FontManager_class.h"

using namespace std;

const string HEAD_FILE = "flf2";

FontManager_class::FontManager_class()
{


}

string FontManager_class::load(string vPathToFile,string fileName) {
    fileNameToStorageResult = fileName;
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
        
        Debug_class::log("**Unable to open the file!**");
        return false;
    }
}
void FontManager_class::closeFile() {
    c_myFile_Handler.close();

}
vector<string> FontManager_class::getVectorOfChars() {
    vector<string> charOrder{
    " ","!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/",
    "0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?","@",
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    "[","\\","]","^","_","`",
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
    "{","|","}","~","Ä","Ö","Ü","ä","ö","ü","ß"
    };
    return charOrder;
}

int FontManager_class::getPosOfCharInFile(string chartoSearch) {
    int valRet = (-1);
    int count = 0;
    vector<string> strCharArray;

    for (string data : getVectorOfChars()){    
        if (chartoSearch == data) {
            valRet = count;
            break;
        }
        count++;
    }
    
    return valRet;

}

string FontManager_class::getCharFromPosInFile(int chartoSearch) {
    string valRet = "";
    
    vector<string> charOrder = getVectorOfChars();
        

    valRet = charOrder[chartoSearch];
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
        Debug_class::log("* Config string from File **was NOT found**");
    }else {
        Debug_class::log("* Config string from File **was found**");        
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
                Debug_class::log("* The char of end of line is : **@**");
            }else if ((characterFound = findStr(myLine, "##")) != (-1)) {
                finalChar = '#';
                Debug_class::log("* The char of end of line is : **#**");
            }


        }
        if (characterFound == (-1)) {
            Debug_class::log("* The char of end of line **WAS NOT FOUND**");
            cout << "* The char of end of line was seted by defult to : \\n" << endl;
        }
    } catch (int e) {
        cout << "**Error reading file lines**" << e << endl;
    }

}
    

string FontManager_class::getCharlines()
{
    // Keep reading the file
    int characterFound = 0;
    int countline = 0;
    unsigned int countChar = 0;
    string strResult;
    string myLine, caracterStr, strChar;
    string strAllChars;
    string oneChar;
    string doubleChar;
    string singleChar(1, finalChar);
    vector<string> numAscciCode;
    doubleChar = singleChar+ singleChar;
    //cout << " doublechar " << doubleChar << endl;

    Debug_class::log("* Processing: **\""+ c_pathToFile+"\"** ");
    Debug_class::log("* Entering to parse lines");

    Debug_class::log("* Creating and normalizing strings");
    vector<string> fileNameParts = splitStr(normalizeUrl(c_pathToFile), '/');
    string nameWithoutPath = fileNameParts[fileNameParts.size() - 1];
    fileNameParts = splitStr(normalizeUrl(nameWithoutPath), '.');
    string nameWithoutExt = fileNameParts[0];
    string hexaCode;
    string charString;

    strResult += "vectorFonts.push_back(\"" + nameWithoutExt + "\");\n";

    strResult += "if(font==\"" + nameWithoutExt + "\"){\n";

    string strConfig;
    strConfig += "    if ((charNumber == (-1)) || (character == \"conf\" )) {";
    strConfig += "strResturn=\"nl=" + singleChar;
    strConfig += ",found=" + to_string(ConfigFont_class::found);
    strConfig += ",p1=" + ConfigFont_class::p1;
    strConfig += ",p2=" + ConfigFont_class::p2;
    strConfig += ",p3_Height=" + to_string(ConfigFont_class::p3_Height);
    strConfig += ",p4_Height_nd=" + to_string(ConfigFont_class::p4_Height_nd);
    strConfig += ",p5_maxLinLen=" + to_string(ConfigFont_class::p5_maxLinLen);
    strConfig += ",p6_defSmuMod=" + to_string(ConfigFont_class::p6_defSmuMod);
    strConfig += ",p7_numComm=" + to_string(ConfigFont_class::p7_numComm);
    strConfig += "\";}";

    strResult += strConfig + "\n";
    writeFile(fileNameToStorageResult, strResult);
    strResult = "";


    while (getline(c_myFile_Handler, myLine))
    {
        
        countline++;
        if ((configFound==(-1)) || (countline > ConfigFont_class::p7_numComm))
        {
            
            
            if ((countChar > getVectorOfChars().size()) && (findStr(myLine, singleChar) == (-1))) {
                
                
                    numAscciCode = splitStr(myLine, ' ');

                    hexaCode = numAscciCode[0];
                    Debug_class::log("Captura de caracter EXTRA");
                    Debug_class::log("HexaCode "+ hexaCode);
                    //cout << "----->" << numAscciCode[0] << endl;
                   // cout << "codigo de fuente "<< endl;
                    //cout << "codigo de fuente " << numAscciCode[0];
                
            }
            else {
                

                if ((characterFound = findStr(myLine, doubleChar)) != (-1))
                {
                    //Debug_class::log("Entre a getCharLines 2");

                    strChar = myLine.substr(0, characterFound);
                    oneChar = oneChar + strChar;
                    if (hexaCode!=""){
                        charString = hexaCode;

                    }
                    else {
                        charString = normalizeChar(getCharFromPosInFile(countChar));
                    }
                    

                    strAllChars += "    if ((charNumber == " + to_string(countChar) + ") || (character == \"" + charString+ "\" )) { strResturn =\"" + oneChar + "\";}\n";
                    countChar++;
                    oneChar = "";
                    
                    writeFile(fileNameToStorageResult, strAllChars);
                    strAllChars = "";

                    Debug_class::log("* add one Char to the string " + to_string(countChar) + " " + normalizeChar(getCharFromPosInFile(countChar)), true);
                    hexaCode = "";

                }
                else {
                    if (findStr(myLine, singleChar) != (-1)) {
                        oneChar += normalizeStr(myLine);
                        Debug_class::log(myLine, true);
                        //Debug_class::log("* add one Char to the string " + to_string(countChar), true);
                        //cout << oneChar << endl;
                    }
                }
                
            }
        }
        
    }
    

    strResult = "";
    
    strResult += "}\n\n";
    writeFile(fileNameToStorageResult, strResult);
    Debug_class::log("* Complete string to write in file");
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
