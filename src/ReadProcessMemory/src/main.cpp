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

    /// ��ȡ ���� Ȩ�� ���
    HANDLE ���̾�� = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); /// HWND
    printf("���̾��=%p \r\n", ���̾��);
    unsigned int ����ֵ = 0;
    ReadProcessMemory(���̾��, (LPCVOID)0x1841D2BA400 /*Ҫ��ȡ�ĵ�ַ*/, &����ֵ /*������ݵĵ�ַ*/, 4, 0);
    printf("����ֵ=%X  ����ֵ=%d ����ֵ=%u\r\n", ����ֵ, ����ֵ, ����ֵ); ///  GetLastError();

    /// Ҫд�����ֵ
    unsigned int ��ֵ = 42; /// �滻Ϊ��Ҫд���ֵ
    if (!WriteProcessMemory(���̾��, (LPVOID)0x1841D2BA400, &��ֵ, sizeof(��ֵ), nullptr))
    {
        printf("д���ڴ�ʧ�ܣ��������=%lu\r\n", GetLastError());
    }
    else
    {
        printf("�ɹ�д����ֵ=%X  ��ֵ=%d  ��ֵ=%u\r\n", ��ֵ, ��ֵ, ��ֵ);
    }

    return 0;
}
