# ESTE REPOSITORIO CONTIENE LA QUINTA PRÁCTICA DE AyEDA.
*( Implementación de métodos de ordenación)*
***
## Resumen:

  xxxxxxRESUMIR ENUNCIADOxxxxxx

## Contenido:
**En el include:**
- [Plantilla de función del algoritmo de Inserción](./include/insertion_sorting.hpp)
- [Plantilla de función del algoritmo Burbuja](./include/bubble_sorting.hpp)
- [Plantilla de función del algoritmo Quick Sort](./include/quick_sorting.hpp)
- [Plantilla de función del algoritmo Heap Sort](./include/heap_sorting.hpp)
- [Plantilla de función del algoritmo Shell Sort](./include/shell_sorting.hpp)

- [Definición de la clase DNI](./include/dni.hpp)
- [Plantilla de clase Vector](./include/vector_t.hpp)

**En el modif:**

**En el src:**
- [Implementación de la clase de clave DNI](./src/dni.cpp)
- [Implementación del programa principal](./src/sorting_main.cpp)

**En el tests:**
- [Fichero de unión de los test](./tests/includer.test.cpp)
- [Tests de la clase vector](./tests/vector.test.hpp)
- [Test de ordenación por Inserción](./tests/insertion.test.hpp)
- [Test de ordenación Burbuja](./tests/bubble.test.hpp)
- [Test de ordenación Quick](./tests/quick_sort.test.hpp)
- [Test de ordenación Heap ](./tests/heap_sort.test.hpp)
- [Test de ordenación Shell ](./tests/shell_sort.test.hpp)

## Dependencias

- [Catch2](https://github.com/catchorg/Catch2)
  > Librería de testing para C++ con BDD
  
  
  **Para instalarla:**
  ```BASH
    ~$ git clone https://github.com/catchorg/Catch2.git 
    ~$ cd Catch2 
    ~$ cmake -Bbuild -H. -DBUILD_TESTING=OFF 
    ~$ sudo cmake --build build/ --target install
  ```
## Integración
  - [Travis-CI](https://travis-ci.org/)
> Se integra automáticamente el proyecto al hacer un "push" al remoto
> Se ejecutan automáticamente los test y se comprueba su compilación.

Se especifica su uso en el [archivo de configuraciones](.travis.yml)

## funciones del makefile 

- make       :arrow_right: compila el fichero fuente básico solicitado
> genera el ejecutable como "runner" 
- make test  :arrow_right: compila los test
> genera el ejecutable como "test_runner". Si se ejecuta con "-s" se despliegan todos 
> los test
- make clean :arrow_right: eliminar ejecutables

