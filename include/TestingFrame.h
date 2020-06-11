#pragma once

#include <wx\wx.h>
#include <wx\notebook.h>
#include <wx\listctrl.h>
#include <wx\stattext.h>
#include <wx\datectrl.h>
#include <wx\fontpicker.h>
#include <wx\filepicker.h>
#include <wx\dataview.h>
#include <wx\combo.h>
#include <wx\timer.h>
#include <wx\statusbr.h>
#include <wx\spinctrl.h>
#include <wx\calctrl.h>
#include <wx\filectrl.h>
#include <wx\textfile.h>
#include <wx\tglbtn.h>
#include "CpuUsageReader.h"
#include "DialogFrame.h"


class TestingFrame : public wxFrame
{
public:
	TestingFrame(wxWindow* parent_, wxWindowID id, std::unordered_map<wxString, float> & config);
	~TestingFrame();

private:
	// Standard events handlers
	void OnMenuNew(wxCommandEvent& e);
	void OnMenuOpen(wxCommandEvent& e);
	void OnMenuSave(wxCommandEvent& e);
	void OnMenuPrint(wxCommandEvent& e);
	void OnMenuSettings(wxCommandEvent& e);
	void OnMenuExit(wxCommandEvent& e);
	void OnMenuHelp(wxCommandEvent& e);
	void OnButtonRefresh(wxCommandEvent& e);
	void OnCompassClick(wxCommandEvent& e);
	void OnGaugeInc(wxCommandEvent& e);
	void OnGaugeDec(wxCommandEvent& e);

	// Time Events handlers for tests
	void OnTimerTickZOrder(wxTimerEvent& e);
	void OnTimerTickSeq(wxTimerEvent& e);
	void OnTimerTickRefresh(wxTimerEvent& e);
	void OnTimerTickTabCtrl(wxTimerEvent& e);
	void OnTimerTickButton(wxTimerEvent& e);
	void OnTimerTickScroll(wxTimerEvent& e);

	// Helper functions
	void CloseAllDialogs();
	unsigned long GetPlannedOperationsCount();

