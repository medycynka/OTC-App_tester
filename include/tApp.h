#pragma once

#include <wx\wx.h>
#include "TestingFrame.h"
#include "MainFrame.h"

class tApp : public wxApp
{
public:
	tApp();
	~tApp();

	virtual bool OnInit();

private:
	int m_nr_of_frames = 5;
	wxWindowID m_app_id = 1000;
	std::vector<TestingFrame*> m_frames;
	MainFrame* m_main_frame = nullptr;
};

