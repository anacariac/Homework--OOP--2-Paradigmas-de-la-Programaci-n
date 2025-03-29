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

    void addCurse(string course, double note);
    string getName();
    int getFile();
    double getScore();
    vector<pair<string,double>> getCourses();
    bool operator<(const Student& other);
    friend ostream& operator<<(ostream& os, Student& student);
};

class Course{
private:
    vector<shared_ptr<Student>> Students;
    const size_t capacity = 20;

public:
    Course();

    bool IsComplete();
    void RegisterStudent(shared_ptr<Student> student, string course , double note);
    void NoRegisterStudent(int file);
    bool IsRegistered(int file);
    void PrintSorted();

};

void Test();