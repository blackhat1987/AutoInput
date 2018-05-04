#include<Windows.h>
#include<iostream>

void main() {
	LPCSTR classname = "WTWindow";
	//char windowname[] = "汇编代码转换器 Ver4.0  By:美夜赤月";
	HWND wnd;

	wnd = FindWindow(NULL, TEXT("汇编代码转换器 Ver4.0  By:美夜赤月"));
	if (wnd == NULL) {
		std::cout << "程序未打开" << std::endl;
		exit(0);
	}
	//SendMessage(wnd, WM_CLOSE, 0, 0);//发送关闭命令
	HWND wnd_input_1;
	//DWORD test = 0x0051027A;
	wnd_input_1 = FindWindowEx(wnd, NULL, TEXT("Afx:400000:b:10003:1900010:0"), NULL);
	HWND wnd_input_2;
	wnd_input_2 = FindWindowEx(wnd_input_1, NULL, TEXT("Scintilla"), NULL);
	//wnd_text=GetDlgItem(wnd, 0xA0);
	
	SendMessage(wnd_input_2, WM_SETTEXT, 0, (LPARAM)TEXT("call MessageBoxA"));//发送数据给输入框
	//SendMessage(wnd_input_2, WM_SETTEXT, 0, (LPARAM)TEXT("call MessageBoxA"));//发送数据给输入框
	HWND buttonc;
	buttonc = GetDlgItem(wnd,0xBE);
	SendMessage(buttonc, BM_CLICK, 0, 0);
	HWND out_1, out_2;
	out_1 = GetDlgItem(wnd,0x96);
	out_2 = GetDlgItem(out_1, 0xA0);
	DWORD err = GetLastError();
	TCHAR out[1000] = {};

	//GetWindowText(out_2, out, 1000);
	SendMessage(out_2, WM_GETTEXT, 1000, (LPARAM)out);
	std::wcout << out << std::endl;
	

}