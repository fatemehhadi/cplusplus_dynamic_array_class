# include <iostream>

#include "studentvec.h"

using namespace std;

StudentVec::StudentVec()
{
    fcapacity = 2;
    pl = new (nothrow) value_type [fcapacity];
	fsize = 0;
}

StudentVec::StudentVec(size_type init_size)
{
    fcapacity = init_size;
    pl = new (nothrow) value_type [fcapacity];  
    memset(pl,fcapacity,0);
    fsize =  fcapacity;
}

StudentVec::StudentVec(const StudentVec& other)
{
    fcapacity = other.fcapacity;
    pl = new (nothrow) value_type [fcapacity]; 
    fsize = other.fsize;  
    std::copy(other.pl, other.pl + other.fsize, pl);
}

StudentVec::~StudentVec()
{
   delete [] pl;
}

void StudentVec::regrow()
{
    fcapacity = 2*fcapacity;
    plregrow = new (nothrow) value_type [fcapacity];
    for (int i=0; i<fsize; i++)
    {
        plregrow[i] = pl[i];
    }
    delete [] pl;
    pl = new (nothrow) value_type [fcapacity];   
    for (int i=0; i<fcapacity; i++)
    {
        pl[i] = plregrow[i];
    }        
    delete [] plregrow;
}

void StudentVec::push_back(value_type value)
{
    if (fsize == fcapacity)
    {
        regrow();
    }
    pl[fsize] = value;
    fsize++;
}

size_t StudentVec::size() const
{
    return fsize;
}

size_t StudentVec::capacity() const
{
    return fcapacity;
}

StudentVec::value_type& StudentVec::operator[](int position)
{
    return pl[position];
}

StudentVec::value_type StudentVec::operator[](int position) const
{
    return pl[position];
}

StudentVec::StudentVec StudentVec::operator=(const StudentVec& other)
{
    delete [] this->pl;
    fcapacity = other.fcapacity;
    pl = new (nothrow) value_type [fcapacity]; 
    fsize = other.fsize;  
    std::copy(other.pl, other.pl + other.fsize, this->pl);  
    return *this;  
}


