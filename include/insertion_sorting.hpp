#pragma once
#include "./vector_t.hpp"

template <class KEY> 
void insertion_sort (Vector_T<KEY>& keys, int size)
{
    for (int i = 1; i < size; i++)
    {
        int pos = i;
        KEY value = keys[i];
        while ((pos > 0) && (value < keys[pos -1]))
        {
            keys[pos] = keys[pos -1];
            pos--;
        }
        keys[pos] = value;
    }
    
};

