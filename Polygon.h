//---------------------------------------------------------------------------

#ifndef PolygonH
#define PolygonH
#include <vcl.h>
#include "Polygons.h"

class Polygons
{
private:
	float centre_X_, centre_Y_, phi_, k_, incircle_, excircle_;
	int num_of_ver;
	Types::TPoint *points;

public:
	//User sets values in the forms.
	setValue(float centreX, float centreY, int size, float incircle);

	//Memory clearing.
	~Polygons();

	//Draw polygon.
	drawPolygon();

	//Calculation of the area of a polygone.
	calculateArea();

	//Calculation of the perimeter of a polygone.
	calculatePerimeter();

	//Redrawing of a polygone minding a cofficient.
	scalePolygon(int p);

	//Rotate to the entered angle.
	turnPolygon(float phi);

	//Replace - change coordinates of the center to the entered.
	replacePolygon (float centreX, float centreY);
};

//---------------------------------------------------------------------------
#endif

