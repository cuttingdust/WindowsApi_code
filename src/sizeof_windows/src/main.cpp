#include <iostream>

#include <limits.h>


/// ʶ����ֵ����char   1���ֽ� 8��������λ -128,127
/// ʶ����ֵ����short
/// ʶ����ֵ����int
/// ʶ�� sizeof �����
/// �˽���ֵ����char*��LPCTSTR
/// �˽��޷�������unsigned
/// �˽��Զ��庯�� int myaddt(int a,int b)
/// %d //��ʾ��ʽ������������       //<4�ֽ�
/// %u //��ʾ��ʽ���޷������� >=0   //<4�ֽ�
/// %zd //��ʽ��   >=0 size_t
/// %llu //��ʽ����ʾ 8�ֽ� �޷�������
/// sizeof����� ����ֵ��size_t ռ�ÿռ�8�ֽ� %llu %zd


int main(int argc, char *argv[])
{
    char ������;  /// _abc123,abc,����
    char a, b, c; /// size_t
    /// char��ʾ��Χ -128,0,127 //256
    /// unsigned char 0..255    //256
    a = -123;
    b = 126;
    c = 33336;
    printf("char��ռ�ڴ�ռ��С =%llu BYTE %zd �ֽ�,%zd �ֽ�,%zd �ֽ�\n", sizeof(������), sizeof(a), sizeof(b),
           sizeof(c));
    printf("a=%d,b=%d,c=%d \r\n", a, b, c);
    ///    //short(2�ֽ�) 0..65535 int 0..0..65535*65535
    short i = 0, j = 0, k = 0;
    i = 33336;
    k = -33336;
    printf("j=%d,k=%d \r\n", i, k);
    /// int(4�ֽ�)
    int a2, a3;
    a2 = 33336;
    a3 = -33336;
    printf("a2=%d,a3=%d \r\n", a2, a3);
    
    /// char short int�ı�ʾ��Χ
    printf("char���ͱ�ʾ��Χ %d��%d\r\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char���ͱ�ʾ��Χ %u��%u\r\n", 0, UCHAR_MAX);
    /// short
    printf("short���ͱ�ʾ��Χ %d��%d\r\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short���ͱ�ʾ��Χ %u��%u\r\n", 0, USHRT_MAX);
    /// int  -21�� +21��
    printf("int���ͱ�ʾ��Χ %d��%d\r\n", INT_MIN, INT_MAX);
    printf("unsigned int���ͱ�ʾ��Χ %u��%u\r\n", 0, UINT_MAX);

    ///  ��ͣ�ȴ���������
    getchar();
    return 1;
}
