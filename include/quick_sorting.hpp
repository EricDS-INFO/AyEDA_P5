#pragma once
#include "vector_t.hpp"


template <class KEY>
void quick_sort(Vector_T<KEY>& keys, int start, int end)
{
    int s = start ; 
    int e = end ;
    int pivot = keys[(s + e)/2] ;
    while (s <= e)
    {
        while (keys[s] < pivot) s++ ;
        while (keys[e] > pivot) e-- ;
        if (s <= e) 
        {
            std::swap(keys[s], keys[e]) ;
            s++ ;
            e-- ;
        } 
    } 
    if (start < e) 
        quick_sort(keys, start, e) ;
    if (s < end) 
        quick_sort(keys, s, end) ;
}

