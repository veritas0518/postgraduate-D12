#include<stdio.h>
#include<malloc.h>
typedef struct linknode {
	char data;
	struct linknode* next;
}Linknode;
Linknode* head;
int n;  //线性表长度
void CreateLink() {
	n = 0;
	Linknode* p, * s;
	char x;
	int z = 1;
	head = (Linknode*)malloc(sizeof(Linknode));//
	p = head;
	printf("\n\t\t请输入结点，以“x”为结束标记！\n");
	printf("\n");
	while (z) {
		printf("\t\t请输入一个字符，并按回车：");
		scanf_s("%c", &x);
		getchar();
		if (x != 'x') {
			s = (Linknode*)malloc(sizeof(Linknode));
			n++;
			s->data = x;
			p->next = s;
			s->next = NULL;
			p = s;
		}
		else z = 0;
	}
}

void InsertList(int i, char x) {
	Linknode* p, * s;
	p = head;
	int j = 0;
	while (p != NULL && j < i) {
		j++;   //j 一个一个往后找，直到找到i
		p = p->next;
	}
	if (p != NULL) {
		s = (Linknode*)malloc(sizeof(Linknode));
		s->data = x;  //插入结点
		s->next = p->next;//修改指针
		p->next = s;
		n++; //表的长度加一

	}
	else printf("\n\t\t线性表为空或插入位置超出！\n");
}

void DelList(char x) {
	Linknode* p, * q;
	if (head == NULL) {
		printf("\n\t\t链表下溢！");
		return;
	}
	if (head->next == NULL) {
		printf("\n\t\t链表已经为空！");
		return;
	}
	q = head;
	p = head->next;
	while (p != NULL && p->data != x) {
		q = p;
		p = p->next;
	}
	if (p != NULL) {
		q->next = p->next;
		free(p);
		n--; //表长减一
		printf("\n\t\t结点%c已经被删除！", x);
	}
	else {
		printf("\n\t\t抱歉！没有找到您要删除的结点！");
	}
}

void ShowList() {
	Linknode* p = head;
	printf("\n\t\t显示线性表的所有元素：");
	if (head->next == NULL || p == NULL) {
		printf("链表为空！");
	}
	else {
		printf("\n\t\t");
		while (p->next != NULL) {
			printf("%5c", p->next->data);
			p = p->next;
		}
	}
}

void SearchList(char x) {
	Linknode* p;
	int i = 1;
	if (head == NULL) {
		printf("链表下溢！");
		return;
	}
	if (head->next == NULL) {
		printf("\n\t\t链表为空,没有任何结点！");
		return;
	}
	p = head->next;
	while (p != NULL && p->data != x) {
		p = p->next;
		i++;
	}
	if (p != NULL) {
		printf("\n\t\t在表的第%d位上找到值为%c的结点！", i, x);
	}
	else {
		printf("\n\t\t抱歉！未找到值为%c的结点！", x);
	}
}
int main() {
	head = NULL;
	int choice, i, j = 1;
	char x;
	while (j) {
		printf("\n");
		printf("\n\t\t          线性表子系统           ");
		printf("\n\t\t*********************************");
		printf("\n\t\t*         1------建表           *");
		printf("\n\t\t*         2------插入           *");
		printf("\n\t\t*         3------删除           *");
		printf("\n\t\t*         4------显示           *");
		printf("\n\t\t*         5------查找           *");
		printf("\n\t\t*         6------求表长         *");
		printf("\n\t\t*         0------返回           *");
		printf("\n\t\t*********************************");
		printf("\n\t\t请选择菜单号（0--6）：");
		scanf("%d", &choice);
		getchar();
		if (choice == 1)
			CreateLink();
		else if (choice == 2) {
			printf("\n\t\t请输入插入的位置i和插入的数据（输入格式：i,x）：");
			scanf_s("%d,%c", &i, &x);
			InsertList(i, x);
		}
		else if (choice == 3) {
			printf("\n\t\t请输入要删除的数值：");
			scanf_s("%c", &x);
			DelList(x);
		}
		else if (choice == 4) {
			if (head == NULL) {
				printf("\n\t\t请先建立线性表！");
			}
			else {
				ShowList();
			}
		}
		else if (choice == 5) {
			printf("\n\t\t请输入要查找的元素：");
			scanf_s("%c", &x);
			SearchList(x);
		}
		else if (choice == 6) {
			printf("\n\t\t线性表的长度为：%d ", n);
		}
		else if (choice == 0)
			j = 0;
		else printf("\n\t\t输入错误！请重新输入！");
	}
	return 0;
}