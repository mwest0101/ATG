#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <AtlBase.h>
//#include <atlconv.h>
#include "text_encoding_detect.h"

#include "Debug_class.h"

#include <stdio.h>
#include <tchar.h>


using namespace AutoIt::Common;



#ifndef FUNCTIONS_H
#define FUNCTIONS_H
	using namespace std;


	string convertToUtf8(string data);
	bool fileExist(const std::string& name);
	string convertToUtf8(string data,string fileEncoding);
	string getFileCoding(string fileName);
	void writeFile(string filename, string text);
	string strRemoveParamsEnveded(string data);
	int getMaxWidthLine(vector<string> vectStr);

#endif
