#ifndef HW_C_30_FUNCTIONS_H
#define HW_C_30_FUNCTIONS_H
#include "./Shapes/Shape/Shape.h"
template<typename T>
void addObj(Shape**& arr, int& size, T* obj)
{
    Shape** newArr = new Shape*[size+1];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    newArr[size] = obj;
    size+=1;

    delete[] arr;
    arr = newArr;
}
#endif
