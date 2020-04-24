#include "../include/catch/catch.h"
#include <iostream>

#include "../include/vector_t.hpp"

SCENARIO("Testing the relative vector", "[vector]")
{
    
    GIVEN( "An empty vector" )
    {
        Vector_T<int> my_vector;
        REQUIRE(my_vector.empty());
        WHEN( "pushed one elemnt" )
        {
            my_vector.push_back(1);
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 1);
                CHECK(my_vector.start() == 0);
                CHECK(my_vector.end()   ==  0);
                std::cout << my_vector << "\n";
            }
        }
        AND_WHEN( "pushed two elemnts" )
        {
            my_vector.push_back(1);
            my_vector.push_back(2);
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 2);
                CHECK(my_vector.start() == 0);
                CHECK(my_vector.end()   ==  1);
                std::cout << my_vector << "\n";
            }
        }
    }

    GIVEN( "An empty negative vector" )
    {
        Vector_T<int> my_vector(0,-1);
        REQUIRE(my_vector.empty());
        WHEN( "pushed one elemnt" )
        {
            my_vector.push_back(1);
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 1);
                CHECK(my_vector.start() == -1);
                CHECK(my_vector.end()   ==  -1);
                std::cout << my_vector << "\n";
            }
        }
        AND_WHEN( "pushed two elemnts" )
        {
            my_vector.push_back(1);
            my_vector.push_back(2);
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 2);
                CHECK(my_vector.start() == -1);
                CHECK(my_vector.end()   ==  0);
                std::cout << my_vector << "\n";
            }
        }
    }
    GIVEN( "An empty positive vector" )
    {
        Vector_T<int> my_vector(0,1);
        REQUIRE(my_vector.empty());
        WHEN( "pushed one elemnt" )
        {
            my_vector.push_back(1);
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 1);
                CHECK(my_vector.start() == 1);
                CHECK(my_vector.end()   == 1);
                std::cout << my_vector << "\n";
            }
        }
        AND_WHEN( "pushed two elemnts" )
        {
            my_vector.push_back(1);
            my_vector.push_back(2);
            THEN( "Size increased by 3 and start and end" )
            {
                CHECK(my_vector.size()  == 2);
                CHECK(my_vector.start() == 1);
                CHECK(my_vector.end()   ==  2);
                std::cout << my_vector << "\n";
            }
        }
    }
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
        AND_WHEN("pushed an element")
        {   
            for (int i = my_vector.start(); i <= my_vector.end(); i++)
            {
                my_vector[i] = i;
            }
            my_vector.push_back(9);
            my_vector.push_back(9);
            THEN( "Size increased by 1 and  and end is modified" )
            {
                CHECK(my_vector.size()  == 7);
                CHECK(my_vector.start() == -2);
                CHECK(my_vector.end()   == 4);
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
            for (int i = my_vector.start(); i <= my_vector.end(); i++)
            {
                my_vector[i] = i;
            }
            my_vector.push_back(9);
            my_vector.push_back(9);
            THEN( "Size increased by 1 and  and end is modified" )
            {
                CHECK(my_vector.size()  == 7);
                CHECK(my_vector.start() == 2);
                CHECK(my_vector.end()   == 8);
                std::cout << my_vector << "\n";
            }
        }
    }

}