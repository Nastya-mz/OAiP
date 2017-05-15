//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Ellipses.h"
#include "Ellipse.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Ellipses ell;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	float centreX = StrToFloat(Edit1->Text);//x center coordinate
	float centreY = StrToFloat(Edit2->Text);//y center coordinate

	float a = StrToFloat(Edit3->Text);//major axis
	float b = StrToFloat(Edit4->Text);//minor axis

	ell.setValue(a, b, centreX, centreY);

	Panel1->Caption = "100";
	Panel2->Caption = FloatToStr(ell.calculateArea());//show area
	Panel3->Caption = FloatToStr(ell.calculatePerimeter());//show perimeter
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	float m = StrToFloat(Panel1->Caption);//zoom out

	ell.scaleEllipse(-1);

	Panel1->Caption = FloatToStr(m - 10);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	float k = StrToFloat(Panel1->Caption);//zoom in

	ell.scaleEllipse(1);

	Panel1->Caption = FloatToStr(k + 10);
}

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	float a = StrToFloat(Edit5->Text);//turn

	ell.turnEllipse(a);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
	float newCentreX = StrToFloat(Edit6->Text);//new x center coordinate
	float newCentreY = StrToFloat(Edit7->Text);//new y center coordinate

	ell.replaceEllipse(newCentreX, newCentreY);
}
//---------------------------------------------------------------------------

