#include "funcionesaux.hpp"
#include <iostream>
using namespace std;

void Test(vector<shared_ptr<Course>>& AllCourses, Course course){
    // Llenar el curso hasta el máximo permitido
    for (size_t i = 1; i <= course.getCapacity(); ++i) {
        string name = "Estudiante" + to_string(i);
        if (i < 10) name = "Estudiante0" + to_string(i);  // Asegura nombres con formato uniforme

        course.RegisterStudent(make_shared<Student>(name, i));
    }

    cout << "\nIntentando inscribir a otro estudiante cuando el curso está lleno:\n";
    if (course.IsComplete()) {
        cout << "\nEl curso está lleno. No se puede inscribir más estudiantes.\n";
    } else {
        course.RegisterStudent(make_shared<Student>("Extra", 999));
    }

    // Pruebas de funciones
    cout << "\n--- Pruebas de funciones ---\n";

    // 1. Verificar inscripción
    size_t fileToCheck = 3;
    cout << "\nVerificando inscripción de estudiante con legajo " << fileToCheck << ": "
         << (course.IsRegistered(fileToCheck) ? "Inscripto.\n" : "No inscripto.\n");

    // 2. Eliminar estudiante
    size_t fileToRemove = 2;
    cout << "\nEliminando estudiante con legajo " << fileToRemove << ".\n";
    course.NoRegisterStudent(fileToRemove);

    // 3. Imprimir lista ordenada
    cout << "\nLista de estudiantes ordenada:\n";
    course.PrintSorted();

    // 4. Añadir curso y nota a un estudiante
    size_t fileToAddCourse = 1;
    Course course2 = Course("Inglés");
    AllCourses.push_back(make_shared<Course>(course2));
    double grade = 8.5;
    cout << "Añadiendo curso '" << course2.getCoursename() << "' con nota " << grade << " al estudiante con legajo " << fileToAddCourse << ".\n";
    course.addCoursetoStudent(fileToAddCourse, course2.getCoursename(), grade);

    // 5. Reimprimir lista para ver los cambios
    cout << "\nLista de estudiantes después de añadir curso:\n";
    course.PrintSorted();

    //6. Copiar el curso usando el constructor de copia
    Course copiedCourse = course;  // se invoca el Course(const Course& other)

    // Mostrar ambos cursos
    cout << "\nCurso original:\n";
    course.PrintSorted();

    cout << "\nCurso copiado:\n";
    copiedCourse.PrintSorted();

    // Modificar un estudiante del original
    course.addCoursetoStudent(1, "Física", 9.0);

    // Ver si eso afecta al curso copiado
    cout << "\nDespués de modificar el estudiante en el curso original:\n";

    cout << "\nCurso original:\n";
    course.PrintSorted();

    cout << "\nCurso copiado:\n";
    copiedCourse.PrintSorted();
    // Este es un ejemplo de copia superficial de los estudiantes,
    // ya que los shared_ptr se copian pero comparten el mismo objeto.
    // Si modificamos el estudiante original, también se verá en el copiado.
    cout << "\nFin de pruebas predeterminadas.\n";
    
}

shared_ptr<Course> FindCourse(vector<shared_ptr<Course>>& allCourses, const string& name){
    for (auto& c : allCourses) {
        if ((*c).getCoursename() == name)
            return c;
    }
    return nullptr;
}