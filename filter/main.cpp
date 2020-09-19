#include <iostream>
#include <cstring>
#include <string>
#include "filtergamma.h"
#include "filterlinear.h"
#include "filterblur.h"
#include "filterlaplace.h"

using namespace image;

bool isNumber(string x);
bool existsNext(char *argv[], int x, int y);

int main(int argc, char *argv[])
{

	Image image(0,0,0);
	Array2D<float>* f;
	Filter* filter;
	float* fx;

	string img_name;
	double linear_args[6];
	double gamma;
	int blur_n;
	int filter_count = 0;
		
	img_name = argv[argc-1];


	if (!image.load(img_name, "ppm")) return 0;

	for (int arg_count = 1; arg_count < argc; arg_count++)
	{
		if (arg_count == argc - 1) break;

		if (strcmp(argv[arg_count], "-f") == 0)
		{
			filter_count++;
			arg_count++;

			if (strcmp(argv[arg_count], "linear") == 0)
			{	
				//loop for 6 arguments for linear filter arguments
				for (int lin_arg_count = 1; lin_arg_count < 7; lin_arg_count++)
				{
					//if the next arg is null
					if (!existsNext(argv, arg_count, lin_arg_count)) return 0;

					//if we find alphabetical character
					if (!isNumber(argv[arg_count + lin_arg_count])) return 0;

					linear_args[lin_arg_count - 1] = atof(argv[arg_count + lin_arg_count]);
				}
				cout << "\nApplying linear filter. Please wait!" << endl;
				filter = new FilterLinear(linear_args[0], linear_args[1], linear_args[2], linear_args[3], linear_args[4], linear_args[5]);
				image = *filter << image;
				
				arg_count += 6;
				delete filter;
			}			
			else if (strcmp(argv[arg_count], "gamma") == 0)
			{
				//if the next arg is null
				if (!existsNext(argv, arg_count, 1)) return 0;

				//if we find alphabetical character
				if (!isNumber(argv[arg_count + 1])) return 0;

				gamma = atof(argv[arg_count += 1]);
				cout << "\nApplying gamma filter. Please wait!" << endl;
				filter = new FilterGamma(gamma);
				image = *filter << image;
				delete filter;
			}
			else if (strcmp(argv[arg_count], "blur") == 0)
			{
				//if the next arg is null
				if (!existsNext(argv, arg_count, 1)) return 0;

				//if we find alphabetical character
				if (!isNumber(argv[arg_count + 1])) return 0;

				blur_n = atoi(argv[arg_count += 1]);
				if (blur_n % 2 == 0)
				{
					cerr << "Parameter N of blur filter must be an odd number. Please try again!" << endl;
					return 0;
				}

				fx = new float[blur_n*blur_n];
				for (int i = 0; i < blur_n*blur_n; i++)	{ fx[i] = 1 / pow(blur_n, 2);};
				
				cout << "\nApplying blur filter. Please wait!" << endl;
				f = new Array2D<float>(blur_n, blur_n, fx);
				filter = new FilterBlur(blur_n, *f);
				image = *filter << image;
				delete filter;
				delete f;
			}
			else if (strcmp(argv[arg_count], "laplace") == 0)
			{
				cout << "\nApplying laplace filter. Please wait!" << endl;
				fx = new float[3 * 3]{0, 1, 0, 1, -4, 1, 0, 1, 0};
				f = new Array2D<float>(3, 3, fx);
				filter = new FilterLaplace(3, *f);
				image = *filter << image;
				delete filter;
				delete fx;
				delete f;
			}
			else
			{
				cerr << "No filter specified. Please try again!" << endl;
				return 0;
			}

			cout << "Completed filter number: " << filter_count<< endl;			
		}
		else
		{
			cerr << "Identifier \"-f\" not found. Please try again!" << endl;
			return 0;
		}
	}
	
	if (!image.save(img_name, "ppm"))return 0;
	cout << ">>FINISHED<<" << endl;
	return 0;
}

bool isNumber(string x)
{
	for (int char_no = 0; char_no < x.length(); char_no++)
	{
		if (isalpha(x[char_no]))
		{
			cerr << "Alphabetical character found in argument: \"" << x << "\". Must be numeric. Please try again!" << endl;
			return false;
		}
	}
	return true;
}

bool existsNext(char *argv[], int x , int y)
{
	if (argv[x + y] == NULL)
	{
		cerr << "An argument is missing from the end. Please try again!" << endl;
		return false;
	}
	return true;
}