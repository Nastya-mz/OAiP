//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\Menu.cpp", Form1);
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\Polygons.cpp", Form5);
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\Rectangles.cpp", Form6);
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\Ellipses.cpp", Form2);
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\Houses.cpp", Form8);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
