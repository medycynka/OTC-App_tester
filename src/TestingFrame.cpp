#include "TestingFrame.h"

wxBEGIN_EVENT_TABLE(TestingFrame, wxFrame)

wxEND_EVENT_TABLE()

TestingFrame::TestingFrame(wxWindow* parent_, wxWindowID id, std::unordered_map<wxString, float>& config) : wxFrame(parent_, id, "Format", wxPoint(0, 0), wxSize(config["w_width"], config["w_height"])), m_config(config), frame_id(id), m_cpu_reader(GetCurrentProcessId())
{
	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	width = m_config["w_width"];
	height = m_config["w_height"];
	m_time_limit = m_config["time_limit"] * 60 * 1000;

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
	m_tool_bar = this->CreateToolBar(wxTB_HORIZONTAL, frame_id + 50);
	m_btn_refresh = new wxButton(m_tool_bar, frame_id + 51, "Refresh");
	m_btn_refresh->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnButtonRefresh, this);
	m_tool_bar->AddControl(m_btn_refresh);
	m_tool_bar->Realize();

	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	// Add grid layout
	wxGridSizer* m_grid = new wxGridSizer(2, 2, 10, 10);

	// Top-left part
	m_note = new wxNotebook(this, frame_id + 100, wxDefaultPosition, wxSize(width / 2, height / 2));

	// Buttons & editors page
	m_be_page = new wxNotebookPage(m_note, frame_id + 101, wxDefaultPosition, wxSize(width / 2, height / 2), 0L, "Test content");
	m_compass = new wxButton * [16];
	{
		m_compass[0] = new wxButton(m_be_page, frame_id + 102, "NW", wxPoint(0, 0), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[1] = new wxButton(m_be_page, frame_id + 103, "NNW", wxPoint(width / 10 - 2, 0), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[2] = new wxButton(m_be_page, frame_id + 104, "N", wxPoint(width / 5 - 4, 0), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[3] = new wxButton(m_be_page, frame_id + 105, "NNE", wxPoint(3 * width / 10 - 6, 0), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[4] = new wxButton(m_be_page, frame_id + 106, "NE", wxPoint(4 * width / 10 - 8, 0), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[5] = new wxButton(m_be_page, frame_id + 107, "NEE", wxPoint(4 * width / 10 - 8, height / 10 - 8), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[6] = new wxButton(m_be_page, frame_id + 108, "E", wxPoint(4 * width / 10 - 8, height / 5 - 16), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[7] = new wxButton(m_be_page, frame_id + 109, "SEE", wxPoint(4 * width / 10 - 8, 3 * height / 10 - 24), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[8] = new wxButton(m_be_page, frame_id + 110, "SE", wxPoint(4 * width / 10 - 8, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[9] = new wxButton(m_be_page, frame_id + 111, "SSE", wxPoint(3 * width / 10 - 6, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[10] = new wxButton(m_be_page, frame_id + 112, "S", wxPoint(width / 5 - 4, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[11] = new wxButton(m_be_page, frame_id + 113, "SSW", wxPoint(width / 10 - 2, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[12] = new wxButton(m_be_page, frame_id + 114, "SW", wxPoint(0, 4 * height / 10 - 32), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[13] = new wxButton(m_be_page, frame_id + 115, "SWW", wxPoint(0, 3 * height / 10 - 24), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[14] = new wxButton(m_be_page, frame_id + 116, "W", wxPoint(0, height / 5 - 16), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
		m_compass[15] = new wxButton(m_be_page, frame_id + 117, "NWW", wxPoint(0, height / 10 - 8), wxSize(width / 10 - 2, height / 10 - 8));
		m_compass[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnCompassClick, this);
	}
	m_board = new wxTextCtrl(m_be_page, frame_id + 118, "", wxPoint(width / 10 - 2, height / 10 - 8), wxSize(3 * width / 10 - 6, 3 * height / 10 - 24), wxTE_MULTILINE | wxTE_RICH);
	m_note->InsertPage(0, m_be_page, "Buttons and edits", true);

	// Lists page
	m_li_page = new wxNotebookPage(m_note, frame_id + 120, wxDefaultPosition, wxSize(width / 2, height / 2), 0L, "Test content");

	m_page_list_box = new wxListBox(m_li_page, frame_id + 121, wxPoint(0, 0), wxSize(width / 4 - 4, height / 4 - 2));
	m_page_check = new wxCheckListBox(m_li_page, frame_id + 122, wxPoint(width / 4, 0), wxSize(width / 4 - 8, height / 4 - 2));

	wxArrayString p_arr;
	for (auto i = 0; i < 40; ++i) {
		p_arr.Add("radio_" + std::to_string(i + 1));
	}
	m_radio = new wxRadioBox(m_li_page, frame_id + 123, "Radio box", wxPoint(0, height / 4), wxSize(width / 2 - 4, height / 5), p_arr, 8);
	m_page_radio = new wxRadioBox();

	m_note->InsertPage(1, m_li_page, "\tLists\t", false);

	// Boxes Page
	m_bo_page = new wxNotebookPage(m_note, frame_id + 150, wxDefaultPosition, wxSize(width / 2, height / 2), 0L, "Test content");

	wxChoice* pg_choice_box = new wxChoice(m_bo_page, frame_id + 151, wxPoint(0, 0), wxSize(width / 6 - 5, 40), {});
	wxComboBox* pg_combo_box = new wxComboBox(m_bo_page, frame_id + 152, "Choose one again", wxPoint(width / 6, 0), wxSize(width / 6 - 5, 40));
	wxSpinCtrl* pg_spin = new wxSpinCtrl(m_bo_page, frame_id + 153, "", wxPoint(width / 3, 0), wxSize(width / 6 - 5, 20), 16384L, -1000, 1000, 0);
	wxCalendarCtrl* pg_calendar = new wxCalendarCtrl(m_bo_page, frame_id, wxDefaultDateTime, wxPoint(0, 5 * height / 64), wxSize(width / 4 - 5, 3 * height / 8 - 5));
	wxFileCtrl* pf_file_ctrl = new wxFileCtrl(m_bo_page, frame_id + 154, wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFC_MULTIPLE, wxPoint(width / 4, 5 * height / 64));

	m_note->InsertPage(2, m_bo_page, "\tBoxes\t", false);
	m_grid->Add(m_note, wxEXPAND | wxALL);

	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	// Top-right-part
	m_top_right = new wxWindow(this, frame_id + 200);

	// Add text field
	m_txt = new wxTextCtrl(m_top_right, frame_id + 201, m_lorem, wxPoint(10, 0), wxSize(width / 8, height / 2), wxTE_MULTILINE | wxTE_RICH);

	// Add buttons
	m_main_btn = new wxToggleButton * [20];
	for (auto i = 0; i < 10; ++i) {
		m_main_btn[i] = new wxToggleButton(m_top_right, frame_id + 202 + i, "Clicker " + std::to_string(i + 1), wxPoint(5 * width / 32, i * (height / 20)), wxSize(width / 16, height / 20));
		m_main_btn[i + 10] = new wxToggleButton(m_top_right, frame_id + 202 + i + 10, "Clicker " + std::to_string(i + 11), wxPoint(7 * width / 32, i * (height / 20)), wxSize(width / 16, height / 20));
	}

	// Add check list
	m_checker = new wxListBox(m_top_right, frame_id + 222, wxPoint(41 * width / 128, 0), wxSize(11 * width / 64, height / 2));

	m_grid->Add(m_top_right, wxEXPAND | wxALL);

	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	// Bottom-left part
	m_bottom_left = new wxWindow(this, frame_id + 300);

	// Add report table
	m_table = new wxListCtrl(m_bottom_left, frame_id + 301, wxPoint(0, 45), wxSize(width / 4, height / 5 - 10), wxLC_REPORT, wxDefaultValidator, "Report table");
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
	m_report = new wxStaticText(m_bottom_left, frame_id + 302, "Write a report", wxPoint(17 * width / 64, 45));
	m_date = new wxDatePickerCtrl(m_bottom_left, frame_id + 303, wxDefaultDateTime, wxPoint(width / 4 + 20, 65), wxSize(100, 30));
	m_font = new wxFontPickerCtrl(m_bottom_left, frame_id + 304, wxNullFont, wxPoint(width / 4 + 140, 65), wxSize(100, 30));
	m_report_txt = new wxTextCtrl(m_bottom_left, frame_id + 305, "", wxPoint(width / 4 + 20, 100), wxSize(width / 4 - 30, height / 5), wxTE_MULTILINE | wxTE_RICH);
	m_btn_save = new wxButton(m_bottom_left, frame_id + 306, "Save", wxPoint(35 * width / 128, 11 * height / 32), wxSize(9 * width / 128, 30));
	m_btn_print = new wxButton(m_bottom_left, frame_id + 307, "Print", wxPoint(89 * width / 256, 11 * height / 32), wxSize(9 * width / 128, 30));
	m_btn_send = new wxButton(m_bottom_left, frame_id + 308, "Send", wxPoint(27 * width / 64, 11 * height / 32), wxSize(9 * width / 128, 30));

	//Add check list
	m_task_check = new wxCheckListBox(m_bottom_left, frame_id + 310, wxPoint(0, height / 4), wxSize(width / 4, height / 6));

	m_grid->Add(m_bottom_left, wxEXPAND | wxALL);

	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	// Bottom-right part
	m_bottom_right = new wxWindow(this, frame_id + 400);

	// Add combo box
	m_cmb_box = new wxComboBox(m_bottom_right, frame_id + 401, "Combo box", wxPoint(0, 50), wxSize(200, 200));

	// Add radio box
	wxArrayString arr;
	for (auto i = 0; i < 24; ++i) {
		arr.Add("rad_" + std::to_string(i + 1));
	}
	m_radio = new wxRadioBox(m_bottom_right, frame_id + 402, "Radio box", wxPoint(0, 100), wxSize(200, 200), arr, 3);

	// Add gauge
	m_gauge = new wxGauge(m_bottom_right, frame_id + 403, 100, wxPoint(width / 5, 50), wxSize(width / 6, 40));
	m_gauge->SetValue(0);

	m_inc_gauge_btn = new wxButton(m_bottom_right, frame_id + 404, "Gauge +1", wxPoint(width / 5, 100), wxSize(width / 12, 30));
	m_inc_gauge_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnGaugeInc, this);
	m_dec_gauge_btn = new wxButton(m_bottom_right, frame_id + 405, "Gauge -1", wxPoint(17 * width / 60, 100), wxSize(width / 12, 30));
	m_dec_gauge_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TestingFrame::OnGaugeDec, this);
	wxStaticText* gauge_txt = new wxStaticText(m_bottom_right, 1406, "Current gauge lvl:", wxPoint(23 * width / 60, 50));
	m_gauge_lvl = new wxTextCtrl(m_bottom_right, frame_id + 406, "0", wxPoint(23 * width / 60, 70));

	// Add file/dir picker
	m_file_picker = new wxFilePickerCtrl(m_bottom_right, frame_id + 407, "", "File picker", "", wxPoint(width / 5, 5 * width / 32), wxSize(width / 4 - 10, 30));
	m_dir_picker = new wxDirPickerCtrl(m_bottom_right, frame_id + 408, "", "Dir picker", wxPoint(width / 5, 3 * width / 16), wxSize(width / 4 - 10, 30));
	
	m_grid->Add(m_bottom_right, wxEXPAND | wxALL);

	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	// Fillers
	for (auto i = 0; i < 50; ++i) {
		m_page_list_box->Append("list_box_item_" + std::to_string(i + 1));
		m_page_check->Append("check_list_choise_" + std::to_string(i + 1));
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
	Show();

	// Creating dialogs
	for (auto i = 0; i < m_config["dialogs_count"]; ++i) {
		DialogFrame* temp = new DialogFrame(this, frame_id + 1000 + (m_dialogs.size() + 1) * 100, wxSize(config["w_width"] / 3, config["w_height"] / 3));
		temp->Show();

		if (m_config["seq_count"] != 0) {
			temp->Iconize();
		}

		m_dialogs.push_back({ frame_id + 1000 + (m_dialogs.size() + 1) * 100, temp });
	}

	if (m_config["seq_count"] != 0) {
		m_dialogs[0].second->Maximize(false);
	}

	// Creating timer

	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	RunAllTests();
}

TestingFrame::~TestingFrame()
{
	delete[] m_main_btn;
	delete[] m_compass;
}

void TestingFrame::OnMenuNew(wxCommandEvent& e)
{
	DialogFrame* temp = new DialogFrame(this, frame_id + 1000 + (m_dialogs.size() + 1) * 100, wxSize(m_config["w_width"] / 3, m_config["w_height"] / 3));
	temp->Show();
	m_dialogs.push_back({ frame_id + 1000 + (m_dialogs.size() + 1) * 100, temp });

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

void TestingFrame::OnButtonRefresh(wxCommandEvent& e)
{
	this->Refresh();
	e.Skip();
}

void TestingFrame::OnCompassClick(wxCommandEvent& e)
{
	wxWindowID id_ = e.GetId();

	if (id_ == frame_id + 102) {
		m_board->AppendText("NW, ");
	} else if (id_ == frame_id + 103) {
		m_board->AppendText("NNW, ");
	}
	else if(id_ == frame_id + 104) {
		m_board->AppendText("N, ");
	}
	else if (id_ == frame_id + 105) {
		m_board->AppendText("NNE, ");
	}
	else if (id_ == frame_id + 106) {
		m_board->AppendText("NE, ");
	}
	else if (id_ == frame_id + 107) {
		m_board->AppendText("NEE, ");
	}
	else if (id_ == frame_id + 108) {
		m_board->AppendText("E, ");
	}
	else if (id_ == frame_id + 109) {
		m_board->AppendText("SEE, ");
	}
	else if (id_ == frame_id + 110) {
		m_board->AppendText("SE, ");
	}
	else if (id_ == frame_id + 111) {
		m_board->AppendText("SSE, ");
	}
	else if (id_ == frame_id + 112) {
		m_board->AppendText("S, ");
	}
	else if (id_ == frame_id + 113) {
		m_board->AppendText("SSW, ");
	}
	else if (id_ == frame_id + 114) {
		m_board->AppendText("SW, ");
	}
	else if (id_ == frame_id + 115) {
		m_board->AppendText("SWW, ");
	} 
	else if (id_ == frame_id + 116) {
		m_board->AppendText("W, ");
	}
	else if (id_ == frame_id + 117) {
		m_board->AppendText("NWW, ");
	}

	e.Skip();
}

void TestingFrame::OnGaugeInc(wxCommandEvent& e)
{
	if (m_gauge->GetValue() >= 0 && m_gauge->GetValue() < 100) {
		m_gauge->SetValue(m_gauge->GetValue() + 1);
		m_gauge_lvl->Clear();
		m_gauge_lvl->AppendText(std::to_string(m_gauge->GetValue()));
	}
	else {
		m_gauge->SetValue(0);
		m_gauge_lvl->Clear();
		m_gauge_lvl->AppendText(std::to_string(m_gauge->GetValue()));
	}

	e.Skip();
}

void TestingFrame::OnGaugeDec(wxCommandEvent& e)
{
	if (m_gauge->GetValue() > 0) {
		m_gauge->SetValue(m_gauge->GetValue() - 1);
		m_gauge_lvl->Clear();
		m_gauge_lvl->AppendText(std::to_string(m_gauge->GetValue()));
	}
	else {
		m_gauge->SetValue(100);
		m_gauge_lvl->Clear();
		m_gauge_lvl->AppendText(std::to_string(m_gauge->GetValue()));
	}

	e.Skip();
}

void TestingFrame::OnTimerTickZOrder(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["z-order_count"]) {
			if (m_curr_op_count < m_config["z-order_count"]) {
				if (m_curr_it == m_dialogs.end()) {
					m_curr_it = m_dialogs.begin();
				}

				(*m_curr_it).second->Raise();
				m_curr_it++;

				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["z-order"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickZOrder));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRefresh));

				CloseAllDialogs();
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["z-order"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickZOrder));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRefresh));

			CloseAllDialogs();
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["z-order"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickSeq(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["seq_count"]) {
			if (m_curr_op_count < m_config["seq_count"]) {
				(*m_curr_it).second->Iconize();
				m_curr_it++;

				if (m_curr_it == m_dialogs.end()) {
					m_curr_it = m_dialogs.begin();
				}

				(*m_curr_it).second->Maximize(false);

				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["seq"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickSeq));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRefresh));

				CloseAllDialogs();
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["seq"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickSeq));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRefresh));

			CloseAllDialogs();
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["seq"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickRefresh(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["refresh_count"]) {
			if (m_curr_op_count < m_config["refresh_count"]) {
				this->Refresh();
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["refresh"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRefresh));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickTabCtrl));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["refresh"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRefresh));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickTabCtrl));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["refresh"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickTabCtrl(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["tab_change_count"]) {
			if (m_curr_op_count < m_config["tab_change_count"]) {
				m_note->ChangeSelection(m_curr_op_count % 3);
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["tab"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickTabCtrl));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickButton));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["tab"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickTabCtrl));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickButton));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["tab"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickButton(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["button_press_count"]) {
			if (m_curr_op_count < m_config["button_press_count"]) {
				m_main_btn[2]->SetValue(!m_main_btn[2]->GetValue());
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["button"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_main_btn[2]->SetValue(false);
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickButton));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickScroll));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["button"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_main_btn[2]->SetValue(false);
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickButton));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickScroll));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["button"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickScroll(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["scroll_count"]) {
			if (m_curr_op_count < m_config["scroll_count"]) {
				if (m_scroll_down) {
					m_txt->ScrollLines(1);

					if (m_txt->GetScrollPos(wxVERTICAL) >= m_txt->GetScrollRange(wxVERTICAL) / 2) {
						m_scroll_down = false;
					}
				}
				else {
					m_txt->ScrollLines(-1);

					if (m_txt->GetScrollPos(wxVERTICAL) <= 2) {
						m_scroll_down = true;
					}
				}

				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["scroll"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickScroll));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickSelect));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["scroll"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickScroll));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickSelect));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["scroll"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickSelect(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["select_list_count"]) {
			if (m_curr_op_count < m_config["select_list_count"]) {
				m_checker->Select(5 + m_curr_op_count % 5);
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["select"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickSelect));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickCheck));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["select"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickSelect));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickCheck));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["select"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickCheck(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["check_list_count"]) {
			if (m_curr_op_count < m_config["check_list_count"]) {
				if (m_curr_op_count % 2 == 0) {
					m_task_check->Check(2, true);
					m_task_check->Check(6, false);
				}
				else {
					m_task_check->Check(2, false);
					m_task_check->Check(6, true);
				}

				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["check"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickCheck));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickWrite));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["check"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickCheck));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickWrite));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["check"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickWrite(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["write_count"]) {
			if (m_curr_op_count < m_config["write_count"]) {
				if (m_curr_op_count % 10 == 0) {
					m_report_txt->Clear();
				}

				m_report_txt->AppendText("Testing...\n");
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["write"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickWrite));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRadio));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["write"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickWrite));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRadio));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["write"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickRadio(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["radio_list_count"]) {
			if (m_curr_op_count < m_config["radio_list_count"]) {
				m_radio->Select(5 + m_curr_op_count % 5);
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["radio"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				// Setting time event handler to next operation
				Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRadio));
				Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickGauge));
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["radio"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			// Setting time event handler to next operation
			Disconnect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickRadio));
			Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickGauge));
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["radio"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::OnTimerTickGauge(wxTimerEvent& e)
{
	if (m_accumulate_time <= m_time_limit) {
		if (wxGetLocalTimeMillis() - m_start_point <= m_config["interval"] * m_config["gauge_count"]) {
			if (m_curr_op_count < m_config["gauge_count"]) {
				if (m_inc_gauge) {
					m_gauge->SetValue(m_gauge->GetValue() + 1);

					if (m_gauge->GetValue() == 100) {
						m_inc_gauge = false;
					}
				}
				else {
					m_gauge->SetValue(m_gauge->GetValue() - 1);

					if (m_gauge->GetValue() == 0) {
						m_inc_gauge = true;
					}
				}

				m_gauge_lvl->Clear();
				m_gauge_lvl->AppendText(std::to_string(m_gauge->GetValue()));
				m_curr_op_count++;
				m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
			}
			else {
				m_all_op_count += m_curr_op_count;
				m_result["gauge"] = m_curr_op_count;
				m_curr_op_count = 0;
				m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
				m_start_point = wxGetLocalTimeMillis();

				m_timer->Stop();
				WriteResults();
			}
		}
		else {
			m_all_op_count += m_curr_op_count;
			m_result["gauge"] = m_curr_op_count;
			m_curr_op_count = 0;
			m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
			m_start_point = wxGetLocalTimeMillis();

			m_timer->Stop();
			WriteResults();
		}
	}
	else {
		m_all_op_count += m_curr_op_count;
		m_result["gauge"] = m_curr_op_count;
		m_accumulate_time += wxGetLocalTimeMillis() - m_start_point;
		m_timer->Stop();
		WriteResults();
	}

	e.Skip();
}

void TestingFrame::CloseAllDialogs()
{
	for (auto& e : m_dialogs) {
		e.second->Close();
	}
}

unsigned long TestingFrame::GetPlannedOperationsCount()
{
	return unsigned long(m_config["z-order_count"] + m_config["seq_count"] + m_config["refresh_count"] + m_config["tab_change_count"] + m_config["button_press_count"] + m_config["scroll_count"] + m_config["select_list_count"] + m_config["check_list_count"] + m_config["write_count"] + m_config["radio_list_count"] + m_config["gauge_count"]);
}

void TestingFrame::RunAllTests()
{
	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	m_timer = new wxTimer(this, frame_id + 500);

	if (m_config["z-order_count"] != 0) {
		Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::OnTimerTickZOrder));
	}
	else {
		Connect(frame_id + 500, wxEVT_TIMER, wxTimerEventHandler(TestingFrame::TestingFrame::OnTimerTickSeq));
	}

	m_curr_it = m_dialogs.begin();
	m_start_point = wxGetLocalTimeMillis();
	m_timer->Start(m_config["interval"]);
	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();
}

