#include "iostream"
using namespace std;
#include "./config.h"
#include "./Shapes/Shape/Shape.h"
#include "./Shapes/Square/Square.h"
#include "./Shapes/Rectangle/Rectangle.h"
#include "./Shapes/Circle/Circle.h"
#include "./Shapes/Ellipse/Ellipse.h"

int main()
{
    const int N = 5;
    Shape* arr[N] = {
            new Square(1,2,4.4),
            new Rectangle(1,2,4.4,4.0),
            new Circle(3,3,43.0),
            new Ellipse(3,1,6,10.1),
            new Square(7,7,7.7)
    };

    for (int i = 0; i < N; ++i) {
        arr[i]->Save();
        delete arr[i];
    }


    int size = 0;
    Shape** newArr = nullptr;

    Square::Load(newArr, size);
    Rectangle::Load(newArr, size);
    Circle::Load(newArr, size);
    Ellipse::Load(newArr, size);

    for (int i = 0; i < size; ++i) {
        newArr[i]->Show();
    }

    for (int i = 0; i < size; ++i) {
        delete newArr[i];
    }
    delete[] newArr;





    return 0;
}