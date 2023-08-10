#include "array.hpp"

Array::Array(const int i, const int j)
{
    ARRAY = new int ** [i];
    for (int k = 0; k < i; k++) {
        ARRAY[k] = new int * [j];
    }
}

Array::~Array()
{
    delete ARRAY;
}

int *** Array::array()
{
    return ARRAY;
}

int ** Array::operator[](int i)
{
    return ARRAY[i];
}
