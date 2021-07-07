#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>

#include "Login.h"
#include "Student.h"
#include "Menu.h"
using namespace std;

namespace example
{
    Login login;
    Student student;
    void Menu::menu()
    {
    p:
        system("cls");
        int choice;
        string email, password;
        char ch;
        cout << "\n\n\t\t Student Report Card System";
        cout << "\n\n 1. Admin Login";
        cout << "\n\n 2. Student Panel";
        cout << "\n\n 3. Exit";
        cout << "\n\n Enter Your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            login.check();
            break;
        case 2:
            student.menus();
            break;
        case 3:
            system("cls");
            exit(0);
        default:
            cout << "Inavlid choice ...Please Try Again";
        }
        getch();
        goto p;
    }
}