#include <iostream>
#include <fstream>
#include <string>
#include <cmath>   

using namespace std;

namespace image{

	float * ReadPPM(const char * filename, int * w, int * h){

		string line;
		string format;
		int max_val = 0;

		ifstream file(filename, ios::in | ios::binary);
		if (!file.is_open()){
			cout << "Cannot open file" << endl;
			return nullptr;
		}
		else{

			file >> line;
			if (line != "P6"){
				cout << "Image's format is not P6 " << endl;
				return nullptr;
			}


			file >> line;
			if (line.size() > 100){
				cerr << "Data from the header is missing. Please try again!" << endl;
				return nullptr;
			}
			for (unsigned i = 0; i < line.length(); ++i){
				if (isalpha(line[i])){
					cout << "Alphabetical character found in width" << endl;
					return nullptr;
				}
			}
			*w = stoi(line);


			file >> line;
			if (line.size() > 100){
				cerr << "Data from the header is missing. Please try again!" << endl;
				return nullptr;
			}
			for (unsigned i = 0; i < line.length(); ++i){
				if (isalpha(line[i])){
					cout << "Alphabetical character found in height" << endl;
					return nullptr;
				}
			}
			*h = stoi(line);


			file >> line;
			if (line.size() > 100){
				cerr << "Data from the header is missing. Please try again!" << endl;
				return nullptr;
			}
			for (unsigned i = 0; i < line.length(); ++i){
				if (isalpha(line[i])){
					cout << "Alphabetical character found in maximum value" << endl;
					return nullptr;
				}
			}
			max_val = stoi(line);
			
			if (max_val > 255){
				cout << "Maximum pixel value greater than 255!" << endl;
				return nullptr;
			}

			int binary_int;
			int i = 0;
			int image_size = 3 * (*w) * (*h);
			float* pixels_arr = new float[image_size];

			binary_int = file.get();
			while (binary_int == 32 || binary_int == 10 || binary_int == 9){
				binary_int = file.get();
			}
			while (!file.eof()){
				//If not eof
				if (binary_int != -1){
					//Normalize and store to pixels_arr 
					pixels_arr[i] = binary_int / 255.f;
					i++;
				}
				binary_int = file.get();
			}
			file.close();
			return pixels_arr;
		}
	}

	bool WritePPM(const float * data, int w, int h, const char * filename){

		if (data == nullptr){
			return false;
		}

		ofstream file(filename, ios::out | ios::binary);
		if (!file.is_open()) {
			cout << "Cannot open file" << endl;
			return false;

		}
		else{
			file << "P6" << endl << w << endl << h << endl << "255" << endl;
			char rgb[3];
			for (unsigned i = 0; i <= 3 * h*w; i = i + 3){

				rgb[0] = data[i] * 255;
				rgb[1] = data[i + 1] * 255;
				rgb[2] = data[i + 2] * 255;

				file.write((char*)rgb, 3);
			}
			return true;
		}
	}
}

