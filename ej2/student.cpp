#include "STUDENT.hpp"
#include <iostream>
#include <algorithm>

Student::Student(string n, int f): name(n),file(f) {}

Student::Student(string n, int f, vector<pair<string, double>> c) : name(n), file(f), courses(c) {}

string Student::getName() {return name;}

int Student::getFile() {return file;}

vector<pair<string,double>> Student::getCourses() {return courses;}

double Student::getScore(){
    if(courses.empty()) return 0.0;

    size_t  finishedCourses =0;
    double sum = 0.0;
    for(const auto& course : courses){
        if(course.second == -1) continue;
        sum += course.second;
        finishedCourses += 1;
    }

    return (finishedCourses > 0) ? sum / finishedCourses : 0.0; // Evita dividir por 0
}

void Student::addCourse(string curse, double note){
    courses.push_back({curse,note});
}

bool Student::operator<(const Student& other){
    return name < other.name;
}

ostream& operator<<(ostream& os, Student& student){
    os<< "Nombre: "<< student.getName()<< ", Legajo: "<< student.getFile();
    os<<", Cursos: ";
    for(const auto& course : student.getCourses()){
        if(course.second == -1) continue;
        os<<"["<<course.first <<":"<<course.second<<"]";
    }
    os<<", Promedio General: "<< student.getScore();
    return os;
}