#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"

const string HEAD_FILE = "flf2";

struct TextConfig {
	int found = (-1);
	string p1 = "";
	string p2 = "";
	int  p3_Height = 0;
	int  p4_Height_nd = 0;
	int  p5_maxLinLen = 0;
	int  p6_defSmuMod = 0;
	int  p7_numComm = 0;
};
using namespace std;

int getPosOfCharInFile(string chartoSearch) {
	int valRet = (-1);
	//char* arr;
	vector<string> strCharArray;

	//string charOrder = "[comment] [space] ! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~ Ä Ö Ü ä ö ü ß";
	string charOrder = "  ! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~ Ä Ö Ü ä ö ü ß ";
	//					0123456789012345678901234567890123456789012345678901234567890123456789
	//					0         1         2         3         4         5         6    
	//strCharArray=splitStr(charOrder, ' ');
	//strCharArray[1] = " ";
	valRet = charOrder.find(chartoSearch);
	valRet = (valRet/2);
	//printStrVector(strCharArray);
	return valRet;
}


vector<string> getCharFromFile(vector<vector <string>> sourceVecOfChar,string charToSearch){
	return sourceVecOfChar[getPosOfCharInFile(charToSearch)];
}

vector<string> concStrVector(vector<string> vecOfAllChars,vector<string> vecOfAChar) {
	//cout << vecOfAChar.size() << endl;

	if (vecOfAllChars.size() == 0) {
		for (string data : vecOfAChar) {
			vecOfAllChars.push_back(data);			
		}	
	}
	else {
		cout << "pase 2" << endl;
		for (unsigned int i = 0; i < vecOfAChar.size(); i++) {
			//cout << vecOfAChar[i] << endl;
			vecOfAllChars[i] = vecOfAllChars[i] + vecOfAChar[i];
		}
	}
	return vecOfAllChars;
}
/*
void anlizeString(string str) {
	int count_find = 0;

	string subStr;

	int newPos = 0;

	subStr = str;
	int band = 1;

	while (band) {
		if ((count_find == 0) && ((newPos = str.find("((")) != -1)) {
			subStr = str.substr(0, newPos);
			cout << subStr;
			str = str.substr(newPos + 2);
			count_find = 1;
		} else {
			cout << str; //Imprimo cadena posterior al parametro			
			band = 0;
		}

	}
}*/







