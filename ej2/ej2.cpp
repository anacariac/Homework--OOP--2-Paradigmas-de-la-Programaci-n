#include "ej2.hpp"
#include <iostream>
#include <algorithm>

Student ::Student(string n, int f): name(n),file(f) {}

void Student::addCurse(string curse, double note){
    courses.push_back({curse,note});
}

string Student::getName() {return name;}

int Student::getFile() {return file;}

vector<pair<string,double>> Student::getCourses() {return courses;}

double Student::getScore(){
    if(courses.empty()) return 0.0;

    double sum = 0.0;
    for(const auto& course : courses){
        sum += course.second;
    }

    return sum / courses.size();
}

bool Student::operator<(const Student& other){
    return name < other.name;
}

ostream& operator<<(ostream& os, Student& student){
    os<< "Nombre: "<< student.getName()<< ", Legajo: "<< student.getFile();
    os<<", Cursos: ";
    for(const auto& course : student.getCourses()){
        os<<"["<<course.first <<":"<<course.second<<"]";
    }
    os<<", Promedio General: "<< student.getScore();
    return os;
}

Course::Course(){}

bool Course::IsComplete(){return Students.size() == 20;}

bool Course::IsRegistered(int file){
    for(const auto& student: Students){
        if(student->getFile() == file){
            return true;
        }
    }
    return false;
}

void Course::RegisterStudent(shared_ptr<Student> student,string course, double note){
    if(IsComplete()) throw runtime_error("Capacidad máxima alcanzada.");
    if(IsRegistered(student->getFile())) throw runtime_error("Estudiante ya inscripto.");

    student->addCurse(course,note);
    Students.push_back(student);
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

void Course::PrintSorted(){
    sort(Students.begin(),Students.end(),[](const shared_ptr<Student>& s1, const shared_ptr<Student>& s2){
        return s1->getName() > s2->getName();
    });

    for(const auto& student : Students){
        cout<< *student <<endl;
    }
}