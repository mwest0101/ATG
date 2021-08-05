#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions_str.h"



string normalizeStr(string result) {
	result = strReplace(result, "\\", "\\\\");
	result = strReplace(result, "\'", "\\\'");
	result = strReplace(result, "\"", "\\\"");

	return result;
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







