#include "image.h"

#ifndef _FILTER
#define _FILTER

namespace image
{

	class Filter
	{
	protected:
		string filtername;

	public:

		Filter();
		Filter(const Filter &src);
		string getFilterName();
		virtual Image operator << (const Image & img) = 0;

	};
}
#endif
