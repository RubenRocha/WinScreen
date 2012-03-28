#define _WIN32_WINNT  0x0501
#define WINVER 0x0501

#include<windows.h>
#include<iostream>

#include <stdio.h>

HANDLE  hConsole;
int normal = 7;
int white = 15;
int green = 10;
int red = 12;
int yellow = 14;
int blue = 9;
int lblue = 11;

void writeColor(int color, char* options, char* text= (char*) NULL)
{
    SetConsoleTextAttribute(hConsole, color);
    printf(options, text);
    SetConsoleTextAttribute(hConsole, normal);
}

char* convertBytes(float size)
{
    char buf[255];
    int i = 0;
    const char* units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    sprintf(buf, "%.*f %s", i, size, units[i]);
    return buf;
}

char* PrintSystemName()
{
    char compName[255];
    DWORD size = 40;

    if(GetComputerName(compName,&size)!=0)
        return compName;
}

char* PrintUserName()
{
    char uName[255];
    DWORD size = 40;

    if(GetUserName(uName,&size) != 0)
        return uName;
}

void PrintSystemUpTime()
{
    unsigned int t,d,h,m,s;

    // Retrieves the number of milliseconds that have elapsed since
    t = GetTickCount();

    // Get the seconds
    t/=1000;
    //days
    d = t/86400;
    t = t%86400;
    // hours
    h = t/3600;
    t = t%3600;
    // minutes
    m = t/60;
    t = t%60;
    // seconds
    s = t;

    printf("System Up Time(D:H:M:S): ");
    writeColor(white, "%u:", (char*) d);
    writeColor(white, "%u:", (char*) h);
    writeColor(white, "%u:", (char*) m);
    writeColor(white, "%u", (char*) s);
}
void PrintMonitorResolution()
{
    int width,height;

    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);
    printf("Monitor Resolution:");
    writeColor(white, "%dx",(char*) width);
    writeColor(white, "%d",(char*) height);
    SetConsoleTextAttribute(hConsole, normal);
}

void PrintOSInfo()
{
    OSVERSIONINFO verInfo = {sizeof(OSVERSIONINFO)};
    printf("OS: ");
    GetVersionEx(&verInfo);
    if(verInfo.dwMajorVersion == 4 && verInfo.dwMinorVersion == 10)
        writeColor(white, " Windows 98 %s",verInfo.szCSDVersion);
    if(verInfo.dwMajorVersion == 5 && verInfo.dwMinorVersion == 0)
        writeColor(white, " Windows 2000 %s",verInfo.szCSDVersion);
    if(verInfo.dwMajorVersion == 5 && verInfo.dwMinorVersion == 1)
        writeColor(white, " Windows XP %s",verInfo.szCSDVersion);
    if(verInfo.dwMajorVersion == 5 && verInfo.dwMinorVersion == 2)
        writeColor(white, " Windows Server 2003 %s",verInfo.szCSDVersion);
    if(verInfo.dwMajorVersion == 6 && verInfo.dwMinorVersion == 0)
        writeColor(white, " Windows Vista %s",verInfo.szCSDVersion);
    if(verInfo.dwMajorVersion == 6 && verInfo.dwMinorVersion == 1)
        writeColor(white, " Windows 7 %s",verInfo.szCSDVersion);
    if(verInfo.dwMajorVersion == 6 && verInfo.dwMinorVersion == 2)
        writeColor(white, " Windows 8 %s", verInfo.szCSDVersion);
}

void PrintKernelInfo()
{
    OSVERSIONINFO verInfo = {sizeof(OSVERSIONINFO)};
    printf("Kernel Version: ");
    GetVersionEx(&verInfo);
    writeColor(white, "%d.", (char*) verInfo.dwMajorVersion);
    writeColor(white, "%d", (char*) verInfo.dwMinorVersion);
}

