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

double getTotalExpenseByType(exp* head, string exptype) {
    double totalExpense = 0;
    exp* temp = head;
    while (temp != NULL) {
        if (temp->exptype == exptype) {
            totalExpense += temp->expam;
        }
        temp = temp->next;
    }
    return totalExpense;
}

double getTotalExpenseByID(exp* head, int empID) {
    double totalExpense = 0;
    exp* temp = head;
    while (temp != NULL) {
        if (temp->empID == empID) {
            totalExpense += temp->expam;
        }
        temp = temp->next;
    }
    return totalExpense;
}


int main() {
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


    cout << "Enter the expense type to calculate the total expense: "<<endl;

    exptype;
    cin >> exptype;
    double totalExpense = getTotalExpenseByType(head, exptype);
    cout << "Total expense for " << exptype << " is " << totalExpense << endl;

    cout << "Enter the employee ID to calculate the total expense: ";
    int id;
    cin >> id;
    totalExpense = getTotalExpenseByID(head, id);
    cout << "Total expense for employee " << id << " is " << totalExpense << endl;

    return 0;
}

