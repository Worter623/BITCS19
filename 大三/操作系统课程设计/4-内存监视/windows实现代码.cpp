#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <Psapi.h>
#include <conio.h>
#include <TlHelp32.h> //使用PROCESSENTRY32结构体
#include <tchar.h>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")
using namespace std;

void ShowHelp() {
	system("cls");
	cout << "这是一个内存监视程序" << endl;
	cout << "输入‘space_plot’获取系统地址空间布局" << endl;
	cout << "输入‘memory_used’获取物理内存使用情况" << endl;
	cout << "输入‘process_state’打开我的实验二可执行文件并查看它的实时虚拟地址空间布局和工作集信息" << endl;
	//待完善 可以输入任意可执行文件 此处为完成作业要求先使用CreateProcess打开子进程了
	cout << "输入‘ctrl+C’或者‘quit’可终止该程序" << endl;
	cout << "按任意键以返回主菜单" << endl;
	while (!_kbhit());
	return;
}
void ShowSpacePlot() {
	while (!_kbhit())
	{
		system("cls");
		SYSTEM_INFO system_info;
		PERFORMACE_INFORMATION performance_information;
		performance_information.cb = sizeof(performance_information);
		GetPerformanceInfo(&performance_information, performance_information.cb);
		GetSystemInfo(&system_info);
		cout << "----------地址空间布局----------" << endl;
		cout << "内存总量为" << performance_information.KernelTotal << endl;
		cout << "内存页的大小为：" << performance_information.PageSize / 1024 << "KB" << endl;
		cout << "分页池当前大小为：" << performance_information.KernelPaged << endl;
		cout << "非分页池当前大小为：" << performance_information.KernelNonpaged << endl;
		cout << "每个进程可用地址空间的最小内存地址为：   0x" << system_info.lpMinimumApplicationAddress << endl;
		cout << "每个进程可用地址空间的最大内存地址为：   0x" << system_info.lpMaximumApplicationAddress << endl;
		cout << "系统配备的CPU的数量为：" << system_info.dwNumberOfProcessors << endl;
		cout << "能够保留地址空间区域的最小单位为：" << system_info.dwAllocationGranularity / 1024 << "KB" << endl;
		cout << "----------按任意键以返回主菜单----------" << endl;
		Sleep(1000);
	}
}
void ShowMemoryUsed() {
	while (!_kbhit())
	{
		system("cls");
		MEMORYSTATUSEX memory_status;
		PERFORMACE_INFORMATION performance_information;
		memory_status.dwLength = sizeof(memory_status);
		performance_information.cb = sizeof(performance_information);
		GetPerformanceInfo(&performance_information, performance_information.cb);
		GlobalMemoryStatusEx(&memory_status);
		cout << "----------物理内存使用情况----------" << endl;
		cout << "内存的总容量为：" << (float)memory_status.ullTotalPhys / 1024 / 1024 / 1024 << "GB" << endl;
		cout << "当前可用的物理内存为：" << performance_information.PhysicalAvailable << endl;
		cout << "内存的使用率为：" << memory_status.dwMemoryLoad << "%" << endl;
		cout << "系统缓存的容量为：" << performance_information.SystemCache << endl;
		cout << "页文件的总容量为：" << (float)memory_status.ullTotalPageFile / 1024 / 1024 / 1024 << "GB" << endl;
		cout << "系统当前提交页面总数为：" << performance_information.CommitTotal << endl;
		cout << "可用的页文件为：" << (float)memory_status.ullAvailPageFile / 1024 / 1024 / 1024 << "GB" << endl;
		cout << "虚拟内存的总容量为：" << (float)memory_status.ullTotalVirtual / 1024 / 1024 / 1024 << "GB" << endl;
		cout << "可用的虚拟内存为：" << (float)memory_status.ullAvailVirtual / 1024 / 1024 / 1024 << "GB" << endl;
		cout << "可用的扩展虚拟内存为：" << (float)memory_status.ullAvailExtendedVirtual / 1024 << "KB" << endl;
		cout << "当前打开的句柄个数为：" << performance_information.HandleCount << endl;
		cout << "当前进程个数为：" << performance_information.ProcessCount << endl;
		cout << "当前线程个数为：" << performance_information.ThreadCount << endl;
		cout << "----------按任意键以返回主菜单----------" << endl;
		Sleep(1000);
	}
}
HANDLE FilenameToHandle(WCHAR filename[]){
	PROCESSENTRY32 process_entry;
	process_entry.dwSize = sizeof(process_entry);
	HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	bool ok = Process32First(hProcess, &process_entry);
	bool flag = false;
	if (!ok) {
		cout << "process32first failed" << endl;
		return NULL;
	}
	while (ok)
	{
		if (wcscmp(process_entry.szExeFile, filename) == 0) {
			flag = true;
			break;
		}
		ok = Process32Next(hProcess, &process_entry);
	}//拿到了filename的进程句柄
	CloseHandle(hProcess);
	if (flag)
		return (OpenProcess(PROCESS_ALL_ACCESS, false, process_entry.th32ProcessID));
	else
		return NULL;
}
void ShowProcessState() {
	while (!_kbhit())
	{
		system("cls");
		cout << "----------查看ParentProcess的虚拟空间布局和工作集信息----------" << endl;
		WCHAR filename[20] = { '\0' };
		wcscpy_s(filename, L"ParentProcess.exe");
		HANDLE hProcess = FilenameToHandle(filename);
		if (hProcess == NULL) {
			cout << "进程已结束" << endl;
			continue;
		}
		MEMORY_BASIC_INFORMATION memory_basic_information;
		memset(&memory_basic_information, 0, sizeof(MEMORY_BASIC_INFORMATION));
		PROCESS_MEMORY_COUNTERS process_memory_counters;
		SYSTEM_INFO system_info;
		GetSystemInfo(&system_info);
		GetProcessMemoryInfo(hProcess, &process_memory_counters, sizeof(process_memory_counters));
		LPCVOID block_counter = system_info.lpMinimumApplicationAddress;
		cout << "工作集信息：" << (float)process_memory_counters.WorkingSetSize / 1024 << "KB" << endl;
		for (; block_counter < system_info.lpMaximumApplicationAddress;)
		{
			if (VirtualQueryEx(hProcess, block_counter, &memory_basic_information, sizeof(memory_basic_information)) == sizeof(memory_basic_information)) 
			{//长度的确认
				 //confirmed,查询地址空间中内存地址的信息  //计算块的结尾及其长度
				LPCVOID page_end = (PBYTE)block_counter + memory_basic_information.RegionSize;//页基地址+虚存区大小
				TCHAR size[MAX_PATH];
				StrFormatByteSize(memory_basic_information.RegionSize, size, MAX_PATH);//格式化文件的大小
				cout << "块地址：   " << (DWORD)block_counter << "--" << (DWORD)page_end << "(" << size << ")     ";
				if(memory_basic_information.State==MEM_COMMIT)
					cout << "被提交";
				else if (memory_basic_information.State == MEM_FREE)
					cout << "空闲的";
				else if (memory_basic_information.State == MEM_RESERVE)
					cout << "被保留";
				if (memory_basic_information.Type == MEM_IMAGE)
					cout << ",Image";
				else if (memory_basic_information.Type == MEM_PRIVATE)
					cout << ",Private";
				else if (memory_basic_information.Type == MEM_MAPPED)
					cout << ",Mapped";
				cout << endl;
				block_counter = page_end; //移动指针以获得下一个块
			}
		}
		Sleep(3000);
	}
}
int main()
{
	while (1)
	{
		system("cls");
		cout << "-----内存监视程序-----" << endl;
		cout << "输入‘help’可获取帮助" << endl;
		string input;
		cin >> input;
		if (input == "help")
			ShowHelp();
		else if (input == "space_plot")
			ShowSpacePlot();
		else if (input == "memory_used")
			ShowMemoryUsed();
		else if (input == "process_state")
			ShowProcessState();
		else if (input == "quit")
			break;
	}
	return 0;
}