#include "boxs.h"

string showRectangle(string font, int cn, string cs) {
    string sr="";

    //cout << "entre a showfonts |font : "<< font <<"| cn: "<<cn <<"|cs:"<< cs << endl;
    vector<string> vectorRectangles;

    //if ((cn == 0) || (cs == "boxText")) { sr = u8"█▄▄█▀██░▒▓╚╗═╔╝║ │└┐─┌┘"; }
    string boxName = "";

    boxName = "Rec Asterix";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"*[(*)]*"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"*[(C)]*"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"*[(*)]*"; }
    }

    boxName = "Rec X";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"X[(X)]X"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"X[(C)]X"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"X[(X)]X"; }
    }

    boxName = "Rec Parenthesis";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"_[(_)]_"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"([(C)])"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"~[(~)]~"; }
    }

    boxName = "Rec Simbols";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"+[(-)]+"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"|[(C)]|"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"+[(-)]+"; }
    }

    boxName = "Rombo Simbols Ascci";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"/[(-)]\\"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"|[(C)]|"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"\\[(-)]//"; }
    }

    boxName = "Rec Full Thick";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██"; }
    }

    boxName = "Rec Full Thin";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▄[(▄)]▄"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▀[(▀)]▀"; }
    }

    boxName = "Rec Double Line";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"╔[(═)]╗"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"║[(C)]║"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"╚[(═)]╝"; }

    }

    boxName = "Rec Single Line";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"┌[(─)]┐"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"│[(C)]│"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"└[(─)]┘"; }

    }

    boxName = "Rounded Rectangle Full Thin";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"  ▄▀[(▀)]▀▄  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▄▀  [(c)]  ▀▄"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█   [(C)]   █"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▀▄  [(c)]  ▄▀"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"  ▀▄[(▄)]▄▀  "; }
    }

    boxName = "Rec Full Shadow Soft";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██░░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(░)]░░░░"; }
    }

    boxName = "Rec Full Shadow Medium";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▒▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▒)]▒▒▒▒"; }
    }

    boxName = "Rec Full Shadow Dark";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▓▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▓▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▓)]▓▓▓▓"; }
    }

    boxName = "Rec Full Shadow Soft Inverted";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"░░[(░)]░░  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"░░[(C)]░░██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"░░[(░)]░░██"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(█)]████"; }
    }

    boxName = "Rec Full Shadow Medium Inverted";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▒▒[(▒)]▒▒  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▒▒[(C)]▒▒██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▒▒[(▒)]▒▒██"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(█)]████"; }
    }

    boxName = "Rec Full Dark Inverted";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▓▓[(▓)]▓▓  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▓▓[(C)]▓▓██"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▓▓[(▓)]▓▓██"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(█)]████"; }
    }

    boxName = "Rec Light Shadow Soft";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"█[(█)]█ "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█[(█)]█░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8" [(░)]░░"; }
    }


    boxName = "Rec Light Shadow Medium";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"█[(█)]█ "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█[(█)]█▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8" [(▒)]▒▒"; }
    }


    boxName = "Rec Light Shadow Dark";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"█[(█)]█ "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"█[(C)]█▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"█[(█)]█▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8" [(▓)]▓▓"; }
    }

    boxName = "Rec Full Rounded Soft";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"░░░░[(░)]░░░░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"░░██[(█)]██░░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"░░██[(C)]██░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"░░██[(█)]██░░"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"░░░░[(░)]░░░░"; }
    }

    boxName = "Rec Full Rounded Medium";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▒▒▒▒[(▒)]▒▒▒▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▒▒██[(█)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▒▒██[(C)]██▒▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▒▒██[(█)]██▒▒"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▒▒▒▒[(▒)]▒▒▒▒"; }

    }


    boxName = "Rec Full Rounded Dark";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▓▓▓▓[(▓)]▓▓▓▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▓▓██[(█)]██▓▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▓▓██[(C)]██▓▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▓▓██[(█)]██▓▓"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▓▓▓▓[(▓)]▓▓▓▓"; }
    }

 
    boxName = "Rec Thin Rounded Soft";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"░░[(░)]░░"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"░█[(█)]█░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"░█[(C)]█░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"░█[(█)]█░"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"░░[(░)]░░"; }
    }


    boxName = "Rec Thin Rounded Medium";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▒▒[(▒)]▒▒"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▒█[(█)]█▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▒█[(C)]█▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▒█[(█)]█▒"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▒▒[(▒)]▒▒"; }

    }

    boxName = "Rec Thin Rounded Dark";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"▓▓[(▓)]▓▓"; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"▓█[(█)]█▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"▓█[(C)]█▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"▓█[(█)]█▓"; }
        if ((cn == 5) || (cs == "boxText5")) { sr = u8"▓▓[(▓)]▓▓"; }
    }

  
    boxName = "Rec Full With Shadow Soft";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██░░"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██░░"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(░)]░░░░"; }
    }

  
    boxName = "Rec Full With Shadow Medium";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▒▒"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▒▒"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▒)]▒▒▒▒"; }
    }

    boxName = "Rec Full With Shadow Dark";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {

        if ((cn == 1) || (cs == "boxText1")) { sr = u8"██[(█)]██  "; }
        if ((cn == 2) || (cs == "boxText2")) { sr = u8"██[(C)]██▓▓"; }
        if ((cn == 3) || (cs == "boxText3")) { sr = u8"██[(█)]██▓▓"; }
        if ((cn == 4) || (cs == "boxText4")) { sr = u8"  [(▓)]▓▓▓▓"; }
    }

    boxName = "Rec Full With three shadow";
    vectorRectangles.push_back(boxName);
    if (font == boxName) {
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