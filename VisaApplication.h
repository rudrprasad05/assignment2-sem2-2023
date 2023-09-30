#pragma once
#include "Data.h"
#include <iostream>

using namespace std;

class VisaApplication : public Data{

    public: 
        
        string visa_type;
        string invoice_no;
        string surname;
        string first_name;
        string contact;
        string status;
        string result;

        void print()
        {
            cout << this->visa_type << " | " 
            << this->invoice_no << " | " 
            << this->surname << " | " 
            << this->first_name << " | "
            << this->contact << " | "
            << this->status << " | "
            << this->result << " | " << endl;
        }

        string getName(){
            return surname;
        }

};