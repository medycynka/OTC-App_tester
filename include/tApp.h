#pragma once

#include <wx\wx.h>
#include <wx\wfstream.h>
#include <wx\txtstrm.h>
#include <wx\wxprec.h>
#include <wx\cmdline.h>
#include "TestingFrame.h"

class tApp : public wxApp
{
public:
	tApp();
	~tApp();

	virtual bool OnInit();
	virtual int OnExit();
	virtual int OnRun();
	virtual void OnInitCmdLine(wxCmdLineParser& parser);
	virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

private:
	wxWindowID m_app_id = 1000;
	TestingFrame* m_main_frame = nullptr;
	wxString m_config_path = "";
	std::unordered_map<wxString, float> m_config;
	std::unordered_map<wxWindowID, DialogFrame*> m_app_dialogs;
};

static const wxCmdLineEntryDesc g_cmdLineDesc[] = {
	{wxCMD_LINE_PARAM, NULL,  NULL, "Configuration file",  wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM},
	{ wxCMD_LINE_NONE }
};
