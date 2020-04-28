#pragma once
#include "vector_t.hpp"


template <class KEY>
void shell_sort(Vector_T<KEY>& keys, int size , bool simulate = true)
{
    int pos, delta;
    bool flag;
    KEY temp;

    delta = size;

    while (delta > keys.start())
    {
        delta = delta / 2;
        delta_sort(delta, keys, size, simulate);
        
    }
    

    
}

template <class KEY>
void delta_sort(int delta, Vector_T<KEY>& keys, int size , bool simulate = true)
{    
    if (simulate)
    {
        std::cout << "δ: "<< delta << "\n";
    }
    for (int i = delta; i <= keys.end(); i++)
    {
        KEY temp = keys[i];
        int j = i;

        while (((j - keys.start() ) >= delta) && (temp < keys[j - delta ]))
        {
            keys[j] = keys[j - delta ];
            j = j - delta;
        }
        keys[j] = temp;
        if (simulate)
        {  
            for (int k = keys.start(); k <= keys.end(); k++)
            {
                if (keys[k] == keys[i] || (keys[k] == keys[i - delta + keys.start()]))
                    std::cout << "\033[1;36m";
                std::cout << "| [" << k << "]" << keys[k];
                std::cout << "\033[1;0m";
            }
            std::cout << " |";
            int c;
            getchar();
        }
    }
}