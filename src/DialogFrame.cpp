#include "DialogFrame.h"

DialogFrame::DialogFrame(wxWindow* parent_, wxWindowID id, const wxSize& size_) : wxFrame(parent_, id, "Simple dialog " + std::to_string(id), wxPoint(25, 50), size_), m_dialog_id(id)
{
	// Add text
	m_dialog_text = new wxTextCtrl(this, m_dialog_id + 1, m_txt, wxDefaultPosition, wxSize(GetSize().x - 20, GetSize().y / 2 - 20), wxTE_MULTILINE | wxTE_RICH);

	//Add bitmaps
	wxBitmap m_bit_map("dialog_map.bmp", wxBITMAP_TYPE_BMP);
	int bit_n = std::floor(GetSize().x / 25);
	m_btm = new wxStaticBitmap * [2 * bit_n];
	for (auto i = 0; i < bit_n; ++i) {
		m_btm[i] = new wxStaticBitmap(this, m_dialog_id + 2 + i, m_bit_map, wxPoint(i * 25, GetSize().y / 2 - 5), wxSize(25, 25));
		m_btm[i + bit_n] = new wxStaticBitmap(this, m_dialog_id + 2 + bit_n + i, m_bit_map, wxPoint(i * 25, GetSize().y / 2 + 20), wxSize(25, 25));
	}

	// Add buttons
	m_cancel_btn = new wxButton(this, m_dialog_id + 101, "Cancel", wxPoint(5, 2 * GetSize().y / 3), wxSize(GetSize().x / 3 - 15, GetSize().y / 6));
	m_cancel_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &DialogFrame::OnButtonCancel, this);
	m_save_btn = new wxButton(this, m_dialog_id + 102, "Save", wxPoint(GetSize().x / 3, 2 * GetSize().y / 3), wxSize(GetSize().x / 3 - 15, GetSize().y / 6));
	m_save_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &DialogFrame::OnButtonSave, this);
	m_close_btn = new wxButton(this, m_dialog_id + 103, "Close", wxPoint(2 * GetSize().x / 3 - 5, 2 * GetSize().y / 3), wxSize(GetSize().x / 3 - 15, GetSize().y / 6));
	m_close_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &DialogFrame::OnButtonClose, this);
}

DialogFrame::~DialogFrame()
{
	delete[] m_btm;
}

void DialogFrame::OnButtonCancel(wxCommandEvent& e)
{
	e.Skip();
}

void DialogFrame::OnButtonSave(wxCommandEvent& e)
{
	e.Skip();
}

void DialogFrame::OnButtonClose(wxCommandEvent& e)
{
	Close();
	e.Skip();
}
