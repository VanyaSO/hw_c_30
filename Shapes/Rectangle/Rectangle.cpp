#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, double width, double height): Shape("Rectangle")
{
    _topLeft.x = x;
    _topLeft.y = y;
    _width = width;
    _height = height;
}

void Rectangle::Show() const
{
    cout << _type << endl;
    cout << "Сoordinates: " << "top: " << _topLeft.x << ", left: " << _topLeft.y << endl;
    cout << "Width: " << _width << endl;
    cout << "Height: " << _height << endl;
    cout << endl;
}

void Rectangle::Save() const
{
    ofstream file(pathFileRectangle, ofstream::app | ios::binary);

    if (file.is_open())
    {
        file.write((const char*)(this), sizeof(Rectangle));
        file.close();
    }
    else
    {
        cout << "Error open file " << pathFileRectangle << endl;
    }
}

void Rectangle::Load(Shape**& arr, int& size)
{
    std::ifstream file(pathFileRectangle, std::ios::binary);

    if (file.is_open())
    {
        Rectangle obj;
        while(file.read((char*)&obj, sizeof(Rectangle)))
        {
            addObj(arr, size, new Rectangle(obj._topLeft.x, obj._topLeft.y, obj._width, obj._height));
        }
        file.close();
    }
    else
    {
        std::cout << "Error open file " << pathFileRectangle << std::endl;
    }
}
