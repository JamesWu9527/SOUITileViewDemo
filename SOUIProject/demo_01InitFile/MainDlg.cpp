// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
#include "STitleViewAdapter.h"
	
CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;

	//对控件进行初始化
	STileView* pList = FindChildByName2<STileView>(L"tv_test");
	if (pList)
	{
		//设置适配器
		std::vector<TestStruct> vctData{ {L"ssss",1},{L"safdas",2},{L"彦祖",3},{L"JamesWu",4} };
		STitleViewAdapter* pAdapter = new STitleViewAdapter(vctData);
		pList->SetAdapter(pAdapter);
		pAdapter->Release();
	}

	return 0;
}
//TODO:消息映射
void CMainDlg::OnClose()
{
	CSimpleWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnAddWnd()
{
	srand((int)time(0));
	std::vector<TestStruct> vctAddTestData{ {L"ssss",1},{L"safdas",2},{L"彦祖",3},{L"JamesWu",4} };
	STileView* ptv = FindChildByName2<STileView>(L"tv_test");
	if (ptv)
	{
		STitleViewAdapter* pAdapter = (STitleViewAdapter*)ptv->GetAdapter();
		pAdapter->AddWnd(vctAddTestData[rand() % vctAddTestData.size()]);
	}
}

void CMainDlg::OnDeleteAll()
{
	STileView* ptv = FindChildByName2<STileView>(L"tv_test");
	if (ptv)
	{
		STitleViewAdapter* pAdapter = (STitleViewAdapter*)ptv->GetAdapter();
		pAdapter->DeleteAll();
	}
}

void CMainDlg::OnFind()
{
	SEdit* pEdit = FindChildByName2<SEdit>(L"edit_text");
	SStringT strText = pEdit->GetWindowTextW();

	if (strText.IsEmpty())
	{
		SMessageBox(NULL, L"数据为空,开始从新拉取数据们进行数据更新", L"提示", 0);
		OnUpdateData();
		return;
	}
	
	STileView* ptv = FindChildByName2<STileView>(L"tv_test");
	if (ptv)
	{
		STitleViewAdapter* pAdapter = (STitleViewAdapter*)ptv->GetAdapter();
		pAdapter->OnFind(strText);
	}
	pEdit->SetWindowTextW(L"");
}

void CMainDlg::OnUpdateData()
{
	std::vector<TestStruct> vctData{ {L"ssss",1},{L"safdas",2},{L"彦祖",3},{L"JamesWu",4} };
	STileView* ptv = FindChildByName2<STileView>(L"tv_test");
	if (ptv)
	{
		STitleViewAdapter* pAdapter = (STitleViewAdapter*)ptv->GetAdapter();
		pAdapter->OnUpdateData(vctData);
	}
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

