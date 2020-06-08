#include "tApp.h"

wxIMPLEMENT_APP(tApp);

tApp::tApp() {

}

tApp::~tApp() {
}

bool tApp::OnInit()
{
    m_main_frame = new TestingFrame(nullptr, m_app_id + 10000);

    m_main_frame->Show();

    return true;
}
