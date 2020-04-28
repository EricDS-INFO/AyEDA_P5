#include <iostream>
#include <vector>
#include "../include/vector_t.hpp"
#include "../include/dni.hpp"
#include "../include/bubble_sorting.hpp"
#include "../include/heap_sorting.hpp"
#include "../include/insertion_sorting.hpp"
#include "../include/quick_sorting.hpp"
#include "../include/shell_sorting.hpp"


void simulate(int method, Vector_T<dni>& keys);
void stats(Vector_T<dni>& keys);
void initialize(Vector_T<dni>& keys);

int helpmsg(void);
int handleSimulation(std::vector<std::string>& all_args, int argc);


int main(int argc, char* argv[]) 
{   
    std::string exec_name = argv[0];
    std::vector<std::string> all_args;
    
    if (argc < 2)
    {
        std::cout << "\tError se sintaxis:\n";
        std::cout << "\tasegúrese de llamar al programa con los argumentos adecuados\n";
        std::cout << "\t( ./runner -h o ./runner --help     para más información)\n";
    
        return 1;
    }
    else
    {
        all_args.assign(argv + 1, argv + argc);
        for (int i = 0; i < all_args.size();  i++)
        {
            if (all_args[i] == "-h" || all_args[i] == "--help")  
            {
                return helpmsg();
            }
            if (all_args[i] == "-d" || all_args[i] == "--demo")
                return handleSimulation(all_args, argc);
        }
    }
    
}


void simulate(int method, Vector_T<dni>& keys)
{

        switch (method)
        {
        case 1:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN POR INSERCIÓN\n";
            insertion_sort<dni>(keys, keys.size(), true);
            break;
        case 2:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN BURBUJA\n";
            bubble_sort<dni>(keys, keys.size(), true);
            break;
        case 3:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN QUICK\n";
            quick_sort<dni>(keys, keys.start(),keys.end(), true);
            break;
        case 4:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN HEAP\n";
            heap_sort<dni>(keys, keys.size(), true);
            break;
        case 5:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN SHELL\n";
            shell_sort<dni>(keys, keys.size(), true);    
            break;
        default:
            std::cout << "\t\t\t\t\tERROR: no existe el método indicado\n";
            break;
        }
    
    std::cout << "\n\n\t\t\t\t\tFIN DE LA SIMULACIÓN\n";
    int c;
    getchar();
}

void stats(Vector_T<dni> keys)
{

}

void initialize(Vector_T<dni>& keys)
{
    
    for(int i = keys.start(); i <= keys.end(); i++)
    {
        dni aux;
        keys[i] = aux; 
    }
}

int helpmsg(void)
{
    std::cout << "\t\t---LISTA DE COMANDOS---\n\n";
    std::cout << "\t-h | --help\t\t-> mostrar este mensaje\n";
    std::cout << "\t-d | --demo\t\t-> lanzar simulación\n";
    std::cout << "\t-s | --stat\t\t-> lanzar modo estadística\n\n";
    std::cout << "\t\t---LISTA DE ARGUMENTOS---\n\n";
    std::cout << "\tPARA LA SIMULACIÓN\n\n";
    std::cout << "\t-n [value] | --size [value] \t\t-> indicar tamaño del vector\n";
    std::cout << "\t-i [value] | --init [value] \t\t-> indicar inicio del vector\n";
    std::cout << "\t--insertion \t\t-> usar algoritmo por inserción\n";
    std::cout << "\t--bubble \t\t-> usar algoritmo de la burbuja\n";
    std::cout << "\t--quick \t\t-> usar algoritmo quick sort\n";
    std::cout << "\t--heap \t\t-> usar algoritmo heap sort\n";
    std::cout << "\t--shell \t\t-> usar algoritmo shell sort\n\n";
    std::cout << "\t\t-----------------------\n\n";
    std::cout << "\t\tpulse 'enter' para salir\n\n";
    
    int c;
    getchar();
    return 0;
}


int handleSimulation(std::vector<std::string>& all_args, int argc)
{
    int avsz = 0;
    bool szflag = false;
    int avin = 0;
    bool inflag = false;
    int amtd = 0;
    bool mtdflag = false;
 
    std::cout << "\t\t\t---MODO SIMULACIÓN---\n\n";
    if (argc > 2)
    {
        for (int i = 0; i < all_args.size();  i++)
        {
            if((all_args[i] == "-n" || all_args[i] == "--size") && argc > 3)
            {
                avsz = atoi(all_args[i+1].c_str());
                szflag = true;
            }
            else if((all_args[i] == "-n" || all_args[i] == "--size") && argc < 3)
            {
                std::cout << "\n\nERROR: no ha proporcionado un tamaño\n";
                return 1;
            }


            if((all_args[i] == "-i" || all_args[i] == "--init") && argc > 3)
            {
                avin = atoi(all_args[i+1].c_str());
                inflag = true;
            }
            else if((all_args[i] == "-i" || all_args[i] == "--init") && argc < 3)
            {
                std::cout << "\n\nERROR: no ha proporcionado un índice\n";
                return 1;
            }
            
            if ((all_args[i] == "--insertion"))
            {
                amtd = 1;
                mtdflag = true;
            }
            if ((all_args[i] == "--bubble"))
            {
                amtd = 2;
                mtdflag = true;
            }
            if ((all_args[i] == "--quick"))
            {
                amtd = 3;
                mtdflag = true;
            }
            if ((all_args[i] == "--heap"))
            {
                amtd = 4;
                mtdflag = true;
            }
            if ((all_args[i] == "--shell"))
            {
                amtd = 5;
                mtdflag = true;
            }
        }
    }

    if (!szflag)
    {
        std::cout << "Introduzca el tamaño del vector: ";
        std::cin >> avsz;
    }
    if (!inflag)
    {      
        std::cout << "Introduzca el índice inicial del vector: ";
        std::cin >> avin;
    }
    if (!mtdflag)
    {
        std::cout << "\tIntroduzca el algoritmo a simular: \n";
        std::cout << "\t1: \tInserción\n";
        std::cout << "\t2: \tBurbuja\n";
        std::cout << "\t3: \tQuick\n";
        std::cout << "\t4: \tHeap\n";
        std::cout << "\t5: \tShell\n";
        std::cout << "\t> ";
        std::cin >> amtd;
    }
    getchar();
    srand(time(NULL));
    Vector_T<dni> testbench(avsz, avin);
    initialize(testbench);
    simulate(amtd, testbench);
    return 0;
}
