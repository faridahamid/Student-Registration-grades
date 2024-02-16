

#ifndef Registration_NORMALCOURSE_H
#define Registration_NORMALCOURSE_H
#include <iostream>
#include "Course.h"
using namespace std;
class NormalCourse:public Course{
public:
    NormalCourse():Course(){}
    NormalCourse(string n, int level, int hours): Course(n,level,hours)
    {
        code = n + "_N" + to_string(level);
    }
};
#endif //Registration_NORMALCOURSE_H
