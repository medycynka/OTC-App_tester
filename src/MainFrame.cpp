#include "MainFrame.h"

MainFrame::MainFrame(wxWindowID id_, int frames_count) : wxFrame(nullptr, id_, "Tester", wxPoint(10, 10), wxSize(800, 600)), m_frame_id(id_), m_frames_count(frames_count)
{
	// Adding menu bar
	m_menu = new wxMenuBar();
	this->SetMenuBar(m_menu);

	wxMenu* menu_list = new wxMenu();
	menu_list->Append(m_frame_id + 1, "Save");
	menu_list->Append(m_frame_id + 2, "Replay");
	menu_list->Append(m_frame_id + 3, "Exit");
	m_menu->Append(menu_list, "File");

	Connect(m_frame_id + 1, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnMenuSave));
	Connect(m_frame_id + 2, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnMenuReplay));
	Connect(m_frame_id + 3, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnMenuExit));

	m_fr_count = new wxStaticText(this, m_frame_id + 10, "Number of active frames: " + std::to_string(m_frames_count), wxDefaultPosition, wxSize(GetSize().x / 3, GetSize().y / 20));
	m_fr_count->SetFont(wxFont(wxSize(10, GetSize().y / 20 - 2), wxFontFamily::wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL));

	m_cpu_usage = new wxStaticText(this, m_frame_id + 11, "Cpu usage: 0", wxPoint(GetSize().x / 3 + 120, 0), wxSize(GetSize().x / 3, GetSize().y / 20));
	m_cpu_usage->SetFont(wxFont(wxSize(10, GetSize().y / 20 - 2), wxFontFamily::wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL));

	m_timer = new wxTimer(this, m_frame_id + 20);
	m_timer->SetOwner(this, m_frame_id + 20);
	Connect(m_frame_id + 20, wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimeChange));
	m_timer->Start(500);
}

MainFrame::~MainFrame()
{
	m_timer->Stop();
}

void MainFrame::OnMenuSave(wxCommandEvent& e)
{
	e.Skip();
}

void MainFrame::OnMenuReplay(wxCommandEvent& e)
{
	e.Skip();
}

void MainFrame::OnMenuExit(wxCommandEvent& e)
{
	Close();
	e.Skip();
}

void MainFrame::OnTimeChange(wxTimerEvent& e) {
	m_cpu_usage->SetLabel("Cpu usage: " + std::to_string(m_cpu_reader.GetCPULoad() * 100.0f) + "%");
	//m_cpu_usage->Refresh();

	e.Skip();
}

