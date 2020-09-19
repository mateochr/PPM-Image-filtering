#include "filter.h"
#include "array2d.h"

#ifndef _FILTERBLUR
#define _FILTERBLUR

namespace image
{

	class FilterBlur : public Filter, public Array2D<float>{
	public:

	protected:
		int blur_n;
		Array2D<float> f;
	public:

		double getN(){ return blur_n; }

		FilterBlur();

		FilterBlur(int x, Array2D<float> f);

		virtual Image operator << (const Image & img);
	};

}
#endif