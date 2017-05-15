//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Houses.h"
#include "House.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
Rec rec;
Rec rec1;
Rec rec2;
Rec rec3;
Rec rec4;
Rec rec5;
Rec rec6;
Rec rec7;
Rec rec8;
Rec rec9;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
	DoubleBuffered = true;
}
void __fastcall TForm8::Button5Click(TObject *Sender)
{
	Form8->Repaint();
	rec.setValue(310, 300, 320, 260);
	rec1.setValue(230, 235, 50, 61);

	rec2.setValue(242.5, 235, 24, 59 );//right part of the left window
	rec3.setValue(217.5, 235, 24, 59);//left part of the left window
	rec4.setValue(390, 235, 50, 61);
	rec5.setValue(402.5, 235, 24, 59);//right part of the right window
	rec6.setValue(377.5, 235, 24, 59);//left part of the right window
	rec7.setValue(310, 380, 100, 100);
	rec8.setValue(335, 380, 48, 98);//right door
	rec9.setValue(285, 380, 48, 98);//left door
	Form8->Canvas->MoveTo(150, 170);
	Form8->Canvas->LineTo(310, 110);
	Form8->Canvas->LineTo(470, 170);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	rec2.replaceRectangle(255, 235);//open the right part of the left window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button6Click(TObject *Sender)
{
	rec3.replaceRectangle(205, 235);//open the left part of the left window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button7Click(TObject *Sender)
{
	rec5.replaceRectangle(415, 235);//open the right part of the right window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button8Click(TObject *Sender)
{
	rec6.replaceRectangle(365, 235);//open the left part of the right window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button2Click(TObject *Sender)
{
	rec2.replaceRectangle(242.5, 235);//close the right part of the left window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button10Click(TObject *Sender)
{
	rec3.replaceRectangle(217.5, 235);//close the left part of the left window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button9Click(TObject *Sender)
{
	rec5.replaceRectangle(402.5, 235);//close the right part of the right window
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button11Click(TObject *Sender)
{
	rec6.replaceRectangle(377.5, 235);//close the left part of the right window
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Button3Click(TObject *Sender)
{
	rec9.replaceRectangle(235, 380);//open the right door
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button12Click(TObject *Sender)
{
	rec8.replaceRectangle(385, 380);//open the left door
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button4Click(TObject *Sender)
{
	rec9.replaceRectangle(285, 380);//close the right door
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button13Click(TObject *Sender)
{
	rec8.replaceRectangle(335, 380);//close the left door
}
//---------------------------------------------------------------------------

