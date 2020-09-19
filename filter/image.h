#include <iostream>
#include"imageio.h"
#include "array2d.h"
#include "vec3.h"
#include "ppm/ppm.h"

using namespace std;
using namespace math;

#ifndef _IMAGE
#define _IMAGE

namespace image
{
	class Image : public ImageIO, public Array2D <Vec3<float>>
	{
	public:
		Image(unsigned int width = 0, unsigned int height = 0, const Vec3<float> * data_ptr = 0);
		Image(const Array2D &src);

		virtual bool load(const std::string & filename, const std::string & format);
		virtual bool save(const std::string & filename, const std::string & format);
	};
}
#endif