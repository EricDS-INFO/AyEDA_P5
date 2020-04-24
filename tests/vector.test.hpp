#include "../include/catch/catch.h"
#include <iostream>

#include "../include/vector_t.hpp"

SCENARIO("Testing the relative vector", "[vector]")
{
    GIVEN( "A negative vector" )
    {
        Vector_T<int> my_vector(5,-2);
        WHEN( "started the elements" )
        {
            for (int i = my_vector.start(); i <= my_vector.end(); i++)
            {
                my_vector[i] = i;
            }
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 5);
                CHECK(my_vector.start() == -2);
                CHECK(my_vector.end()   ==  2);
                std::cout << my_vector << "\n";
            }
        }
    }

    GIVEN( "A positive vector" )
    {
        Vector_T<int> my_vector(5,2);
        WHEN( "started the elements" )
        {
            for (int i = my_vector.start(); i <= my_vector.end(); i++)
            {
                my_vector[i] = i;
            }
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 5);
                CHECK(my_vector.start() == 2);
                CHECK(my_vector.end()   ==  6);
                std::cout << my_vector << "\n";
            }
        }
        AND_WHEN("pushed an element")
        {
            my_vector.push_back(9);
            THEN( "Size increased by 1 and  and end is modified" )
            {
                CHECK(my_vector.size()  == 6);
                CHECK(my_vector.start() == 2);
                CHECK(my_vector.end()   ==  7);
                std::cout << my_vector << "\n";
            }
        }
    }

}