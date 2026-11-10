#include <iostream>
#include <cmath>
using namespace std;

class Vector2 {
private:
    float x, y;

public:
    Vector2(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

    float getX() { return x; }
    float getY() { return y; }

    float norm()             { return sqrt(x * x + y * y); }
    float dot(Vector2 r)     { return x * r.x + y * r.y; }
    float cross(Vector2 r)   { return x * r.y - y * r.x; }
    Vector2 scale(float u)   { return Vector2(x * u, y * u); }
    Vector2 negate()         { return Vector2(-x, -y); }
};

class Point2 {
private:
    float x, y;

public:
    Point2(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

    float getX() { return x; }
    float getY() { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    // point + vecteur = point
    Point2 add(Vector2 v) { return Point2(x + v.getX(), y + v.getY()); }

    // point - point = vecteur
    Vector2 sub(Point2 p) { return Vector2(x - p.x, y - p.y); }

    void print() { cout << "{" << x << ", " << y << "}" << endl; }
};


enum IntersectionStatus {
    POINT,
    COLINEAR_INTERSECTING,
    COLINEAR_NON_INTERSECTING,
    PARALLEL_NON_INTERSECTING,
    NON_INTERSECTING
};

class Segment2 {
private:
    Point2 origin;
    Vector2 direction;

public:
    Segment2(Point2 origin, Vector2 direction) {
        this->origin = origin;
        this->direction = direction;
    }

    Point2 getOrigin()     { return origin; }
    Vector2 getDirection() { return direction; }

    float length() { return direction.norm(); }

    IntersectionStatus intersect(Segment2 r, Point2 &p) {
        Point2 oa = origin, ob = r.origin;
        Vector2 da = direction, db = r.direction;
        Vector2 dc = ob.sub(oa);

        float det = da.cross(db);

        if (det != 0) {
            float u = dc.cross(db) / det;
            float v = dc.cross(da) / det;
            if (u >= 0 && u <= 1 && v >= 0 && v <= 1) {
                p = oa.add(da.scale(u));
                return POINT;
            }
            return NON_INTERSECTING;
        }

        if (dc.cross(da) != 0) {
            return PARALLEL_NON_INTERSECTING;
        }

        float pj = da.dot(da);
        float d1 = dc.dot(da) / pj;
        float d2 = d1 + db.dot(da) / pj;

        if (d1 >= 0 && d1 <= 1) {
            p = ob;
            return COLINEAR_INTERSECTING;
        }
        if (d2 >= 0 && d2 <= 1) {
            p = ob.add(db);
            return COLINEAR_INTERSECTING;
        }
        return COLINEAR_NON_INTERSECTING;
    }
};

int main() {
    Point2 p1(0, 0), p2(1, 2);
    Vector2 v1(1, 1), v2(2, 4);

    Segment2 s1(p1, v1);
    Segment2 s2(p2, v2);

    cout << "Longueur s1 : " << s1.length() << endl;
    cout << "Longueur s2 : " << s2.length() << endl;

    Point2 p;
    IntersectionStatus status = s1.intersect(s2, p);

    if (status == POINT || status == COLINEAR_INTERSECTING) {
        cout << "Intersection en ";
        p.print();
    } else {
        cout << "Pas d'intersection (code " << status << ")" << endl;
    }

    return 0;
}