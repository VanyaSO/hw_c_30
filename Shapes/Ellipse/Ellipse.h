#ifndef HW_C_30_ELLIPSE_H
#define HW_C_30_ELLIPSE_H
#include "../Shape/Shape.h"
#include "../../functions.h"

class Ellipse: public Shape
{
    Point _topLeft;
    double _width;
    double _height;

public:
    explicit Ellipse() = default;
    explicit Ellipse(int x, int y, double width, double height);

    void Show() const override;
    void Save() const override;
    static void Load(Shape**&, int&);
};


#endif
