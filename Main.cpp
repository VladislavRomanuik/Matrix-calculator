//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Matrix.h"
#include "IstrUser.h"
#include "InstrProgr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
int N, M, index;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VisibleComp(bool IsVisible)
{
	LBx->Visible = IsVisible;
	ComboBox2->Visible = IsVisible;
}

void __fastcall Print1(Matrix const& m, TStringGrid& s){m.Print(s);}
void __fastcall Print2(Matrix const& m, TStringGrid& s){m.Print2(s);}

void __fastcall TMainForm::SLRGrid()
{
	for(int i = 0; i < StringGrid1->ColCount; i++)
	{
		if (i == StringGrid1->ColCount - 1)
		{
			StringGrid1->Cells[i][0] = "res";
		}
		else
		{
			StringGrid1->Cells[i][0] = "x" + IntToStr(i + 1);
		}
	}

	for (int i = 1; i < StringGrid1->RowCount; i++)
	{
		for (int j = 0; j < StringGrid1->ColCount; j++)
		{
			if(StringGrid1->Cells[j][i] == "")
			{
				StringGrid1->Cells[j][i] = 0;
			}
		}
	}

	for (int i = 0; i < StringGrid3->RowCount; i++)
	{
		StringGrid3->Cells[0][i] = "X" + IntToStr(i + 1);
		if(StringGrid3->Cells[1][i] == "")
		{
			StringGrid3->Cells[1][i] = 0;
		}
	}
}

void __fastcall TMainForm::DefaultValueGrid(bool IsClear, TStringGrid& s)
{
	for(int i = 0; i < s.RowCount; i++)
	{
		for(int j = 0; j < s.ColCount; j++)
		{
			if(IsClear)
			{
				s.Cells[j][i] = 0;
            }
			else
			{
				if(s.Cells[j][i] == "")
				{
					s.Cells[j][i] = 0;
				}
			}

		}
	}
}

