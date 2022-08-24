//
// Created by Ayesha on 11/6/2020.
//

#include "Shapes.h"


Shapes::~Shapes() {
}

/* ======== SHAPE 2D ======== */
void Shape2D::ShowArea() const {
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const {
    if (Area() > rhs.Area()) {
        return true;
    }
    else {
        return false;
    }
}

bool Shape2D::operator<(const Shape2D &rhs) const {
    if (Area() < rhs.Area()) {
        return true;
    }
    else {
        return false;
    }
}

bool Shape2D::operator==(const Shape2D &rhs) const {
    if (Area() == rhs.Area()) {
        return true;
    }
    else {
        return false;
    }
}


//SQUARE
Square::Square() {
    sideLength = 0.0f;
}

Square:: Square(float length) {
    sideLength = length;
}

void Square::Scale(float scaleFactor) {
    sideLength *= scaleFactor;
}

void Square::Display() const {
    cout << "The area of the Square is : " << Area() << endl;
    cout << "Length of a side: " << sideLength << endl;
}

float Square::Area() const {
    return sideLength * sideLength;
}

string Square::GetName2D() const {
    return "Square";
}

Square::~Square() {
}

//TRIANGLE
Triangle::Triangle() {
    height = 0.0f;
    base = 0.0f;
}

Triangle::Triangle(float base, float height) {
    this->height = height;
    this->base = base;
}

float Triangle::Area() const {
    return (base * height) / 2;
}

string Triangle::GetName2D() const {
    return "Triangle";
}

void Triangle::Scale(float scaleFactor) {
    base *= scaleFactor;
    height *= scaleFactor;
}

void Triangle::Display() const {
    cout << "The area of the Triangle is : " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}
void Triangle::setBaseAndHeight(float base, float height) {
    this->base = base;
    this->height = height;
}
float Triangle::getBase() const {
    return base;
}
float Triangle::getHeight() const {
    return height;
}

Triangle::~Triangle() {
}


//CIRCLE
Circle::Circle() {
    radius = 0.0f;
}

Circle::Circle(float radius) {
    this->radius = radius;
}

void Circle::Scale(float scaleFactor) {
    radius *= scaleFactor;
}

void Circle::Display() const {
    cout << "The area of the Circle is : " << Area() << endl;
    cout << "Radius: " << radius << endl;
}

float Circle::Area() const {
    return pow((double) radius, 2) * PI;
}

string Circle::GetName2D() const {
    return "Circle";
}

void Circle::setRadius(float radius) {
    this->radius = radius;
}

float Circle::getRadius() const{
    return radius;
}

Circle::~Circle() {
}







/* ======== SHAPE 3D ======== */
void Shape3D::ShowVolume() const {
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const {
    if (Volume() > rhs.Volume()) {
        return true;
    }
    else {
        return false;
    }
}

bool Shape3D::operator<(const Shape3D &rhs) const {
    if (Volume() < rhs.Volume()) {
        return true;
    }
    else {
        return false;
    }
}

bool Shape3D::operator==(const Shape3D &rhs) const {
    if (Volume() == rhs.Volume()) {
        return true;
    }
    else {
        return false;
    }
}


//TRIANGULAR PYRAMID
TriangularPyramid::TriangularPyramid() {
    pyramidHeight = 0.0f;
}

TriangularPyramid::TriangularPyramid(float pyramidHeight, float base, float height) {
    setBaseAndHeight(base, height);
    this->pyramidHeight = pyramidHeight;
}

void TriangularPyramid::Scale(float scaleFactor) {
    Triangle::Scale(scaleFactor);
    pyramidHeight *= scaleFactor;
}

void TriangularPyramid::Display() const {
    cout << "The volume of the TriangularPyramid is : " << Volume() << endl;
    cout << "The height is: " << pyramidHeight << endl;
    cout << "The area of the Triangle is: " << Area() << endl;
    cout << "Base: " << getBase() << endl;
    cout << "Height: " << getHeight() << endl;
}

float TriangularPyramid::Volume() const {
    return ( pyramidHeight * Area() ) / 3.0;
}

string TriangularPyramid::GetName3D() const {
    return "TriangularPyramid";
}

TriangularPyramid::~TriangularPyramid() {
}


//CYLINDER
Cylinder::Cylinder() {
    height = 0.0f;
    setRadius(0.0f);
}

Cylinder::Cylinder(float height, float radius) {
    this->height = height;
    setRadius(radius);
}

void Cylinder::Scale(float scaleFactor) {
    Circle::Scale(scaleFactor);
    height *= scaleFactor;
}

void Cylinder::Display() const {
    cout << "The volume of the Cylinder is : " << Volume() << endl;
    cout << "The height is: " << height << endl;
    cout << "The area of the Circle is: " << Area() << endl;
    cout << "Radius: " << getRadius() << endl;
}

float Cylinder::Volume() const {
    return pow(getRadius(), 2) * height * PI;
}

string Cylinder::GetName3D() const {
    return "Cylinder";
}

Cylinder::~Cylinder() {
}


//SPHERE
Sphere::Sphere() {
    setRadius(0.0f);
}

Sphere::Sphere(float radius) {
    Circle::setRadius(radius);
}

void Sphere::Scale(float scaleFactor) {
    Circle::Scale(scaleFactor);
}

void Sphere::Display() const {
    cout << "The volume of the Sphere is : " << Volume() << endl;
    cout << "The area of the Circle is: " << Area() << endl;
    cout << "Radius: " << getRadius() << endl;
}

float Sphere::Volume() const {
    return pow(getRadius(), 3) * PI * (4.0 / 3);
}

string Sphere::GetName3D() const {
    return "Sphere";
}

Sphere::~Sphere() {
}