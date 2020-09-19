#include "filterlaplace.h"

namespace image
{
	FilterLaplace::FilterLaplace(int x, Array2D<float> f) :FilterBlur(x, f){}

	Image FilterLaplace::operator << (const Image & img)
	{
		Image im = img;
		Image imread = img;

		Vec3<float> sum;

		for (unsigned int j = 0; j < im.getHeight(); j++)
		{
			for (unsigned int i = 0; i < im.getWidth(); i++)
			{
				for (int n = -1; n <= 1; n++)
				{
					for (int m = -1; m <= 1; m++)
					{
						if (i + m >= 0 && i + m < im.getWidth() && j + n >= 0 && j + n < im.getHeight())
						{
							sum = sum + (imread(i + m, j + n) * f(m+1, n+1));
						}
					}
				}
				sum = (sum.clampToUpperBound(1)).clampToLowerBound(0);
				im(i, j) = sum;
				sum = 0;
			}
		}

		
		return im;
	}
}