#include <iostream>
#include <iomanip>
#include "Course.h"
#include "NormalCourse.h"
#include "SummerCourse.h"
#include "Student.h"
#include "GeneralStudent.h"
#include "SpecialStudent.h"
using namespace std;
static Course* courses [] = {new NormalCourse("Math", 1, 2),
                             new NormalCourse("Programming_1", 1, 3),
                             new NormalCourse("Technical_Writing", 1, 3),
                             new NormalCourse("Electronics", 2, 4),
                             new NormalCourse("Data_Structures", 2, 3),
                             new NormalCourse("OOP", 2, 3),
                             new NormalCourse("Algorithms", 3, 2),
                             new NormalCourse("Operating_Systems", 3, 3),
                             new NormalCourse("Databases", 3, 3),
                             new NormalCourse("Machine_Learning", 4, 3),
                             new NormalCourse("Compilers", 4, 4),
                             new NormalCourse("Programming_Concepts", 4, 4),
                             new SummerCourse("Math", 1, 2),
                             new SummerCourse("Compilers", 4, 4),
                             new SummerCourse("Algorithms", 3, 2),
                             new SummerCourse("OOP", 2, 3)};
Course* searchcourse(string code){
    for(int i=0;i<16;i++){
        if(courses[i]->getcode()==code){
            return courses[i];
        }
    }
    return nullptr;
}
int main()
{
    int num_of_students;
    int student_type;
    string student_name;
    string student_ID;
    int student_level;
    int num_of_courses;
    string course_code;
    int course_grade;

    cout<<"enter total number of students: ";
    cin>>num_of_students;
    Student* student_list[num_of_students];
    for(int i=0;i<num_of_students;i++){

        while (true){
            cout<<"enter student type (0: general, 1: special): ";
            cin>>student_type;
            if (student_type==0||student_type==1){
                break;
            }
            else{
                cout<<"invalid choice"<<endl;
            }
        }
        if(student_type==0){
            student_list[i]= new general_student;
        }
        else if(student_type==1){
            student_list[i]=new special_student;
        }
        else{
            cout<<"invalid choice";
        }
        cout<<"enter name: ";
        cin.ignore();
        getline(cin,student_name);
        student_list[i]->setSname(student_name);

        cout<<"enter ID: ";
        cin>>student_ID;
        student_list[i]->setID(student_ID);
        cout<<"enter student level: ";
        cin>>student_level;
        student_list[i]->setlevel(student_level);
        while(true){
            cout<<"Number of courses to be registered: ";
            cin>>num_of_courses;
            if(num_of_courses<=6&&num_of_courses>0){
                break;}
            else{
                cout<<"invalid number of courses"<<endl;
            }
        }



        cout<<"courses to be registered: "<<endl;
        double *grades=student_list[i]->getGrades();
        for(int j=0;j<num_of_courses;j++){
            cout<<"course "<<j+1<<": "<<endl;
            cout<<"enter course code: " << endl;
            cin>>course_code;
            Course* course= searchcourse(course_code);
            if(course == nullptr){
                cout << "This course doesn't exist"<<endl;
                continue;
            }
            if (course->get_minstudent_level()>student_level){
                cout<<"You cannot register in this course"<<endl;
                continue;
            }

            student_list[i]->Register_Course(course);
            cout<<"enter grade: " << endl;
            cin>>course_grade;
            grades[student_list[i]->getnumCourses()-1]=course_grade;


        }
        student_list[i]->setgrades(grades);

    }

    for(int i=0;i<num_of_students;i++){
        cout<<"student name: ";
        cout<<student_list[i]->getSname()<<endl;
        cout<<"student ID: ";
        cout<<student_list[i]->getID()<<endl;
        cout<<"student level: ";
        cout<<student_list[i]->getlevel()<<endl;
        student_list[i]->printRegisteredCourses();
        cout<<"overall GPA: ";
        cout<<fixed << setprecision(1) << student_list[i]->get_total_gpa()<<endl;
        cout<<"expenses="<<student_list[i]->calculate_Expenses()<<"EGP"<<endl;

    }

    return 0;
}

