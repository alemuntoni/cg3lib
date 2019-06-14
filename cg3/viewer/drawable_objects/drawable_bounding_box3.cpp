/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#include "drawable_bounding_box3.h"

#include "../opengl_objects/opengl_objects3.h"


namespace cg3 {

DrawableBoundingBox3::DrawableBoundingBox3() :
    BoundingBox3(),
    edgeWidth(1),
    edgeColor()
{
}

DrawableBoundingBox3::DrawableBoundingBox3(const BoundingBox3& bb) :
    BoundingBox3(bb),
    edgeWidth(1),
    edgeColor()
{
}

DrawableBoundingBox3::DrawableBoundingBox3(const Point3d& min, const Point3d& max) :
	DrawableBoundingBox3(BoundingBox3(min, max))
{
}

void DrawableBoundingBox3::draw() const
{
    opengl::drawBox3(_min, _max, edgeColor, edgeWidth);
}

Point3d DrawableBoundingBox3::sceneCenter() const
{
    return center();
}

double DrawableBoundingBox3::sceneRadius() const
{
    return diag() / 2;
}

void DrawableBoundingBox3::setEdgeColor(const QColor& c)
{
    edgeColor = c;
}

void DrawableBoundingBox3::setEdgeWidth(int w)
{
    edgeWidth = w;
}

} //namespace cg3