void __fastcall TMainForm::BtnTransMatrixClick(TObject *Sender)
{
	ComboBox1->Text = 3;
	ComboBox1->OnChange(Sender);
	PnFirstMatrix->Visible = true;
	PnSecondMatrix->Visible = false;
	PnResult->Visible = true;
	BtnCount->Visible = true;
	BtnClear->Visible = true;
	LBHint->Visible = true;
	VisibleComp(false);
	LBHint->Caption = "Виберіть розмірність матриць за допогою випадаючих списків. Заповніть матрицю";
	LBInfo->Caption = "Транспонована матриця";
	DefaultValueGrid(true, *StringGrid1);
	DefaultValueGrid(true, *StringGrid3);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnGaussMatrixClick(TObject *Sender)
{
	ComboBox1->Text = 3;
	ComboBox1->OnChange(Sender);
	PnFirstMatrix->Visible = true;
	PnSecondMatrix->Visible = false;
	PnResult->Visible = true;
	BtnCount->Visible = true;
	BtnClear->Visible = true;
	LBHint->Visible = true;
	VisibleComp(false);
	LBHint->Caption = "Виберіть розмірність матриць за допогою випадаючих списків. Заповніть матрицю";
	LBInfo->Caption = "Результат оберненої матриці А";
	DefaultValueGrid(true, *StringGrid1);
	DefaultValueGrid(true, *StringGrid3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ComboBox1Change(TObject *Sender)
{

	if(BtnTransMatrix->Down || BtnGaussMatrix->Down)
	{
		StringGrid1->RowCount = StrToInt(ComboBox1->Text);
		StringGrid1->ColCount = StrToInt(ComboBox1->Text);
		StringGrid1->Height = StringGrid1->RowCount*(StringGrid1->DefaultRowHeight + 6);
		StringGrid1->Width = StringGrid1->ColCount*(StringGrid1->DefaultColWidth + 6);
	}

	if (BtnSLR->Down)
	{
		StringGrid1->ColCount = StrToInt(ComboBox1->Text) + 1;
		StringGrid1->RowCount = StrToInt(ComboBox1->Text) + 1;
		StringGrid1->Height = StringGrid1->RowCount*(StringGrid1->DefaultRowHeight +  5);
		StringGrid1->Width = StringGrid1->ColCount*(StringGrid1->DefaultColWidth +  5);
		StringGrid3->RowCount = StrToInt(ComboBox1->Text);
		StringGrid3->Height = StringGrid3->RowCount*(StringGrid3->DefaultRowHeight + 5);
		SLRGrid();
	}

	DefaultValueGrid(false, *StringGrid1);
	DefaultValueGrid(false, *StringGrid2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ComboBox2Change(TObject *Sender)
{
	DefaultValueGrid(false, *StringGrid1);
	DefaultValueGrid(false, *StringGrid2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnCountClick(TObject *Sender)
{

	if(BtnTransMatrix->Down || BtnGaussMatrix->Down)
	{
		index = 0;
		N = StringGrid1->RowCount;
		Matrix A(N,N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				A.p[index] = StrToInt(StringGrid1->Cells[j][i]);
				index++;
			}
		}
		if(BtnTransMatrix->Down)
		{
			Print1(A.T(A), *StringGrid3);
		}
		if(BtnGaussMatrix->Down)
		{
			Print1(A.Inv(A), *StringGrid3);
		}
	}

	else if (BtnSLR->Down)
	{
		index = 0;
		N = StrToInt(ComboBox1->Text);
		Matrix A(N,N);
		for (int i = 1; i < StringGrid1->RowCount; i++)
		{
			for (int j = 0; j < (StringGrid1->ColCount - 1); j++)
			{
				A.p[index] = StrToInt(StringGrid1->Cells[j][i]);
				index++;
			}
		}

		index = 0;
		M = 1;
		Matrix B(N, M);
		for (int i = 1; i < StringGrid1->RowCount; i++)
		{
			B.p[index] = StrToInt(StringGrid1->Cells[StringGrid1->ColCount - 1][i]);
			index++;
		}

		Print2(A.Inv(A)*B, *StringGrid3);
	}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnClearClick(TObject *Sender)
{
	DefaultValueGrid(true, *StringGrid1);
	DefaultValueGrid(true, *StringGrid2);
	DefaultValueGrid(true, *StringGrid3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N1Click(TObject *Sender)
{
//	UserForm->Show();
ShellExecute(NULL, _T("open"), _T("userinstr.docx"), NULL, NULL, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender)
{
ShellExecute(NULL, _T("open"), _T("devinstr.docx"), NULL, NULL, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnSLRClick(TObject *Sender)
{
	ComboBox1->Text = 3;
	StringGrid3->ColCount = 2;
	StringGrid3->Width = StringGrid3->ColCount*(StringGrid3->DefaultColWidth + 4);
	ComboBox1->OnChange(Sender);
	SLRGrid();
	PnFirstMatrix->Visible = true;
	PnSecondMatrix->Visible = false;
	PnResult->Visible = true;
	BtnCount->Visible = true;
	BtnClear->Visible = true;
	LBHint->Visible = true;
	VisibleComp(false);
	LBHint->Caption = "Виберіть кількість невідомих в рівнянні за допомогою випадаючих списків. Заповніть таблицю";
	LBInfo->Caption = "Рішення СЛАР методом оберненої матриці";
	DefaultValueGrid(false, *StringGrid1);
	DefaultValueGrid(false, *StringGrid3);
}
//---------------------------------------------------------------------------
// код для других разрешений
void __fastcall TMainForm::FormCreate(TObject *Sender)
{

	struct res{float x,y;}res;

	struct factor{float x,y;}factor;

	res.x=Screen->Width;
	res.y=Screen->Height;
	// вместо 1920 и 1080 нужно написать разрешение окна, в котором пишете
	factor.x=1920/res.x;
	factor.y=1080/res.y;
	int cc=ControlCount-1; //количество объектов на форме
	while(cc!=-1)
	{
		Controls[cc]->Left/=factor.x; //правильно располагаем по горизонтали
		Controls[cc]->Top/=factor.y; //по вертикали
		Controls[cc]->Width/=factor.x; //растягиваем до нужной ширины
		Controls[cc]->Height/=factor.y; //…высоты
		cc--;
	}
	//теперь растягиваем саму форму
	MainForm->Width/=factor.x;
	MainForm->Height/=factor.y;

	MainForm->PixelsPerInch=Screen->PixelsPerInch;
	// FULL WINDOW
	//MainForm->SetBounds( 0, 0, Screen->Width, Screen->Height );

}
//---------------------------------------------------------------------------



