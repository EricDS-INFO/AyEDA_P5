#pragma once
#include "vector_t.hpp"


template <class KEY>
void shell_sort(Vector_T<KEY>& keys, int size)
{
    int pos, delta;
    bool flag;
    KEY temp;

    delta = size;

    while (delta > keys.start() + 1)
    {
        delta = delta / 2;
        delta_sort(delta, keys, size);
        
    }
}

template <class KEY>
void delta_sort(int delta, Vector_T<KEY>& keys, int size)
{
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

    }
}