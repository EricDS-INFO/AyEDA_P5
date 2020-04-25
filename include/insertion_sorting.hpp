#pragma once
#include "./vector_t.hpp"

template <class KEY> 
void insertion_sort (Vector_T<KEY>& keys, int size)
{
    for (int i = keys.start() + 1; i <= keys.end(); i++)
    {
        int pos = i;
        KEY value = keys[i];
        while ((pos > keys.start()) && (value < keys[pos -1]))
        {
            keys[pos] = keys[pos -1];
            pos--;
        }
        keys[pos] = value;
    }
    
};

