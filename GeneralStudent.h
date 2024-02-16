

#ifndef Registration_GENERALSTUDENT_H
#define Registration_GENERALSTUDENT_H
#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;
class general_student:public Student{
public:
    general_student():Student(){

    }
    bool Register_Course(Course*course){
        if(course_number<6 && level>=course->get_minstudent_level()&& course != nullptr){
            course_list[course_number]=course;
            course_number++;
            return true;
        }
        else{
            return false;
        }
    }
    float calculate_Expenses(){
        return (level*1000);
    }


};
#endif //Registration_GENERALSTUDENT_H
