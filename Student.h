#ifndef __Student
#define __Student

namespace example
{
    class Student
    {
    public:
        std::string name;
        int roll_no;
        int physics_marks, maths_marks, chemistry_marks;
    public:
        void search_report(int n);
        void show_report();
        void menus();
    };
}
#endif