#include "filter.h"

#ifndef _FILTERGAMMA
#define _FILTERGAMMA

namespace image
{

	class FilterGamma : public Filter{
	public:

	protected:
		double gamma;
	public:

		double getGamma(){ return gamma; }

		void setGamma(double x);

		FilterGamma();

		FilterGamma(double x);

		virtual Image operator << (const Image & img);
	};

}
#endif