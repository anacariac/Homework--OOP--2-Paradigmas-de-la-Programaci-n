## Homework 2 - Paradigmas de Programación

---

## **Ejercicio 1 - Clase TIME**
### **Descripción**
Se implementa una clase `Time` que representa un horario en formato de 12 horas con indicador de `a.m.` o `p.m.`. Se proveen múltiples constructores y validaciones para asegurar que los datos sean válidos.

### **Implementación**
- Constructores con distintos parámetros: sin parámetros, solo hora, hora y minutos, etc.
- Validación de rangos: horas [1–12], minutos y segundos [0–59].
- Métodos para obtener y modificar cada campo (`get` y `set`).
- Métodos para imprimir el tiempo en formato 12h (`a.m./p.m.`) y 24h.
- Interacción con el usuario: ingresar datos y mostrar resultados.

### **Cómo ejecutarlo**
- g++ ej1.cpp -Wall -o ejecutable.exe
- valgrind ./ejecutable.exe

---

## **Ejercicio 2 - Sistema de Cursos y Estudiantes**
### **Descripción**
Este ejercicio implementa un sistema de inscripción a cursos, utilizando clases `Student` y `Course`. Los cursos mantienen una lista de smart pointers a estudiantes.

### **Implementación**
#### Clase `Student`
- Atributos: nombre completo, legajo, vector de cursos y notas.
- Métodos: obtener promedio, asignar nota, mostrar datos.

#### Clase `Course`
- Atributos: nombre del curso, lista de `shared_ptr<Student>`.
- Capacidad máxima de 20 estudiantes.
- Métodos: inscribir, desinscribir, verificar inscripción por legajo, verificar si está lleno.
- Imprime la lista de estudiantes ordenada alfabéticamente (`std::sort`).
- Sobrecarga de `operator<` y `operator<<`.
- Copia profunda de cursos (manteniendo referencias compartidas a estudiantes).

### **Diseño**
- Relación entre clases: el curso contiene estudiantes mediante `shared_ptr`, permitiendo compartirlos entre cursos sin duplicarlos.
- La copia de un curso es profunda (`deep copy` del objeto `Course`), pero los estudiantes siguen siendo los mismos (`shallow copy` de los objetos `Student`).
- Se han implementado funciones auxiliares que permiten optimizar el main().
- Los estudiantes que se alojan en las pruebas predeterminadas no van a aparecer una vez que empiece el do-while, dado que se encuentran en scopes distintos.

### **Cómo ejecutarlo**
- g++ ej2.cpp student.cpp course.cpp funcionesaux.cpp -Wall -o ejecutable.exe
- valgrind ./ejecutable.exe

---

## **Ejercicio 3 - Interfaz Numérica: Integer, Real y Complex**
### **Descripción**
Este ejercicio crea una jerarquía de clases que modelan números: `Integer`, `Real`, `Complex`, todos derivados de una interfaz abstracta `Number`. Permiten realizar operaciones entre sí usando polimorfismo.

### **Implementación**
#### Clase base `Number`
- Métodos virtuales puros: `Addition`, `Subtration`, `Multiplication`, `Division`, `toString`.

#### Clases derivadas:
- `Integer`: encapsula un `int`.
- `Real`: encapsula un `double`.
- `Complex`: encapsula parte real e imaginaria (`double`).

### **Funcionamiento**
- Todas las operaciones devuelven `shared_ptr<Number>`.
- Se usa `dynamic_pointer_cast` para manejar operaciones entre distintos tipos (ej: sumar `Integer` con `Real`).
- `toString()` devuelve la representación adecuada del número.

### **Cómo ejecutarlo**
- g++ ej3.cpp integer.cpp real.cpp complex.cpp -Wall -o ejecutable.exe
- valgrind ./ejecutable.exe

---

## **Ejercicio 4 - Sistema Bancario: Cuenta, CajaDeAhorro y CuentaCorriente**
### **Descripción**
Se desarrolla un sistema bancario con una clase abstracta `Cuenta` y dos clases derivadas: `CajaDeAhorro` y `CuentaCorriente`. Se utilizan métodos virtuales, herencia y clases amigas (`friend`).

### **Implementación**
#### Clase `Cuenta`
- Atributos: nombre del titular, saldo.
- Métodos: `depositar`, `retirar` (virtual puro), `mostrarInfo` (virtual puro).

#### Clase `CajaDeAhorro`
- No permite sobregiros.
- Penaliza con $20 luego de 2 llamados a `mostrarInfo()`.
- Lleva un contador interno.

#### Clase `CuentaCorriente`
- Permite sobregiros si hay una `CajaDeAhorro` asociada.
- Usa `friend` para acceder al saldo de la caja de ahorro.
- Si no hay saldo en ninguna cuenta, no permite retirar.

### **Notas sobre el diseño**
- Se utiliza encapsulamiento: atributos `private`, interfaz pública.
- La relación de amistad (`friend`) solo se usa donde es estrictamente necesaria (entre cuentas).
- Las penalizaciones y transferencias están automatizadas.

### **Cómo ejecutarlo**
- g++ ej4.cpp CuentaBancaria.cpp CajadeAhorro.cpp CuentaCorriente.cpp -Wall -o ejecutable.exe
- valgrind ./ejecutable.exe

---
