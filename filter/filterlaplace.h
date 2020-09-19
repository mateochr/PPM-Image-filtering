#include "filterblur.h"

#ifndef _FILTERLAPLACE
#define _FILTERLAPLACE

namespace image
{

	class FilterLaplace : public FilterBlur{
	public:
		FilterLaplace(int x, Array2D<float> f);
		virtual Image operator << (const Image & img);
	};
}
#endif