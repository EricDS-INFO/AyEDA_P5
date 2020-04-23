#pragma once
#include "vector_t.hpp"

template <class KEY>
void bubble_sort(Vector_T<KEY>& keys, int size)
{
    for (int i = 0; i < size -1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (keys[j] > keys[j + 1])
            {
                KEY aux = keys[j];
                keys[j] = keys[j + 1];
                keys[j + 1] = aux;
            }

        }
    }
}