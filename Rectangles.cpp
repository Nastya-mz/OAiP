//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rectangles.h"
#include "Rectangle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
Rectangles rec;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	float centreX = StrToFloat(Edit1->Text);//x center coordinate
	float centreY = StrToFloat(Edit2->Text);//y center coordinate

	float len = StrToFloat(Edit3->Text);//length
	float wid = StrToFloat(Edit4->Text);//width

	rec.setValue(centreX, centreY, len, wid);

	Panel1->Caption = "100";
	Panel2->Caption = FloatToStr(rec.calculateArea());//show area
	Panel3->Caption = FloatToStr(rec.calculatePerimeter());//show perimeter
}

void __fastcall TForm6::Button2Click(TObject *Sender)
{
	float m = StrToFloat(Panel1->Caption);//zoom out

	if (m != 10)
	{
		rec.scaleRectangle(-1);

		Panel1->Caption = FloatToStr(m - 10);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button3Click(TObject *Sender)
{
	float m = StrToFloat(Panel1->Caption);//zoom in

	rec.scaleRectangle(1);

	Panel1->Caption = FloatToStr(m + 10);
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button4Click(TObject *Sender)
{
	float a = StrToFloat(Edit5->Text);//rotate to the entered angle

	rec.turnRectangle(a);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button5Click(TObject *Sender)
{
	float newCentreX = StrToFloat(Edit6->Text);//new x center coordinate
	float newCentreY = StrToFloat(Edit7->Text);//new y center coordinate

	rec.replaceRectangle(newCentreX, newCentreY);
}
//---------------------------------------------------------------------------

