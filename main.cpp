#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"
#include "Node.h"
#include "Data.h"

using namespace std;

List myList;


void discard_line(ifstream& in);
bool check_white_space(string input1, string input2, string input3, string input4, string input5){
    if(input1 == "" ){
        return true;
    }
    else return false;
}

void print_successful_applicants(string type){
    Node *pHead = myList.getpHead();
    Node *pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)){
            
            Data *d = pNode->getData();
            VisaApplication *v = dynamic_cast<VisaApplication*>(d);
            

            if(v->result == type){
                v->print();
            }
            else{
                continue;
            }
        }
}

void remove_unwated_applicants(){

    Node *pHead = myList.getpHead();
    Node *pNode = pHead;

    if (myList.isEmpty())
        cout << "The list is empty\n";
    else
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)){
            
            Data *d = pNode->getData();
            VisaApplication *v = dynamic_cast<VisaApplication*>(d);
            

            if(v->result == "success" || v->result == "failure"){
                cout << "K";
            }
            else{
                continue;
            }
        }
    // myList.printList();

}


int main()
{

    ifstream in;
    ofstream out;

    in.open("applications.txt", ios::in);
    // out.open("applications_outcome.txt", ios::out);

    if(in.fail()){
        cout << "invalid file or pathname" << endl;
        return 0;
    }

    discard_line(in);

    while(!in.eof()){
        
        VisaApplication *v = new VisaApplication;

        in >> v->visa_type;
        in >> v->invoice_no;
        in >> v->surname;
        in >> v->first_name;
        in >> v->contact;
        in >> v->status;
        in >> v->result;

        if(check_white_space(v->visa_type, v->invoice_no, v->surname, v->first_name, v->contact)){
            break;
        }
        
        myList.appendNode(v);


    }

    myList.printList();
    // print_successful_applicants("success");
    // print_successful_applicants("failure");
    remove_unwated_applicants();
    in.close();
    // out.close();
    
}

void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}

