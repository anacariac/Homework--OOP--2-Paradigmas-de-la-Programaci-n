#pragma once
#include "STUDENT.hpp"

class Course{
    private:
        string courseName;
        vector<shared_ptr<Student>> Students;
        const size_t capacity = 20;
    
    public:
        Course(string name);
        Course(const Course& other);

        bool IsComplete();
        void RegisterStudent(shared_ptr<Student> student);
        void NoRegisterStudent(int file);
        bool IsRegistered(int file) const;
        void PrintSorted();
        void addCoursetoStudent(int file, string course, double note);
        size_t getCapacity();
        string getCoursename() const;
    
    };