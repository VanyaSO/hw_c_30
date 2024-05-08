#ifndef HW_C_30_RECTANGLE_H
#define HW_C_30_RECTANGLE_H
#include "../Shape/Shape.h"
#include "../../functions.h"

class Rectangle: public Shape
{
    Point _topLeft;
    double _width;
    double _height;

public:
    explicit Rectangle() = default;
    explicit Rectangle(int x, int y, double width, double height);

    void Show() const override;
    void Save() const override;
    static void Load(Shape**&, int&);
};


#endif
