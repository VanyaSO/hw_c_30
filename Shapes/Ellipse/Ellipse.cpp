#include "Ellipse.h"

Ellipse::Ellipse(int x, int y, double width, double height): Shape("Ellipse")
{
    _topLeft.x = x;
    _topLeft.y = y;
    _width = width;
    _height = height;
}

void Ellipse::Show() const
{
    cout << _type << endl;
    cout << "Сoordinates: " << "X: " << _topLeft.x << ", Y: " << _topLeft.y << endl;
    cout << "Width: " << _width << endl;
    cout << "Height: " << _height << endl;
    cout << endl;
}

void Ellipse::Save() const
{
    ofstream file(pathFileEllipse, ofstream::app | ios::binary);

    if (file.is_open())
    {
        file.write((const char*)(this), sizeof(Ellipse));
        file.close();
    }
    else
    {
        cout << "Error open file " << pathFileEllipse << endl;
    }
}

void Ellipse::Load(Shape**& arr, int& size)
{
    std::ifstream file(pathFileEllipse, std::ios::binary);

    if (file.is_open())
    {
        Ellipse obj;
        while(file.read((char*)&obj, sizeof(Ellipse)))
        {
            addObj(arr, size, new Ellipse(obj._topLeft.x, obj._topLeft.y, obj._width, obj._height));
        }
        file.close();
    }
    else
    {
        std::cout << "Error open file " << pathFileEllipse << std::endl;
    }
}
