#pragma once

#include "helper/SAdapterBase.h"
#include <vector>

namespace SOUI
{
	class STitleViewAdapter :public SAdapterBase
	{
	public:
		STitleViewAdapter(const std::vector<TestStruct> &vctData);
		~STitleViewAdapter();

	public:
		virtual int getCount();
		virtual void getView(int position, SWindow* pItem, pugi::xml_node xmlTemplate);
		bool OnCloseWnd(EventArgs *e);
		bool OnModifyData(EventArgs* e);

		void AddWnd(const TestStruct &strTemp);
		void DeleteAll();
		void OnFind(const SStringT& strFind);
		void OnUpdateData(const std::vector<TestStruct>& vctData);

	private:
		std::vector<TestStruct> m_vctData;
	};

}

