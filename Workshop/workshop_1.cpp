#include <iostream>
#include <cmath>

class Circle {
    public:
    //Position of the center
    double x;
    double y;

    double r; // radius

    // Set the position of the center
    void set_pos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    };
    // Calculate the perimeter of the circle
    double perimeter() {
        return 2 * M_PI * r;
    };

};

class Rectangle
{
    public:
    //Position of the top left corner
    double x;
    double y;

    double w; //width
    double h; //height

    // Set the position of the top left corner
    void set_pos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    };
    
    // Calculate the perimeter of the rectangle
    double perimeter() {
        return 2 *(w + h);
    }

};


int main() {
    Circle c{0, 0, 1};
    std::cout << c.perimeter() << std::endl;
    c.set_pos(1, 1);
    std::cout << "Coordinates of the center: (" << c.x << ", " << c.y << ")" << std::endl;

    Rectangle r{0, 0, 1, 2};
    std::cout << r.perimeter() << std::endl;
    r.set_pos(-1, -1);
    std::cout << "Coordinates of the top left corner: (" << r.x << ", " << r.y << ")" << std::endl;
    return 0;
}
