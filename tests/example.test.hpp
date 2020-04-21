#include "../include/catch/catch.h"


SCENARIO("Testing a vector", "[vector]")
{
    GIVEN("A integer vector")
    {
       std::vector<int> my_vector;
       REQUIRE(my_vector.empty());

       WHEN("One element is pushed")
       {
           my_vector.push_back(1);
           THEN("Size must increase by 1")
           {
               CHECK(my_vector.size() == 1);
           }
       }
       AND_WHEN("Two elements are pushed")
       {
           my_vector.push_back(1);
           my_vector.push_back(2);
           THEN("Size must increase by 2")
           {
               CHECK(my_vector.size() == 2);
           }
       } 
    }

}
