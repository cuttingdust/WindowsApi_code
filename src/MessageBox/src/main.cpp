#include <iostream>

#include <windows.h>

int DisplayResourceNAMessageBox()
{
    int msgboxID = MessageBox(NULL, (LPCWSTR)L"Resource not available\nDo you want to try again?",
                              (LPCWSTR)L"Account Details", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

    switch (msgboxID)
    {
        case IDCANCEL:
            // TODO: add code
            break;
        case IDTRYAGAIN:
            // TODO: add code
            break;
        case IDCONTINUE:
            // TODO: add code
            break;
    }

    return msgboxID;
}

int main(int argc, char *argv[])
{
    // int WINAPI MessageBox(HWND    hWnd,      /// ���ھ��
    //                       LPCTSTR lpText,    /// �ַ��� ����
    //                       LPCTSTR lpCaption, /// �ַ��� ����
    //                       UINT    uType      /// ��������
    // );

    MessageBoxA(0, "�ҵ�һ�ε���API", "����123", MB_OK);

    printf("dddd\n");

    MessageBoxA(0, "�ҵ�����adsf132", "��d��", MB_OKCANCEL | MB_ICONINFORMATION); /// ����һ�� ����ȷ����ť�� ����

    /// MB_DEFBUTTON3 ��������ť��Ĭ�ϰ�ť
    MessageBoxA(0, "fdsaf�ҵ�����132xxx", "����ddd", MB_USERICON | MB_ABORTRETRYIGNORE | MB_DEFBUTTON3);

    MessageBoxA(0, "fdsaf�ҵ�����132xxx", "����ddd", MB_ICONERROR | MB_CANCELTRYCONTINUE | MB_DEFBUTTON1);

    DisplayResourceNAMessageBox();

    return 0;
}
