#include "Help.h"



using namespace std;

//using std::cout; using std::endl;
//using std::copy; using std::string;

void help() {
	int cbf2 = 7;
	int cbb2 = 0;

	SetColor(7, 4);
	
	cout << "+-----------------------------------------------------------+" << endl;
	cout << "|              ___   _____  _____  _____  _____             |" << endl;
	cout << "|             / _ \\ /  ___|/  __ \\|_   _||_   _|            |" << endl;
	cout << "|            / /_\\ \\\\ `--. | /  \\/  | |    | |              |" << endl;
	cout << "|            |  _  | `--. \\| |      | |    | |              |" << endl;
	cout << "|            | | | |/\\__/ /| \\__/\\ _| |_  _| |_             |" << endl;
	cout << "|            \\_| |_/\\____/  \\____/ \\___/  \\___/             |" << endl;
	cout << "|                                                           |" << endl;
	cout << "|               _____  _____ __   __ _____                  |" << endl;
	cout << "|              |_   _||  ___|\\ \\ / /|_   _|                 |" << endl;
	cout << "|                | |  | |__   \\ V /   | |                   |" << endl;
	cout << "|               | |  |  __|  /   \\   | |                    |" << endl;
	cout << "|                | |  | |___ / /^\\ \\  | |                   |" << endl;
	cout << "|                \\_/  \\____/ \\/   \\/  \\_/                   |" << endl;
	cout << "|                                                           |" << endl;
	cout << "|  _____                                  _                 |" << endl;
	cout << "| |  __ \\                                | |                |" << endl;
	cout << "| | |  \\/  ___  _ __    ___  _ __   __ _ | |_   ___   _ __  |" << endl;
	cout << "| | | __  / _ \\| '_ \\  / _ \\| '__| / _` || __| / _ \\ | '__| |" << endl;
	cout << "| | |_\\ \\|  __/| | | ||  __/| |   | (_| || |_ | (_) || |    |" << endl;
	cout << "|  \\____/ \\___||_| |_| \\___||_|    \\__,_| \\__| \\___/ |_|    |" << endl;
	cout << "+-----------------------------------------------------------+" << endl;


	cout << endl;

	SetColor(7, 0);
	cout << "+----------------------------------------------------------------------+" << endl;
	cout << "| Example: atg [Font Number] [Any text]                                |" << endl;
	cout << "+----------------------------------------------------------------------+" << endl << endl;


	SetColor(cbf2, cbb2);
	cout << "+-------------------------------------------------------------------------+" << endl;
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(0, 7);
	cout << " -s = set On Smush                  ";
	SetColor(cbf2, cbb2); cout << "|";
	
	SetColor(8, 0);
	cout << "  -ra = Rainvown Color Demo         ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(1, 0);
	cout << " -rv = Rainbow vertical Color       ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(9, 0);
	cout << "  -rvt = Rainbow Vertical ColorTotal";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(2, 0);
	cout << " -rh = Rainbow Horizontal           ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(10, 0);
	cout << " -b:[Number] = Display text in a box";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(3, 0);
	cout << " -l = List of fonts availables      ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(11, 0);
	cout << " -dn = List examples fonts          ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(4, 0);
	cout << " -dc = List example fonts custom    ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(12, 0);
	cout << " -d = List of all fonst             ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	SetColor(cbf2, cbb2); cout << "|";
	SetColor(5, 0);
	cout << " -bl = List of all Box names        ";
	SetColor(cbf2, cbb2); cout << "|";
	SetColor(13, 0);
	cout << " -db = Example of all box types     ";
	SetColor(cbf2, cbb2); cout << "|" << endl;

	
	SetColor(cbf2, cbb2);
	cout << "+-------------------------------------------------------------------------+" << endl;
	SetColor(7, 0);
	cout << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|Examples:                                           |" << endl;
	cout << "| atg 12 Test text                                   |" << endl;
	cout << "| atg 12 Test text -b:3                              |" << endl;
	cout << "|                                                   |" << endl;
	cout << "+----------------------------------------------------+" << endl;


	cout << endl;

	SetColor(7, 0);
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|Developed by: Maurcio West                                  |" << endl;
	cout << "|                                                            |" << endl;
	cout << "|e-mail:mauriciowest+wtdev@gmail.com                         |" << endl;
	cout << "|https://github.com/mwest0101/                               |" << endl;
	cout << "|https://www.linkedin.com/in/mauricio-pablo-west-12bb734/    |" << endl;
	cout << "|https://www.facebook.com/groups/322699759016752             |" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	SetColor(0, 7);
}
