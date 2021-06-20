#include <iostream>
#include <string>
#include <vector>
#include "functions_str.h"


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
}







/*
* 
 #include <algorithm> 
 #include <windows.h>
 #include <locale>
 #include <cctype>
 #include <stdio.h>


flf2 - "magic number" for file identification
a    - should always be `a', for now
$    - the "hardblank" -- prints as a blank, but can't be smushed
6    - height of a character
5    - height of a character, not including descenders
14   - max line length (excluding comment lines) + a fudge factor
15   - default smushmode for this font
16   - number of comment lines


*/
//using namespace std::stoi;
//using namespace std::stoi;
/*
namespace{
	const char *spaces = " \t";
	const char *digits = "0123456789";
}

int IntLen(const char *cstr){
	int k, n = 0;
	if (cstr)
	{
		n = strspn(cstr, spaces);
		cstr += n;
		if (*cstr == '-' || *cstr == '+')
			++cstr, ++n;
		k = strspn(cstr, digits);
		n = k ? n + k : 0;
	}
	return n;
}

bool isNumber(const char *cstr){
	int n = IntLen(cstr);
	if (n)
	{
		cstr += n;
		if (*cstr == 'e' || *cstr == 'E')
			n = strspn(++cstr, digits);
	}

	return n > 0;
}

void changeConlorWithString(string colorStr) {
	int col1 ,col2;
	string sCol1, sCol2;

	int color2 = 0;
	int newPos = 0;
	
	if ((newPos = colorStr.find(","))!=-1) {
		sCol1 = colorStr.substr(0, newPos);
		sCol2 = colorStr.substr(newPos + 1);

		col1= atoi(sCol1.c_str());
		col2 = atoi(sCol2.c_str());


		SetColor(col1, col2);
	}

}


*/




