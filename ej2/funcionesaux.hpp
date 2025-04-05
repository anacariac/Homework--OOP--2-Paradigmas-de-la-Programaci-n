#include <vector>
#include <string>
#include <memory>
#include "COURSE.hpp"


shared_ptr<Course> FindCourse(vector<shared_ptr<Course>>& allCourses, const string& name);

void Test(vector<shared_ptr<Course>>& AllCourses, Course course);