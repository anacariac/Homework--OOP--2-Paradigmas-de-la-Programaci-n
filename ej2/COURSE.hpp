#pragma once
#include "STUDENT.hpp"

class Course{
    private:
        string courseName;
        vector<shared_ptr<Student>> Students;
        const size_t capacity = 20;
    
    public:
        //Constructores
        Course(string name);
        Course(const Course& other);

        bool IsComplete();//Verifica si el curso está lleno
        void RegisterStudent(shared_ptr<Student> student);//Inscribe al estudiante
        void NoRegisterStudent(int file);//Desinscribe al estudiante
        bool IsRegistered(int file) const;// Verifica si está el estudiante en el curso
        void PrintSorted();//Imprime a los alumnos ordenados alfabéticamente
        void addCoursetoStudent(int file, string course, double note);//Añade el curso con la nota al estudiante

        //GETTERS
        size_t getCapacity();
        string getCoursename() const;
    
    };