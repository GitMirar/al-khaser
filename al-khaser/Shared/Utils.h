#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include <IPTypes.h>
#include <Shlwapi.h>
#include <Iphlpapi.h>
#include <Psapi.h>
#include <TlHelp32.h>
#include <Wbemidl.h>

#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "wbemuuid.lib")

#include "Common.h"

BOOL IsWoW64();
BOOL Is_RegKeyValueExists(HKEY hKey, CONST TCHAR* lpSubKey, CONST TCHAR* lpValueName, CONST TCHAR* search_str);
BOOL Is_RegKeyExists(HKEY hKey, CONST TCHAR* lpSubKey);
BOOL is_FileExists(TCHAR* szPath);
BOOL is_DirectoryExists(TCHAR* szPath);
BOOL check_mac_addr(CONST TCHAR* szMac);
BOOL check_adapter_name(CONST TCHAR* szName);
BOOL GetOSDisplayString(LPTSTR pszOS);
DWORD GetProccessIDByName(TCHAR* szProcessNameTarget);
DWORD GetProcessIdFromName(CONST LPCTSTR ProcessName);
BOOL SetPrivilege(HANDLE, LPCTSTR, BOOL);
BOOL SetDebugPrivileges(VOID);
DWORD GetMainThreadId(DWORD pid);
BOOL InitWMI(IWbemServices **pSvc, IWbemLocator **pLoc, CONST TCHAR* szNetworkResource);
BOOL ExecWMIQuery(IWbemServices **pSvc, IWbemLocator **pLoc, IEnumWbemClassObject **pEnumerator, CONST TCHAR* szQuery);
ULONG get_idt_base();
ULONG get_ldt_base();
ULONG get_gdt_base();
UCHAR* get_str_base();
BOOL IsElevated();
BOOL find_str_in_data(PBYTE needle, size_t needleLen, PBYTE haystack, size_t haystackLen);
PBYTE get_system_firmware(_In_ DWORD signature, _In_ DWORD table, _Out_ PDWORD pBufferSize);

#define	MALLOC(x)	HeapAlloc(GetProcessHeap(), 0, x)
#define FREE(x)		HeapFree(GetProcessHeap(), 0, x)

#if _WIN32 || _WIN64
#if _WIN64
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif