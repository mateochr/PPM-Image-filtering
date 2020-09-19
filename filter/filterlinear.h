#include "filter.h"

#ifndef _FILTERLINEAR
#define _FILTERLINEAR

namespace image
{

	class FilterLinear : public Filter
	{

	public:

	protected:
		double ar, ag, ab, cr, cg, cb;
	public:

		FilterLinear();
		FilterLinear(double x1, double x2, double x3, double y1, double y2, double y3);

		void setArgs(double x1, double x2, double x3, double y1, double y2, double y3);
		virtual Image operator << (const Image & img);
	};	
}
#endif