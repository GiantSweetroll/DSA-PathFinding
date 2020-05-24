#pragma once

#include "wx/wx.h"
#include "wx/combobox.h"
#include "uaMethods.h"
#include "uaID.h"
#include "BetterPassenger.h"
#include "uaConstants.h"

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
	wxStaticText* stEmail = nullptr;
	wxStaticText* stHeight = nullptr;
	wxStaticText* stWeight = nullptr;
	wxStaticText* stSpecialNeeds = nullptr;
	wxStaticText* stStart = nullptr;
	wxStaticText* stDisclaimer = nullptr;
	wxStaticText* stSeatNum = nullptr;
	wxStaticText* stPregnant = nullptr;
	wxTextCtrl* tfFirstName = nullptr;
	wxTextCtrl* tfLastName = nullptr;
	wxTextCtrl* tfAge = nullptr;
	wxTextCtrl* tfHeight = nullptr;
	wxTextCtrl* tfWeight = nullptr;
	wxTextCtrl* tfEmail = nullptr;
	wxStaticBitmap* logo = nullptr;
	wxStaticBitmap* progress = nullptr;
	wxStaticBitmap* currentPage = nullptr;
	wxButton* btnNext = nullptr;
	wxButton* btnBackStart = nullptr;
	wxButton* btnNextStart = nullptr;
	wxButton* btnNextReg = nullptr;
	wxButton* btnBackReg = nullptr;
	wxButton* btnBackSeat = nullptr;
	wxButton* btnMainMenu = nullptr;
	wxButton* btnBack = nullptr;
	wxComboBox* cmbSex = nullptr;
	wxComboBox* cmbSpecialNeeds = nullptr;
	wxPanel* panelStart = nullptr;
	wxPanel* panelReg = nullptr;
	wxPanel* panelSeat = nullptr;
	wxBoxSizer* mainSizer = nullptr;
	wxRadioBox* radPregnant = nullptr;
	wxScrolledWindow* scroll = nullptr;
	BetterPassenger* passenger = nullptr;

	//Methods
private:
	void initOldRegPage();
	void initStartPage();
	void initRegPage();
	void initSeatPage();
	void onNextStartClick(wxCommandEvent& evt);
	void onNextRegClick(wxCommandEvent& evt);
	void onBackRegClick(wxCommandEvent& evt);
	void onBackSeatClick(wxCommandEvent& evt);
	void onMainMenuClick(wxCommandEvent& evt);
	BetterPassenger* getPassengerData();
	bool allItemsFilled();

	wxDECLARE_EVENT_TABLE();
};