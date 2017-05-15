//---------------------------------------------------------------------------

#pragma hdrstop
#include "Rectangle.h"
#include "Rectangles.h"
//Set the entered values.
Rectangles::setValue(float centreX, float centreY, float len, float wid)
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

	Form6->Canvas->Brush->Color = clWhite;
	drawRectangle();
}

//Draw rectangle.
Rectangles::drawRectangle()
{
	Form6->Repaint();
	Form6->Canvas->MoveTo(x[0], y[0]);

	for (int i = 1; i < 4; i++)
	{
		Form6->Canvas->LineTo(x[i], y[i]);
	}

	Form6->Canvas->LineTo(x[0], y[0]);
}

//Calculation of the area of a rectangle.
Rectangles::calculateArea()
{
	return len_ * wid_;
}

//Calculation of the perimeter of a rectangle.
Rectangles::calculatePerimeter()
{
	return 2 * (len_ + wid_);
}

//Multiplie coordinates and a coefficient.
Rectangles::scaleRectangle(int p)
{
	k_ += p;
	for (int i = 0; i < 4; i++)
	{
		x[0] = centre_X_ - k_ * len_ / 2 / 10;
		y[0] = centre_Y_ - k_ * wid_ / 2 / 10;
		x[2] = centre_X_ + k_ * len_ / 2 / 10;
		y[2] = centre_Y_ + k_ * wid_ / 2 / 10;

		x[1] = x[2];
		y[1] = y[0];
		x[3] = x[0];
		y[3] = y[2];
	}

	for (int i = 0; i < 4; i++)
	{
		float temp_x = x[i];
		float temp_y = y[i];

		x[i] = centre_X_ + (cos(phi_) * (temp_x - centre_X_) - sin(phi_) * (temp_y - centre_Y_));
		y[i] = centre_Y_ + (sin(phi_) * (temp_x - centre_X_) + cos(phi_) * (temp_y - centre_Y_));
	}

	drawRectangle();
}

//Rotate to the entered angle.
Rectangles::turnRectangle(float phi)
{
	float angle;

	for (angle = 0; angle < phi; angle += 1)
	{
		float delta = M_PI / 180;

		for (int i = 0; i < 4; i++)
		{
			float temp_x = x[i];
			float temp_y = y[i];

			x[i] = centre_X_ + cos(delta) * (temp_x - centre_X_) - sin(delta) * (temp_y - centre_Y_);
			y[i] = centre_Y_ + sin(delta) * (temp_x - centre_X_) + cos(delta) * (temp_y - centre_Y_);
		}

		drawRectangle();

		Sleep(10);
	}

	angle *= M_PI / 180;
	phi *= M_PI / 180;
	phi_ += phi;

	for (int i = 0; i < 4; i++)
	{
		float temp_x = x[i];
		float temp_y = y[i];

		x[i] = centre_X_ + cos(-angle) * (temp_x - centre_X_) - sin(-angle) * (temp_y - centre_Y_);
		y[i] = centre_Y_ + sin(-angle) * (temp_x - centre_X_) + cos(-angle) * (temp_y - centre_Y_);

		temp_x = x[i];
		temp_y = y[i];

		x[i] = centre_X_ + cos(phi) * (temp_x - centre_X_) - sin(phi) * (temp_y - centre_Y_);
		y[i] = centre_Y_ + sin(phi) * (temp_x - centre_X_) + cos(phi) * (temp_y - centre_Y_);
	}

	drawRectangle();
}

//Change coordinates of the center to the entered.
Rectangles::replaceRectangle (float centreX, float centreY)
{
	float sx = (centreX - centre_X_) / 100;
	float sy = (centreY - centre_Y_) / 100;

	for (int i = 0; i < 100; i++)
	{
		centre_X_ += sx;
		centre_Y_ += sy;

		for (int i = 0; i < 4; i++)
		{
			x[i] += sx;
			y[i] += sy;
		}
		drawRectangle();

		Sleep(10);
	}
}
