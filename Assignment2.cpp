// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"

using namespace std;

void discard_line(ifstream& in);


int main()
{
    List myList;

    ifstream in;
    ofstream out;
    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);

    //TODO...

    in.close();
    out.close();

    system("pause");
    return 0;
}

void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}

