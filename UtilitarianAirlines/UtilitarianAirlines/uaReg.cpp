#include "uaReg.h"

wxBEGIN_EVENT_TABLE(uaReg, wxPanel)
	EVT_BUTTON(uaID::c_btnRegNextStart, onNextStartClick)
	EVT_BUTTON(uaID::c_btnRegNextReg, onNextRegClick)
	EVT_BUTTON(uaID::c_btnRegBackReg, onBackRegClick)
	EVT_BUTTON(uaID::c_btnRegBackSeat, onBackSeatClick)
wxEND_EVENT_TABLE()

extern BetterPlane plane1;

uaReg::uaReg(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	//Initialization
	progress = new wxStaticBitmap(this, wxID_ANY, wxBitmap("Linear_1.bmp", wxBITMAP_TYPE_BMP));
	currentPage = new wxStaticBitmap(this, wxID_ANY, wxBitmap("banner_start.bmp", wxBITMAP_TYPE_BMP));
	initStartPage();
	initRegPage();
	mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* marginsLR = new wxBoxSizer(wxHORIZONTAL);

	//Properties
	this->SetBackgroundColour(*wxWHITE);

	//Add to sizer
	marginsLR->AddSpacer(50);
	mainSizer->Add(progress);
	mainSizer->Add(currentPage);
	mainSizer->AddSpacer(15);
	mainSizer->Add(panelStart, wxSizerFlags().Expand());
	mainSizer->AddSpacer(30);
	marginsLR->Add(mainSizer);
	marginsLR->AddSpacer(50);

	this->SetSizer(marginsLR);
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
	wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
	stStart = new wxStaticText(panelStart, wxID_ANY, "Welcome to Utilitarian Airlines\n\nWe are here to provide the best seating for your flight's safety\n\nTo start registering to our services, please click the 'Next' button\nto proceed \n\n");
	btnNextStart = new wxButton(panelStart, uaID::c_btnRegNextStart, "Next");
	btnBackStart = new wxButton(panelStart, uaID::c_btnRegBackStart, "Main Menu");
	logo = new wxStaticBitmap(panelStart, wxID_ANY, wxBitmap("logo.bmp", wxBITMAP_TYPE_BMP));

	//Properties
	panelStart->SetBackgroundColour(*wxWHITE);
	stStart->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	btnNextStart->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	btnBackStart->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	btnBackStart->SetBackgroundColour(wxColour(11, 83, 165, 255));
	btnBackStart->SetForegroundColour(wxColour(255, 255, 255, 255));
	btnNextStart->SetBackgroundColour(wxColour(11, 83, 165, 255));
	btnNextStart->SetForegroundColour(wxColour(255, 255, 255, 255));

	//Add to sizer
	sizer->Add(logo);
	sizer->AddSpacer(50);
	txtBtnSizer->Add(stStart);
	btnSizer->Add(btnBackStart);
	btnSizer->Add(btnNextStart);
	txtBtnSizer->Add(btnSizer);
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
	stPregnant = new wxStaticText(panelReg, wxID_ANY, "Pregnant");
	stDisclaimer = new wxStaticText(panelReg, wxID_ANY, "All information remains confidential and will only be used to determine the best seating\nfor you.");
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
	wxString choices[2] = {"Yes", "No"};
	radPregnant = new wxRadioBox(panelReg, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 2, choices);
	wxFont basicFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	//Properties
	panelReg->SetBackgroundColour(*wxWHITE);
	stName->SetFont(basicFont);
	tfFirstName->SetFont(basicFont);
	tfFirstName->SetHint("First Name");
	tfLastName->SetHint("Last Name");
	tfLastName->SetFont(basicFont);
	stEmail->SetFont(basicFont);
	tfEmail->SetFont(basicFont);
	tfEmail->SetHint("e.g. myemail@email.com");
	stAge->SetFont(basicFont);
	tfAge->SetFont(basicFont);
	tfAge->SetHint("8-83");
	tfAge->SetValidator(wxTextValidator(wxFILTER_DIGITS));
	stWeight->SetFont(basicFont);
	tfWeight->SetFont(basicFont);
	tfWeight->SetHint("37 - 206");
	tfWeight->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
	stHeight->SetFont(basicFont);
	tfHeight->SetFont(basicFont);
	tfHeight->SetHint("0.9 - 2.1");
	tfHeight->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
	stGender->SetFont(basicFont);
	cmbSex->SetFont(basicFont);
	cmbSex->SetEditable(false);
	cmbSex->Append(_("Male"));
	cmbSex->Append(_("Female"));
	cmbSex->Append(_("Rather not specify"));
	stPregnant->SetFont(basicFont);
	radPregnant->SetSelection(1);
//	radPregnant->SetFont(basicFont);
	stDisclaimer->SetFont(basicFont);
	stDisclaimer->SetForegroundColour(wxColour(253, 0, 0, 255));
	stSpecialNeeds->SetFont(basicFont);
	cmbSpecialNeeds->SetFont(basicFont);
	cmbSpecialNeeds->SetEditable(false);
	cmbSpecialNeeds->Append("None");
	cmbSpecialNeeds->Append("Cannot walkness");
	cmbSpecialNeeds->Append("Blind");
	cmbSpecialNeeds->Append("Mental Illness");
	cmbSpecialNeeds->Append("Sick");
	cmbSpecialNeeds->Append("Muscle Atrophy");
	cmbSpecialNeeds->Append("Bone Stuff");
	btnNextReg->SetBackgroundColour(wxColour(11, 83, 165, 255));
	btnNextReg->SetForegroundColour(wxColour(255, 255, 255, 255));
	btnNextReg->SetFont(basicFont);
	btnBackReg->SetBackgroundColour(wxColour(11, 83, 165, 255));
	btnBackReg->SetForegroundColour(wxColour(255, 255, 255, 255));
	btnBackReg->SetFont(basicFont);
	panelReg->Hide();

	//Add to sizer
	//Grid
	grid->Add(stName);
	grid->Add(tfFirstName, wxSizerFlags().Expand());
	uaMethods::insertFillers(grid, 4);
	grid->Add(tfLastName, wxSizerFlags().Expand());
	uaMethods::insertFillers(grid, 3);
	grid->Add(stAge);
	grid->Add(tfAge);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stGender);
	grid->Add(cmbSex);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stEmail);
	grid->Add(tfEmail, wxSizerFlags().Expand());
	uaMethods::insertFillers(grid, 3);
	grid->Add(stHeight);
	grid->Add(tfHeight);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stWeight);
	grid->Add(tfWeight);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stPregnant);
	grid->Add(radPregnant);
	uaMethods::insertFillers(grid, 3);
	grid->Add(stSpecialNeeds);
	grid->Add(cmbSpecialNeeds);
	//Buttons
	btnBox->Add(btnBackReg);
	btnBox->Add(btnNextReg);
	//Box
	box->Add(grid);
	box->AddSpacer(5);
	box->Add(stDisclaimer);
	box->AddSpacer(20);
	box->Add(btnBox, wxSizerFlags().Expand());

	panelReg->SetSizer(box);
	panelReg->Layout();
}

