#pragma once
#include "vector_t.hpp"

template <class KEY>
void bubble_sort(Vector_T<KEY>& keys, int size)
{   bool modified;
    do
    {    
        modified = false;
        for (int j = keys.start(); j <= keys.end() - 1; ++j)
        {
            if (keys[j] > keys[j + 1])
            {
                KEY aux = keys[j];
                keys[j] = keys[j + 1];
                keys[j + 1] = aux;
                modified = true;
            }

        }
    }while (modified);
    
}