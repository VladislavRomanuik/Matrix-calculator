//---------------------------------------------------------------------------

#ifndef InstrProgrH
#define InstrProgrH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TProgrForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
private:	// User declarations
public:		// User declarations
	__fastcall TProgrForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgrForm *ProgrForm;
//---------------------------------------------------------------------------
#endif