void uaReg::initSeatPage()
{
	panelSeat = uaMethods::initBasicPanelSeat(this, true, plane1, passenger->getEmail());
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
	if (!allItemsFilled())
	{
		wxMessageDialog md(this, "Please fill in all the fields.");
		md.ShowModal();
	}
	else
	{
		passenger = getPassengerData();
		plane1.addCustomPassenger(*passenger);
		initSeatPage();
		progress->SetBitmap(wxBitmap("Linear_3.bmp", wxBITMAP_TYPE_BMP));
		currentPage->SetBitmap(wxBitmap("banner_Seat.bmp", wxBITMAP_TYPE_BMP));
		mainSizer->Replace(panelReg, panelSeat);
		panelReg->Hide();
		panelSeat->Show();
		this->Layout();
	}
}

void uaReg::onBackRegClick(wxCommandEvent& evt)
{
	progress->SetBitmap(wxBitmap("Linear_1.bmp", wxBITMAP_TYPE_BMP));
	currentPage->SetBitmap(wxBitmap("banner_start.bmp", wxBITMAP_TYPE_BMP));
	mainSizer->Replace(panelReg, panelStart);
	panelReg->Hide();
	panelStart->Show();
	this->Layout();
}

void uaReg::onBackSeatClick(wxCommandEvent& evt)
{
	progress->SetBitmap(wxBitmap("Linear_2.bmp", wxBITMAP_TYPE_BMP));
	currentPage->SetBitmap(wxBitmap("banner_regis.bmp", wxBITMAP_TYPE_BMP));
	mainSizer->Replace(panelSeat, panelReg);
	panelSeat->Hide();
	panelReg->Show();
	this->Layout();
}

