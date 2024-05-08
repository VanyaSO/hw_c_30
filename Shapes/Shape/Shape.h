#ifndef HW_C_30_SHAPE_H
#define HW_C_30_SHAPE_H
#include <fstream>
#include <iostream>
using namespace std;
#include "../../config.h"

struct Point
{
    int x;
    int y;
};

class Shape
{
protected:
    const string _type;
public:
    Shape() = default;
    Shape(string type): _type(type) {};
    virtual void Show() const = 0;
    virtual void Save() const = 0;
};

#endif
