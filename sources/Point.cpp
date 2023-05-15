//
// Created by beni on 5/15/23.
//
#include "Point.hpp"
#include "iostream"

namespace ariel {
    Point::Point(double X_axis, double Y_axis) {
        this->X_axis = 0;
        this->Y_axis = 0;
    }

    double Point::distance(Point &other) {
        return 0;
    }

    void Point::print() {

    }

    Point Point::moveTowards(Point &src, Point &dest, double distance) {
        return Point(0, 0);
    }

    bool Point::operator==(Point &other) {
        return false;
    }

}

