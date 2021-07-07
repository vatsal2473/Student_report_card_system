#ifndef __admin
#define __admin
#include<string>
namespace example
{
    class Admin
    {   
    public:
        std::string name;
        int roll_no;
        int physics_marks, maths_marks, chemistry_marks;
        void admin();
        void create_report();
        void edit_report();
        void search_report(int n);
        void show_report();
        void delete_report();
    };
    
    
}
#endif