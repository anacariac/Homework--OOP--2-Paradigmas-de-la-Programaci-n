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
        Student(string n, int f);
        Student(string n, int f, vector<pair<string, double>> c);
    
        void addCourse(string course, double note);
        string getName();
        int getFile();
        double getScore();
        vector<pair<string,double>> getCourses();
        bool operator<(const Student& other);
        friend ostream& operator<<(ostream& os, Student& student);
    };