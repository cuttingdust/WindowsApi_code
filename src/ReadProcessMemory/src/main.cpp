#include <iostream>

#include <windows.h>

/// ����� ��ȡĿ���ַ  ���� ÿ�ζ�ȡ4�ֽ�

unsigned int ��4�ֽ�(UINT_PTR �ڴ��ַ)
{
    // HWND h = FindWindowA("EVERYTHING", "Everything");
    // HWND h = FindWindowA(NULL, "������");
    HWND h = FindWindowA("MainWindow", "ֲ���ս��ʬ���İ�");
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
    ReadProcessMemory(���̾��, (LPCVOID)�ڴ��ַ /*Ҫ��ȡ�ĵ�ַ*/, &����ֵ /*������ݵĵ�ַ*/, 4, 0);
    printf("����ֵ=%X  ����ֵ=%d ����ֵ=%u �к�=%d\r\n", ����ֵ, ����ֵ, ����ֵ, __LINE__); ///  GetLastError();
    return ����ֵ;
}

void д4�ֽ�(UINT_PTR �ڴ��ַ)
{
    // HWND h = FindWindowA("EVERYTHING", "Everything");
    // HWND h = FindWindowA(NULL, "������");
    HWND h = FindWindowA("MainWindow", "ֲ���ս��ʬ���İ�");
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

    /// Ҫд�����ֵ
    unsigned int ��ֵ = 1000; /// �滻Ϊ��Ҫд���ֵ
    if (!WriteProcessMemory(���̾��, (LPVOID)�ڴ��ַ, &��ֵ, sizeof(��ֵ), nullptr))
    {
        printf("д���ڴ�ʧ�ܣ��������=%lu, �к�=%d\r\n", GetLastError(), __LINE__);
    }
    else
    {
        printf("�ɹ�д����ֵ=%X  ��ֵ=%d  ��ֵ=%u, �к�=%d\r\n", ��ֵ, ��ֵ, ��ֵ, __LINE__);
    }
}

unsigned int R4_bak(UINT_PTR �ڴ��ַ)
{
    //1 ͨ�����ڱ���������� ��ȡĿ�괰�ھ��
    //2 ͨ�����ھ����ȡ���̵�PID,TID
    HWND ���ھ�� = FindWindowA("MainWindow", "ֲ���ս��ʬ���İ�");
    printf("���ھ�� h=%p  �к�=%d\r\n", ���ھ��, __LINE__);
    DWORD pid = 0, tid = 0;
    printf("&pid=%p\r\n", &pid);
    // int ��long�ǵȼ�
    //DWORD  �ȼ��� unsigned long
    //DWORD* �ȼ��� LPDWORD
    tid = GetWindowThreadProcessId(���ھ��, &pid); // a&b
    printf("tid=%d pid=%d  16����tid=%X 16����pid=%X\r\n", tid, pid, tid, pid);
    //��ȡ ���� Ȩ�� ���
    HANDLE ���̾�� = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); //HWND

    unsigned int ����ֵ = 0;
    ReadProcessMemory(���̾��, (LPCVOID)�ڴ��ַ /*Ҫ��ȡ�ĵ�ַ*/, &����ֵ /*������ݵĵ�ַ*/, 4, 0);
    printf("����ֵ=%X  ����ֵ=%d ����ֵ=%u  �к�=%d\r\n", ����ֵ, ����ֵ, ����ֵ, __LINE__); // GetLastError();
    return ����ֵ;
}

//unsigned
int R4(UINT_PTR �ڴ��ַ)
{
    unsigned int ����ֵ = 0;
    if (HWND ���ھ�� = FindWindowA("MainWindow", "ֲ���ս��ʬ���İ�"))
    {
        DWORD pid = 0, tid = 0;
        tid = GetWindowThreadProcessId(���ھ��, &pid);
        if (tid > 0)
        {
            if (HANDLE ���̾�� = OpenProcess(PROCESS_ALL_ACCESS, 0, pid))
            {
                ReadProcessMemory(���̾��, reinterpret_cast<LPCVOID>(�ڴ��ַ /*Ҫ��ȡ�ĵ�ַ*/) /*Ҫ��ȡ�ĵ�ַ*/,
                                  &����ֵ /*������ݵĵ�ַ*/, 4, 0);
            }
        }
    }

    return ����ֵ;
}

int main(int argc, char *argv[])
{
    /// [[PlantsVsZombies.exe+2A9EC0]+768]+5560
    /// [[[6A9EC0]+768]+5560]
    // PlantsVsZombie.exe + 2A9EC0

    int ����ֵ = R4(R4(R4(0x6A9EC0) + 0x768) + 0x5560);
    printf("����ֵ=%d �к�=%d\r\n", ����ֵ, __LINE__);

    // [[[6A9EC0]+768]+5560]+111]+222]+333]+AAA]+BBB
    // int ����ֵ=R4(R4(R4(R4(R4(R4(R4(R4(0x6A9EC0) + 0x768) + 0x5560)+111)+222)+333)+AAA)+BBB);

    getchar();
    return 0;
}
