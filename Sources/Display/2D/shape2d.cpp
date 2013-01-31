/*
**  ClanLib SDK
**  Copyright (c) 1997-2012 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Harry Storbacka
**    Mark Page
*/

#include "Display/precomp.h"
#include "API/Display/2D/shape2d.h"
#include "shape2d_impl.h"
#include "API/Core/Math/ear_clip_result.h"
#include "API/Display/2D/canvas.h"
#include "API/Display/Font/font_vector.h"
#include "API/Core/Math/bezier_curve.h"
#include <vector>

namespace clan
{

/////////////////////////////////////////////////////////////////////////////
// Shape2D Construction:

Shape2D::Shape2D() : impl(new Shape2D_Impl())
{
}

Shape2D::~Shape2D()
{
}

/////////////////////////////////////////////////////////////////////////////
// Shape2D Attributes:


/////////////////////////////////////////////////////////////////////////////
// Shape2D Operations:

void Shape2D::add_path(Path2D &path)
{
	impl->add_path(path);
}

void Shape2D::get_triangles(std::vector<Vec2f> &out_primitives_array, PolygonOrientation orientation) const
{
	impl->get_triangles(out_primitives_array, orientation);
}

void Shape2D::get_outline(std::vector< std::vector<Vec2f> > &out_primitives_array_outline) const
{
	impl->get_outline(out_primitives_array_outline);
}

void Shape2D::add_circle(float center_x, float center_y, float radius, bool reverse)
{
	#define KAPPA		0.5522847498f

	clan::BezierCurve bezier_curve;

	bezier_curve.add_control_point(center_x + radius, center_y);
	bezier_curve.add_control_point(center_x + radius * 1, (center_y + radius * 1 * KAPPA));
	bezier_curve.add_control_point(center_x + radius * 1 * KAPPA, (center_y + radius * 1));
	bezier_curve.add_control_point(center_x + radius * 0, (center_y + radius * 1));
	bezier_curve.add_control_point(center_x - radius * 1  * KAPPA, (center_y + radius * 1));
	bezier_curve.add_control_point(center_x - radius * 1, (center_y + radius * 1 * KAPPA));
	bezier_curve.add_control_point(center_x - radius * 1, (center_y + radius * 0));
	bezier_curve.add_control_point(center_x - radius * 1, (center_y - radius * 1  * KAPPA));
	bezier_curve.add_control_point(center_x - radius * 1 * KAPPA, (center_y - radius * 1));
	bezier_curve.add_control_point(center_x - radius * 0, (center_y - radius * 1));
	bezier_curve.add_control_point(center_x + radius * 1 * KAPPA, (center_y - radius * 1));
	bezier_curve.add_control_point(center_x + radius * 1, (center_y - radius * 1 * KAPPA));
	bezier_curve.add_control_point(center_x + radius * 1, (center_y - radius * 0));

	Path2D path;
	path.add_curve(bezier_curve);
	if (reverse)
		path.reverse();

	add_path(path);
}

void Shape2D::add_circle(const Pointf &center, float radius, bool reverse)
{
	add_circle(center.x, center.y, radius, reverse);
}

/////////////////////////////////////////////////////////////////////////////
// Shape2D Implementation:

}