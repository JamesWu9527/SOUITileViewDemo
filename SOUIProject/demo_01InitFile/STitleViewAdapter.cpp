#include "stdafx.h"
#include "STitleViewAdapter.h"
#include "SModifyData.h"

namespace SOUI
{
	STitleViewAdapter::STitleViewAdapter(const std::vector<TestStruct>& vctData)
	{
		m_vctData = vctData;
	}

	STitleViewAdapter::~STitleViewAdapter()
	{
	}

	int STitleViewAdapter::getCount()
	{
		return m_vctData.size();
	}

	void STitleViewAdapter::getView(int position, SWindow* pItem, pugi::xml_node xmlTemplate)
	{
		if (0 == pItem->GetChildrenCount())
		{
			pItem->InitFromXml(xmlTemplate);
		}

		//数据初始化
		SStatic *pText = pItem->FindChildByName2<SStatic>(L"txt_show");
		SASSERT(pText);
		pText->SetWindowTextW(m_vctData[position].strtest);

		SButton* pButton = pItem->FindChildByName2<SButton>(L"btn_closewnd");
		SASSERT(pButton);
		pButton->SetUserData(position);
		pButton->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&STitleViewAdapter::OnCloseWnd, this));

		pButton = pItem->FindChildByName2<SButton>(L"btn_modify");
		SASSERT(pButton);
		pButton->SetUserData(position);
		pButton->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&STitleViewAdapter::OnModifyData, this));
	}

	bool STitleViewAdapter::OnCloseWnd(EventArgs* e)
	{
		SButton* pBtn = sobj_cast<SButton>(e->sender);
		int iItem = pBtn->GetUserData();
		SMessageBox(NULL, SStringT().Format(_T("button of %d item was clicked"), m_vctData[iItem].ipos), _T("haha"), MB_OK);

		//删除操作
		auto it = m_vctData.begin() + iItem;
		m_vctData.erase(it);
		notifyDataSetChanged();

		return true;
	}

	bool STitleViewAdapter::OnModifyData(EventArgs* e)
	{
		SButton* pBtn = sobj_cast<SButton>(e->sender);
		int iItem = pBtn->GetUserData();

		//Step1: 获取当前选中窗口的数据 填入到要修改的框内
		TestStruct data = m_vctData[iItem];
		SModifyData dlg(data);
		int ret = dlg.DoModal();
		if (0 == ret)
			return false;

		//Step2: 将修改的值 返回到控件内进行显示
		m_vctData[iItem] = dlg.getData();
		notifyDataSetChanged();
		return false;
	}

	void STitleViewAdapter::AddWnd(const TestStruct& strTemp)
	{
		m_vctData.push_back(strTemp);
		notifyDataSetChanged();
	}

	void STitleViewAdapter::DeleteAll()
	{
		m_vctData.clear();
		m_vctData.swap(std::vector<TestStruct>());
		notifyDataSetChanged();
	}

	//这里可以通过后台来处理好数据 这里单独测试用
	void STitleViewAdapter::OnFind(const SStringT& strFind)
	{
		std::vector<TestStruct> vctData;
		for (auto data : m_vctData)
		{
			if (data.strtest.Find(strFind)>=0)
			{
				vctData.push_back(data);
			}
		}

		if (!strFind.IsEmpty())
		{
			m_vctData.clear();
			m_vctData.swap(vctData);
		}
		
		notifyDataSetChanged();
	}

	void STitleViewAdapter::OnUpdateData(const std::vector<TestStruct>& vctData)
	{
		m_vctData.clear();
		m_vctData.swap(std::vector<TestStruct>());
		m_vctData = vctData;
		notifyDataSetChanged();
	}

}

