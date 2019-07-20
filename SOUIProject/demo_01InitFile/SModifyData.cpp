#include "stdafx.h"
#include "SModifyData.h"
#include <string>

namespace SOUI
{
	SModifyData::SModifyData(const TestStruct& data):SHostDialog(L"LAYOUT:dlg_modifydata")
	{
		m_data = data;
		m_editInput01 = nullptr;
		m_editInput02 = nullptr;
	}

	SModifyData::~SModifyData()
	{
	
	}

	void SModifyData::OnClickOK()
	{
		//将修改的数据存储起来 通过数据结构 
		m_data.strtest = m_editInput01->GetWindowTextW();
		std::string strTemp = S_CT2A(m_editInput02->GetWindowTextW());
		m_data.ipos = std::stoi(strTemp);

		EndDialog(1);
	}

	void SModifyData::OnClickCancel()
	{
		EndDialog(0);
	}

	void SModifyData::OnClickExit()
	{
		EndDialog(0);
	}

	BOOL SModifyData::OnInitDialog(HWND wnd, LPARAM lInitParam)
	{
		//导入数据
		m_editInput01 = FindChildByName2<SEdit>(L"edit_input1");
		SASSERT(m_editInput01);
		m_editInput02 = FindChildByName2<SEdit>(L"edit_input2");
		SASSERT(m_editInput02);

		m_editInput01->SetWindowTextW(m_data.strtest);
		m_editInput02->SetWindowTextW(SStringT().Format(L"%d", m_data.ipos));

		return 0;
	}
}
