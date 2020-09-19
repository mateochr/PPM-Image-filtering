# Main project

*info can be found in every .h file*

## Array2D class

* array2d.h: declaration of templated class Array2D
* arrat2d.hpp: definition of every function of array2d.h

## Image class
Derived  of Array2D<Vec3<float>> and ImageIO

* imageio.h: abstract class
* image.h: declaration of load() and save() inherited from imageio.h
* image.cpp: definition of load() and save()

In this class every pixel is presented as an object of the Vec3 class stored
in the linear buffer that is inherited from Array2D.

## Filter class

Base class for all filters, includes a pure virtual function `virtual Image operator << (const Image & img) = 0;`
that acts on an image producing a new one. This function is implemented differently by each derived class of Filter(Polymorphism).


