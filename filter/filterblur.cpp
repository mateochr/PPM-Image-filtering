#include "filterblur.h"

namespace image
{

	FilterBlur::FilterBlur(){ blur_n = 10; }

	FilterBlur::FilterBlur(int x, Array2D<float> f)
	{
		blur_n = x;
		this->f = f;
	}

	Image FilterBlur::operator << (const Image & img){
		Image im = img;
		Image imread = img;
	
		Vec3<float> sum;
	
		for (unsigned int j = 0; j < im.getHeight(); j++)
		{
			for (unsigned int i = 0; i < im.getWidth(); i++)
			{
					for (int n = (-blur_n / 2); n <= (blur_n / 2); n++)
					{
						for (int m = (-blur_n / 2); m <= (blur_n / 2); m++)
						{
							if (i + m >= 0 && i + m < im.getWidth() && j + n >= 0 && j + n < im.getHeight())
							{
								sum = sum + (imread(i + m, j + n) * f(m + (blur_n / 2), n + (blur_n / 2)));
							}
						}
					}
					im(i, j) = sum;
					sum = 0;
			}
		}

		return im;
	}
}


