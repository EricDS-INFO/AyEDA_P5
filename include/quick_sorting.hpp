#pragma once
#include "vector_t.hpp"


template <class KEY>
void quick_sort(Vector_T<KEY>& keys, int start, int end, bool simulate = false)
{
    int s = start ; 
    int e = end ;
    int pivot = keys[(s + e)/2] ;

    if (simulate)
    {
        for (int i = keys.start(); i <= keys.end(); i++)
        {

            if(i <= e && i >= s)
                std::cout << "\033[1;36m";
            if(keys[i] == pivot) 
                std::cout << "\033[1;31m";
            std::cout<<"| ["<< i <<"]"<< keys[i];
            std::cout << "\033[1;0m";
        }     
        std::cout << " |\tPivote: " << pivot;
        int c;
        c=getchar();
    }

    while (s <= e)
    {
        while (keys[s] < pivot) s++;
        while (keys[e] > pivot) e--;
        if (s <= e) 
        {
            if(keys[s] == keys[e]);

            std::swap(keys[s], keys[e]);
            s++;
            e--;
        } 
        
    }
    if (start < e)
        quick_sort(keys, start, e, simulate);
    if (s < end)
        quick_sort(keys, s, end, simulate);     
}