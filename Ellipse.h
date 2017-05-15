//---------------------------------------------------------------------------

#ifndef EllipseH
#define EllipseH
#include <vcl.h>
#include <math.h>
#include "Ellipses.h"

class Ellipses
{
private:
	float a_, b_, e_, k_, phi_;
	float centre_X_, centre_Y_;
	Types::TPoint points[181];

public:
	//User sets values in the forms.
	setValue(float a, float b, float centreX, float centreY);

	//Drawing ellipse (polar coordinates formula).
	drawEllipse();

	//Multiplie coordinates and a coefficient.
	scaleEllipse(int p);

	//Rotate to the entered angle.
	turnEllipse(float phi);

	//Replace - change coordinates of the center to the entered.
	replaceEllipse(float centreX, float centreY);

	//Calculation of the area of an ellipse.
	calculateArea();

	//Calculation of the perimeter of an ellipse using the Ramanujans' formula.
	calculatePerimeter();
};
//---------------------------------------------------------------------------
#endif
