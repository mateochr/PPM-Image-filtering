# PPM Image filtering
Applying filters on images with ppm format using C++

## The Filters
Every filter except laplace has parameters.
* gamma: Has 1 parameter γ, every color channel of the pixel is raised to the power of γ.
* linear: Has 6 parameters, 2 for each color channel of the pixel. Each channel is multiplied with and then added to the correspondant values. 
* laplace: Edge detector. Each pixel is a weighted sum of it's 3x3 neighboring valid pixels. The weights are determined by a specidied 3x3 matrix.
* blur: Has 1 parameter N. Each pixel is the average value of it's NxN neighboring valid pixels.

## HowTo
1. Download all files into one folder. 
2. Open Assignment.sln with visual studio (created on visual studio 2013) 
3. Build the solution.
4. Go to Debug/Release folder, depending on which build you did.
5. Open cmd
6. Use filterd etc./filter etc. depending on which build you did. (Release is faster)

**input image must be in the same folder**

To transform an image input.ppm into it's negative version and save it as filtered_input.ppm 

`filter -f linear -1 -1 -1 1 1 1 input.ppm`

You can also supply a list of multiple filters to be applied successively, for example

`filter -f laplace -f blur 3 -f gamma 2 -f linear 2 2 2 0 0 0 -f blur 1 input.ppm`
