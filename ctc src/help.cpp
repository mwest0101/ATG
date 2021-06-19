

#include "stdafx.h"
#include "config.h"
#include <iostream>
#include <windows.h>
#include "ctc.h"



using namespace std;
//using std::cout; using std::endl;
//using std::copy; using std::string;

void help(){	
	int cbf2=7;
	int cbb2=0;
		
	SetColor(7,4);
	cout << "+--------------------------------------------+" << endl;
	cout << "|   ____                        _            |" << endl;
	cout << "|  / ____|                     | |           |" << endl;
	cout << "| | |      ___  _ __  ___  ___ | | ___       |" << endl;
	cout << "| | |     / _ \\| '_ \\/ __|/ _ \\| |/ _ \\      |" << endl;
	cout << "| | |____| (_) | | | \\__ \\ (_) | |  __/      |" << endl;
	cout << "|  \\_____|\\___/|_| |_|___/\\___/|_|\\___|      |" << endl;
	cout << "|                                            |" << endl;
	cout << "|  _______         _                         |" << endl;
	cout << "| |__   __|      | |                         |" << endl;
	cout << "|   | | _____  __| |                         |" << endl;
	cout << "|   | |/ _ \\ \\/ /| __|                       |" << endl;
	cout << "|   | |  __/>  < | |_                        |" << endl;
	cout << "|   |_|\\___/_/\\_\\ \\__|  V 2.0                |" << endl;
	cout << "|                                            |" << endl;
	cout << "|   _____       _                            |" << endl;
	cout << "|  / ____|     | |                           |" << endl;
	cout << "| | |      ___ | | ___  _ __                 |" << endl;
	cout << "| | |     / _ \\| |/ _ \\| '__|                |" << endl;
	cout << "| | |____| (_) | | (_) | |                   |" << endl;
	cout << "|  \\_____|\\___/|_|\\___/|_|                   |" << endl;
	cout << "|                                     2021   |" << endl;
	cout << "+--------------------------------------------+" << endl;
    
	cout << endl;

	SetColor(7, 0);
	cout << "+----------------------------------------------------------------------+" << endl;
	cout << "| Example: ctc [Back Color] [Font color] [Any text]                    |" << endl;
	cout << "|       This example lets only one space betwen word in [Any text]     |" << endl;
	cout << "|                                                                      |" << endl;
	cout << "| Example: ctc [Back Color] [Font color] \"[Any text]\"                  |" << endl;
	cout << "|      This example, with \", leaves all spaces defined in [Any text]   |" << endl;
	cout << "|                                                                      |" << endl;
	cout << "| Example: ctc [Back Color] [Font color] [Any ((2,0)) text]            |" << endl;
	cout << "|      To change the string colo in line you can uses (( [colors] ))   |" << endl;
	cout << "+----------------------------------------------------------------------+" << endl << endl;


	SetColor(cbf2, cbb2);
	cout << "+--------------------------------------+" << endl;
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(0, 7);
	cout << " 0 = Black       ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(8, 0);
	cout << "  8 = Dark Grey     ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(1, 0);
	cout << " 1 = Blue        ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(9, 0);
	cout << "  9 = Light Blue    ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(2, 0);
	cout << " 2 = Green       ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(10, 0);
	cout << " 10 = Light Green   ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(3, 0);
	cout << " 3 = Cyan        ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(11, 0);
	cout << " 11 = Light Cyan    ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(4, 0);
	cout << " 4 = Red         ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(12, 0);
	cout << " 12 = Light Red     ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(5, 0);
	cout << " 5 = Magenta     ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(13, 0);
	cout << " 13 = Light Magenta ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(6, 0);
	cout << "  6 = Brown      ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(14, 0);
	cout << " 14 = Yellow        ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(7, 0);
	cout << " 7 = Light Grey  ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(15, 0);
	cout << " 15 = White         ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2);
	cout << "+--------------------------------------+" << endl;
	SetColor(7, 0);
	cout << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|Examples:                                           |" << endl;
	cout << "| ctc 4 0 Example    test                            |" << endl;
	cout << "| Out:";
	SetColor(4, 0);
	cout << "Example test";
	SetColor(7, 0); cout << "                                   |" << endl;
	cout << "|                                                    |" << endl;
	cout << "| ctc 4 0 \"Example    test\"                          |" << endl;
	cout << "| Out:";
	SetColor(4, 0);
	cout << "Example    test";
	SetColor(7, 0); cout << "                                |" << endl;
	cout << "|                                                    |" << endl;
	cout << "| ctc 2 0 test ((4,0)) color                         |" << endl;
	cout << "| Out:";
	SetColor(4, 0);	cout << "test";	SetColor(2, 0);	cout << " color";
	SetColor(7, 0); cout << "                                     |" << endl;
	cout << "+----------------------------------------------------+" << endl;


	cout << endl;

	SetColor(7, 0);
	cout << "+----------------------------------------------------+" << endl;
	cout << "|Developed by: Maurcio West                          |" << endl;
	cout << "|                                                    |" << endl;
	cout << "|e-mail:mauriciowest+wtdev@gmail.com                 |" << endl;
	cout << "|https://github.com/mwest0101/                       |" << endl;
	cout << "|https://www.facebook.com/groups/322699759016752     |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	SetColor(0, 7);
}
