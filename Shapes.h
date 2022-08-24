//
// Created by Ayesha on 11/6/2020.
//

#ifndef LAB6_SHAPES_H
#define LAB6_SHAPES_H
#include <iostream>
#include <math.h>
using namespace std;

class Shapes {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    const float PI = 3.14159;

    virtual ~Shapes() = 0;
};

class Shape2D : virtual public Shapes {
public:
    virtual float Area() const = 0;
    virtual string GetName2D() const = 0;

    void ShowArea() const;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};

class Square : public Shape2D { //a Square is a 2D shape
    float sideLength;
public:
    Square();
    Square(float length);

    //From Shapes
    void Scale(float scaleFactor);
    void Display() const;

    //From Shape2D
    float Area() const;
    string GetName2D() const;

    ~Square();
};

class Triangle : public Shape2D {
    float height;
    float base;
public:
    Triangle();
    Triangle(float base, float height);

    //From Shapes
    void Scale(float scaleFactor);
    void Display() const;

    //From Shape2D
    float Area() const;
    string GetName2D() const;

    void setBaseAndHeight(float base, float height);
    float getBase() const;
    float getHeight() const;

    ~Triangle();
};

class Circle : public Shape2D {
    float radius;
public:
    Circle();
    Circle(float radius);

    //From Shapes
    void Scale(float scaleFactor);
    void Display() const;

    //From Shape2D
    float Area() const;
    string GetName2D() const;

    void setRadius(float radius);
    float getRadius() const;

    ~Circle();
};






class Shape3D : virtual public Shapes {
public:
    virtual float Volume() const = 0;
    virtual string GetName3D() const = 0;

    void ShowVolume() const;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};

class TriangularPyramid : public Shape3D, private Triangle {
    Triangle tri;
    float pyramidHeight;
public:
    TriangularPyramid();
    TriangularPyramid(float pyramidHeight, float base, float height);

    //From Shapes
    void Scale(float scaleFactor);
    void Display() const;

    //From Shape3D
    float Volume() const;
    string GetName3D() const;

    ~TriangularPyramid();
};

class Cylinder : public Shape3D, private Circle {
    float height;
public:
    Cylinder();
    Cylinder(float height, float radius);

    //From Shapes
    void Scale(float scaleFactor);
    void Display() const;

    //From Shape3D
    float Volume() const;
    string GetName3D() const;

    ~Cylinder();
};

class Sphere : public Shape3D, private Circle {
public:
    Sphere();
    Sphere(float radius);

    //From Shapes
    void Scale(float scaleFactor);
    void Display() const;

    //From Shape3D
    float Volume() const;
    string GetName3D() const;

    ~Sphere();
};

#endif //LAB6_SHAPES_H
