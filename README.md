# ESTE REPOSITORIO CONTIENE LA QUINTA PRÁCTICA DE AyEDA.
*( Implementación de métodos de ordenación)*
***
## Resumen:

  xxxxxxRESUMIR ENUNCIADOxxxxxx

## Contenido:
**En el include:**
 

**En el src:**
- [Implementación de la clase de clave DNI](./src/dni.cpp)

**En el tests:**
- [Fichero de unión de los test](./tests/includer.test.cpp)

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

## funciones del makefile 

- make       :arrow_right: compila el fichero fuente básico solicitado
> genera el ejecutable como "runner" 
- make test  :arrow_right: compila los test
> genera el ejecutable como "test_runner". Si se ejecuta con "-s" se despliegan todos 
> los test
- make clean :arrow_right: eliminar ejecutables

