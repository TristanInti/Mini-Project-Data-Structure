#include <iostream>
#include<string>
#include <vector>
#include <iterator>
#include<list>

using namespace std;

class Node
{
public:
    string key;
    int keys;
    Node* next;
};

void push(Node** head_ref, string new_key)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the key */
    new_node->key = new_key;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void append(Node** head_ref, int new_keys)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the key */
    new_node->keys = new_keys;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Checks whether the value x is present in linked list */
bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->keys == x)
            return true;
        current = current->next;
    }
    return false;
}

void insertAfter(Node* prev_node, string new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data */
    new_node->key = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

void deleteNode(Node** head_ref, string keys)
{

    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->key == keys)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
        while (temp != NULL && temp->key != keys)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
    }
}

void customerData() {

    Node* head = NULL;
    string name, address, email, cusAge, cusID, cusPhone, names, swabRes, outcome, date, location, status, dead, discharge, dateStat, data, str;
    long long int id, phoneNo;
    int customer, x, age, result, p, a, * ar, searchData;
    char s, m, o;
    string* arr;

    //Enter customer number
    cout << "Enter number of customers: ";
    cin >> customer;
    cout << "\n";

    arr = new string[customer];
    ar = new int[customer];

    for (x = 0, a = 1; x < customer && a < customer + 1; ++x, ++a) {

        cout << "Customer No: " << a << "\n" << endl;
        ar[a] = a;

        cout << "Enter name?" << endl;//Enter name
        getline(cin >> ws, name);

        cout << "\n";

        cout << "Enter address?" << endl;//Enter address
        getline(cin >> ws, address);

        cout << "\n";

        cout << "Enter email?" << endl;//Enter email
        getline(cin >> ws, email);

        cout << "\n";

        cout << "Enter age?" << endl;//Enter age
        cin >> age;
        cusAge = to_string(age);

        cout << "\n";

        cout << "Enter ID?" << endl;//Enter ID
        cin >> id;
        cusID = to_string(id);

        cout << "\n";

        cout << "Enter phone number?" << endl;//Enter phone number
        cin >> phoneNo;
        cusPhone = to_string(phoneNo);

        cout << "\nDone swab test ? [Y / y or N / n]" << endl;//Swab test 
        cin >> s;

        if (s == 'Y' || s == 'y') {
            swabRes = "Done swab test";//outcome of swab test

            cout << "\n";

            do {
                //cin.fail() to prevent skipping of input when loop
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter your results(Positive = 1/Negative = 0)" << endl;//results
                cin >> result;
                cout << "\n";

                if (result == 0) {
                    outcome = "Negative";

                    cout << "Date of release from quarintine" << endl;//date release
                    cin >> date;
                    cout << "\n";

                }
                else if (result > 0) {
                    outcome = "Positive";//result

                    cout << "Treatment location?" << endl;//location
                    cin >> location;

                    cout << "\n";

                    cout << "Status of patients positive with covid-19(Discharge = 1/Dead = 0)" << endl;//status
                    cin >> p;
                    cout << "\n";

                    if (p >= 1) {
                        status = "Discharge";//status = discharge
                    }
                    else if (p == 0) {
                        status = "Dead";// stats = dead
                    }
                    else {

                    }

                    if (p >= 1) {
                        cout << "Date of discharge?" << endl;//discharge date
                        cin >> discharge;
                        dateStat = discharge;

                        cout << "\n";

                    }
                    else if (p == 0) {
                        cout << "Date of death?" << endl; // death date
                        cin >> dead;
                        dateStat = dead;

                        cout << "\n";

                    }
                    else {
                        cout << "";
                    }
                }

                //if wrong value is entered
                if (!cin) {
                    cin.fail();
                    cout << "Wrong value entered!" << "\n";
                }
            } while (cin.fail());
        }
        // if swab test have not been done
        else if (s == 'N' || s == 'n') {
            swabRes = "Waiting for swab test";

            cout << "\n";

        }
        else {

        }

        if (s == 'N' || s == 'n') {

            //combine data
            data = name + "\n" + address + "\n" + email + "\n" + cusAge + "\n" + cusID + "\n" + cusPhone + "\n" + swabRes + "\n";

        }
        else if ((s == 'Y' || s == 'y') && result == 0) {
            //combine data
            data = name + "\n" + address + "\n" + email + "\n" + cusAge + "\n" + cusID + "\n" + cusPhone + "\n" + swabRes + "\n" + outcome + "\n" + date + "\n";
        }
        else if ((s == 'Y' || s == 'y') && result > 0) {
            //combine data
            data = name + "\n" + address + "\n" + email + "\n" + cusAge + "\n" + cusID + "\n" + cusPhone + "\n" + swabRes + "\n" + outcome + "\n" +
                location + "\n" + status + "\n" + dateStat + "\n";
        }
        else {

        }

        //inout the data to a dynamic array
        arr[x] = data;
        //push & append data to linked list
        push(&head, arr[x]);
        append(&head, ar[a]);
    }

    do {
        //menu
        cout << "a. Search" << "\n" << "b. Edit" << "\n" << "c. Add" << "\n" << "d. Delete" << endl;
        cin >> o;

        cout << "\n";

        //search
        if (o == 'a' || o == 'A') {
            cout << "Search customer" << endl;
            cin >> searchData;

            cout << "\n";

            switch (searchData)
            {
            case 1:
                search(head, 1) ? cout << arr[0] << "\n" : cout << "No Data" << "\n";
                break;
            case 2:
                search(head, 2) ? cout << arr[1] << "\n" : cout << "No Data" << "\n";
                break;
            case 3:
                search(head, 3) ? cout << arr[2] << "\n" : cout << "No Data" << "\n";
                break;
            case 4:
                search(head, 4) ? cout << arr[3] << "\n" : cout << "No Data" << "\n";
                break;
            case 5:
                search(head, 5) ? cout << arr[4] << "\n" : cout << "No Data" << "\n";
                break;
            case 6:
                search(head, 6) ? cout << arr[5] << "\n" : cout << "No Data" << "\n";
                break;
            case 7:
                search(head, 7) ? cout << arr[6] << "\n" : cout << "No Data" << "\n";
                break;
            case 8:
                search(head, 8) ? cout << arr[7] << "\n" : cout << "No Data" << "\n";
                break;
            case 9:
                search(head, 9) ? cout << arr[8] << "\n" : cout << "No Data" << "\n";
                break;
            case 10:
                search(head, 10) ? cout << arr[9] << "\n" : cout << "No Data" << "\n";
                break;
            case 11:
                search(head, 11) ? cout << arr[10] << "\n" : cout << "No Data" << "\n";
                break;
            case 12:
                search(head, 12) ? cout << arr[11] << "\n" : cout << "No Data" << "\n";
                break;
            case 13:
                search(head, 13) ? cout << arr[12] << "\n" : cout << "No Data" << "\n";
                break;
            case 14:
                search(head, 14) ? cout << arr[13] << "\n" : cout << "No Data" << "\n";
                break;
            default:
                cout << "No Data" << "\n";
                break;
            }
        }
        //update/Edit
        else if (o == 'b' || o == 'B') {
            cout << "Select Data" << endl;
            cin >> searchData;

            cout << "\n";

            cout << "Enter Updated Data" << "\n" << endl;
        }

        else if (o == 'c' || o == 'C') {
            //Add
            cout << "Add Data" << "\n" << endl;

            cout << "Enter name?" << endl;
            getline(cin >> ws, name);

            cout << "\n";

            cout << "Enter address?" << endl;
            getline(cin >> ws, address);

            cout << "\n";

            cout << "Enter email?" << endl;
            getline(cin >> ws, email);

            cout << "\n";

            cout << "Enter age?" << endl;
            cin >> age;
            cusAge = to_string(age);

            cout << "\n";

            cout << "Enter ID?" << endl;
            cin >> id;
            cusID = to_string(id);

            cout << "\n";

            cout << "Enter phone number?" << endl;
            cin >> phoneNo;
            cusPhone = to_string(phoneNo);

            cout << "\nDone swab test ? [Y / y or N / n]" << endl;
            cin >> s;

            if (s == 'Y' || s == 'y') {
                swabRes = "Done swab test";

                cout << "\n";

                do {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cout << "Enter your results(Positive = 1/Negative = 0)" << endl;
                    cin >> result;
                    cout << "\n";

                    if (result == 0) {
                        outcome = "Negative";

                        cout << "Date of release from quarintine" << endl;
                        cin >> date;
                        cout << "\n";

                    }
                    else if (result > 0) {
                        outcome = "Positive";

                        cout << "Treatment location?" << endl;
                        cin >> location;

                        cout << "\n";

                        cout << "Status of patients positive with covid-19(Discharge = 1/Dead = 0)" << endl;
                        cin >> p;
                        cout << "\n";

                        if (p >= 1) {
                            status = "Discharge";
                        }
                        else if (p == 0) {
                            status = "Dead";
                        }
                        else {

                        }

                        if (p >= 1) {
                            cout << "Date of discharge?" << endl;
                            cin >> discharge;
                            dateStat = discharge;

                            cout << "\n";

                        }
                        else if (p == 0) {
                            cout << "Date of death?" << endl;
                            cin >> dead;
                            dateStat = dead;

                            cout << "\n";

                        }
                        else {
                            cout << "";
                        }
                    }
                    if (!cin) {
                        cin.fail();
                        cout << "Wrong value entered!" << "\n";
                    }
                } while (cin.fail());
            }
            else if (s == 'N' || s == 'n') {
                swabRes = "Waiting for swab test";

                cout << "\n";

            }
            else {

            }

            if (s == 'N' || s == 'n') {

                data = name + "\n" + address + "\n" + email + "\n" + cusAge + "\n" + cusID + "\n" + cusPhone + "\n" + swabRes + "\n";

            }
            else if ((s == 'Y' || s == 'y') && result == 0) {
                data = name + "\n" + address + "\n" + email + "\n" + cusAge + "\n" + cusID + "\n" + cusPhone + "\n" + swabRes + "\n" + outcome + "\n" + date + "\n";
            }
            else if ((s == 'Y' || s == 'y') && result > 0) {
                data = name + "\n" + address + "\n" + email + "\n" + cusAge + "\n" + cusID + "\n" + cusPhone + "\n" + swabRes + "\n" + outcome + "\n" +
                    location + "\n" + status + "\n" + dateStat + "\n";
            }
            else {

            }

            insertAfter(head, data);
        }
        //delete
        else if (o == 'd' || o == 'D') {
            cout << "Select data to delete" << endl;
            cin >> searchData;

            switch (searchData)
            {
            case 1:
                deleteNode(&head, arr[0]);
                break;
            case 2:
                deleteNode(&head, arr[1]);
                break;
            case 3:
                deleteNode(&head, arr[2]);
                break;
            case 4:
                deleteNode(&head, arr[3]);
                break;
            case 5:
                deleteNode(&head, arr[4]);
                break;
            case 6:
                deleteNode(&head, arr[5]);
                break;
            case 7:
                deleteNode(&head, arr[6]);
                break;
            case 8:
                deleteNode(&head, arr[7]);
                break;
            case 9:
                deleteNode(&head, arr[8]);
                break;
            case 10:
                deleteNode(&head, arr[9]);
                break;
            case 11:
                deleteNode(&head, arr[10]);
                break;
            case 12:
                deleteNode(&head, arr[11]);
                break;
            case 13:
                deleteNode(&head, arr[12]);
                break;
            case 14:
                deleteNode(&head, arr[13]);
                break;
            default:
                cout << "No Data" << "\n";
                break;
            }

            cout << "\n";
        }
        else {

        }

        cout << "Yes to access menu or no to end program?(Y/N)" << endl;
        cin >> m;

        cout << "\n";

        if (m == 'N' || m == 'n') {
            continue;
        }

    } while (m == 'Y' || m == 'y');
}
