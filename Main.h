//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *BtnTransMatrix;
	TSpeedButton *BtnGaussMatrix;
	TPanel *PnFirstMatrix;
	TPanel *PnSecondMatrix;
	TLabel *LBNameMatrix;
	TComboBox *ComboBox1;
	TLabel *LBx;
	TComboBox *ComboBox2;
	TLabel *Label3;
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TLabel *LBHint;
	TBitBtn *BtnCount;
	TPanel *PnResult;
	TLabel *LBInfo;
	TStringGrid *StringGrid3;
	TLabel *Label2;
	TBitBtn *BtnClear;
	TSpeedButton *BtnSLR;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TPanel *Panel1;
	void __fastcall BtnTransMatrixClick(TObject *Sender);
	void __fastcall BtnGaussMatrixClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall BtnCountClick(TObject *Sender);
	void __fastcall BtnClearClick(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall BtnSLRClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void __fastcall SLRGrid();
	void __fastcall DefaultValueGrid(bool IsClear, TStringGrid& s);
	void __fastcall VisibleComp(bool IsVisible);
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
