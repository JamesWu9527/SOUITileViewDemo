//stamp:092a370ee61ba0e8
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				dlg_modifydata = _T("LAYOUT:dlg_modifydata");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * dlg_modifydata;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
			}
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_add",65540},
		{L"btn_cancel",65552},
		{L"btn_close",65536},
		{L"btn_closewnd",65545},
		{L"btn_delete",65541},
		{L"btn_find",65543},
		{L"btn_max",65537},
		{L"btn_min",65539},
		{L"btn_modify",65547},
		{L"btn_ok",65551},
		{L"btn_restore",65538},
		{L"edit_input1",65549},
		{L"edit_input2",65550},
		{L"edit_text",65542},
		{L"tv_test",65544},
		{L"txt_show",65546},
		{L"txt_title",65548}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_add = namedXmlID[1].strName;
			btn_cancel = namedXmlID[2].strName;
			btn_close = namedXmlID[3].strName;
			btn_closewnd = namedXmlID[4].strName;
			btn_delete = namedXmlID[5].strName;
			btn_find = namedXmlID[6].strName;
			btn_max = namedXmlID[7].strName;
			btn_min = namedXmlID[8].strName;
			btn_modify = namedXmlID[9].strName;
			btn_ok = namedXmlID[10].strName;
			btn_restore = namedXmlID[11].strName;
			edit_input1 = namedXmlID[12].strName;
			edit_input2 = namedXmlID[13].strName;
			edit_text = namedXmlID[14].strName;
			tv_test = namedXmlID[15].strName;
			txt_show = namedXmlID[16].strName;
			txt_title = namedXmlID[17].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_add;
		 const wchar_t * btn_cancel;
		 const wchar_t * btn_close;
		 const wchar_t * btn_closewnd;
		 const wchar_t * btn_delete;
		 const wchar_t * btn_find;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_modify;
		 const wchar_t * btn_ok;
		 const wchar_t * btn_restore;
		 const wchar_t * edit_input1;
		 const wchar_t * edit_input2;
		 const wchar_t * edit_text;
		 const wchar_t * tv_test;
		 const wchar_t * txt_show;
		 const wchar_t * txt_title;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_add	=	65540;
		const static int btn_cancel	=	65552;
		const static int btn_close	=	65536;
		const static int btn_closewnd	=	65545;
		const static int btn_delete	=	65541;
		const static int btn_find	=	65543;
		const static int btn_max	=	65537;
		const static int btn_min	=	65539;
		const static int btn_modify	=	65547;
		const static int btn_ok	=	65551;
		const static int btn_restore	=	65538;
		const static int edit_input1	=	65549;
		const static int edit_input2	=	65550;
		const static int edit_text	=	65542;
		const static int tv_test	=	65544;
		const static int txt_show	=	65546;
		const static int txt_title	=	65548;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
