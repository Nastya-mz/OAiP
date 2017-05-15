//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ellipse.h"
#include "Ellipses.h"

//User sets values in the form.
Ellipses::setValue(float a, float b, float centreX, float centreY)
{
	a_ = a;
	b_ = b;
	centre_X_ = centreX;
	centre_Y_ = centreY;
	e_ = sqrt(1 - powl(b/a, 2));
	k_ = 10;
	phi_ = 0;

	drawEllipse();
}

//Drawing ellipse (polar coordinates formula).
Ellipses::drawEllipse()
{
	Form2->Repaint();

	for (int i = 0, n = 0; i < 360; i += 2, n++)
	{
		float phi_rad = M_PI * i / 180;

		float r = k_ / 10*b_ / sqrt(1 - pow(e_*cos(phi_rad), 2));

		points[n].x = centre_X_ + r * cos(phi_rad + phi_);
		points[n].y = centre_Y_ + r * sin(phi_rad + phi_);
	}

	points[180] = points[0];

	Form2->Canvas->Brush->Color = clWhite;
	Form2->Canvas->Polygon(points, 180);
}

//Multiplie coordinates and a coefficient.
Ellipses::scaleEllipse(int p)
{
	k_ += p;
	drawEllipse();
}

//Rotate to the entered angle.
Ellipses::turnEllipse(float phi)
{
	for (int i = 1; i <= phi; i++)
	{
		phi_ += M_PI / 180;
		drawEllipse();

		Sleep(10);
	}
	phi_ += (phi - (int)phi) * M_PI / 180;
	drawEllipse();
}

//Replace - change coordinates of the center to the entered.
Ellipses::replaceEllipse(float centreX, float centreY)
{
	float sx = (centreX - centre_X_)/100;
	float sy = (centreY - centre_Y_)/100;
	for (int i = 0; i < 100; i++)
	{
		centre_X_ += sx;
		centre_Y_ += sy;

		drawEllipse();

		Sleep(10);
	}
}

//Calculation of the area of an ellipse.
Ellipses::calculateArea()
{
	return M_PI * a_ * b_;
}

//Calculation of the perimeter of an ellipse using the Ramanujans' formula.
Ellipses::calculatePerimeter()
{
	return M_PI * (3 * (a_ + b_) - sqrt((3 * a_ + b_) * (a_ + 3 * b_)));
}
