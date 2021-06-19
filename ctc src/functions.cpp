#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "ctc.h"
using namespace std;

//using namespace std::stoi;
//using namespace std::stoi;

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



void anlizeString(string str){
	int count_find=0;
	
	string subStr;
	
	int newPos = 0;

	subStr = str;
	int band = 1;
	
	while (band) {
		if ((count_find == 0) and ((newPos = str.find("((")) != -1)) {			
			subStr = str.substr(0, newPos);			
			cout << subStr;
			str = str.substr(newPos + 2);						
			count_find=1;			
		}else if ((count_find == 1) and ((newPos = str.find("))")) != -1)) {			
			subStr = str.substr(0, newPos);						
			changeConlorWithString(subStr);
			str = str.substr(newPos+2);												
			count_find=0;
		}else{					
			cout << str; //Imprimo cadena posterior al parametro			
			band = 0;
		}

	}
}

