#include "../include/Case.h"
#include <iostream>

using namespace std;

Case::Case(int x)
{
    val = x;
}

Case::~Case()
{
    //dtor
}

int Case::get_val()
{
    return val ;
}

void Case::set_val(int y)
{
    val = y;
}

bool Case::estVide() const
{
    return val > 0;
}

