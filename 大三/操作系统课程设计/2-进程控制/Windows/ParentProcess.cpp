#include <windows.h>
#include <iostream>
using namespace std;

void printTime(SYSTEMTIME time)
{
    cout << time.wYear << "年" << time.wMonth << "月" << time.wDay << "日" << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds <<"毫秒"<< endl;
}
void TimeCost(SYSTEMTIME Tbegin, SYSTEMTIME Tend)
{
    int day = Tend.wDay - Tbegin.wDay;
    int hour = Tend.wHour - Tbegin.wHour;
    int minute = Tend.wMinute - Tbegin.wMinute;
    int seconds = Tend.wSecond - Tbegin.wSecond;
    int milliseconds = Tend.wMilliseconds - Tbegin.wMilliseconds;
    if (milliseconds < 0) { seconds--; milliseconds += 1000; }
    if (seconds < 0) { minute--; seconds += 60; }
    if (minute < 0) { hour--; minute += 60; }
    if (hour < 0) { day--; hour += 24; }
    cout << "子进程耗时" << day << "日" << hour << "时" << minute << "分" << seconds << "秒" << milliseconds << "毫秒" << endl;
}
int main(int argc, char* argv[])
{
    STARTUPINFO si;   //存储新进程启动信息的指针
    PROCESS_INFORMATION pi;  //存储新进程信息（句柄）
    SYSTEMTIME childpStart, childpEnd;
    memset(&si, 0, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    memset(&pi, 0, sizeof(PROCESS_INFORMATION));

    //创建进程
    if (CreateProcess(NULL, argv[1], NULL, NULL, false, false, NULL, NULL, &si, &pi)){
        GetSystemTime(&childpStart);
        cout << "Successfully created child process in ";
        printTime(childpStart);
    }
    else {
        cout << "Failed to create child process" << endl;
        exit(1);
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    GetSystemTime(&childpEnd);
    cout << "Successfully closed child process in ";
    printTime(childpEnd);
    TimeCost(childpStart, childpEnd);
    return 0;
}
