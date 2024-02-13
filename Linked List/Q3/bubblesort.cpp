#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
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

void swapemp(exp*& head, int id1, int id2) {
    if (id1 == id2) return;

    exp* temp1 = head, *prev1 = NULL;
    while (temp1 && temp1->empID != id1) {
        prev1 = temp1;
        temp1 = temp1->next;
    }

    exp* temp2 = head, *prev2 = NULL;
    while (temp2 && temp2->empID != id2) {
        prev2 = temp2;
        temp2 = temp2->next;
    }

    
    if (!(temp1 && temp2)) return;


    if (prev1) prev1->next = temp2;
    else head = temp2;
    if (prev2) prev2->next = temp1;
    else head = temp1;


    exp* temp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp;
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

int maximum(exp* head)
{
    exp* temp = head;
    int maxi=0;

    while(temp!=NULL)
    {   
        if(temp->empID > maxi)
        maxi = temp->empID;
    
        temp = temp->next;
        
    }
    return maxi;
}


int main() 
{
    exp* head = NULL;
    int empID;
    string name, exptype;
    double expam;

   
    ifstream fin("expenses.txt");
    if (!fin.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    while (fin >> empID >> name >> exptype >> expam) {
        insertNode(head, empID, name, exptype, expam);
    }
    fin.close();

   


    bubblesort(head);

    cout << endl << "Sorted list of employees by ID:" << endl;
    exp* curr = head;
    while (curr != NULL) {
        cout << curr->empID << " " << curr->name << " " << curr->exptype << " " << curr->expam << endl;
        curr = curr->next;
    }


    int v = maximum(head);
    int empID1 = rand() %  v + 1; 
    int empID2 = rand() %  v + 1;
    cout<<"First random id "<<empID1<<endl;
    cout<<"Second random id "<<empID2<<endl;

    
    swapemp(head,empID1, empID2);

    cout << endl << "Sorted list of employees by ID (with swapped employees):" << endl;
    curr = head;
    while (curr != NULL) {
        cout << curr->empID << " " << curr->name << " " << curr->exptype << " " << curr->expam << endl;
        curr = curr->next;
    }


    return 0;
}

