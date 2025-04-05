#pragma once
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Student{
    private:
        string name;
        int file;
        vector<pair<string,double>> courses;
    
    public:
        //Constructores
        Student(string n, int f);
        Student(string n, int f, vector<pair<string, double>> c);
    
        //GETTERS
        string getName();
        int getFile();
        double getScore();
        vector<pair<string,double>> getCourses();
        
        //Añade el curso con la nota final al objeto estudiante
        void addCourse(string course, double note);
        
        //Sobrecarga de operadores
        bool operator<(const Student& other);
        friend ostream& operator<<(ostream& os, Student& student);
    };