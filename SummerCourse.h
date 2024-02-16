

#ifndef Registration_SUMMERCOURSE_H
#define Registration_SUMMERCOURSE_H
#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;
class SummerCourse:public Course{
public:
    SummerCourse():Course(){}
    SummerCourse(string n, int level, int hours):Course(n,level,hours)
    {
        code = n + "_S" + to_string(level);
    }
};
#endif //Registration_SUMMERCOURSE_H