void TestingFrame::WriteResults()
{
	m_accumulate_cpu_usage += m_cpu_reader.GetCpuUsage();

	// Writing result to file "result_ID<test_id>x<frame_id>x<PID>.txt"
	wxTextFile result("results/result_ID" + std::to_string(int(m_config["test_id"])) + "x" + std::to_string(frame_id) + "x" + std::to_string(GetCurrentProcessId()) + ".txt");
	result.Create("results/result_ID" + std::to_string(int(m_config["test_id"])) + "x" + std::to_string(frame_id) + "x" + std::to_string(GetCurrentProcessId()) + ".txt");
	result.Open();
	result.Clear();
	{
		result.AddLine("Test " + std::to_string(int(m_config["test_id"])) + " summary with:");
		result.AddLine("\ttime limit: " + std::to_string(int(m_config["time_limit"])) + " minutes");
		result.AddLine("\tinterval: " + std::to_string(int(m_config["interval"])) + "ms");
		result.AddLine("");
		result.AddLine("Planned operations " + std::to_string(GetPlannedOperationsCount()));
		result.AddLine("Actually done " + std::to_string(m_all_op_count));
		result.AddLine("Total performance indicator: " + std::to_string(GetPlannedOperationsCount() == 0 ? 0 : ((float)m_all_op_count / GetPlannedOperationsCount()) * 100.0f) + "%");
		result.AddLine("Test took " + std::to_string(m_accumulate_time.GetValue()) + "ms");
		result.AddLine("Averge CPU usage " + std::to_string((float)m_accumulate_cpu_usage / (m_all_op_count + 10)) + "%");
		result.AddLine("");
		result.AddLine("\"z-order\" result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["z-order_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["z-order"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["z-order_count"] == 0 ? 100 : (m_result["z-order"] / m_config["z-order_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("\"sequential\" result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["seq_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["seq"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["seq_count"] == 0 ? 100 : (m_result["seq"] / m_config["seq_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("refresh result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["refresh_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["refresh"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["refresh_count"] == 0 ? 100 : (m_result["refresh"] / m_config["refresh_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Tab control change result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["tab_change_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["tab"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["tab_change_count"] == 0 ? 100 : (m_result["tab"] / m_config["tab_change_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Button clicks result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["button_press_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["button"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["button_press_count"] == 0 ? 100 : (m_result["button"] / m_config["button_press_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Scroll result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["scroll_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["scroll"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["scroll_count"] == 0 ? 100 : (m_result["scroll"] / m_config["scroll_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Select list result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["select_list_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["select"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["select_list_count"] == 0 ? 100 : (m_result["select"] / m_config["select_list_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Check list result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["check_list_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["check"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["check_list_count"] == 0 ? 100 : (m_result["check"] / m_config["check_list_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Writing result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["write_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["write"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["write_count"] == 0 ? 100 : (m_result["write"] / m_config["write_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Radio box result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["radio_list_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["radio"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["radio_list_count"] == 0 ? 100 : (m_result["radio"] / m_config["radio_list_count"]) * 100.0f) + "%");
		result.AddLine("");
		result.AddLine("Gauge result:");
		result.AddLine("\t planned operations count: " + std::to_string(int(m_config["gauge_count"])));
		result.AddLine("\t actual operations count: " + std::to_string(m_result["gauge"]));
		result.AddLine("\t performance indicator: " + std::to_string(m_config["gauge_count"] == 0 ? 100 : (m_result["gauge"] / m_config["gauge_count"]) * 100.0f) + "%");
	}
	result.Write();
	result.Close();

	// Closing Application
	this->Close();
}
