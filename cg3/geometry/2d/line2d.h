/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef CG3_LINE2D_H
#define CG3_LINE2D_H

#include "point2d.h"
#include "segment2d.h"

namespace cg3 {

/**
 * @ingroup cg3core
 * @brief The Line2D class
 *
 * It models a 2D line coded in the form y = mx + q.
 * Vertical lines are stored with m = std::numeric_limits<double>::infinity() and q = the x coordinate of the line.
 */
class Line2D : public SerializableObject
{
public:
    Line2D();
    Line2D(double m, double q);
    Line2D(const Point2Dd& p1, const Point2Dd& p2);
    Line2D(const Segment2Dd& s);
    Line2D(double m, const Point2Dd& p);
    double m() const;
    double q() const;

    double yValue(double x) const;
    double xValue(double y) const;

    Point2Dd intersection(const cg3::Line2D& l) const;

    // SerializableObject interface
    void serialize(std::ofstream& binaryFile) const;
    void deserialize(std::ifstream& binaryFile);

private:
    double _m;
    double _q;
};

} //namespace cg3

#endif // CG3_LINE2D_H
