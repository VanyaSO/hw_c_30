#ifndef HW_C_30_CIRCLE_H
#define HW_C_30_CIRCLE_H
#include "../Shape/Shape.h"
#include "../../functions.h"

class Circle: public Shape
{
    Point _center;
    double _radius;

public:
    explicit Circle() = default;
    explicit Circle(int x, int y, double radius): Shape("Circle")
    {
        _center.x = x;
        _center.y = y;
        _radius = radius;
    }

    void Show() const override;
    void Save() const override;
    static void Load(Shape**&, int&);
};


#endif
