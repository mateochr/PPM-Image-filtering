#include <iostream>
#include "image.h"


namespace image
{
	Image::Image(unsigned int width, unsigned int height, const Vec3<float> * data_ptr) :Array2D<Vec3<float>>(width, height, data_ptr){}
	Image::Image(const Array2D &src) :Array2D<Vec3<float>>(src){}

	bool Image::load(const std::string & filename, const std::string & format)
	{
		if (!this->buffer.empty()) buffer.clear();
		
		string check_format;
		int width = 0;
		int height = 0;

		//Check if the image format is ppm (case insensitive), if not return false
		int pos = filename.find(".");
		if (pos != std::string::npos)
		{
			check_format = filename.substr(pos + 1);
			for (unsigned j = 0; j < format.length(); ++j)
			{
				if (tolower(check_format[j]) != tolower(format[j]))
				{
					cout << "Incorrect image extension. Extension should be 'ppm'" << endl;
					return false;
				}
			}
		}
		else{
			cout << "Incorrect image name" << endl;
			return false;
		}

		//Read the data of the image
		float* pixelArray = ReadPPM(filename.c_str(), &width, &height);
		if (pixelArray == nullptr) return false;
			
		Vec3<float> *buff = new Vec3<float>[width * height];
			
		int j = 0;
		for (unsigned i = 0; i < 3 * width * height; i = i + 3){
			buff[j].r = pixelArray[i];
			buff[j].g = pixelArray[i + 1];
			buff[j].b = pixelArray[i + 2];
			j++;
		}
		this->width = width;
		this->height = height;
		this->setData(buff);

		return true;
	}

	bool Image::save(const std::string & filename, const std::string & format)
	{	
		if (this->buffer.empty()) return false;	
			
		string check_format;
		string new_image_name = "filtered_" + filename;

		//Check if the image format is ppm (case insensitive), if not return false
		int pos = filename.find(".");
		if (pos != std::string::npos)
		{
			check_format = filename.substr(pos + 1);
			for (unsigned j = 0; j < format.length(); ++j)
			{
				if (tolower(check_format[j]) != tolower(format[j]))
				{
					cout << "Incorrect image extension. Extension should be 'ppm'" << endl;
					return false;
				}
			}
		}
		else{
			cout << "Incorrect image name" << endl;
			return false;
		}

		//Write the data of the image
		float* pixelArray = new float[3 * this->width*this->height];
				
		Vec3<float> *buff = this->getRawDataPtr();
				
		int j = 0;
		for (unsigned i = 0; i < 3*(this->width) * (this->height); i = i+3){
			pixelArray[i] = buff[j].r;
			pixelArray[i + 1] = buff[j].g;
			pixelArray[i + 2] = buff[j].b;
			j++;
		}

		return (WritePPM(pixelArray, this->getWidth(), this->getHeight(), new_image_name.c_str())) ? true : false;
	}
}