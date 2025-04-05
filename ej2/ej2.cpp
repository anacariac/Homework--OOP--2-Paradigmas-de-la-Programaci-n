#include "COURSE.hpp"
#include "STUDENT.hpp"
#include "funcionesaux.hpp"
#include <iostream>
#include <algorithm>


int main(){
    vector<shared_ptr<Course>> AllCourses;
    string courseName = "Matemática";
    Course course(courseName);
    AllCourses.push_back((make_shared<Course>(courseName)));
    
    Test(AllCourses,course);
    
    int op;
    double grade;
    size_t file;
    string name;
    shared_ptr<Course> selected = nullptr;

    do {
        cout << "\nMenú:\n1. Inscribir estudiante\n2. Desinscribir estudiante\n3. Verificar si un estudiante está inscripto\n4. Imprimir lista de estudiantes ordenada\n5. Salir\nSeleccione una opción: ";
        cin>> op;

        try {
            switch (op) {
                case 1:
                    cout << "Ingrese el nombre del estudiante: "<<endl;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Ingrese el legajo: "<<endl;
                    cin >> file;
                    cout << "Ingrese el nombre del curso: "<<endl;
                    cin.ignore();
                    getline(cin, courseName);
                    selected = FindCourse(AllCourses, courseName);
                    if (selected && selected->IsRegistered(file)) {
                        cout << "El estudiante ya está inscripto en el curso." << endl;
                        break;
                    }
                    
                    if (!selected) {
                        selected = make_shared<Course>(courseName);
                        AllCourses.push_back(selected);
                    }                    
                    if (selected->IsComplete()) {
                        cout << "El curso está lleno." << endl;
                        break;
                    }
                    cout << "Ingrese la nota final del curso: " << endl;
                    cin >> grade;
                    selected->RegisterStudent(make_shared<Student>(name, file));
                    selected->addCoursetoStudent(file, courseName, grade);
                    cout << "Estudiante inscripto correctamente." << endl;
                    break;
                case 2:
                    cout << "Ingrese el nombre del curso de donde quiere desinscribir al estudiante: "<<endl;
                    cin.ignore();
                    getline(cin, courseName);
                    cout << "Ingrese el legajo del estudiante a desinscribir: "<<endl;
                    cin >> file;
                    selected = FindCourse(AllCourses, courseName);
                    if (selected) {
                        selected->NoRegisterStudent(file);
                        cout << "Estudiante eliminado correctamente." << endl;
                    } else {
                        cout << "No se encontró el curso mencionado." << endl;
                    }
                    break;
                case 3:
                    cout << "Ingrese el legajo: "<<endl;
                    cin >> file;
                    for (auto& c: AllCourses) {
                        cout << ((*c).IsRegistered(file) ? "El estudiante está inscripto.\n" : "No está inscripto.\n")<<"En "<<(*c).getCoursename()<<endl;
                        }
                    break;
                case 4:
                    for (auto& c: AllCourses) {
                        cout << "Curso: " << (*c).getCoursename() << endl;
                        (*c).PrintSorted();
                    }                
                    break;
                case 5:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opción inválida.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (op != 5);
    return 0;
}