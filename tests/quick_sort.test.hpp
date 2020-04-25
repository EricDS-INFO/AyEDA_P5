#include "../include/catch/catch.h"

#include <iostream>
#include <cstdlib>
#include "../include/vector_t.hpp"
#include "../include/dni.hpp"
#include "../src/dni.cpp"
#include "../include/quick_sorting.hpp"

SCENARIO( "Testing the Quick Sorting method", "[CUADRATIC]" )
{
    GIVEN( "A DNI type vector" )
    {
        Vector_T<dni> key_array;
        REQUIRE(key_array.empty());
        WHEN( "Elements inserted" )
        {
            srand(time(NULL));
            dni key_1;
            dni key_2;
            dni key_3;
            key_array.push_back(key_1);
            key_array.push_back(key_2);
            key_array.push_back(key_3);

            THEN("Size is increased")
            {
                CHECK(key_array.size() == 3);
                std::cout << "BEFORE: " << key_array << "\n";
            }
            AND_THEN("They can be sorted")
            {
                quick_sort(key_array, key_array.start(), key_array.end());
                std::cout << "AFTER: " << key_array << "\n";
            
                CHECK(key_array[0] <= key_array[1]); 
                
                CHECK(key_array[1] <= key_array[2]); 
                
                CHECK(key_array[0] <= key_array[2]);                

            }
        }
    }
}
