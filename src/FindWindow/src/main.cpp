#include <iostream>

#include <windows.h>

int  monitorCount      = 0;     /// ���ڼ�¼��ʾ������
RECT secondMonitorRect = { 0 }; /// �洢�ڶ�����ʾ����λ����Ϣ

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{
    monitorCount++; /// ������ʾ������
    if (monitorCount == 2)
    {                                     /// ֻ�洢�ڶ�����ʾ������Ϣ
        secondMonitorRect = *lprcMonitor; /// ���Ƶڶ�����ʾ���ľ�����Ϣ
    }
    return TRUE; /// ����ö����һ����ʾ��
}

int main(int argc, char *argv[])
{
    // HWND ���ھ�� = FindWindowA(NULL, "Everything"); /// (HWND)000000000AC11234
    HWND ���ھ�� = FindWindowA("EVERYTHING", NULL);
    printf("���ھ��=%p\r\n", ���ھ��);

    // LPSTR ���� = (LPSTR)malloc(256);
    // GetClassNameA(���ھ��, ����, 256);
    // printf("����=%s\r\n", ����);

    // SetWindowTextA(���ھ��, "������");
    // SetWindowTextA(���ھ��, "������123...");
    SetWindowTextA(���ھ��, "�ļ�����������");
    printf("sizeof(���ھ��)=%zd�ֽ�\r\n", sizeof(���ھ��)); //eax,rax


    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);

    /// ����еڶ�����ʾ��
    if (monitorCount > 1)
    {
        /// �ƶ����ڵ��ڶ�����ʾ�������Ͻ�
        SetWindowPos(���ھ��, NULL, secondMonitorRect.left, secondMonitorRect.top, 0, 0,
                     SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        std::cout << "�������ƶ���������" << std::endl;
    }
    else
    {
        std::cout << "δ�ҵ�������" << std::endl;
    }


    // /// �����µ�λ�úʹ�С
    // int x      = 500; /// �µ� x ����
    // int y      = 100; /// �µ� y ����
    int width  = 800; /// �µĿ��
    int height = 600; /// �µĸ߶�

    /// �ƶ�����
    {
        /// �ƶ�λ��
        // SetWindowPos(���ھ��, NULL, secondMonitorRect.left + x, secondMonitorRect.top + y, width, height,
        //              SWP_NOZORDER | SWP_NOACTIVATE);
    }

    {
        /// ��ȡ���ڵĿ�Ⱥ͸߶�
        RECT windowRect;
        GetWindowRect(���ھ��, &windowRect);
        int windowWidth  = windowRect.right - windowRect.left; /// ���ڿ��
        int windowHeight = windowRect.bottom - windowRect.top; /// ���ڸ߶�

        /// ���㴰�ڵ���λ�ã�ʹ���ڸ����Ͼ���
        int newX = secondMonitorRect.left + (secondMonitorRect.right - secondMonitorRect.left - windowWidth) / 2;
        int newY = secondMonitorRect.top + (secondMonitorRect.bottom - secondMonitorRect.top - windowHeight) / 2;

        // SetWindowPos(���ھ��, NULL, newX, newY, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }

    {
        /// ��󻯴���
        ShowWindow(���ھ��, SW_SHOWMAXIMIZED);

        /// ��ѡ�����ô���Ϊǰ̨����
        SetForegroundWindow(���ھ��);
    }

    getchar();

    return 0;
}
