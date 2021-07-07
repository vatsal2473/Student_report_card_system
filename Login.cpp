#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>

#include "Login.h"
#include "Admin.h"
using namespace std;

namespace example
{
    Admin admin;
    void Login::check()
    {
        system("cls");
        string password,email;
        char ch;
        cout << "\n\n\t\t\tLogin System";
        cout << "\n\n E-mail : ";
        cin >> email;
        cout << "\n\n Password : ";
        for (int i = 1; i <= 9; i++)
        {
            ch = getch();
            password += ch;
            cout << "*";
        }
        if (email == "admin@gmail.com" && password == "admin1234")
        {
            admin.admin();
        }
        else
        {
            cout << "\n\nInvalid email or password";
        }
    }
}