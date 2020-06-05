#include "TestingFrame.h"


TestingFrame::TestingFrame(wxWindow* parent_, wxWindowID id) : wxFrame(parent_, id, "Format", wxPoint(0, 0)), frame_id(id)
{
	//fullscrean size
	this->Maximize(true);
	this->GetSize(&width, &height);

	// Menu bar
	m_menu_bar = new wxMenuBar();
	this->SetMenuBar(m_menu_bar);
	{
		// Menu operations
		wxMenu* menuList = new wxMenu();
		menuList->Append(frame_id + 10, "New");
		menuList->Append(frame_id + 11, "Open");
		menuList->Append(frame_id + 12, "Save");
		menuList->Append(frame_id + 13, "Print");

		wxMenu* settings_menu = new wxMenu();
		settings_menu->Append(frame_id + 14, "Account");
		settings_menu->Append(frame_id + 15, "Options");
		settings_menu->Append(frame_id + 16, "Cusomize");
		menuList->AppendSubMenu(settings_menu, "Settings");

		menuList->Append(frame_id + 20, "Exit");
		m_menu_bar->Append(menuList, "File");

		wxMenu* menuHelp = new wxMenu();
		menuHelp->Append(frame_id + 21, "View help");
		menuHelp->Append(frame_id + 22, "Send feedback");
		menuHelp->Append(frame_id + 23, "Check for updates");
		m_menu_bar->Append(menuHelp, "Help");

		// Binding menu options to functions
		Connect(frame_id + 10, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuNew));
		Connect(frame_id + 11, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuOpen));
		Connect(frame_id + 12, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuSave));
		Connect(frame_id + 13, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuPrint));
		Connect(frame_id + 14, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuSettings));
		Connect(frame_id + 15, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuSettings));
		Connect(frame_id + 16, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuSettings));
		Connect(frame_id + 20, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuExit));
		Connect(frame_id + 21, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuHelp));
		Connect(frame_id + 22, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuHelp));
		Connect(frame_id + 23, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(TestingFrame::OnMenuHelp));
	}
	// Add toolbar
	m_tool_bar = this->CreateToolBar(wxTB_HORIZONTAL, 1050);
	m_tool_bar->Realize();

	// Add grid layout
	wxGridSizer* m_grid = new wxGridSizer(2, 2, 0, 0);

	// Top-left part
	m_note = new wxNotebook(this, frame_id + 100, wxDefaultPosition, wxSize(width / 2, height / 2));

	// Buttons & editors page
	m_be_page = new wxNotebookPage(m_note, frame_id + 101, wxDefaultPosition, wxSize(width / 2, height / 2), 0L, "Test content");
	compass = new wxButton * [16];
	{
		compass[0] = new wxButton(m_be_page, frame_id + 102, "NW", wxPoint(0, 0), wxSize(width / 10 - 2, height / 10 - 8));
		compass[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[1] = new wxButton(m_be_page, frame_id + 103, "NNW", wxPoint(width / 10 - 2, 0), wxSize(width / 10 - 2, height / 10 - 8));
		compass[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[2] = new wxButton(m_be_page, frame_id + 104, "N", wxPoint(width / 5 - 4, 0), wxSize(width / 10 - 2, height / 10 - 8));
		compass[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[3] = new wxButton(m_be_page, frame_id + 105, "NNE", wxPoint(3 * width / 10 - 6, 0), wxSize(width / 10 - 2, height / 10 - 8));
		compass[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[4] = new wxButton(m_be_page, frame_id + 106, "NE", wxPoint(4 * width / 10 - 8, 0), wxSize(width / 10 - 2, height / 10 - 8));
		compass[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[5] = new wxButton(m_be_page, frame_id + 107, "NEE", wxPoint(4 * width / 10 - 8, height / 10 - 8), wxSize(width / 10 - 2, height / 10 - 8));
		compass[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[6] = new wxButton(m_be_page, frame_id + 108, "E", wxPoint(4 * width / 10 - 8, height / 5 - 16), wxSize(width / 10 - 2, height / 10 - 8));
		compass[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[7] = new wxButton(m_be_page, frame_id + 109, "SEE", wxPoint(4 * width / 10 - 8, 3 * height / 10 - 24), wxSize(width / 10 - 2, height / 10 - 8));
		compass[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[8] = new wxButton(m_be_page, frame_id + 110, "SE", wxPoint(4 * width / 10 - 8, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		compass[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[9] = new wxButton(m_be_page, frame_id + 111, "SSE", wxPoint(3 * width / 10 - 6, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		compass[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[10] = new wxButton(m_be_page, frame_id + 112, "S", wxPoint(width / 5 - 4, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		compass[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[11] = new wxButton(m_be_page, frame_id + 113, "SSW", wxPoint(width / 10 - 2, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		compass[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[12] = new wxButton(m_be_page, frame_id + 114, "SW", wxPoint(0, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		compass[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[13] = new wxButton(m_be_page, frame_id + 115, "SWW", wxPoint(0, 3 * height / 10 - 24), wxSize(width / 10 - 2, height / 10 - 8));
		compass[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[14] = new wxButton(m_be_page, frame_id + 116, "W", wxPoint(0, height / 5 - 16), wxSize(width / 10 - 2, height / 10 - 8));
		compass[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		compass[15] = new wxButton(m_be_page, frame_id + 117, "NWW", wxPoint(0, height / 10 - 8), wxSize(width / 10 - 2, height / 10 - 8));
		compass[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
	}
	board = new wxTextCtrl(m_be_page, frame_id + 118, "", wxPoint(width / 10 - 2, height / 10 - 8), wxSize(3 * width / 10 - 6, 3 * height / 10 - 24), wxTE_MULTILINE | wxTE_RICH);
	m_note->InsertPage(0, m_be_page, "Buttons and edits", true);

	// Lists page
	m_li_page = new wxNotebookPage(m_note, frame_id + 120, wxDefaultPosition, wxSize(width / 2, height / 2), 0L, "Test content");

	page_list_box = new wxListBox(m_li_page, frame_id + 121, wxPoint(0, 0), wxSize(width / 4 - 4, height / 4 - 2));
	page_check = new wxCheckListBox(m_li_page, frame_id + 122, wxPoint(width / 4, 0), wxSize(width / 4 - 8, height / 4 - 2));

	wxArrayString p_arr;
	for (auto i = 0; i < 117; ++i) {
		p_arr.Add("radio_" + std::to_string(i + 1));
	}
	m_radio = new wxRadioBox(m_li_page, frame_id + 123, "Radio box", wxPoint(0, height / 4), wxSize(width / 2 - 4, height / 4 - 10), p_arr, 13);
	page_radio = new wxRadioBox();

	m_note->InsertPage(1, m_li_page, "\tLists\t", false);

	// Boxes Page
	m_bo_page = new wxNotebookPage(m_note, frame_id + 150, wxDefaultPosition, wxSize(width / 2, height / 2), 0L, "Test content");

	wxChoice* pg_choice_box = new wxChoice(m_bo_page, frame_id + 151, wxPoint(0, 0), wxSize(width / 6 - 5, 40), {});
	wxComboBox* pg_combo_box = new wxComboBox(m_bo_page, frame_id + 152, "Choose one again", wxPoint(width / 6, 0), wxSize(width / 6 - 5, 40));
	wxSpinCtrl* pg_spin = new wxSpinCtrl(m_bo_page, frame_id + 153, "", wxPoint(width / 3, 0), wxSize(width / 6 - 5, 20), 16384L, -1000, 1000, 0);
	wxCalendarCtrl* pg_calendar = new wxCalendarCtrl(m_bo_page, frame_id, wxDefaultDateTime, wxPoint(0, height / 8), wxSize(width / 4 - 5, 3 * height / 8 - 5));
	wxFileCtrl* pf_file_ctrl = new wxFileCtrl(m_bo_page, frame_id + 154, wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFC_MULTIPLE, wxPoint(width / 4, height / 8));

	m_note->InsertPage(2, m_bo_page, "\tBoxes\t", false);
	m_grid->Add(m_note, wxEXPAND | wxALL);

	// Top-right-part
	top_right = new wxWindow(this, frame_id + 200);

	// Add text field
	m_txt = new wxTextCtrl(top_right, frame_id + 201, lorem, wxDefaultPosition, wxSize(width / 8, height / 2), wxTE_MULTILINE | wxTE_RICH);

	// Add buttons
	main_btn = new wxButton * [20];
	for (auto i = 0; i < 10; ++i) {
		main_btn[i] = new wxButton(top_right, frame_id + 202 + i, "Clicker " + std::to_string(i + 1), wxPoint(width / 8 + 50, i * (height / 20)), wxSize(width / 16 + 10, height / 20));
		main_btn[i + 10] = new wxButton(top_right, frame_id + 202 + i + 10, "Clicker " + std::to_string(i + 11), wxPoint(2 * width / 8 - 50, i * (height / 20)), wxSize(width / 16 + 10, height / 20));
	}

	// Add check list
	m_checker = new wxListBox(top_right, frame_id + 222, wxPoint(21 * width / 64, 0), wxSize(11 * width / 64, height / 2));

	m_grid->Add(top_right, wxEXPAND | wxALL);

	// Bottom-left part
	bottom_left = new wxWindow(this, frame_id + 300);

	// Add report table
	m_table = new wxListCtrl(bottom_left, frame_id + 301, wxPoint(0, 35), wxSize(width / 4, height / 5), wxLC_REPORT, wxDefaultValidator, "Report table");
	{
		wxListItem col0, col1, col2, col3, col4;
		col0.SetId(0);
		col0.SetText("ID");
		m_table->InsertColumn(0, col0);
		col1.SetId(1);
		col1.SetText("Item");
		m_table->InsertColumn(1, col1);
		col2.SetId(2);
		col2.SetText("Price");
		m_table->InsertColumn(2, col2);
		col3.SetId(3);
		col3.SetText("Description");
		m_table->InsertColumn(3, col3);
		col4.SetId(2);
		col4.SetText("Serial number");
		col4.SetWidth(250);
		m_table->InsertColumn(4, col4);
	}

	// Add Report writer
	m_report = new wxStaticText(bottom_left, frame_id + 302, "Write a report", wxPoint(width / 4 + 20, 35), wxSize(width / 4 - 20, 30));
	m_date = new wxDatePickerCtrl(bottom_left, frame_id + 303, wxDefaultDateTime, wxPoint(width / 4 + 20, 60), wxSize(100, 30));
	m_font = new wxFontPickerCtrl(bottom_left, frame_id + 304, wxNullFont, wxPoint(width / 4 + 140, 60), wxSize(100, 30));
	m_report_txt = new wxTextCtrl(bottom_left, frame_id + 305, "", wxPoint(width / 4 + 20, 100), wxSize(width / 4 - 30, height / 3 - 20), wxTE_MULTILINE | wxTE_RICH);
	m_btn_save = new wxButton(bottom_left, frame_id + 306, "Save", wxPoint(width / 4 + 30, height / 3 + 85), wxSize(120, 30));
	m_btn_print = new wxButton(bottom_left, frame_id + 307, "Print", wxPoint(width / 4 + 185, height / 3 + 85), wxSize(120, 30));
	m_btn_send = new wxButton(bottom_left, frame_id + 308, "Send", wxPoint(width / 4 + 340, height / 3 + 85), wxSize(120, 30));

	//Add check list
	m_task_check = new wxCheckListBox(bottom_left, frame_id + 310, wxPoint(0, height / 4), wxSize(width / 4, height / 5));

	m_grid->Add(bottom_left, wxEXPAND | wxALL);

	// Bottom-right part
	bottom_right = new wxWindow(this, frame_id + 400);

	// Add combo box
	m_cmb_box = new wxComboBox(bottom_right, frame_id + 401, "Combo box", wxPoint(0, 50), wxSize(200, 200));

	// Add radio box
	wxArrayString arr;
	for (auto i = 0; i < 24; ++i) {
		arr.Add("rad_" + std::to_string(i + 1));
	}
	m_radio = new wxRadioBox(bottom_right, frame_id + 402, "Radio box", wxPoint(0, 100), wxSize(200, 200), arr, 3);

	// Add gauge
	gauge = new wxGauge(bottom_right, frame_id + 403, 100, wxPoint(310, 50), wxSize(200, 40));
	gauge->SetValue(0);

	inc_gauge = new wxButton(bottom_right, frame_id + 404, "Gauge +1", wxPoint(310, 100), wxSize(120, 30));
	inc_gauge->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnGaugeInc, this);
	dec_gauge = new wxButton(bottom_right, frame_id + 405, "Gauge -1", wxPoint(440, 100), wxSize(120, 30));
	dec_gauge->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnGaugeDec, this);
	wxStaticText* gauge_txt = new wxStaticText(bottom_right, 1406, "Current gauge lvl:", wxPoint(530, 50));
	gauge_lvl = new wxTextCtrl(bottom_right, frame_id + 406, "0", wxPoint(530, 70));

	// Add file/dir picker
	m_file_picker = new wxFilePickerCtrl(bottom_right, frame_id + 407, "", "File picker", "", wxPoint(0, 320), wxSize(width / 2 - 10, 30));
	m_dir_picker = new wxDirPickerCtrl(bottom_right, frame_id + 408, "", "Dir picker", wxPoint(0, 360), wxSize(width / 2 - 10, 30));
	
	m_grid->Add(bottom_right, wxEXPAND | wxALL);

	// Fillers
	for (auto i = 0; i < 50; ++i) {
		page_list_box->Append("list_box_item_" + std::to_string(i + 1));
		page_check->Append("check_list_choise_" + std::to_string(i + 1));
		m_checker->Append("Item_" + std::to_string(i + 1));
	}
	for (auto i = 0; i < 20; ++i) {
		auto item_index = m_table->InsertItem(i, std::to_string(i));
		m_table->SetItem(item_index, 1, "item_" + std::to_string(i + 1));
		m_table->SetItem(item_index, 2, "price $");
		m_table->SetItem(item_index, 3, "description");
		m_table->SetItem(item_index, 4, "5gnjafs_serial_number_abc" + std::to_string(i + 1));

		m_task_check->Append("Task_" + std::to_string(i + 1));
		m_cmb_box->Append("choice_" + std::to_string(i + 1));

		pg_choice_box->Append("Choice " + std::to_string(i + 1));
		pg_combo_box->Append("Combo choice " + std::to_string(i + 1));
	}

	this->SetSizer(m_grid);
	m_grid->Layout();
}

TestingFrame::~TestingFrame()
{
	delete[] main_btn;
	delete[] compass;
}

void TestingFrame::OnMenuNew(wxCommandEvent& e)
{
	e.Skip();
}

void TestingFrame::OnMenuOpen(wxCommandEvent& e)
{
	e.Skip();
}

void TestingFrame::OnMenuSave(wxCommandEvent& e)
{
	e.Skip();
}

void TestingFrame::OnMenuPrint(wxCommandEvent& e)
{
	e.Skip();
}

void TestingFrame::OnMenuSettings(wxCommandEvent& e)
{
	e.Skip();
}

void TestingFrame::OnMenuExit(wxCommandEvent& e)
{
	Close();
	e.Skip();
}

void TestingFrame::OnMenuHelp(wxCommandEvent& e)
{
	e.Skip();
}

void TestingFrame::OnCompassClick(wxCommandEvent& e)
{
	wxWindowID id_ = e.GetId();

	if (id_ == frame_id + 102) {
		board->AppendText("NW, ");
	} else if (id_ == frame_id + 103) {
		board->AppendText("NNW, ");
	}
	else if(id_ == frame_id + 104) {
		board->AppendText("N, ");
	}
	else if (id_ == frame_id + 105) {
		board->AppendText("NNE, ");
	}
	else if (id_ == frame_id + 106) {
		board->AppendText("NE, ");
	}
	else if (id_ == frame_id + 107) {
		board->AppendText("NEE, ");
	}
	else if (id_ == frame_id + 108) {
		board->AppendText("E, ");
	}
	else if (id_ == frame_id + 109) {
		board->AppendText("SEE, ");
	}
	else if (id_ == frame_id + 110) {
		board->AppendText("SE, ");
	}
	else if (id_ == frame_id + 111) {
		board->AppendText("SSE, ");
	}
	else if (id_ == frame_id + 112) {
		board->AppendText("S, ");
	}
	else if (id_ == frame_id + 113) {
		board->AppendText("SSW, ");
	}
	else if (id_ == frame_id + 114) {
		board->AppendText("SW, ");
	}
	else if (id_ == frame_id + 115) {
		board->AppendText("SWW, ");
	} 
	else if (id_ == frame_id + 116) {
		board->AppendText("W, ");
	}
	else if (id_ == frame_id + 117) {
		board->AppendText("NWW, ");
	}

	e.Skip();
}

void TestingFrame::OnGaugeInc(wxCommandEvent& e)
{
	if (gauge->GetValue() >= 0 && gauge->GetValue() < 100) {
		gauge->SetValue(gauge->GetValue() + 1);
		gauge_lvl->Clear();
		gauge_lvl->AppendText(std::to_string(gauge->GetValue()));
	}
	else {
		gauge->SetValue(0);
		gauge_lvl->Clear();
		gauge_lvl->AppendText(std::to_string(gauge->GetValue()));
	}

	e.Skip();
}

void TestingFrame::OnGaugeDec(wxCommandEvent& e)
{
	if (gauge->GetValue() > 0) {
		gauge->SetValue(gauge->GetValue() - 1);
		gauge_lvl->Clear();
		gauge_lvl->AppendText(std::to_string(gauge->GetValue()));
	}
	else {
		gauge->SetValue(100);
		gauge_lvl->Clear();
		gauge_lvl->AppendText(std::to_string(gauge->GetValue()));
	}

	e.Skip();
}
