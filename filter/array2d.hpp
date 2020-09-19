#include <iterator>
#include "array2d.h"

namespace math
{
	template <typename T>
	const unsigned int Array2D<T>::getWidth() const{ return width; }

	template <typename T>
	const unsigned int Array2D<T>::getHeight() const{ return height; }

	template <typename T>
	T *  Array2D<T>::getRawDataPtr()
	{	
		T *point = buffer.data();
		return point;
	}

	template <typename T>
	void  Array2D<T>::setData(const T * const & data_ptr)
	{
		if (!buffer.empty())this->~Array2D();
		int size = width * height;
		copy(&data_ptr[0], &data_ptr[size], back_inserter(buffer));
	}

	template <typename T>
	T & Array2D<T>::operator () (unsigned int x, unsigned int y)
	{
		if ((x >= 0 && x <= width) && (y >= 0 && y <= height))
		{
			int pixel = (y*width) + x;
			return buffer[pixel];
		}
		else{
			cerr << "operator (): Index out of image bounds!!!" << endl;
			exit(1);
		}
	
	}

	template <typename T>
	Array2D<T>::Array2D(unsigned int width = 0, unsigned int height = 0, const T * data_ptr = 0)
	{
		this->width = width;
		this->height = height;

		if (data_ptr == 0 && width > 0 && height > 0)
		{
			int size = width * height;
			buffer.reserve(size);
			for (int i = 0; i < size; i++)
			{
				buffer.push_back(0);
			}
		}
		else
		{
			setData(data_ptr);
		}
	}

	template <typename T>
	Array2D<T>::Array2D(const Array2D &src)
	{
		width = src.getWidth();
		height = src.getHeight();
		this->buffer.assign(src.buffer.begin(), src.buffer.end());
	}

	template <typename T>
	Array2D<T>::~Array2D(){}

	template <typename T>
	Array2D<T> & Array2D<T>::operator = (const Array2D & right)
	{
		width = right.getWidth();
		height = right.getHeight();
		this->buffer.assign(right.buffer.begin(), right.buffer.end());
		return *this;
	}
}