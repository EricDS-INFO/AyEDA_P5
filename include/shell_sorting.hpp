#pragma once
#include "vector_t.hpp"


template <class KEY>
void shell_sort(Vector_T<KEY>& keys, int size)
{
    int pos, delta;
    bool flag;
    KEY temp;

    delta = size;

    while (delta > 1)
    {
        delta = delta / 2;
        delta_sort(delta, keys, size);
    }
}

template <class KEY>
void delta_sort(int delta, Vector_T<KEY>& keys, int size)
{
    for (int i = delta; i < size; i++)
    {
        KEY temp = keys[i];
        int j = i;
        while ((j >= delta) && (temp < keys[j - delta]))
        {
            keys[j] = keys[j - delta];
            j = j - delta;
        }
        keys[j] = temp;

    }
}