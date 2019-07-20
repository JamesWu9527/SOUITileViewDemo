#pragma once
#include ".\core\SHostDialog.h"

namespace SOUI
{
	class SModifyData :public SHostDialog
	{
	public:
		SModifyData(const TestStruct& data);
		~SModifyData();

	public:
		void OnClickOK();
		void OnClickCancel();
		void OnClickExit();
		BOOL OnInitDialog(HWND wnd, LPARAM lInitParam);
		const TestStruct& getData() { return m_data; }

	protected:
		//soui消息
		EVENT_MAP_BEGIN()
			EVENT_NAME_COMMAND(L"btn_close", OnClickExit)
			EVENT_NAME_COMMAND(L"btn_cancel", OnClickCancel)
			EVENT_NAME_COMMAND(L"btn_ok", OnClickOK)
			
			EVENT_MAP_END()

			//HostWnd真实窗口消息处理
			BEGIN_MSG_MAP_EX(SModifyData)
			MSG_WM_INITDIALOG(OnInitDialog)
			MSG_WM_SIZE(OnSize)
			CHAIN_MSG_MAP(SHostDialog)
			REFLECT_NOTIFICATIONS_EX()
			END_MSG_MAP()

	private:
		SEdit *m_editInput01;
		SEdit *m_editInput02;
		TestStruct m_data;
	};

}

