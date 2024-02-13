#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct exp {
    int empID;
    string name;
    string exptype;
    double expam;
    exp* next;
};

void insertNode(exp*& head, int empID, string name, string exptype, double expam) {
    exp* newNode = new exp;
    newNode->empID = empID;
    newNode->name = name;
    newNode->exptype = exptype;
    newNode->expam = expam;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        exp* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}




void bubblesort(exp* &head) {

    int v=1;
    while (v) {
        v=0;
        exp* temp1 = head;
        while ((temp1)->next != NULL) {
            if ((temp1)->empID > (temp1)->next->empID) {
                exp* temp = (temp1)->next;
                (temp1)->next = (temp1)->next->next;
                temp->next = temp1;
                temp1 = temp;
                v=1;
            }
            temp1 = temp1->next;
        }
    }
}



void remove(exp* &head) {
    exp* temp = head;
    exp* nexptr;

    while (temp != NULL && temp->next != NULL) {
        nexptr = temp;
        while (nexptr->next != NULL) {
            if (temp->empID == nexptr->next->empID &&temp->name == nexptr->next->name &&temp->exptype == nexptr->next->exptype &&temp->expam == nexptr->next->expam) {
                exp* duplicateNode = nexptr->next;
                nexptr->next = nexptr->next->next;
                delete duplicateNode;
            }
            else {
                nexptr = nexptr->next;
            }
        }
        temp = temp->next;
    }
}


int main() {

    ifstream inFile("expenses.txt");
    if (!inFile) {
        cout << "Error: Cannot open file" << endl;
        return 1;
    }

    exp* head = NULL;
    int empID;
    string name, exptype;
    double expam;

    while (inFile >> empID >> name >> exptype >> expam) {
        insertNode(head, empID, name, exptype, expam);
    }
    inFile.close();

   

 
    bubblesort(head);

    
    cout << endl << "Final list of employees :" << endl;
    exp*  temp = head;
    while (temp != NULL) {
        cout << temp->empID << " " << temp->name << " " << temp->exptype << " " << temp->expam << endl;
        temp = temp->next;
    }

   

    return 0;
}

