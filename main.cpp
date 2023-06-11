#include<iostream>
#include<fstream>// file handling 
#include<cstring>// Salary slip  
#include<string>
#include<ctime> // for pause time (for login) 
#include<conio.h>// for _getch()(press enter to continue)
#include<Windows.h>// for sleep() command (Login animation)
using namespace std;
string centre_allign = "\t\t\t\t\t";
fstream outfile;
fstream index;
int i = -1; //index
string space = " ";

struct Employee {
    string Fname;
    string Lname;
    string Fullname = " ";
    int id = 0;
    string Designation = " ";
    int age = 0;
    float salaray = 0;// Per Hour Pay
    int WH = 0;//Working Hours
};
Employee info[20];

void pause(int dur)//pause duration(status:ok/working)
{
    time_t temp = time(NULL) + dur;
    while (temp > time(NULL));
}
void input()
{
    fstream outfile;
    fstream index;
    char ans = 'y';
    do
    {
        i++;
        if (i < 20)
        {
            cout << centre_allign << "=====" << "Employee Number : " << i + 1 << "======";
            cout << "\n" << centre_allign << "----------------------------------------";
            cout << "\n" << centre_allign << "=>Enter First Name of Employee: ";
            cin >> info[i].Fname;
            cout << "\n" << centre_allign << "----------------------------------------";
            cout << "\n" << centre_allign << "=>Enter Last Name of Employee: ";
            cin >> info[i].Lname;
            info[i].Fullname = info[i].Fname + space + info[i].Lname;
            cout << "\n" << centre_allign << "----------------------------------------";
            cout << "\n" << centre_allign << "=>Enter Employee ID: ";
            cin >> info[i].id;
            cout << "\n" << centre_allign << "----------------------------------------";
            cout << "\n " << centre_allign << "=>Enter Designation: ";
            cin.ignore();
            getline(cin, info[i].Designation);
            cout << "\n" << centre_allign << "----------------------------------------";
            cout << "\n" << centre_allign << "=>Enter Employee Age: ";
            cin >> info[i].age;
            cout << "\n" << centre_allign << "----------------------------------------";
            cout << "\n" << centre_allign << "=>Enter Employee Pay per Hour: ";
            cin >> info[i].salaray;
            cout << "\n" << centre_allign << "----------------------------------------";
            system("cls");
        }
        else
        {
            cout << centre_allign << "You Have Reached Maximum Inputs";
            cout << centre_allign << "Press Enter to Return back to Menu" << endl;
            (void)_getch();
            break;
        }
        cout << centre_allign << "===================================================================" << endl;
        cout << centre_allign << "=> Do you want to add another empolyee('Y' for Yes * 'N' for No):";
        cin >> ans;
        system("cls");

    } while (ans == 'Y' || ans == 'y' || ans == 'yes' || ans == 'Yes' || ans == 'YES');
}
void display()
{
    system("cls");
    cout << "\n" << centre_allign << "\t           List of Employees\n";
    cout << "\n" << centre_allign << "----------------------------------------------------------------------------";
    cout << "\n" << centre_allign << " NAME           |     ID        |     DESIGNATION        \t| Pay pr Hour\n";
    cout << centre_allign << "-----------------------------------------------------------------------------\n";
    for (int t = 0; t <= i; t++)
    {
        cout << centre_allign << "" << t + 1 << ")" << info[t].Fullname << "\t|\t" << info[t].id << "\t|\t" << info[t].Designation << "\t\t|\t" << info[t].salaray << endl;
    }
    cout << centre_allign << "Press Enter to Continue" << endl;
    (void)_getch();
}
void update()
{
    bool found = false;
    int cid;
    system("cls");
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "               UPDATE MENU                   " << endl;
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "=>Enter Employee ID:";
    cin >> cid;
    for (int t = 0; t <= i; t++)
    {
        if (cid == info[t].id)
        {
            found = true;
            system("cls");
            int choice;
            cout << centre_allign << "=============================================" << endl;
            cout << centre_allign << "              UPDATE MENU                   " << endl;
            cout << centre_allign << "=============================================" << endl;
            cout << centre_allign << "=> 1:  Update Employee ID" << endl;
            cout << centre_allign << "=> 2:  Update Name of Employee" << endl;
            cout << centre_allign << "=> 3:  Update Age of Employee" << endl;
            cout << centre_allign << "=> 4:  Change Designation of Employee" << endl;
            cout << centre_allign << "=> 5:  Change Pay Rate of Employee" << endl;
            cout << centre_allign << "=> 6:  GO BACK" << endl;
            cout << centre_allign << "INPUT:";
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
            {
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "=>Current Employee ID:" << info[t].id << endl;
                cout << centre_allign << "=>Enter New  Employee ID:";
                cin >> info[t].id;
                cout << centre_allign << "ID is Sucessfully Updated!!" << " against Employee id:" << info[t].id << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
                break;
            }
            case 2:
            {

                string space = " ";
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "=>Current Employee ID:" << info[t].Fullname << endl;
                cout << "\n" << centre_allign << "----------------------------------------";
                cout << "\n" << centre_allign << "=>Enter First Name of Employee: ";
                cin >> info[t].Fname;
                //cin.ignore();
                //getline(cin, info[i].Fullname);
                cout << "\n" << centre_allign << "----------------------------------------";
                cout << "\n" << centre_allign << "=>Enter Last Name of Employee: ";
                cin >> info[t].Lname;
                info[t].Fullname = info[t].Fname + space + info[t].Lname;
                cout << centre_allign << "Name is Sucessfully Updated!!" << " against Employee id:" << info[t].id << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
                break;

            }
            case 3:
            {
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "=>Current Employee AGE:" << info[t].age << endl;
                cout << centre_allign << "=>Enter New Employee AGE:";
                cin >> info[t].age;
                cout << centre_allign << "AGE is Sucessfully Updated!!" << " against Employee id:" << info[t].id << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
                break;
            }
            case 4:
            {
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "=>Current Employee Designation:" << info[t].Designation << endl;
                cout << centre_allign << "=>Enter New Employee Designation:";
                cin.ignore();
                getline(cin, info[t].Designation);
                cout << centre_allign << "Designation is sucessfully Updated!!" << " against Employee id:" << info[t].id << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
                break;
            }
            case 5:
            {
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "=>Current Pay rate per hour:" << info[t].salaray << endl;
                cout << centre_allign << "=>Enter New Pay rate per hour:";
                cin >> info[t].salaray;
                cout << centre_allign << "Pay rate is sucessfully Updated!!" << " against Employee id:" << info[t].id << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
                break;
            }
            case 6:
                break;
            default:
                cout << centre_allign << "---------------------------------------------" << endl;
                cout << centre_allign << "Invalid Choice" << endl;
                cout << centre_allign << "---------------------------------------------" << endl;
                pause(2);
                break;
            }
        }
    }
    if (found == false)
    {
        cout << centre_allign << "---------------------------------------------" << endl;
        cout << centre_allign << "Invalid Employee ID" << endl;
        cout << centre_allign << "---------------------------------------------" << endl;
        pause(2);
    }
}
void Search()
{
    system("cls");
    int IDsrch, AGEsrch, Salarysrch;
    string namesrch, desigsrch;
    bool found;
    found = false;
    int choice;
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "           Employee Search MENU             " << endl;
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "=> 1:  Search with respect to ID" << endl;
    cout << centre_allign << "=> 2:  Search with respect to Name" << endl;
    cout << centre_allign << "=> 3:  Search with respect to Designation" << endl;
    cout << centre_allign << "=> 4:  Search with respect to Age" << endl;
    cout << centre_allign << "=> 5:  Search with respect to PayRate" << endl;
    cout << centre_allign << "=> 6:  GO BACK" << endl;
    cout << centre_allign << "INPUT:";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "=>Enter Employee ID:";
        cin >> IDsrch;
        for (int t = 0; t <= i; t++)
        {
            if (IDsrch == info[t].id)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
        }
        if (found == false)
        {
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Invalid Employee ID" << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            pause(2);
        }
        break;
    case 2:
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "=>Enter Employee Name:";
        cin.ignore();
        getline(cin, namesrch);
        for (int t = 0; t <= i; t++)
        {
            if (info[t].Fullname == namesrch)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
            if (info[t].Fname == namesrch)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
            if (info[t].Lname == namesrch)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
        }
        if (found == false)
        {
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Invalid Employee Name" << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            pause(2);
        }
        break;
    case 3:
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "=>Enter Employee Designation:";
        cin >> desigsrch;
        for (int t = 0; t <= i; t++)
        {
            if (info[t].Designation == desigsrch)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
        }
        if (found == false)
        {
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Invalid Employee Designation" << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            pause(2);
        }
        break;
    case 4:
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "=>Enter Employee AGE:";
        cin >> AGEsrch;
        for (int t = 0; t <= i; t++)
        {
            if (info[t].age == AGEsrch)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
        }
        if (found == false)
        {
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Invalid Employee AGE" << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            pause(2);
        }
        break;
    case 5:
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "Enter Employee Salary:";
        cin >> Salarysrch;
        for (int t = 0; t <= i; t++)
        {
            if (info[t].salaray == Salarysrch)
            {
                found = true;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "    Employee Detial's     " << endl;
                cout << centre_allign << "==========================" << endl;
                cout << centre_allign << "Employee ID:" << info[t].id << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Name:" << info[t].Fullname << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "AGE:" << info[t].age << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Designation:" << info[t].Designation << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                cout << centre_allign << "--------------------------" << endl;
                cout << centre_allign << "Press Enter to Continue" << endl;
                (void)_getch();
            }
        }
        if (found == false)
        {
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Invalid Employee Salary" << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            pause(2);
        }
        break;
    case 6:
        break;
    default:
        cout << centre_allign << "---------------------------------------------" << endl;
        cout << centre_allign << "Invalid Employee INPUT" << endl;
        cout << centre_allign << "---------------------------------------------" << endl;
        pause(2);
        break;
    }
}
void Deleteheheh()
{

    int del_id;
    bool found = false;
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "=>Enter Employee ID:";
    cin >> del_id;
    for (int t = 0; t <= i; t++)
    {
        if (del_id == info[t].id)
        {
            int z;
            found = true;
            for (z = t; z < 18; z++)
            {
                info[z].id = info[z + 1].id;
                info[z].Fullname = info[z + 1].Fullname;
                info[z].age = info[z + 1].age;
                info[z].salaray = info[z + 1].salaray;
                info[z].Designation = info[z + 1].Designation;
            }
            info[z + 1].id = NULL;
            info[z + 1].Fullname = "";
            info[z + 1].age = NULL;
            info[z + 1].salaray = NULL;
            info[z + 1].Designation = "";
            cout << centre_allign << "Employee detail's Sucessfully Deleted !!" << endl;
            i--;
            cout << centre_allign << "Press Enter to Continue" << endl;
            (void)_getch();
        }

    }
    if (found == false)
    {
        cout << centre_allign << "---------------------------------------------" << endl;
        cout << centre_allign << "Invalid Employee ID" << endl;
        cout << centre_allign << "---------------------------------------------" << endl;
        pause(2);
    }
}
void workinghours()
{
    bool found = false;
    int WH_id, WH;
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "=> Enter Employee ID:";
    cin >> WH_id;
    for (int t = 0; t <= i; t++)
    {
        if (WH_id == info[t].id)
        {
            found = true;
            cout << centre_allign << "--------------------------" << endl;
            cout << centre_allign << "=> Enter Working Hour:";
            cin >> WH;
            info[t].WH = WH;
            cout << centre_allign << "Working Hour Sucessfully Added !!" << endl;
            cout << centre_allign << "Press Enter to Continue" << endl;
            (void)_getch();
        }
    }
    if (found == false)
    {
        cout << centre_allign << "---------------------------------------------" << endl;
        cout << centre_allign << "Invalid Employee ID" << endl;
        cout << centre_allign << "---------------------------------------------" << endl;
        pause(2);
    }
}
void displaySslip(float theNetPay)
{
    bool found = false;
    int idsslip;
    cout << centre_allign << "=============================================" << endl;
    cout << centre_allign << "Enter Employee ID:";
    cin >> idsslip;
    for (int t = 0; t <= i; t++)
    {
        if (idsslip == info[t].id)
        {
            found = true;
            system("cls");
            cout << centre_allign << "=============================================" << endl;
            cout << centre_allign << "            " << info[t].Fullname << "'s Salary Slip " << endl;
            cout << centre_allign << "=============================================" << endl;
            cout << centre_allign << "Employee Name: " << info[t].Fullname << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Hours Worked: " << info[t].WH << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Pay Rate: " << info[t].salaray << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            float netPay = info[t].salaray * info[t].WH;
            cout << centre_allign << "Net Pay: " << netPay << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            float benefits = netPay * 0.1f;
            cout << centre_allign << "Additional Benefits: \n\n" << centre_allign << "Insurance: 10% of your net pay: " << benefits << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            if (info[t].Designation == "CEO" || info[t].Designation == "ceo") {
                cout << centre_allign << "Special benefit for CEO: Extra 20% off on meals" << endl;
                cout << centre_allign << "---------------------------------------------" << endl;
                float special_benefit = netPay * 0.2f;
                cout << centre_allign << "Special Benefit (Maximum discount): " << special_benefit << endl;
                cout << centre_allign << "---------------------------------------------" << endl;
                benefits += special_benefit;
            }
            else {
                cout << centre_allign << "No additional benefits for this designation" << endl;
                cout << centre_allign << "---------------------------------------------" << endl;
            }

            float gst = netPay * 0.13f;
            cout << centre_allign << "G.S.T 13%: " << gst << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            float finalPay = netPay - gst + benefits;
            cout << centre_allign << "Final Pay: " << netPay << " - " << gst << " + " << benefits << " = " << finalPay << endl;
            cout << centre_allign << "---------------------------------------------" << endl;
            cout << centre_allign << "Press Enter to Continue" << endl;
            (void)_getch();

        }

    }
    if (found == false)
    {
        cout << centre_allign << "---------------------------------------------" << endl;
        cout << centre_allign << "Invalid Employee ID" << endl;
        cout << centre_allign << "---------------------------------------------" << endl;
        pause(2);
    }
}
int option()
{
    float theNetPay = 0;
    char ans = 'y';
    do
    {

        system("cls");
        ofstream index;
        int choice;
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "           HR MANAGEENT SYSTEM MENU             " << endl;
        cout << centre_allign << "=============================================" << endl;
        cout << centre_allign << "=> 1:  ADD NEW EMPLOYEE" << endl;
        cout << centre_allign << "=> 2:  VIEW ALL EMPLOYEE" << endl;
        cout << centre_allign << "=> 3:  Update Employee STATUS" << endl;
        cout << centre_allign << "=> 4:  Search Employee Detail's" << endl;
        cout << centre_allign << "=> 5:  Delete Employee Detail's" << endl;
        cout << centre_allign << "=> 6:  ADD Working Hours " << endl;
        cout << centre_allign << "=> 7:  Display Salary slip" << endl;
        cout << centre_allign << "=> 8:  Return To Login Page" << endl;
        cout << centre_allign << "=> 9:  Quit To Desktop" << endl;
        cout << centre_allign << "INPUT:";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            display();
            break;
        case 3:
            update();
            break;
        case 4:
            Search();
            break;
        case 5:
            Deleteheheh();
            break;
        case 6:
            workinghours();
            break;
        case 7:
            displaySslip(theNetPay);
            break;
        case 8:
            return 0;
            break;
        case 9:
            outfile.open("employee_info.txt", ios::out | ios::trunc);
            outfile.close();
            for (int t = 0; t <= i; t++)
            {
                outfile.open("employee_info.txt", ios::out | ios::app);
                outfile << info[t].Fname << ' ' << info[t].Lname << ' ' << info[t].id << ' ' << info[t].Designation << ' ' << info[t].age << ' ' << info[t].salaray << ' ' << info[t].WH << endl;
                outfile.close();
            }
            index.open("index.txt", ios::out);
            index << i;
            index.close();
            exit(0);
            break;
        default:
            cout << centre_allign << "Invalid Input" << endl;
            cout << centre_allign << "Returning to Menu!! Please Wait" << endl;
            pause(3);
            break;
        }

    } while (ans == 'y');
    return NULL;
}
int employeesection()
{
    ofstream index("index.txt");
    char ans = 'y';
    bool ok = false;
    int emp_id;
    cout << centre_allign << "============================================" << endl;
    cout << centre_allign << "           Employee's Portal                " << endl;
    cout << centre_allign << "============================================" << endl;
    cout << centre_allign << "=> Enter Ur Employee ID:";
    cin >> emp_id;
    for (int t = 0; t <= i; t++)
    {
        if (emp_id == info[t].id)
        {
            ok = true;
            cout << centre_allign << "Welcome To the Portal Mr/Mr.s " << info[t].Fullname << "!!" << endl;
            do
            {
                system("cls");
                int choice;
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "              Employee's Menu                " << endl;
                cout << centre_allign << "=============================================" << endl;
                cout << centre_allign << "=> 1:  Your Total Working Hours" << endl;
                cout << centre_allign << "=> 2:  Your Personal Information" << endl;
                cout << centre_allign << "=> 3:  Your SalarySlip" << endl;
                cout << centre_allign << "=> 4:  Update your Personal Information" << endl;
                cout << centre_allign << "=> 5:  Return to Login Page" << endl;
                cout << centre_allign << "INPUT:";
                cin >> choice;
                system("cls");
                switch (choice)
                {
                case 1:
                    system("cls");
                    cout << centre_allign << "=============================================" << endl;
                    cout << centre_allign << "     " << info[t].Fullname << "'s Working Hours    " << endl;
                    cout << centre_allign << "=============================================" << endl;
                    cout << centre_allign << "Employee ID: " << info[t].id << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    cout << centre_allign << "Hours Worked: " << info[t].WH << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    cout << centre_allign << "Press Enter to Continue" << endl;
                    (void)_getch();
                    break;
                case 2:
                    system("cls");
                    cout << centre_allign << "==========================" << endl;
                    cout << centre_allign << "    Employee Detial's     " << endl;
                    cout << centre_allign << "==========================" << endl;
                    cout << centre_allign << "Employee ID:" << info[t].id << endl;
                    cout << centre_allign << "--------------------------" << endl;
                    cout << centre_allign << "Name:" << info[t].Fullname << endl;
                    cout << centre_allign << "--------------------------" << endl;
                    cout << centre_allign << "AGE:" << info[t].age << endl;
                    cout << centre_allign << "--------------------------" << endl;
                    cout << centre_allign << "Designation:" << info[t].Designation << endl;
                    cout << centre_allign << "--------------------------" << endl;
                    cout << centre_allign << "Pay per Hour:" << info[t].salaray << endl;
                    cout << centre_allign << "--------------------------" << endl;
                    cout << centre_allign << "Press Enter to Continue" << endl;
                    (void)_getch();
                    break;
                case 3:
                {
                    system("cls");
                    cout << centre_allign << "=============================================" << endl;
                    cout << centre_allign << "            Salary Slip                      " << endl;
                    cout << centre_allign << "=============================================" << endl;
                    cout << centre_allign << "Employee Name: " << info[t].Fullname << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    cout << centre_allign << "Hours Worked: " << info[t].WH << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    cout << centre_allign << "Pay Rate: " << info[t].salaray << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    float netPay = info[t].salaray * info[t].WH;
                    cout << centre_allign << "Net Pay: " << netPay << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    float benefits = netPay * 0.1f;
                    cout << centre_allign << "Additional Benefits: \n\n" << centre_allign << "Insurance: 10% of your net pay: " << benefits << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    if (info[t].Designation == "CEO" || info[t].Designation == "ceo") {
                        cout << centre_allign << "Special benefit for CEO: Extra 20% off on meals" << endl;
                        cout << centre_allign << "---------------------------------------------" << endl;
                        float special_benefit = netPay * 0.2f;
                        cout << centre_allign << "Special Benefit (Maximum discount): " << special_benefit << endl;
                        cout << centre_allign << "---------------------------------------------" << endl;
                        benefits += special_benefit;
                    }
                    float gst = netPay * 0.13f;
                    cout << centre_allign << "G.S.T 13%: " << gst << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;
                    float finalPay = netPay - gst + benefits;
                    cout << centre_allign << "Final Pay: " << netPay << " - " << gst << " + " << benefits << " = " << finalPay << endl;
                    cout << centre_allign << "---------------------------------------------" << endl;

                    cout << centre_allign << "Press Enter to Continue" << endl;
                    (void)_getch();
                    break;
                }


                case 4:
                    int choice;
                    cout << centre_allign << "=============================================" << endl;
                    cout << centre_allign << "              UPDATE MENU                   " << endl;
                    cout << centre_allign << "=============================================" << endl;
                    cout << centre_allign << "=> 1:  Update Your Name" << endl;
                    cout << centre_allign << "=> 2:  Update Your Age" << endl;
                    cout << centre_allign << "=> 3:  GO BACK" << endl;
                    cout << centre_allign << "INPUT:";
                    cin >> choice;
                    system("cls");
                    switch (choice)
                    {
                    case 1:
                    {

                        string space = " ";
                        cout << centre_allign << "=============================================" << endl;
                        cout << centre_allign << "=>Your Current Name:" << info[t].Fullname << endl;
                        cout << "\n" << centre_allign << "----------------------------------------";
                        cout << "\n" << centre_allign << "=>Enter First Name of Employee: ";
                        cin >> info[t].Fname;
                        cout << "\n" << centre_allign << "----------------------------------------";
                        cout << "\n" << centre_allign << "=>Enter Last Name of Employee: ";
                        cin >> info[t].Lname;
                        info[t].Fullname = info[t].Fname + space + info[t].Lname;
                        cout << centre_allign << "Your Name is Sucessfully Updated!!" << " To" << info[t].Fullname << endl;
                        break;
                    }
                    case 2:
                    {
                        int temp = info[t].age;
                        cout << centre_allign << "=============================================" << endl;
                        cout << centre_allign << "=>Your Current AGE:" << info[t].age << endl;
                        cout << centre_allign << "=>Enter Your New AGE:";
                        cin >> info[t].age;
                        cout << centre_allign << "AGE is Sucessfully Updated!!" << " from:" << temp << " To:" << info[t].age << endl;
                        cout << centre_allign << "Press Enter to Continue" << endl;
                        (void)_getch();
                        break;
                    }
                    case 3:
                        break;
                    default:
                        cout << centre_allign << "Invalid INPUT" << endl;
                        cout << "Returning To Main Menu!! Please Wait" << endl;
                        pause(3);
                        break;
                    }
                    break;
                case 5:
                    return 0;
                    break;
                default:
                    cout << centre_allign << "Invalid Input" << endl;
                    cout << centre_allign << "Returning To Main Menu!! Please Wait" << endl;
                    pause(3);
                    break;
                }
            } while (ans == 'y');
        }
    }
    if (ok == false)
    {
        cout << "\n" << centre_allign << " Invalid Employee ID Or You Are not registered in the System!!" << endl;
        cout << "\n" << centre_allign << " Press Enter to Go Back" << endl;
        (void)_getch();
    }
    return NULL;
}
int HRlog(int& atempt)//status:completed --login attempts left 
{
    string pass = "";
    char ch;
    cout << centre_allign << "============================================" << endl;
    cout << centre_allign << "              HR MANAGEMENT SYSTEM          " << endl;
    cout << centre_allign << "============================================" << endl;
    cout << "\n\n\n\n";
    cout << centre_allign << "=>Enter Your Password :";
    ch = _getch();
    while (ch != 13) {//character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl;
    if (pass == "pass")
    {
        cout << "\n\n\n" << centre_allign << "LOADING \n" << centre_allign;
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\n\n" << centre_allign << "Access Granted!! \n\n\n";
        pause(1);
        system("CLS");
        option();
    }
    else
    {
        if (atempt > 4)
        {
            cout << "\n" << centre_allign << "You Entered Wrong Password More than 5 times!!" << endl;
            cout << "\n" << centre_allign << "Try Again Later" << endl;
            cout << "\n" << centre_allign << "Exiting Program" << endl;
            pause(1);
            outfile.open("employee_info.txt", ios::out | ios::trunc);
            outfile.close();
            for (int t = 0; t <= i; t++)
            {
                outfile.open("employee_info.txt", ios::out | ios::app);
                outfile << info[t].Fname << ' ' << info[t].Lname << ' ' << info[t].id << ' ' << info[t].Designation << ' ' << info[t].age << ' ' << info[t].salaray << ' ' << info[t].WH << endl;
                outfile.close();
            }
            index.open("index.txt", ios::out);
            index << i;
            index.close();
            exit(0);
        }
        else
        {
            atempt++;
            cout << "\n" << centre_allign << "Wrong Password!! \n";
            cout << "\n" << centre_allign << "Access Aborted...\n";
            cout << centre_allign << "Returing to Login Menu!!" << endl;
            pause(2);

        }

    }

    system("CLS");
    return NULL;
}
int main()
{
    index.open("index.txt", ios::in);
    index >> i;
    index.close();
    ifstream in_file;
    in_file.open("employee_info.txt", ios::in);
    string line;
    int t = 0;
    while (in_file >> info[t].Fname >> info[t].Lname >> info[t].id >> info[t].Designation >> info[t].age >> info[t].salaray >> info[t].WH)
    {
        info[t].Fullname = info[t].Fname + space + info[t].Lname;
        t++;
    }
    in_file.close();
    int atempt = 1;
    char ans = 'y';
    do
    {
        system("cls");
        int input;
        cout << centre_allign << "============================================" << endl;
        cout << centre_allign << "           HR MANAGEMENT SYSTEM             " << endl;
        cout << centre_allign << "============================================" << endl;
        cout << centre_allign << "=> 1: ADMIN                                     \n" << endl;
        cout << centre_allign << "=> 2: EMPLOYEE                                  \n" << endl;
        cout << centre_allign << "=> 3: EXIT                                      \n" << endl;
        cout << centre_allign << "INPUT:";
        cin >> input;
        system("cls");
        switch (input)
        {
        case 1:
            HRlog(atempt);
            break;
        case 2:
            employeesection();
            break;
        case 3:

            outfile.open("employee_info.txt", ios::out | ios::trunc);
            outfile.close();
            for (int t = 0; t <= i; t++)
            {
                outfile.open("employee_info.txt", ios::out | ios::app);
                outfile << info[t].Fname << ' ' << info[t].Lname << ' ' << info[t].id << ' ' << info[t].Designation << ' ' << info[t].age << ' ' << info[t].salaray << ' ' << info[t].WH << endl;
                outfile.close();
            }
            index.open("index.txt", ios::out);
            index << i;
            index.close();
            exit(0);
            break;
        default:
            cout << centre_allign << "Invalid Input" << endl;
            pause(2);
            break;
        }
    } while (ans == 'y');
    return NULL;
}