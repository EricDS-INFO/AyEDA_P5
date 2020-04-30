#pragma once
#include <iostream>
#include <cstdlib>


#define I_BOUND 10000000000



class counter;
class isbn
{
    private:
        int             value_;
        unsigned long   lvalue_;
        int             length_;
        static counter  cntr_;
    
    public: 
        isbn();
        isbn(int seed);
        ~isbn();

        inline  int value() const { return value_; }
        
        inline  void value(int value) { value_ = value; } 
        
        static int nth_compare(); 
        inline void set_none(void){ value_ = -1;}
        inline int length() const { return length_; }

        friend std::ostream& operator<< (std::ostream& os, isbn& isbn_t);
        
        bool operator== (isbn& r_value);
        bool operator!= (isbn& r_value);
        bool operator> (isbn& r_value);
        bool operator< (isbn& r_value);
        bool operator>= (isbn& r_value);
        bool operator<= (isbn& r_value);


        operator unsigned long() const;

        static void reset_c(void);

    private:
        void inc(void);
};
