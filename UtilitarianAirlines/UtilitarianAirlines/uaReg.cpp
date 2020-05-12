#include "uaReg.h"

uaReg::uaReg(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	//Initialization
	stName = new wxStaticText(this, wxID_ANY, "   Customer Name");
	stAge = new wxStaticText(this, wxID_ANY, "   Age");
	stGender = new wxStaticText(this, wxID_ANY, "   Gender");
	stHeight = new wxStaticText(this, wxID_ANY, "   Height (m)");
	stWeight = new wxStaticText(this, wxID_ANY, "   Weight (Kg)");
	stSpecialNeeds = new wxStaticText(this, wxID_ANY, "   Special Needs");
	tfFirstName = new wxTextCtrl(this, wxID_ANY);
	tfLastName = new wxTextCtrl(this, wxID_ANY);
	tfAge = new wxTextCtrl(this, wxID_ANY);
	tfHeight = new wxTextCtrl(this, wxID_ANY);
	tfWeight = new wxTextCtrl(this, wxID_ANY);
	btnNext = new wxButton(this, uaID::c_btnRegNext, "Next");
	btnBack = new wxButton(this, uaID::c_btnRegBack, "Back");
	cmbSex = new wxComboBox(this, wxID_ANY, "Male");
	cmbSpecialNeeds = new wxComboBox(this, wxID_ANY, "None");
	wxGridSizer* grid = new wxGridSizer(5, 0, 0);

	//Properties
	tfFirstName->SetHint("First Name");
	tfLastName->SetHint("Last Name");
	cmbSex->SetEditable(false);
	cmbSex->Append(_("Male"));
	cmbSex->Append(_("Female"));
	cmbSex->Append(_("Rather not specify"));
	cmbSpecialNeeds->SetEditable(false);
	cmbSpecialNeeds->Append("None");
	cmbSpecialNeeds->Append("Cannot walkness");
	cmbSpecialNeeds->Append("Blind");
	cmbSpecialNeeds->Append("Mental Illness");
	cmbSpecialNeeds->Append("Sick");
	cmbSpecialNeeds->Append("Muscle Atrophy");
	cmbSpecialNeeds->Append("Bone Stuff");

	//Add to sizer
	grid->Add(stName);
	grid->Add(tfFirstName);
	uaMethods::insertFillers(grid, 4);
	grid->Add(tfLastName);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stAge);
	grid->Add(tfAge);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stGender);
	grid->Add(cmbSex);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stHeight);
	grid->Add(tfHeight);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stWeight);
	grid->Add(tfWeight);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stSpecialNeeds);
	grid->Add(cmbSpecialNeeds);
	uaMethods::insertFillers(grid, 3);
	grid->Add(btnNext, wxSizerFlags().Expand());
	uaMethods::insertFillers(grid, 14);
	grid->Add(btnBack, wxSizerFlags().Expand());

	this->SetSizer(grid);
	this->Layout();
}

uaReg::~uaReg()
{

}