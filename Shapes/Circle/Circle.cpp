#include "Circle.h"

void Circle::Show() const {
    cout << _type << endl;
    cout << "Сoordinates: " << "X: " << _center.x << ", Y: " << _center.y << endl;
    cout << "Radius: " << _radius << endl;
    cout << endl;
}

void Circle::Save() const {
    ofstream file(pathFileCircle, ofstream::app | ios::binary);

    if (file.is_open())
    {
        file.write((const char*)(this), sizeof(Circle));
        file.close();
    }
    else
    {
        cout << "Error open file " << pathFileCircle << endl;
    }
}

void Circle::Load(Shape**& arr, int& size)
{
    std::ifstream file(pathFileCircle, ios::binary);

    if (file.is_open())
    {
        Circle obj;
        while(file.read((char*)&obj, sizeof(Circle)))
        {
            addObj(arr, size, new Circle(obj._center.x, obj._center.y, obj._radius));
        }
        file.close();
    }
    else
    {
        std::cout << "Error open file " << pathFileCircle << std::endl;
    }
}