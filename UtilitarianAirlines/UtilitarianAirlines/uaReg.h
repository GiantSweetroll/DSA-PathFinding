#pragma once

#include "wx/wx.h"
#include "wx/combobox.h"
#include "uaMethods.h"
#include "uaID.h"

class uaReg : public wxPanel
{
	//Constructor
public:
	uaReg(wxWindow* parent);
	~uaReg();

	//Fields:
private:
	wxStaticText* stName = nullptr;
	wxStaticText* stAge = nullptr;
	wxStaticText* stGender = nullptr;
	wxStaticText* stHeight = nullptr;
	wxStaticText* stWeight = nullptr;
	wxStaticText* stSpecialNeeds = nullptr;
	wxTextCtrl* tfFirstName = nullptr;
	wxTextCtrl* tfLastName = nullptr;
	wxTextCtrl* tfAge = nullptr;
	wxTextCtrl* tfHeight = nullptr;
	wxTextCtrl* tfWeight = nullptr;
	wxButton* btnNext = nullptr;
	wxButton* btnBack = nullptr;
	wxComboBox* cmbSex = nullptr;
	wxComboBox* cmbSpecialNeeds = nullptr;
};