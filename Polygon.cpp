#include "Polygon.h"
#include "Polygons.h"
#include <math.h>

//User sets values in the form.
Polygons::setValue(float centreX, float centreY, int size, float incircle)
{
	centre_X_ = centreX;
	centre_Y_ = centreY;
	k_ = 10;
	phi_ = 0;
	num_of_ver = size;
	incircle_ = incircle;
	excircle_ = incircle_ / cos(M_PI / num_of_ver);
	points = new Types::TPoint[size];

	for (int i = 0; i < num_of_ver; i++)
	{
		points[i].x = centre_X_ + k_ * excircle_ * cos(3 * M_PI / 2 + 2 * M_PI * i / num_of_ver) / 10;
		points[i].y = centre_Y_ + k_ * excircle_ * sin(3 * M_PI / 2 + 2 * M_PI * i / num_of_ver) / 10;
	}

	Form5->Canvas->Brush->Color = clWhite;
	drawPolygon();
}

//Memory clearing.
Polygons::~Polygons()
{
	delete [] points;
}

//Draw polygon.
Polygons::drawPolygon()
{
	Form5->Repaint();
	Form5->Canvas->Polygon(points, num_of_ver - 1);
}

//Ñalculation of the area of a polygone.
Polygons::calculateArea()
{
	return pow(incircle_, 2) * num_of_ver * tan(M_PI / num_of_ver);
}

//Ñalculation of the perimeter of a polygone.
Polygons::calculatePerimeter()
{
	return 2 * incircle_ * num_of_ver * tan(M_PI / num_of_ver);
}

//Redrawing of a polygone minding a cofficient.
Polygons::scalePolygon(int p)
{
	k_ += p;
	for (int i = 0; i < num_of_ver; i++)
	{
		points[i].x = centre_X_ + k_ * excircle_ * cos(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
		points[i].y = centre_Y_ + k_ * excircle_ * sin(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
	}
	drawPolygon();
}

//Rotate to the entered angle.
Polygons::turnPolygon(float phi)
{
	float angle;

	for (angle = 0; angle < phi; angle++)
	{
		phi_ += M_PI / 180;

		for (int i = 0; i < 4; i++)
		{
			points[i].x = centre_X_ + k_ * excircle_ * cos(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
			points[i].y = centre_Y_ + k_ * excircle_ * sin(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
		}

		drawPolygon();

		Sleep(10);
	}

	phi_ -= angle;
	phi_ += phi;

	for (int i = 0; i < num_of_ver; i++)
	{
		points[i].x = centre_X_ + k_ * excircle_ * cos(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
		points[i].y = centre_Y_ + k_ * excircle_ * sin(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
	}

	drawPolygon();
}

//Change coordinates of the center to the entered.
Polygons::replacePolygon (float centreX, float centreY)
{
	float sx = (centreX - centre_X_) / 100;
	float sy = (centreY - centre_Y_) / 100;
	for (int i = 0; i < 100; i++)
	{
		centre_X_ += sx;
		centre_Y_ += sy;

		for (int i = 0; i < num_of_ver; i++)
		{
			points[i].x = centre_X_ + k_ * excircle_ * cos(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
			points[i].y = centre_Y_ + k_ * excircle_ * sin(3 * M_PI / 2 + phi_ + 2 * M_PI * i / num_of_ver) / 10;
		}

		drawPolygon();

		Sleep(10);
	}
}

