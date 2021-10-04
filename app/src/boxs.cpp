#include "boxs.h"

string showRectangle(string font, int cn, string cs) {
    string sr="";

    //cout << "entre a showfonts |font : "<< font <<"| cn: "<<cn <<"|cs:"<< cs << endl;
    vector<string> vectorRectangles;

    //if ((cn == 0) || (cs == "boxText")) { sr = u8"█▄▄█▀██░▒▓╚╗═╔╝║ │└┐─┌┘"; }

    vectorRectangles.push_back("Reactangle asterix");
    if (font == "Reactangle asterix") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"*[(*)]*"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"*[(C)]*"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"*[(*)]*"; }
    }

    vectorRectangles.push_back("Reactangle X");
    if (font == "Reactangle X") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"X[(X)]X"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"X[(C)]X"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"X[(X)]X"; }
    }

    vectorRectangles.push_back("Reactangle Parenthesis");
    if (font == "Reactangle Parenthesis") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"_[(_)]_"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"([(C)])"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"~[(~)]~"; }
    }

    vectorRectangles.push_back("Reactangle Simbols");
    if (font == "Reactangle Simbols") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"+[(-)]+"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"|[(C)]|"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"+[(-)]+"; }
    }

    vectorRectangles.push_back("Rombo Simbols Ascci");
    if (font == "Rombo Simbols Ascci") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"/[(-)]\\"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"|[(C)]|"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"\\[(-)]//"; }
    }

    vectorRectangles.push_back("Reactangle Full Thick");
    if (font == "Reactangle Full Thick") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██"; }
    }

    vectorRectangles.push_back("Reactangle Full Thin");
    if (font == "Reactangle Full Thin") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▄[(▄)]▄"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▀[(▀)]▀"; }
    }

    vectorRectangles.push_back("Reactangle Double Line");
    if (font == "Reactangle Double Line") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"╔[(═)]╗"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"║[(C)]║"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"╚[(═)]╝"; }

    }

    vectorRectangles.push_back("Reactangle Single Line");
    if (font == "Reactangle Single Line") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"┌[(─)]┐"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"│[(C)]│"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"└[(─)]┘"; }

    }

    vectorRectangles.push_back("Rounded Reactangle Full Thin");
    if (font == "Rounded Reactangle Full Thin") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"  ▄▀[(▀)]▀▄"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▄▀  [(c)]  ▀▄"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█   [(C)]   █"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▀▄  [(c)]  ▄▀"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"  ▀▄[(▄)]▄▀"; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Soft");
    if (font == "Reactangle Full With Shadow Soft") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██░░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██░░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(░)]░░░░"; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Medium");
    if (font == "Reactangle Full With Shadow Medium") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██▒▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▒▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▒)]▒▒▒▒"; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Dark");
    if (font == "Reactangle Full With Shadow Dark") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██▓▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▓▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▓▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▓)]▓▓▓▓"; }
    }


    vectorRectangles.push_back("Reactangle Full With Shadow Soft Inverted");
    if (font == "Reactangle Full With Shadow Soft Inverted") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"░░[(░)]░░██"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"░░[( )]░░██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"░░[(░)]░░██"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(█)]████"""; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Medium Inverted");
    if (font == "Reactangle Full With Shadow Medium Inverted") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▒▒[(▒)]▒▒██"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▒▒[(C)]▒▒██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▒▒[(▒)]▒▒██"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▒)]████"""; }
    }

    vectorRectangles.push_back("Reactangle Full With Dark Inverted");
    if (font == "Reactangle Full With Dark Inverted") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▓▓[(▓)]▓▓██"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▓▓[(C)]▓▓██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▓▓[(▓)]▓▓██"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(█)]████"""; }
    }


    vectorRectangles.push_back("Reactangle Light With Shadow Soft");
    if (font == "Reactangle Light With Shadow Soft") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"█[(█)]█░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█[(█)]█░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8" [(░)]░"; }
    }

    vectorRectangles.push_back("Reactangle Light With Shadow Medium");
    if (font == "Reactangle Light With Shadow Medium") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"█[(█)]█▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█[(█)]█▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8" [(▒)]▒▒"; }
    }

    vectorRectangles.push_back("Reactangle Light With Shadow Dark");
    if (font == "Reactangle Light With Shadow Dark") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"█[(█)]█▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█[(█)]█▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8" [(▓)]▓▓"""; }
    }


    vectorRectangles.push_back("Reactangle Full With Rounded Soft");
    if (font == "Reactangle Full With Rounded Soft") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"░░░░[(░)]░░░░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"░░██[(█)]██░░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"░░██[(C)]██░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"░░██[(█)]██░░"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"░░░░[(░)]░░░░"; }
    }
    vectorRectangles.push_back("Reactangle Full With Rounded Medium");
    if (font == "Reactangle Full With Rounded Medium") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▒▒▒▒[(▒)]▒▒▒▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▒▒██[(█)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▒▒██[(C)]██▒▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▒▒██[(█)]██▒▒"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▒▒▒▒[(▒)]▒▒▒▒"; }

    }

    vectorRectangles.push_back("Reactangle Full With Rounded Dark");
    if (font == "Reactangle Full With Rounded Dark") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▓▓▓▓[(▓)]▓▓▓▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▓▓██[(█)]██▓▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▓▓██[(C)]██▓▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▓▓██[(█)]██▓▓"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▓▓▓▓[(▓)]▓▓▓▓"; }
    }

    vectorRectangles.push_back("Reactangle Thin With Rounded Soft");
    if (font == "Reactangle Thin With Rounded Soft") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"░░[(░)]░░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"░█[(█)]█░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"░█[(C)]█░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"░█[(█)]█░"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"░░[(░)]░░"; }
    }

    vectorRectangles.push_back("Reactangle Thin With Rounded Medium");
    if (font == "Reactangle Thin With Rounded Medium") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▒▒[(▒)]▒▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▒█[(█)]█▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▒█[(C)]█▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▒█[(█)]█▒"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▒▒[(▒)]▒▒"; }

    }

    vectorRectangles.push_back("Reactangle Thin With Rounded Dark");
    if (font == "Reactangle Full With Rounded Dark") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▓▓[(▓)]▓▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▓█[(█)]█▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▓█[(C)]█▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▓█[(█)]█▓"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▓▓[(▓)]▓▓"; }
    }


    vectorRectangles.push_back("Reactangle Full With Shadow Soft");
    if (font == "Reactangle Full With Shadow Soft") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██░░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██░░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(░)]░░░░"; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Medium");
    if (font == "Reactangle Full With Shadow Medium") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██▒▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▒▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▒)]▒▒▒▒"; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Dark");
    if (font == "Reactangle Full With Shadow Dark") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██▓▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▓▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▓▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▓)]▓▓▓▓"""; }
    }

    vectorRectangles.push_back("Reactangle Full With Shadow Dark");
    if (font == "Reactangle Full With Shadow Dark") {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"████[(█)]██"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██  [(c)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██  [(C)]██▒▒░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"██  [(c)]██▒▒░░"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"████[(█)]██▒▒░░"; }
        if ((cn == 6) || (cs == "boxText6")) { sr = u8"  ▒▒[(▒)]▒▒▒▒░░"; }
        if ((cn == 7) || (cs == "boxText7")) { sr = u8"    [(░)]░░░░░░"; }

    }


    if (font == "allRectangles") {
        int countRec = 0;
        string listRect = "";
        for (string oneRect : vectorRectangles) {
            listRect += to_string(countRec) + ":" + oneRect + ";";
            countRec++;
        }

        sr = listRect;
    }


    return sr;


}