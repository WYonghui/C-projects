#include <stdio.h>
#include <stdlib.h>
#include<windows.h> 

class STACK{
    int  *const  elems;	//�����ڴ����ڴ��ջ��Ԫ��
    const  int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
STACK(int m);		//��ʼ��ջ�����m��Ԫ��
STACK(const STACK&s); //��ջs������ʼ��ջ
int  size ( ) const;		//����ջ�����Ԫ�ظ���max
int  howMany ( ) const;	//����ջ��ʵ��Ԫ�ظ���pos
STACK& push(int e); 	//��e��ջ,������ջ
STACK& pop(int &e); 	//��ջ��e,������ջ
STACK& assign(const STACK&s); //��s��ջ,�����ر���ֵ��ջ
void print( ) const;		//��ӡջ
~STACK( );				//����ջ
};

