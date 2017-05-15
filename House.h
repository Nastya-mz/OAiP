#ifndef HouseH
#define HouseH
#include <math.h>
#include <vcl.h>
#include "Houses.h"
#include "Rectangle.h"

/*All the house(accepting the roof) consists of rectangles, that is why I
chose class Rectangles as a parent class.*/
class Rec : public Rectangles
{
public:
	//Set value
	setValue(float centreX, float centreY, float len, float wid);

	//Draw rectangle
	drawRectangle();

	//Change coordinates of the center
	replaceRectangle (float centreX, float centreY);
};
//---------------------------------------------------------------------------
#endif
