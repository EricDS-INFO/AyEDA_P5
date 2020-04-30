#pragma once
#include "./ISBN.hpp"
#include "../include/counter.hpp"



counter isbn::cntr_; 
isbn::isbn()
{
    value_ = rand() % I_BOUND;
    lvalue_ = value_;
    length_ = std::to_string(value_).length();
}


isbn::isbn(int seed)
{   srand(seed);
    value_ = rand() % I_BOUND;
    length_ = std::to_string(value_).length();
}

isbn::~isbn(){}


int isbn::nth_compare() { return isbn::cntr_.value(); }
void isbn::reset_c(void) { isbn::cntr_.reset(); }

std::ostream& operator<< (std::ostream& os, isbn& isbn_t)
{
    switch( isbn_t.length() )
    {
        case 0:
            os << " 000000000" <<  isbn_t.value() << " ";
            break;    
        case 1:
            if (isbn_t.value() != -1)
                os << " 000000000" <<  isbn_t.value() << " ";
            else 
                os << "          ";  
            break;

        case 2:
            if (isbn_t.value() != -1)
                os << " 00000000" <<  isbn_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 3:
            if (isbn_t.value() != -1)    
                os << " 0000000" <<  isbn_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 4:
            if (isbn_t.value() != -1)    
                os << " 000000" <<  isbn_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 5:
            if (isbn_t.value() != -1)    
                os << " 00000" <<  isbn_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 6:
            if (isbn_t.value() != -1)    
                os << " 0000" <<  isbn_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 7:

            if (isbn_t.value() != -1)
                os << " 000" <<  isbn_t.value() << " ";
            else 
                os << "          ";            
            break;

        case 8:
            if (isbn_t.value() != -1)
                os << " 00" <<  isbn_t.value() << " ";
            else 
                os << "          ";
            break;

        case 9:
            if (isbn_t.value() != -1)
                os << " 0" <<  isbn_t.value() << " ";
            else 
                os << "          ";
            break;
        case 10:
            if (isbn_t.value() != -1)
                os << " " <<  isbn_t.value() << " ";
            else 
                os << "          ";
            break;

        default:
            os << " XXXXXXXXXX ";
            break;
    }
    return os;
}

bool isbn::operator== (isbn& r_value)
{
    isbn::cntr_.increase();
    return value() == r_value.value();
}
bool isbn::operator!= (isbn& r_value)
{
    isbn::cntr_.increase();
    return value() != r_value.value();
}
bool isbn::operator> (isbn& r_value)
{
    isbn::cntr_.increase();
    return value() > r_value.value();
}
bool isbn::operator< (isbn& r_value)
{
    isbn::cntr_.increase();
    return value() < r_value.value();
}
bool isbn::operator>= (isbn& r_value)
{
    isbn::cntr_.increase();
    return value() >= r_value.value();
}
bool isbn::operator<= (isbn& r_value)
{
    isbn::cntr_.increase();
    return value() <= r_value.value();
}


isbn::operator unsigned long() const
{
    return lvalue_;
}


void isbn::inc(void)
{
    cntr_.increase();
}