void PrintMemoryInfo()
{
    MEMORYSTATUSEX ms;
    ms.dwLength = sizeof (ms);
    GlobalMemoryStatusEx(&ms);
    printf("Memory Info: ");
    SetConsoleTextAttribute(hConsole, white);
    double totalMem = (ms.ullTotalPhys);
    double availMem = (ms.ullAvailPhys);
    double freeMem = (totalMem - availMem);
    double usedMem = (totalMem - availMem);
    int col1;
    if(availMem > 0) {
        col1 = green;
    }
    if(usedMem >= totalMem * 0.5) {
        col1 = yellow;
    }
    if(usedMem >= totalMem * 0.75) {
        col1 = red;
    }
    printf("%s", convertBytes(usedMem));
    printf("/");
    writeColor(white, "%s", convertBytes(totalMem));
    printf(" (");
    double usedmemd = (freeMem / totalMem) * 100;
    char usedm[50];
    sprintf(usedm, "%0.2f", usedmemd);
    writeColor(col1, "%s%%", usedm);
    writeColor(white, " used)");

    SetConsoleTextAttribute(hConsole, normal);
}

void PrintProcessorInfo()
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo( &sysinfo );
    int nCores = sysinfo.dwNumberOfProcessors;
    char* pName;
    HKEY hKey = 0;
    char buf[255] = {0};
    DWORD dwType = 0;
    DWORD dwBufSize = sizeof(buf);
    const char* subkey = "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
    if( RegOpenKey(HKEY_LOCAL_MACHINE,subkey,&hKey) == ERROR_SUCCESS)
    {
        dwType = REG_SZ;
        if( RegQueryValueEx(hKey,"ProcessorNameString",0, &dwType, (BYTE*)buf, &dwBufSize) == ERROR_SUCCESS)
        {
            pName = buf;
        } else {
            pName = "Unknown Processor";
        }
        RegCloseKey(hKey);
    } else {
        pName = "Unknown Processor";
    }

    printf("Processor:");
    writeColor(white, "%s ", pName);
    writeColor(white, "(%d Cores)", (char*) nCores);
}


void PrintVideoInfo()
{
    char* aName;
    HKEY hKey = 0;
    char buf[255] = {0};
    DWORD dwType = 0;
    DWORD dwBufSize = sizeof(buf);
    const char* subkey = "SYSTEM\\ControlSet001\\Control\\Class\\{4D36E968-E325-11CE-BFC1-08002BE10318}\\0000\\Settings";
    if( RegOpenKey(HKEY_LOCAL_MACHINE,subkey,&hKey) == ERROR_SUCCESS)
    {
        dwType = REG_SZ;
        if( RegQueryValueEx(hKey,"Device Description",0, &dwType, (BYTE*)buf, &dwBufSize) == ERROR_SUCCESS)
        {
            aName = buf;
        } else {
            aName = "Unknown Adapter";
        }
        RegCloseKey(hKey);
    } else {
        aName = "Unknown Adapter";
    }
    printf("Video adapter: ");
    writeColor(white, "%s", aName);
}

void getDriveInfo()
{
#define wszDrive L"\\\\.\\PhysicalDrive0"
    BOOL  fResult;
    int col1;
    __int64 fbtc, tb, fb;

    fResult = GetDiskFreeSpaceEx((LPCSTR) wszDrive, (PULARGE_INTEGER)&fbtc,
                                 (PULARGE_INTEGER)&tb, (PULARGE_INTEGER)&fb);

    if (fResult)
    {
        float freeBytes =  fb;
        float totalBytes =  tb;
        printf("Primary disk: ");
        writeColor(white, "%s/", convertBytes(freeBytes));
        writeColor(white, "%s", convertBytes(totalBytes));
        writeColor(white, "(");
        float usedPer = 100 * (1 - (freeBytes / totalBytes));
        char usedPerc[10];
        sprintf(usedPerc,"%0.2f",usedPer);

        if(usedPer > 0) {
            col1 = green;
        }
        if(usedPer >= 50) {
            col1 = yellow;
        }
        if(usedPer >= 75) {
            col1 = red;
        }

        writeColor(col1, "%s%% ", usedPerc);
        writeColor(white, "used)");
    }
}