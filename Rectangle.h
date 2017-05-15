//---------------------------------------------------------------------------

#ifndef RectangleH
#define RectangleH
#include <math.h>
#include <vcl.h>
#include "Rectangles.h"

class Rectangles
{
protected:
	float centre_X_, centre_Y_, phi_, k_, len_, wid_;
	float x[4];
	float y[4];

public:
	//Set value.
	setValue(float centreX, float centreY, float len, float wid);

	//Draw rectangle
	drawRectangle();

	//Calculation of the area of a rectangle
	calculateArea();

	//Calculation of the perimeter of a rectangle
	calculatePerimeter();

	//Scale - multiplie coordinates and a coefficient
	scaleRectangle(int p);

	//Rotate to the entered angle
	turnRectangle(float phi);

	//Replace - change coordinates of the center to the entered
	replaceRectangle (float centreX, float centreY);
};
//---------------------------------------------------------------------------
#endif
