#include <iostream>

#include <windows.h>

int main(int argc, char *argv[])
{
    // HWND h = FindWindowA("EVERYTHING", "Everything");
    HWND h = FindWindowA(NULL, "������");
    printf("���ھ�� h=%p\r\n", h);

    DWORD pid, tid;
    printf("&pid=%p\r\n", &pid);
    /// int ��long�ǵȼ�
    /// DWORD  �ȼ��� unsigned long
    /// DWORD* �ȼ��� LPDWORD
    tid = GetWindowThreadProcessId(h, &pid); /// a&b
    printf("tid=%d pid=%d  16����tid=%X 16����pid=%X\r\n", tid, pid, tid, pid);

    return 0;
}
