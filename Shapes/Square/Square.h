#ifndef HW_C_30_SQUARE_H
#define HW_C_30_SQUARE_H
#include "../Shape/Shape.h"
#include "../../functions.h"

class Square: public Shape
{
    Point _topLeft;
    double _length;

public:
    explicit Square() = default;
    explicit Square(int x, int y, double length);

    void Show() const override;
    void Save() const override;
    static void Load(Shape**&, int&);
};


#endif
