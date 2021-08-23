


#ifndef DEBUG_CLASS_H
#define DEBUG_CLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

class Debug_class{
public:
	static void log(string text, bool toFile=true);
	

};

#endif