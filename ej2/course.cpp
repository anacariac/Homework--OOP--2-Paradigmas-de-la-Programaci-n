#include "COURSE.hpp"
#include <iostream>
#include <algorithm>

Course::Course(string name): courseName(name){}

bool Course::IsComplete(){return Students.size() == 20;}

size_t Course::getCapacity() {return capacity;}

string Course::getCoursename(){return courseName;}
bool Course::IsRegistered(int file){
    for(const auto& student: Students){
        if(student->getFile() == file){
            return true;
        }
    }
    return false;
}

void Course::RegisterStudent(shared_ptr<Student> student){
    if(IsComplete()) runtime_error("Capacidad máxima alcanzada.");
    if(IsRegistered(student->getFile())) throw runtime_error("Estudiante ya inscripto.");
    
    Students.push_back(student);
    student->addCourse(courseName, -1);
}

void Course::NoRegisterStudent(int file){
    if(!IsRegistered(file)) throw runtime_error("Estudiante no registrado.");

    for(auto student = Students.begin(); student != Students.end(); ++student){
        if((*student)->getFile() == file){ 
            Students.erase(student);
            return;
        }
    }
   
}

void Course::addCoursetoStudent(int file, string course, double note) {
    if(!IsRegistered(file)) throw runtime_error("El estudiante no está registrado en el curso.");
    for (const auto& student : Students) {
        if (student->getFile() == file) {
            student->addCourse(course, note);
            return;
        }
    }
}

void Course::PrintSorted(){
    sort(Students.begin(),Students.end(),[](const shared_ptr<Student>& s1, const shared_ptr<Student>& s2){
        return s1->getName() < s2->getName();
    });

    for(const auto& student : Students){
        cout<< *student <<endl;
    }
}
