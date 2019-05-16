/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#ifndef CG3_BOUNDINGBOX2D_H
#define CG3_BOUNDINGBOX2D_H

#include "point2d.h"

#ifdef _WIN32
#undef min
#undef max
#endif

namespace cg3 {

/**
 * @ingroup cg3core
 * @brief The BoundingBox2D class
 * This class models an axis aligned 2D box.
 * It is composed of two points, min and max, which represent the minimum and
 * maximum coordinates of the box.
 */
class BoundingBox2D : public SerializableObject
{
public:
    BoundingBox2D();
    BoundingBox2D(const Point2Dd& minCoord, const Point2Dd& maxCoord);


    const Point2Dd& min() const;
    Point2Dd& min();
    void setMin(const Point2Dd& value);

    const Point2Dd& max() const;
    Point2Dd& max();
    void setMax(const Point2Dd& value);
    void set(const Point2Dd& min, const Point2Dd& max);

    Point2Dd center() const;
    double diag() const;

    double lengthX() const;
    double lengthY() const;

    bool isInside(const Point2Dd& p) const;
    bool isStrictlyInside(const Point2Dd& p) const;

    // SerializableObject interface
    void serialize(std::ofstream& binaryFile) const;
    void deserialize(std::ifstream& binaryFile);

    #ifdef CG3_OLD_NAMES_COMPATIBILITY
    inline const Point2Dd& getMin() const {return min();}
    inline const Point2Dd& getMax() const {return max();}
    #endif

protected:
    Point2Dd minCoord, maxCoord;
};

template <class InputContainer>
BoundingBox2D boundingBox(const InputContainer& container);

#ifdef CG3_OLD_NAMES_COMPATIBILITY
template <class InputContainer>
inline BoundingBox2D getBoundingBox(const InputContainer& container) {return boundingBox(container);}
#endif

} //namespace cg3

//hash specialization
namespace std {

template<>
struct hash<cg3::BoundingBox2D> {
    size_t operator()(const cg3::BoundingBox2D& k) const;
};

} //namespace std

#include "bounding_box2d.tpp"

#endif // CG3_BOUNDINGBOX2D_H
