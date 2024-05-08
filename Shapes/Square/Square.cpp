#include "Square.h"

Square::Square(int x, int y, double length):Shape("Square")
{
    _topLeft.x = x;
    _topLeft.y = y;
    _length = length;
}

void Square::Show() const
{
    cout << _type << endl;
    cout << "Сoordinates: " << "top: " << _topLeft.x << ", left: " << _topLeft.y << endl;
    cout << "Length: " << _length << endl;
    cout << endl;
}

void Square::Save() const
{
    ofstream file(pathFileSquare, ofstream::app | ios::binary);

    if (file.is_open())
    {
        file.write((const char*)(this), sizeof(Square));
        file.close();
    }
    else
    {
        cout << "Error open file " << pathFileSquare << endl;
    }
}

void Square::Load(Shape**& arr, int& size)
{
    std::ifstream file(pathFileSquare, ios::binary);

    if (file.is_open())
    {
        Square obj;
        while(file.read((char*)&obj, sizeof(Square)))
        {
            addObj(arr, size, new Square(obj._topLeft.x, obj._topLeft.y, obj._length));
        }
        file.close();
    }
    else
    {
        std::cout << "Error open file " << pathFileSquare << std::endl;
    }
}


