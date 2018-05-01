#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>


VOID print_detected() ;
VOID print_not_detected() ;
VOID print_category(CONST TCHAR* text);
VOID print_last_error(CONST TCHAR* lpszFunction);
VOID exec_check(int(*callback)(), CONST TCHAR* text_log);
VOID print_os();
TCHAR* ascii_to_wide_str(CHAR* lpMultiByteStr);
CHAR* wide_str_to_multibyte(TCHAR* lpWideStr);
VOID resize_console_window();
VOID print_results(int result, CONST TCHAR* szMsg);





