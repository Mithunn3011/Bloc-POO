#include <iostream>
#include <cmath>

class Circle {
    public:
    //Position of the center
    double x;
    double y;

    double r; // radius

};

// Set the position of the center
void set_pos(Circle *c, double x, double y) {
    c->x = x;
    c->y = y;
}

// Calculate the perimeter of the circle
double perimeter(Circle c) {
    return 2 * M_PI * c.r;
}

//TODO: Add a method to calculate the area of the circle

class Rectangle
{
    public:
    //Position of the top left corner
    double x;
    double y;

    double w; //width
    double h; //height

};

// TODO: Add a method to calculate the area of the rectangle

// Set the position of the top left corner
void set_pos(Rectangle *r, double x, double y) {
    r->x = x;
    r->y = y;
}
// Calculate the perimeter of the rectangle
double perimeter(Rectangle r) {
    return 2 *(r.w + r.h);
}

int main() {
    Circle c{0, 0, 1};
    std::cout << perimeter(c) << std::endl;
    set_pos(&c, 1, 1);
    std::cout << "Coordinates of the center: (" << c.x << ", " << c.y << ")" << std::endl;

    Rectangle r{0, 0, 1, 2};
    std::cout << perimeter(r) << std::endl;
    set_pos(&r, -1, -1);
    std::cout << "Coordinates of the top left corner: (" << r.x << ", " << r.y << ")" << std::endl;
    return 0;
}
