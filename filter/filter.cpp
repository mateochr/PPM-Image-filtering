#include "filter.h"
#include <string>



namespace image
{

	Filter::Filter() {}

	string Filter::getFilterName() {
		return filtername;
	}

	Filter::Filter(const Filter &src){
		filtername = src.filtername;
	}
}