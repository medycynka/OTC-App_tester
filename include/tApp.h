#pragma once

#include <wx\wx.h>
#include "TestingFrame.h"

class tApp : public wxApp
{
public:
	tApp();
	~tApp();

	virtual bool OnInit();

private:
	wxWindowID m_app_id = 1000;
	TestingFrame* m_main_frame = nullptr;
};

