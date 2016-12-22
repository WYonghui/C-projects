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
		printf("-------------选择菜单------------------\n");
		printf("0.初始化栈P             5.出栈\n");
		printf("1.用S初始化栈P          6.赋栈S给栈P\n"); 
		printf("2.栈中最大元素个数      7.打印栈\n");
		printf("3.栈中实际元素个数      8.销毁栈\n");
		printf("4.入栈                  9.退出程序\n");
		printf("---------------------------------------\n");
		printf("请输入数字0 ~ 9进行操作选择：\n");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 0:
				printf("请输入栈的最大元素个数："); 
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
						printf("请输入栈S的第%d个元素：", m+1);
						scanf("%d", &e);
						S.elems[m] = e;
					}
				}
				initSTACK(p, S);
				system("pause");
				system("cls");
				break;
			case 2:
				printf("栈中最大元素个数为%d\n", size(p));
				system("pause");
				system("cls");
				break;
			case 3:
				printf("栈中实际元素个数为%d\n", howMany(p));
				system("pause");
				system("cls");
				break;
			case 4:
				printf("请输入要入栈的元素：");
				scanf("%d", &e);
				push(p, e);
				system("pause");
				system("cls");
				break;
			case 5:
				pop(p, e);
				printf("出栈元素为%d\n", e);
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
						printf("请输入栈S的第%d个元素：", m+1);
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
	printf("栈P初始化成功！\n");
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
	printf("用S初始化栈P成功！\n");
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
	{ //栈未满，可插入 
		p->elems[p->pos++] = e;
	    printf("入栈成功！\n"); 
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
	printf("P指向的栈的栈中元素依次是：\n");
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
	printf("销毁成功！\n");
}

