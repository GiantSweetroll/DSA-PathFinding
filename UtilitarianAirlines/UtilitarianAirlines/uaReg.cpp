#include "uaReg.h"

wxBEGIN_EVENT_TABLE(uaReg, wxPanel)
	EVT_BUTTON(uaID::c_btnRegNextStart, onNextStartClick)
	EVT_BUTTON(uaID::c_btnRegNextReg, onNextRegClick)
	EVT_BUTTON(uaID::c_btnRegBackReg, onBackRegClick)
	EVT_BUTTON(uaID::c_btnRegBackSeat, onBackSeatClick)
	EVT_BUTTON(uaID::c_btnRegMainMenu, onMainMenuClick)
wxEND_EVENT_TABLE()

uaReg::uaReg(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	//Initialization
	progress = new wxStaticBitmap(this, wxID_ANY, wxBitmap("Linear_1.bmp", wxBITMAP_TYPE_BMP));
	currentPage = new wxStaticBitmap(this, wxID_ANY, wxBitmap("banner_start.bmp", wxBITMAP_TYPE_BMP));
	initStartPage();
	initRegPage();
	mainSizer = new wxBoxSizer(wxVERTICAL);

	//Add to sizer
	mainSizer->Add(progress);
	mainSizer->Add(currentPage);
	mainSizer->Add(panelStart, wxSizerFlags().Expand());

	this->SetSizer(mainSizer);
	this->Layout();
}

uaReg::~uaReg()
{

}

void uaReg::initStartPage()
{
	//Initialization
	panelStart = new wxPanel(this, wxID_ANY);
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* txtBtnSizer = new wxBoxSizer(wxVERTICAL);
	stStart = new wxStaticText(panelStart, wxID_ANY, "Welcome to Utilitarian Airlines\n\nWe are here to provide the best seating for your flight's safety\n\nTo start registering to our services, please click the 'Next' button to proceed \n\n");
	btnNextStart = new wxButton(panelStart, uaID::c_btnRegNextStart, "Next");
	logo = new wxStaticBitmap(panelStart, wxID_ANY, wxBitmap("logo.bmp", wxBITMAP_TYPE_BMP));

	//Properties
	stStart->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	btnNextStart->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	//Add to sizer
	sizer->Add(logo);
	sizer->AddSpacer(50);
	txtBtnSizer->Add(stStart);
	txtBtnSizer->Add(btnNextStart);
	sizer->Add(txtBtnSizer);

	panelStart->SetSizer(sizer);
	panelStart->Layout();
}

void uaReg::initRegPage()
{
	//Initialization
	panelReg = new wxPanel(this, wxID_ANY);
	wxBoxSizer* box = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* btnBox = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer* grid = new wxGridSizer(5, 5, 5);
	stName = new wxStaticText(panelReg, wxID_ANY, "Customer Name");
	stAge = new wxStaticText(panelReg, wxID_ANY, "Age");
	stGender = new wxStaticText(panelReg, wxID_ANY, "Gender");
	stEmail = new wxStaticText(panelReg, wxID_ANY, "Email");
	stHeight = new wxStaticText(panelReg, wxID_ANY, "Height (m)");
	stWeight = new wxStaticText(panelReg, wxID_ANY, "Weight (Kg)");
	stSpecialNeeds = new wxStaticText(panelReg, wxID_ANY, "Special Needs");
	stDisclaimer = new wxStaticText(panelReg, wxID_ANY, "All information remains confidential and will only be used to determine the best seating for you.");
	tfFirstName = new wxTextCtrl(panelReg, wxID_ANY);
	tfLastName = new wxTextCtrl(panelReg, wxID_ANY);
	tfAge = new wxTextCtrl(panelReg, wxID_ANY);
	tfHeight = new wxTextCtrl(panelReg, wxID_ANY);
	tfWeight = new wxTextCtrl(panelReg, wxID_ANY);
	tfEmail = new wxTextCtrl(panelReg, wxID_ANY);
	cmbSex = new wxComboBox(panelReg, wxID_ANY, "Male");
	cmbSpecialNeeds = new wxComboBox(panelReg, wxID_ANY, "None");
	btnNextReg = new wxButton(panelReg, uaID::c_btnRegNextReg, "Next");
	btnBackReg = new wxButton(panelReg, uaID::c_btnRegBackReg, "Back");

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
	panelReg->Hide();

	//Add to sizer
	//Grid
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
	grid->Add(stEmail);
	grid->Add(tfEmail);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stHeight);
	grid->Add(tfHeight);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stWeight);
	grid->Add(tfWeight);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stSpecialNeeds);
	grid->Add(cmbSpecialNeeds);
	//Buttons
	btnBox->Add(btnNextReg);
	btnBox->Add(btnBackReg);
	//Box
	box->Add(grid);
	box->Add(stDisclaimer);
	box->Add(btnBox, wxSizerFlags().Expand());

	panelReg->SetSizer(box);
	panelReg->Layout();
}

void uaReg::initSeatPage()
{
	//Initialization
	panelSeat = new wxPanel(this, wxID_ANY);
	btnBackSeat = new wxButton(panelSeat, uaID::c_btnRegBackSeat, "Back");
	btnMainMenu = new wxButton(panelSeat, uaID::c_btnRegMainMenu, "Main Menu");
	stSeatNum = new wxStaticText(panelSeat, wxID_ANY, "A1");
	wxStaticText* st1 = new wxStaticText(panelSeat, wxID_ANY, "According to your registration your seat will be at:");
	wxStaticText* st2 = new wxStaticText(panelSeat, wxID_ANY, "Please enjoy your flight,\nThank you for choosing");
	wxStaticText* st3 = new wxStaticText(panelSeat, wxID_ANY, "Utilitarian Airlines");
	wxStaticText* st4 = new wxStaticText(panelSeat, wxID_ANY, "Remember to always check your seat because it might change according to others, we will be sending you an email of the final seating 3 days before the flight. Thank you.");
	wxGridSizer* seating = nullptr;	//TODO: replace this with the generate seating sizer method.
	wxBoxSizer* leftBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* btnBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

	//Properties
	panelSeat->Hide();

	//Add to sizer
	btnBox->Add(btnBackSeat);
	btnBox->AddSpacer(10);
	btnBox->Add(btnMainMenu);
	leftBox->Add(st1);
	leftBox->Add(stSeatNum);
	leftBox->Add(st2);
	leftBox->Add(st3);
	leftBox->Add(st4);
	leftBox->Add(btnBox);
	box->Add(leftBox);
	box->AddSpacer(20);
	box->Add(seating);

}

void uaReg::initOldRegPage()
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

void uaReg::onNextStartClick(wxCommandEvent& evt)
{
	progress->SetBitmap(wxBitmap("Linear_2.bmp", wxBITMAP_TYPE_BMP));
	currentPage->SetBitmap(wxBitmap("banner_regis.bmp", wxBITMAP_TYPE_BMP));
	mainSizer->Replace(panelStart, panelReg);
	panelStart->Hide();
	panelReg->Show();
	this->Layout();
}

void uaReg::onNextRegClick(wxCommandEvent& evt)
{

}

void uaReg::onBackRegClick(wxCommandEvent& evt)
{

}

void uaReg::onBackSeatClick(wxCommandEvent& evt)
{

}

void uaReg::onMainMenuClick(wxCommandEvent& evt)
{

}