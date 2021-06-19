#include "stdafx.h"
#include <iostream>
#include <windows.h>

#include "config.h"

#include "ctc.h"
#include "help.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[], char* envp[])
{
	int color1, color2;
	int i = 1;
	if (argc > 1){

		if (isNumber(argv[1]) and !isNumber(argv[2])) {			
				color2 = atoi(argv[1]);
				color1 = 0;						
				i++;
		} else {
			if (isNumber(argv[1])) {
				color1 = atoi(argv[1]);
				i++;
			}else {
				color1 = 0;
			}

			if (isNumber(argv[2])) {
				color2 = atoi(argv[2]);
				i++;
			}else {
				color2 = 7;
			}
		}

		SetColor(color1, color2);
		

		string cad;
		for (i; i < argc; i++){			
			cad=cad+argv[i]+" ";
		}
		cad = cad.substr(0,cad.size()-1);
		anlizeString(cad);
	}else{		
		help();		
	}
	
	return 0;
}
