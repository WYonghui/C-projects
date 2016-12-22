#include"stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	STACK *p, P, S;
	p = &P;
	int ch = 0;
	int m, e;
	S.elems = 0;
	while(1)
	{
		printf("-------------ѡ��˵�------------------\n");
		printf("0.��ʼ��ջP             5.��ջ\n");
		printf("1.��S��ʼ��ջP          6.��ջS��ջP\n"); 
		printf("2.ջ�����Ԫ�ظ���      7.��ӡջ\n");
		printf("3.ջ��ʵ��Ԫ�ظ���      8.����ջ\n");
		printf("4.��ջ                  9.�˳�����\n");
		printf("---------------------------------------\n");
		printf("����������0 ~ 9���в���ѡ��\n");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 0:
				printf("������ջ�����Ԫ�ظ�����"); 
				scanf("%d", &m);
				initSTACK(p, m);
				system("pause");
				system("cls");
				break;
			case 1:
				if(!S.elems)
				{
					S.max = 10;
					S.pos = 4;
					S.elems = (int *)malloc(S.max*sizeof(int));
					for(m=0;m<S.pos;m++)
					{
						printf("������ջS�ĵ�%d��Ԫ�أ�", m+1);
						scanf("%d", &e);
						S.elems[m] = e;
					}
				}
				initSTACK(p, S);
				system("pause");
				system("cls");
				break;
			case 2:
				printf("ջ�����Ԫ�ظ���Ϊ%d\n", size(p));
				system("pause");
				system("cls");
				break;
			case 3:
				printf("ջ��ʵ��Ԫ�ظ���Ϊ%d\n", howMany(p));
				system("pause");
				system("cls");
				break;
			case 4:
				printf("������Ҫ��ջ��Ԫ�أ�");
				scanf("%d", &e);
				push(p, e);
				system("pause");
				system("cls");
				break;
			case 5:
				pop(p, e);
				printf("��ջԪ��Ϊ%d\n", e);
				system("pause");
				system("cls");
				break;
			case 6:
				if(!S.elems)
				{
					S.max = 10;
					S.pos = 4;
					S.elems = (int *)malloc(S.max*sizeof(int));
					for(m=0;m<S.pos;m++)
					{
						printf("������ջS�ĵ�%d��Ԫ�أ�", m+1);
						scanf("%d", &e);
						S.elems[m] = e;
					}
				}
				assign(p, S);
				system("pause");
				system("cls");
				break;
			case 7:
				print(p);
				system("pause");
				system("cls");
				break;
			case 8:
				destroySTACK(p);
				system("pause");
				system("cls");
				break;
			case 9:
				free(S.elems);
				return 0;
		}
	}
}

void initSTACK(STACK *const p, int m)
{
	p->elems = (int *)malloc(m*sizeof(int));
	p->max = m;
	p->pos = 0;
	printf("ջP��ʼ���ɹ���\n");
}

void initSTACK(STACK *const p, const STACK &s)
{
	int i = 0;
	p->elems = (int *)malloc((s.max)*sizeof(int));
	for(i=0; i<s.pos; i++)
	{
		p->elems[i] = s.elems[i];
	}
	p->max = s.max;
	p->pos = s.pos;
	printf("��S��ʼ��ջP�ɹ���\n");
}

int  size(const STACK *const p)
{
	return p->max;
}

int  howMany(const STACK *const p)
{
	return p->pos;
}

STACK *const push(STACK *const p, int e)
{
	if(p->pos < p->max)
	{ //ջδ�����ɲ��� 
		p->elems[p->pos++] = e;
	    printf("��ջ�ɹ���\n"); 
	}
	return p;
}

STACK *const pop(STACK *const p, int &e)
{
	if(p->pos)
	{
		e = p->elems[(--p->pos)];
	}
	return p;
}

STACK *const assign(STACK*const p, const STACK&s)
{
	int i;
	free(p->elems);
	p->elems = (int *)malloc((s.max)*sizeof(int));
	for(i=0; i<s.pos; i++)
	{
		p->elems[i] = s.elems[i];
	}
	p->max = s.max;
	p->pos = s.pos;
}

void print(const STACK*const p)
{
	int i;
	printf("Pָ���ջ��ջ��Ԫ�������ǣ�\n");
	for(i=0; i<p->pos; i++)
	{
		printf("%d",p->elems[i]);
		if(i!=(p->pos-1)) printf(" ");
		else printf("\n");
	}
}

void destroySTACK(STACK*const p)
{
	if(p->elems)
	{		
		free(p->elems);
		p->elems = 0;
		p->max = 0;
		p->pos = 0;
	}
	printf("���ٳɹ���\n");
}

