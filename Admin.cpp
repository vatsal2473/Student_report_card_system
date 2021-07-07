#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>

#include "Admin.h"
#include "Menu.h"
using namespace std;

namespace example
{
    Menu menu;
    void Admin::admin()
    {
    p:
        system("cls");
        int choice;
        cout << "\n\n\t\t Admin Panel ";
        cout << "\n\n 1. Create Student Report Card";
        cout << "\n\n 2. Edit Student Report Card";
        cout << "\n\n 3. Search Student Report Card";
        cout << "\n\n 4. Show all Student Report Card";
        cout << "\n\n 5. Delete Student Report Card";
        cout << "\n\n 6. Go Back";
        cout << "\n\n Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            create_report();
            break;
        case 2:
            edit_report();
            break;
        case 3:
            search_report(0);
            break;
        case 4:
            show_report();
            break;
        case 5:
            delete_report();
            break;
        case 6:
            menu.menu();
            break;
        }
        getch();
        goto p;
    }

    void Admin::create_report()
    {
        system("cls");
        fstream file;
        int found = 0;
        int r;
        int p, c, m;
        char n[50];
        cout << "\n\n\t\tCreate Student Report";
        cout << "\n\n Roll no : ";
        cin >> roll_no;
        cout << "\n\n Name : ";
        cin >> name;
        cout << "\n\n Marks in Physics out of 100 : ";
        cin >> physics_marks;
        cout << "\n\n Marks in Chemistry out of 100 : ";
        cin >> chemistry_marks;
        cout << "\n\n Marks in Maths out of 100 : ";
        cin >> maths_marks;
        file.open("report.txt", ios::in);
        if (!file)
        {
            file.open("report.txt", ios::app | ios::out);
            file << "\n"
                 << roll_no << " " << name << " " << physics_marks << " " << chemistry_marks << " " << maths_marks << "\n";
            file.close();
            cout << "\n\n Student Report Created !";
            //no_of_reports++;
        }
        else
        {
            file >> r >> n >> p >> c >> m;
            while (!file.eof())
            {
                if (r == roll_no)
                {
                    found++;
                }
                file >> r >> n >> p >> c >> m;
            }
            file.close();
            if (found == 1)
            {
                cout << "\n\n Student Report already exist !";
            }
            else
            {
                file.open("report.txt", ios::app | ios::out);
                file << "\n"
                     << roll_no << " " << name << " " << physics_marks << " " << chemistry_marks << " " << maths_marks << "\n";
                file.close();
                cout << "\n\n Student Report Created !";
                //no_of_reports++;
            }
        }
    }

    void Admin::edit_report()
    {
        int r;
        system("cls");
        cout << "\n\nEnter Roll no of student whose record you want to edit : ";
        cin >> r;
        ifstream file;
        int check = 0;
        file.open("report.txt");
        ofstream file1;
        file1.open("new.txt");

        file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        while (!file.eof())
        {
            if (roll_no != r)
            {
                file1 << "\n"
                      << roll_no << " " << name << " " << physics_marks << " " << chemistry_marks << " " << maths_marks << "\n";
            }
            else
            {
                int r1, p, c, m;
                char n[50];
                cout << "\n Enter new roll no of the Student : ";
                cin >> r1;
                cout << "\n Name : ";
                cin >> n;
                cout << "\n\n Marks in Physics : ";
                cin >> p;
                cout << "\n\n Marks in Chemistry : ";
                cin >> c;
                cout << "\n\n Marks in Maths : ";
                cin >> m;
                file1 << "\n"
                      << r1 << " " << n << " " << p << " " << c << " " << m << "\n";
                check = 1;
            }

            file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        }

        if (check == 1)
        {
            cout << "\n Student record edited ! ";
        }
        else
        {
            cout << "\n Student with roll no " << r << " does not exist !";
        }

        file.close();
        file1.close();

        if (remove("report.txt") != 0)
        {
            //cout << "\nfile not removed !";
        }
        else
        {
            //cout << "\nfile removed !";
        }

        if (rename("new.txt", "report.txt"))
        {
            //cout << "\nfile not renamed !";
        }
        else
        {
            //cout << "\nfile renamed !";
        }
    }

    void Admin::search_report(int n)
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

    void Admin::show_report()
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

    void Admin::delete_report()
    {
        int r;
        system("cls");
        cout << "\n\nEnter Roll no of student you want to delete : ";
        cin >> r;
        ifstream file;
        file.open("report.txt");
        ofstream file1;
        file1.open("new.txt");

        file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        while (!file.eof())
        {
            if (roll_no != r)
            {
                file1 << "\n"
                      << roll_no << " " << name << " " << physics_marks << " " << chemistry_marks << " " << maths_marks << "\n";
            }
            else
            {
                cout << "\nRecord deleted !";
            }

            file >> roll_no >> name >> physics_marks >> chemistry_marks >> maths_marks;
        }
        file.close();
        file1.close();

        if (remove("report.txt") != 0)
        {
            //cout << "\nfile not removed !";
        }
        else
        {
            //cout << "\nfile removed !";
        }

        if (rename("new.txt", "report.txt"))
        {
            //cout << "\nfile not renamed !";
        }
        else
        {
            //cout << "\nfile renamed !";
        }
    }

}
