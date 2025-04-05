#include <vector>
#include <string>
#include <memory>
#include "COURSE.hpp"

//Entre todos los cursos que estan en el vector de Cursos, encuentra el curso que estas buscando dado el nombre del mismo
shared_ptr<Course> FindCourse(vector<shared_ptr<Course>>& allCourses, const string& name);

//Pruebas predeterminadas
void Test(vector<shared_ptr<Course>>& AllCourses, Course course);