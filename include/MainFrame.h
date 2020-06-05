#pragma once

#include <wx\wx.h>
#include <wx\timer.h>
#include "CpuUsageReader.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(wxWindowID id_, int frames_count);
	~MainFrame();

private:
	void OnMenuSave(wxCommandEvent& e);
	void OnMenuReplay(wxCommandEvent& e);
	void OnMenuExit(wxCommandEvent& e);
	void OnTimeChange(wxTimerEvent& e);

private:
	int m_frames_count;
	wxWindowID m_frame_id;
	wxMenuBar* m_menu = nullptr;
	wxStaticText* m_fr_count = nullptr;
	wxStaticText* m_cpu_usage = nullptr;
	wxTimer* m_timer = nullptr;
	CpuUsageReader m_cpu_reader;
};

