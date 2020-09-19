#include "filtergamma.h"

namespace image
{

	FilterGamma::FilterGamma(){ this->gamma = 0.5; }

	FilterGamma::FilterGamma(double x)
	{
		if (x < 0.5 || x > 2.0)
		{
			cerr << "Typical gamma values are between 0.5 and 2" << endl;
			exit(1);
		}
		this->gamma = x;
	}

	void FilterGamma::setGamma(double x)
	{
		if (x < 0.5 || x > 2.0)
		{
			cerr << "Typical gamma values are between 0.5 and 2" << endl;
			exit(1);
		}
		this->gamma = x;
	}

	Image FilterGamma::operator << (const Image & img){
		Image im = img;
		for (unsigned int j = 0; j < im.getHeight(); j++) {
			for (unsigned int i = 0; i < im.getWidth(); i++) {
				im(i, j).r = pow(im(i, j).r, gamma);
				im(i, j).g = pow(im(i, j).g, gamma);
				im(i, j).b = pow(im(i, j).b, gamma);
			}
		}
		return im;
	}
}


