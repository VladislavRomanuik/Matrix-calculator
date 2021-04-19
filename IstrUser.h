//---------------------------------------------------------------------------

#ifndef IstrUserH
#define IstrUserH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TUserForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
private:	// User declarations
public:		// User declarations
	__fastcall TUserForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUserForm *UserForm;
//---------------------------------------------------------------------------
#endif
