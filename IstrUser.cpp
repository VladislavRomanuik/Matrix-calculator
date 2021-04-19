//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IstrUser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUserForm *UserForm;
//---------------------------------------------------------------------------
__fastcall TUserForm::TUserForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