void uaReg::resetDefaults()
{
	//Resets all pages and fields to their initial state
	plane1.savePassengerData("myData");

	tfFirstName->SetValue("");
	tfLastName->SetValue("");
	tfAge->SetValue("");
	cmbSex->SetSelection(0);
	tfEmail->SetValue("");
	tfHeight->SetValue("");
	tfWeight->SetValue("");	
	radPregnant->SetSelection(1);
	cmbSpecialNeeds->SetSelection(0);

	progress->SetBitmap(wxBitmap("Linear_1.bmp", wxBITMAP_TYPE_BMP));
	currentPage->SetBitmap(wxBitmap("banner_start.bmp", wxBITMAP_TYPE_BMP));
	if (panelSeat != NULL)
	{
		mainSizer->Replace(panelSeat, panelStart);
		panelSeat->Hide();
		panelStart->Show();
	}
	
	this->Layout();
}

BetterPassenger* uaReg::getPassengerData()
{
	//Get gender
	Passenger::Gender gender;
	if (cmbSex->GetSelection() == 0)
	{
		gender = Passenger::MALE;
	}
	else if (cmbSex->GetSelection() == 1)
	{
		gender = Passenger::FEMALE;
	}
	else
	{
		gender = Passenger::OTHER;
	}
	//Get weight
	string temp = tfWeight->GetValue().Trim().ToStdString();
	double weight = stod(temp);
	//Get height
	temp = tfHeight->GetValue().Trim().ToStdString();
	double height = stod(temp);

	//Check if pregnant
	bool preg = radPregnant->GetSelection() == 0;

	//Get special needs
	Passenger::Disabilities sn;
	switch (cmbSpecialNeeds->GetSelection())
	{
		case 0:
			sn = Passenger::NONE;
			break;
		case 1:
			sn = Passenger::HANDICAPPED;
			break;
		case 2:
			sn = Passenger::BLIND;
			break;
		case 3:
			sn = Passenger::MENTALILLNESS;
			break;
		case 4:
			sn = Passenger::MILDSICKNESS;
			break;
		case 5:
			sn = Passenger::MUSCLEATROPHY;
			break;
		case 6:
			sn = Passenger::HEAVYSICKNESS;
			break;

		default:
			sn = Passenger::NONE;
			break;
	}

	return new BetterPassenger(tfFirstName->GetValue().Trim().ToStdString(), 
								tfLastName->GetValue().Trim().ToStdString(), 
								tfEmail->GetValue().Trim().ToStdString(), 
								gender, wxAtoi(tfAge->GetValue().Trim()), 
								weight, height, preg, sn);
}

bool uaReg::allItemsFilled()
{
	return tfFirstName->GetValue().Trim() != "" &&
		tfAge->GetValue().Trim() != "" &&
		tfEmail->GetValue().Trim() != "" &&
		tfHeight->GetValue().Trim() != "" &&
		tfWeight->GetValue().Trim() != "";
}