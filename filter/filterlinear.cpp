#include "filterlinear.h"

namespace image
{

	FilterLinear::FilterLinear(){}

	FilterLinear::FilterLinear(double x1, double x2, double x3, double y1, double y2, double y3)
	{
		ar = x1;
		ag = x2;
		ab = x3;
		cr = y1;
		cg = y2;
		cb = y3;
	}

	void FilterLinear::setArgs(double x1, double x2, double x3, double y1, double y2, double y3)
	{
		ar = x1;
		ag = x2;
		ab = x3;
		cr = y1;
		cg = y2;
		cb = y3;
	}

	Image FilterLinear::operator << (const Image & img){
		Image im = img;
		for (unsigned int j = 0; j < im.getHeight(); j++) {
			for (unsigned int i = 0; i < im.getWidth(); i++) {
				im(i, j).r = (im(i, j).r * ar) + cr;
				if (im(i, j).r > 1)im(i, j).r = 1;
				if (im(i, j).r < 0)im(i, j).r = 0;

				im(i, j).g = (im(i, j).g * ag) + cg;
				if (im(i, j).g > 1)im(i, j).g = 1;
				if (im(i, j).g < 0)im(i, j).g = 0;

				im(i, j).b = (im(i, j).b * ab) + cb;
				if (im(i, j).b > 1)im(i, j).b = 1;
				if (im(i, j).b < 0)im(i, j).b = 0;
			}
		}
		return im;
	}
}
