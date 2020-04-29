#include <iostream>
#include <vector>
#include "../include/vector_t.hpp"
#include "../include/dni.hpp"
#include "../include/insertion_sorting.hpp"
#include "../include/selection_sorting.hpp"
#include "../include/bubble_sorting.hpp"
#include "../include/heap_sorting.hpp"
#include "../include/quick_sorting.hpp"
#include "../include/shell_sorting.hpp"


void simulate(int method, Vector_T<dni>& keys);
void stats(int size, int times);
void initialize(Vector_T<dni>& keys, bool preseed = false);

int helpmsg(void);
int handleSimulation(std::vector<std::string>& all_args, int argc);
int handleStatistics(std::vector<std::string>& all_args, int argc);

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
                return helpmsg();
            
            if (all_args[i] == "-d" || all_args[i] == "--demo")
                return handleSimulation(all_args, argc);

            if (all_args[i] == "-s" || all_args[i] == "--stat")
                return handleStatistics(all_args, argc);
        }

        std::cout << "\nERROR: Argumento no válido\n";
        return 1;
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
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN POR SELECCIÓN\n";
            selection_sort<dni>(keys, keys.size(), true);
            break;
        case 3:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN BURBUJA\n";
            bubble_sort<dni>(keys, keys.size(), true);
            break;
        case 4:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN QUICK\n";
            quick_sort<dni>(keys, keys.start(),keys.end(), true);
            break;
        case 5:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN HEAP\n";
            heap_sort<dni>(keys, keys.size(), true);
            break;
        case 6:
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

void stats(int size, int tests)
{
    int min = 100000000;
    int max = 0;
    int accum = 0;


    Vector_T<dni> aux(size, 1);
    initialize(aux, true);

    std::cout << "\n\n\n\t\t ---NUMERO DE COMPARACIONES---\n\n";   
    std::cout << "\t         \tMínimo\tMedio\tMáximo\n\n";
    for (int i = 0;  i < tests; i++)
    {
        dni::reset_c();   
        insertion_sort(aux, aux.size());
        accum += dni::nth_compare();
        
        if (dni::nth_compare() < min)
           min = dni::nth_compare();

        if (max < dni::nth_compare())
            max = dni::nth_compare();
    }
    std::cout << "\tInserción";
    std::cout << "\t" << min;
    std::cout << "\t" << accum / tests;
    std::cout << "\t" << max;
    std::cout << "\n\n";
   
    // Reset measure values
    accum = 0;
    min = 100000000;
    max = 0;
    // Reset the key secuence in the vector (we use a default seed)
    initialize(aux, true);
    for (int i = 0;  i < tests; i++)
    {
        dni::reset_c();   
        selection_sort(aux, aux.size());
        accum += dni::nth_compare();
        
        if (dni::nth_compare() < min)
           min = dni::nth_compare();

        if (max < dni::nth_compare())
            max = dni::nth_compare();
    }
    
    std::cout << "\tSelección  ";
    std::cout << "\t" << min;
    std::cout << "\t" << accum / tests;
    std::cout << "\t" << max;
    std::cout << "\n\n";

    accum = 0;
    min = 100000000;
    max = 0;
    initialize(aux, true);
    for (int i = 0;  i < tests; i++)
    {
        dni::reset_c();   
        bubble_sort(aux, aux.size());
        accum += dni::nth_compare();
        
        if (dni::nth_compare() < min)
           min = dni::nth_compare();

        if (max < dni::nth_compare())
            max = dni::nth_compare();
    }
    
    std::cout << "\tBurbuja  ";
    std::cout << "\t" << min;
    std::cout << "\t" << accum / tests;
    std::cout << "\t" << max;
    std::cout << "\n\n";
    accum = 0;
    min = 100000000;
    max = 0;
    initialize(aux, true);
     
    for (int i = 0;  i < tests; i++)
    {
        dni::reset_c();   
        quick_sort(aux, aux.start(), aux.end());
        accum += dni::nth_compare();
        if (dni::nth_compare() < min)
            min = dni::nth_compare();

        if (max < dni::nth_compare())
            max = dni::nth_compare();
    }
    
    std::cout << "\tQuick     ";
    std::cout << "\t" << min;
    std::cout << "\t" << accum / tests;
    std::cout << "\t" << max;
    std::cout << "\n\n";
    accum = 0;
    min = 100000000;
    max = 0;
    initialize(aux, true);

    for (int i = 0;  i < tests; i++)
    {
        dni::reset_c();   
        heap_sort(aux, aux.size());
        accum += dni::nth_compare();
        if (dni::nth_compare() < min)
            min = dni::nth_compare();

        if (max < dni::nth_compare())
            max = dni::nth_compare();
    }
    std::cout << "\tHeap      ";
    std::cout << "\t" << min;
    std::cout << "\t" << accum / tests;
    std::cout << "\t" << max;
    std::cout << "\n\n";
    accum = 0;
    min = 100000000;
    max = 0;
    initialize(aux, true);
    for (int i = 0;  i < tests; i++)
    {
        dni::reset_c();   
        shell_sort(aux, aux.size());
        accum += dni::nth_compare();
        if (dni::nth_compare() < min)
            min = dni::nth_compare();

        if (max < dni::nth_compare())
            max = dni::nth_compare();
    }
    std::cout << "\tShell     ";
    std::cout << "\t" << min;
    std::cout << "\t" << accum / tests;
    std::cout << "\t" << max;
    std::cout << "\n\n";
   
    
}