	// Init test / write result
	void RunAllTests();
	void WriteResults();

private:
	std::unordered_map<wxString, float> m_config;
	wxWindowID frame_id;
	int width = 0;
	int height = 0;
	wxToolBar* m_tool_bar = nullptr;
	wxMenuBar* m_menu_bar = nullptr;
	wxButton* m_btn_refresh = nullptr;
	wxNotebook* m_note = nullptr;
	wxNotebookPage* m_be_page = nullptr;
	wxNotebookPage* m_li_page = nullptr;
	wxNotebookPage* m_bo_page = nullptr;
	wxButton** compass = nullptr;
	wxTextCtrl* board = nullptr;
	wxListBox* page_list_box = nullptr;
	wxCheckListBox* page_check = nullptr;
	wxRadioBox* page_radio = nullptr;
	wxWindow* top_right = nullptr;
	wxWindow* bottom_left = nullptr;
	wxWindow* bottom_right = nullptr;
	wxTextCtrl* m_txt = nullptr;
	std::string lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam euismod ac velit in volutpat. Integer consequat nisi quis sapien congue finibus. Aenean porta rhoncus auctor. Phasellus odio elit, lobortis sed lectus et, accumsan accumsan leo. Proin eget odio mi. Aenean id augue interdum, lobortis justo ut, pulvinar lorem. Phasellus a mi quis lectus ultricies ultricies.\nAliquam erat volutpat.Quisque condimentum gravida purus, ultrices auctor ipsum maximus nec.Donec quam lacus, vestibulum sed sem nec, iaculis rutrum arcu.Nulla ut ultrices quam.Pellentesque accumsan arcu sapien, non tristique nunc iaculis et.Nullam ullamcorper, justo in scelerisque viverra, purus elit consectetur risus, ut molestie dolor metus in risus.Vivamus ultrices enim sit amet velit viverra varius in ac lorem.Fusce velit sem, egestas in sodales nec, lobortis nec nulla.Etiam quis mi nec justo vulputate tincidunt.\n 		Lorem ipsum dolor sit amet, consectetur adipiscing elit.Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.Donec eu augue molestie, vestibulum dui quis, aliquam leo.Donec eleifend ligula nec metus volutpat malesuada.Ut vehicula massa dui, at lobortis libero imperdiet vel.Mauris tristique lorem sodales massa elementum, eget mattis odio maximus.Vivamus tincidunt, justo id eleifend malesuada, nisl justo consequat ligula, vel vehicula sapien arcu mattis sem.Donec id lacinia justo, at sagittis ante.Nullam accumsan consequat enim vel facilisis.Fusce feugiat nibh in urna molestie tincidunt.Ut porttitor justo nec auctor elementum.\n 		Nam consectetur lobortis massa, non euismod risus mattis blandit.Mauris cursus diam dui, id molestie dui aliquam non.Fusce vitae molestie orci.Pellentesque maximus nec orci at fringilla.Ut porta leo eget augue congue, vel aliquam velit venenatis.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Pellentesque vitae ipsum dolor.Phasellus a ornare est, a rutrum sapien.Cras et turpis lacus.\n 		Aenean et porttitor ex, in finibus mauris.Cras faucibus tincidunt cursus.Aenean faucibus enim maximus, vulputate velit vitae, finibus eros.Nunc fringilla purus id justo lacinia euismod.Aenean sed ornare libero.Donec ac dui blandit, scelerisque turpis sed, posuere nulla.Aenean in ex nunc.Etiam tristique congue odio consequat ornare.\n 		Vivamus a neque in sapien commodo dapibus a at lacus.Maecenas tempor cursus justo et cursus.Donec at efficitur sem, sit amet mollis odio.Quisque malesuada sapien massa, at bibendum est euismod a.Nulla facilisi.Aliquam erat volutpat.Nunc tempor, urna quis mollis efficitur, justo diam pulvinar risus, ut semper diam ipsum non nisi.\n 		Aenean tristique ante risus.Maecenas tempus blandit consequat.Etiam sagittis rutrum malesuada.Vivamus consequat mauris porttitor libero varius volutpat.In venenatis mauris et erat fringilla, at ultrices velit faucibus.Donec id imperdiet mauris.Donec facilisis, magna quis tincidunt varius, dolor mauris rhoncus est, non porttitor magna odio sit amet est.\n 		Cras ullamcorper blandit mattis.Mauris vel erat ut neque hendrerit suscipit.Donec faucibus eget odio non imperdiet.Vivamus lacus quam, congue eget purus at, iaculis mattis dui.Duis sem odio, malesuada eget posuere et, porttitor a enim.Quisque at dui ac ligula tincidunt laoreet sed in massa.Fusce enim quam, ullamcorper vitae blandit quis, gravida a mauris.Curabitur ultricies nisi at metus tempus facilisis.Proin nec lorem nibh.Proin vestibulum ac augue at sodales.Cras a diam a lacus vulputate semper sed quis mauris.Vivamus elementum turpis in magna vehicula ultrices.\n 		Vestibulum dictum ac tellus pretium vulputate.Vivamus eget urna quis lorem mollis pharetra quis id nibh.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Aenean vel erat risus.Phasellus congue tellus turpis, ac sagittis lectus porta eu.Ut elementum nibh tortor, et maximus augue tincidunt eu.Etiam id nulla facilisis massa molestie elementum.In sapien diam, feugiat in felis sit amet, faucibus mattis felis.Mauris nisi nulla, eleifend at congue non, molestie sed arcu.Phasellus commodo tellus orci, sed ultricies erat rhoncus vel.Suspendisse vestibulum porttitor elit dapibus bibendum.\n 		Vivamus a dui vulputate, interdum turpis sit amet, consectetur lorem.Morbi interdum pharetra dui ut scelerisque.Nulla ac diam sodales, maximus odio et, consequat odio.Morbi nibh nunc, rhoncus vitae euismod eu, tincidunt in sem.In suscipit ex mi, sit amet facilisis libero ultrices sed.Vestibulum fermentum elementum purus, non dignissim erat consequat a.Ut maximus convallis euismod.Aenean congue quam vel imperdiet scelerisque.In accumsan odio nec massa convallis, eget finibus felis viverra.Sed elementum, tortor vitae vestibulum auctor, dui ex scelerisque massa, ac fringilla urna quam vitae ex.Sed eros magna, sagittis at ante eget, eleifend lacinia turpis.Interdum et malesuada fames ac ante ipsum primis in faucibus.Duis vel volutpat metus, eu consequat ligula.Vestibulum sit amet massa ut libero tempus facilisis eget id augue.Vivamus quis sagittis mauris.Nulla facilisi.";
	wxToggleButton** main_btn;
	wxListBox* m_checker = nullptr;
	wxListCtrl* m_table = nullptr;
	wxStaticText* m_report = nullptr;
	wxDatePickerCtrl* m_date = nullptr;
	wxFontPickerCtrl* m_font = nullptr;
	wxTextCtrl* m_report_txt = nullptr;
	wxButton* m_btn_save = nullptr;
	wxButton* m_btn_print = nullptr;
	wxButton* m_btn_send = nullptr;
	wxCheckListBox* m_task_check = nullptr;
	wxComboBox* m_cmb_box = nullptr;
	wxRadioBox* m_radio = nullptr;
	wxFilePickerCtrl* m_file_picker = nullptr;
	wxDirPickerCtrl* m_dir_picker = nullptr;
	wxStatusBar* stat_bar = nullptr;
	wxGauge* gauge = nullptr;
	wxButton* inc_gauge = nullptr;
	wxButton* dec_gauge = nullptr;
	wxTextCtrl* gauge_lvl = nullptr;
	std::vector<std::pair<wxWindowID, DialogFrame*>> m_dialogs;
	std::vector<std::pair<wxWindowID, DialogFrame*>>::iterator m_curr_it;
	wxTimer* m_timer = nullptr;
	wxMilliClock_t m_start_point = 0;
	wxMilliClock_t m_accumulate_time = 0;
	unsigned long m_curr_op_count = 0;
	unsigned long m_all_op_count = 0;
	std::unordered_map<wxString, unsigned long> m_result;
	bool m_scroll_down = true;

	wxDECLARE_EVENT_TABLE();
};

