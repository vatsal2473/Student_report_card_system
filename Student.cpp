#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>

#include "Student.h"
#include "Menu.h"
using namespace std;

namespace example
{
    Menu menu0;
    void Student::menus()
    {
    p:
        system("cls");
        int choice;
        cout << "\n\n\t\t Student Panel";
        cout << "\n\n 1. Student Result";
        cout << "\n\n 2. Class Result";
        cout << "\n\n 3. Go Back";
        cout << "\n\n Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            search_report(1);
            break;
        case 2:
            show_report();
            break;
        case 3:
            menu0.menu();
            break;
        default:
            cout << "\n\nInvalid Choice...Please Try Again";
            break;
        }
        getch();
        goto p;
    }

    void Student::search_report(int n)
    {
        system("cls");
        int r, check = 0;
        if (n == 0)
            cout << "Enter the roll no of the student : ";
        else if (n == 1)
            cout << "Enter Your Roll no : ";
        cin >> r;
        ifstream file;
        file.open("report.txt");

        file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        while (!file.eof())
        {
            if (roll_no == r)
            {
                cout << "\n"
                     << setw(75) << "Student Name       : " << name;
                cout << "\n"
                     << setw(75) << "Marks in Physics   : " << physics_marks;
                cout << "\n"
                     << setw(75) << "Marks in Chemistry : " << chemistry_marks;
                cout << "\n"
                     << setw(75) << "Marks in Maths     : " << maths_marks;
                cout << "\n"
                     << setw(75) << "Total              : " << (physics_marks + chemistry_marks + maths_marks) << "/300";
                double percentage = (physics_marks + chemistry_marks + maths_marks) / 3;
                cout << "\n"
                     << setw(75) << "Percentage         : " << percentage << "%";
                check = 1;
            }

            file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        }

        if (check == 0)
        {
            cout << "\n Student with roll no " << r << " does not exist !";
        }
    }

    void Student::show_report()
    {
        system("cls");
        ifstream file;
        file.open("report.txt");

        file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        cout << "\n #==================================================#\n";
        cout << " # R.No       Name        P   C   M   total    %age #" << endl;
        cout << " #==================================================#\n";

        while (!file.eof())
        {
            int len = name.size();
            cout << " # " << roll_no << "          " << name;
            for (int i = 1; i <= 12 - len; i++)
            {
                cout << " ";
            }
            cout << physics_marks << "  " << chemistry_marks << "  " << maths_marks << "  " << (physics_marks + chemistry_marks + maths_marks) << "/300"
                 << "  " << (physics_marks + chemistry_marks + maths_marks) / 3 << "%"
                 << "  #" << endl;
            cout << " #==================================================#\n";
            file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        }
    }
}