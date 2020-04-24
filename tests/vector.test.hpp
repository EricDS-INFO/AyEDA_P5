#include "../include/catch/catch.h"
#include <iostream>

#include "../include/vector_t.hpp"

SCENARIO("Testing the relative vector", "[vector]")
{
    GIVEN( "An empty vector" )
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
        my_vector.~Vector_T();
    }

    GIVEN( "A vector with defined  size and negative start" )
    {
        Vector_T<int> my_vector(5, -1);
    
        REQUIRE(my_vector.size()  == 5);
        REQUIRE(my_vector.start() == -1);
        REQUIRE(my_vector.end()   == 3);
        
        WHEN( "Added an element from the back " )
        {
            my_vector.push_back(1);
            my_vector.push_back(3);
            std::cout << my_vector << "\n";
            THEN("Size is increased and end value is modified")
            {
                CHECK(my_vector.size()  == 7);
                CHECK(my_vector.start() == -1);
                CHECK(my_vector.end()   == 5);
            }
        }

        my_vector.~Vector_T();
    }


}