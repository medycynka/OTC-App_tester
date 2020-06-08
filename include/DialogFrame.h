#pragma once

#include <wx\wx.h>


class DialogFrame : public wxFrame
{
public:
	DialogFrame(wxWindow* parent_, wxWindowID id, const wxSize &size_);
	~DialogFrame();

private:
	void OnButtonCancel(wxCommandEvent& e);
	void OnButtonSave(wxCommandEvent& e);
	void OnButtonClose(wxCommandEvent& e);

private:
	wxWindowID m_dialog_id;
	wxTextCtrl* m_dialog_text = nullptr;
	wxString m_txt = "Nunc ut nisi risus. Morbi ultricies eget magna sed posuere. Nam dapibus, enim quis malesuada congue, neque nunc aliquet turpis, id ultrices nisi orci quis ligula. Phasellus ut nibh nulla. Maecenas ornare non neque ut efficitur. Nunc ullamcorper erat in aliquam tempor. Maecenas condimentum dictum mi at varius. Vivamus eu nunc in urna cursus rutrum in ac leo. Aliquam ut enim non metus egestas interdum ut at tellus. \nPhasellus id dolor laoreet quam tincidunt vulputate vitae nec metus. Pellentesque porttitor euismod libero, id gravida ligula molestie ac. Donec non tortor venenatis, pulvinar orci nec, lacinia arcu. Morbi at consequat nulla. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc fermentum est ipsum, id sodales odio lacinia nec. Vivamus vestibulum, quam vitae vestibulum fermentum, nisi tellus laoreet magna, quis aliquam magna ex vel ex. Vivamus dictum, lorem ac facilisis tempor, lorem mauris dapibus est, in egestas mi eros maximus orci. Maecenas ac sagittis ante. Vivamus euismod congue sem nec pulvinar. Etiam porta sed sapien eget aliquam.";
	wxButton* m_cancel_btn = nullptr;
	wxButton* m_save_btn = nullptr;
	wxButton* m_close_btn = nullptr;
	wxBitmap m_bit_map;
	wxStaticBitmap** m_btm = nullptr;
};