void initialize(Vector_T<dni>& keys, bool preseed )
{
    
    for(int i = keys.start(); i <= keys.end(); i++)
    {
        if (preseed)
            srand(i);   
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
    std::cout << "\t--insertion \t\t\t\t-> usar algoritmo por inserción\n";
    std::cout << "\t--selection \t\t\t\t-> usar algoritmo por selección\n";
    std::cout << "\t--bubble \t\t\t\t-> usar algoritmo de la burbuja\n";
    std::cout << "\t--quick \t\t\t\t-> usar algoritmo quick sort\n";
    std::cout << "\t--heap  \t\t\t\t-> usar algoritmo heap sort\n";
    std::cout << "\t--shell \t\t\t\t-> usar algoritmo shell sort\n\n";

    std::cout << "\tPARA LAS ESTADÍSTICAS\n\n";
    std::cout << "\t-n [value] | --size [value] \t\t-> indicar tamaño del vector\n";
    std::cout << "\t-t [value] | --times [value] \t\t-> el número de repeticiones\n";

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
            if ((all_args[i] == "--selection"))
            {
                amtd = 2;
                mtdflag = true;
            }
            if ((all_args[i] == "--bubble"))
            {
                amtd = 3;
                mtdflag = true;
            }
            if ((all_args[i] == "--quick"))
            {
                amtd = 4;
                mtdflag = true;
            }
            if ((all_args[i] == "--heap"))
            {
                amtd = 5;
                mtdflag = true;
            }
            if ((all_args[i] == "--shell"))
            {
                amtd = 6;
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

int handleStatistics(std::vector<std::string>& all_args, int argc)
{
    int avs = 0;
    bool sizeflag = false;
    int avt = 0;
    bool timesflag = false;
 
    std::cout << "\n\n\n\t\t\t---MODO ESTADÍSTICA---\n\n";
    if (argc > 2)
    {
        for (int i = 0; i < all_args.size();  i++)
        {
            if((all_args[i] == "-n" || all_args[i] == "--size") && argc > 3)
            {
                avs = atoi(all_args[i+1].c_str());
                sizeflag = true;
            }
            else if((all_args[i] == "-n" || all_args[i] == "--size") && argc < 3)
            {
                std::cout << "\n\nERROR: no ha proporcionado un tamaño\n";
                return 1;
            }


            if((all_args[i] == "-t" || all_args[i] == "--times") && argc > 3)
            {
                avt = atoi(all_args[i+1].c_str());
                timesflag = true;
            }
            else if((all_args[i] == "-i" || all_args[i] == "--init") && argc < 3)
            {
                std::cout << "\n\nERROR: no ha proporcionado un índice\n";
                return 1;
            }
            
        }
    }

    if (!sizeflag)
    {
        std::cout << "Introduzca el tamaño del vector: ";
        std::cin >> avs;
    }
    if (!timesflag)
    {      
        std::cout << "Introduzca el número de veces que se ejecuta cada método: ";
        std::cin >> avt;
    }
    stats(avs, avt);
    return 0;

}