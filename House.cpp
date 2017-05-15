//---------------------------------------------------------------------------

#pragma hdrstop

#include "House.h"
#include "Houses.h"
//Set value.
Rec::setValue(float centreX, float centreY, float len, float wid)
{
	centre_X_ = centreX;
	centre_Y_ = centreY;
	k_ = 10;
	phi_ = 0;
	len_ = len;
	wid_ = wid;
	x[0] = centre_X_ - k_ * len / 2 / 10;
	y[0] = centre_Y_ - k_ * wid / 2 / 10;
	x[2] = centre_X_ + k_ * len / 2 / 10;
	y[2] = centre_Y_ + k_ * wid / 2 / 10;

	x[1] = x[2];
	y[1] = y[0];
	x[3] = x[0];
	y[3] = y[2];


	drawRectangle();
}

//Draw rectangle.
Rec::drawRectangle()
{
	Form8->Canvas->MoveTo(x[0], y[0]);

	for (int i = 1; i < 4; i++)
	{
		Form8->Canvas->LineTo(x[i], y[i]);
	}

	Form8->Canvas->LineTo(x[0], y[0]);
}

//Change coordinates of the center.
Rec::replaceRectangle (float centreX, float centreY)
{
	float sx = (centreX - centre_X_) / 100;
	float sy = (centreY - centre_Y_) / 100;

	for (int i = 0; i < 100; i++)
	{
		centre_X_ += sx;
		centre_Y_ += sy;

		Form8->Canvas->Pen->Color = clWhite;

		drawRectangle();

		for (int i = 0; i < 4; i++)
		{
			x[i] += sx;
			y[i] += sy;
		}

		Form8->Canvas->Pen->Color = clBlack;

		drawRectangle();

		Sleep(10);
	}
}
