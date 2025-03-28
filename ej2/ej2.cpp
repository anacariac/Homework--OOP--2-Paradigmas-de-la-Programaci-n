#include "ej2.hpp"
#include <iostream>
#include <algorithm>

void Test(){
    Course course;
    int op;
    size_t file;
    string name, courseName;
    double grade;

    do {
        cout << "\nMenú:\n1. Inscribir estudiante\n2. Desinscribir estudiante\n3. Verificar si un estudiante está inscripto\n4. Imprimir lista de estudiantes ordenada\n5. Añadir curso y nota a un estudiante\n6. Salir\nSeleccione una opción: ";
        cin>> op;

        try {
            switch (op) {
                case 1:
                    if (course.IsComplete()) {
                        cout << "El curso está lleno."<<endl;
                        break;
                    }
                    cout << "Ingrese el nombre del estudiante: "<<endl;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Ingrese el legajo: "<<endl;
                    cin >> file;
                    cout << "Ingrese el nombre del curso: "<<endl;
                    getline(cin, courseName);
                    cout << "Ingrese la nota final del curso: "<<endl;
                    cin >> grade;
                    course.RegisterStudent(make_shared<Student>(name, file));
                    cout << "Estudiante inscripto correctamente."<<endl;
                    break;
                case 2:
                    cout << "Ingrese el legajo del estudiante a desinscribir: "<<endl;
                    cin >> file;
                    course.NoRegisterStudent(file);
                    cout << "Estudiante eliminado correctamente."<<endl;
                    break;
                case 3:
                    cout << "Ingrese el legajo: "<<endl;
                    cin >> file;
                    cout << (course.IsRegistered(file) ? "El estudiante está inscripto.\n" : "No está inscripto.\n")<<endl;
                    break;
                case 4:
                    course.PrintSorted();
                    break;
                case 5:
                cout << "Ingrese el legajo del estudiante: "<<endl;
                cin >> file;
                if (!course.IsRegistered(file)) {
                    cout << "El estudiante no está inscripto."<<endl;
                    break;
                }
                cout << "Ingrese el nombre del nuevo curso: "<<endl;
                cin.ignore();
                getline(cin, courseName);
                cout << "Ingrese la nota final del curso: "<<endl;
                cin >> grade;

                course.addCoursetoStudent(file, courseName, grade);
                cout << "Curso añadido correctamente."<<endl;
                break;
                case 6:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opción inválida.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (op != 6);
}

Student ::Student(string n, int f): name(n),file(f) {}

void Student::addCourse(string curse, double note){
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

void Course::RegisterStudent(shared_ptr<Student> student){
    if(IsComplete()) throw runtime_error("Capacidad máxima alcanzada.");
    if(IsRegistered(student->getFile())) throw runtime_error("Estudiante ya inscripto.");
    
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

int main(){
    Test();
    return 0;
}