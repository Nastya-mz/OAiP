//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Polygons.h"
#include "Polygon.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
Polygons pol;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
   DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	//The number of sides.
	float n = StrToFloat(Edit4->Text);

	//X center coordinate.
	float centreX = StrToFloat(Edit1->Text);
	//Y center coordinate.
	float centreY = StrToFloat(Edit2->Text);

	//Incircle radius.
	float r = StrToFloat(Edit3->Text);

	pol.setValue(centreX, centreY, n, r);

	Panel1->Caption = "100";
	//Show area.
	Panel2->Caption = FloatToStr(pol.calculateArea());
	//Show perimeter.
	Panel3->Caption = FloatToStr(pol.calculatePerimeter());
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Button2Click(TObject *Sender)
{
	//Zoom out.
	float m = StrToFloat(Panel1->Caption);

	pol.scalePolygon(-1);

	Panel1->Caption = FloatToStr(m - 10);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button3Click(TObject *Sender)
{
	//Zoom in.
	float m = StrToFloat(Panel1->Caption);

	pol.scalePolygon(1);

	Panel1->Caption = FloatToStr(m + 10);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button4Click(TObject *Sender)
{
	//Turn.
	float a = StrToFloat(Edit5->Text);

	pol.turnPolygon(a);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button5Click(TObject *Sender)
{
	//New x center coordinate.
	float newCentreX = StrToFloat(Edit6->Text);
	//New y center coordinate.
	float newCentreY = StrToFloat(Edit7->Text);

	pol.replacePolygon(newCentreX, newCentreY);
}
//---------------------------------------------------------------------------

