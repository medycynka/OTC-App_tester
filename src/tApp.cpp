#include "tApp.h"

wxIMPLEMENT_APP(tApp);

tApp::tApp(){

}

tApp::~tApp() {
}

bool tApp::OnInit()
{
    if (!wxApp::OnInit()) {
        return false;
    }

    // Reading from file with pattern:
    // configuration_type number
    if (m_config_path != "") {
        wxFileInputStream config_file(m_config_path);
        wxTextInputStream txt(config_file, "\x20", wxConvUTF8);

        while (config_file.IsOk() && !config_file.Eof()) {
            wxString line = txt.ReadWord();
            float nr = txt.ReadDouble();
            m_config[line] = nr;
        }

        if (m_config["z-order_count"] != 0 && m_config["seq_count"] != 0) {
            m_config["seq_count"] = 0;
        }
    }
    else {
        m_config = std::unordered_map<wxString, float>{ 
            {"w_width", 1600}, {"w_height", 1024}, 
            {"total_time", 1}, 
            {"interval", 1000}, 
            {"dialogs_count", 3}, 
            {"z-order_count", 10}, 
            {"seq_count", 0}, 
            {"refresh_count", 3}
        };
    }

    m_main_frame = new TestingFrame(nullptr, m_app_id + 10000, m_config);

    return true;
}

int tApp::OnExit()
{
    m_app_dialogs.clear();\

    return 0;
}

int tApp::OnRun()
{
    auto exit_code = wxApp::OnRun();

    if (exit_code != 0) {
        return exit_code;
    }

    return 0;
}

void tApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(g_cmdLineDesc);
    //// must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars(wxT("-"));
}

bool tApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    // For more than one parameter
    /*wxArrayString files;
    for (int i = 0; i < parser.GetParamCount(); i++)
    {
        files.Add(parser.GetParam(i));
    }*/
    if (parser.GetParamCount() > 0) {
        m_config_path = parser.GetParam(0);
    }

    return true;
}
