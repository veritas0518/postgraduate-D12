#include<stdio.h>
#include<malloc.h>
typedef struct linknode {
	char data;
	struct linknode* next;
}Linknode;
Linknode* head;
int n;  //���Ա���
void CreateLink() {
	n = 0;
	Linknode* p, * s;
	char x;
	int z = 1;
	head = (Linknode*)malloc(sizeof(Linknode));//
	p = head;
	printf("\n\t\t�������㣬�ԡ�x��Ϊ������ǣ�\n");
	printf("\n");
	while (z) {
		printf("\t\t������һ���ַ��������س���");
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
		j++;   //j һ��һ�������ң�ֱ���ҵ�i
		p = p->next;
	}
	if (p != NULL) {
		s = (Linknode*)malloc(sizeof(Linknode));
		s->data = x;  //������
		s->next = p->next;//�޸�ָ��
		p->next = s;
		n++; //��ĳ��ȼ�һ

	}
	else printf("\n\t\t���Ա�Ϊ�ջ����λ�ó�����\n");
}

void DelList(char x) {
	Linknode* p, * q;
	if (head == NULL) {
		printf("\n\t\t�������磡");
		return;
	}
	if (head->next == NULL) {
		printf("\n\t\t�����Ѿ�Ϊ�գ�");
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
		n--; //����һ
		printf("\n\t\t���%c�Ѿ���ɾ����", x);
	}
	else {
		printf("\n\t\t��Ǹ��û���ҵ���Ҫɾ���Ľ�㣡");
	}
}

void ShowList() {
	Linknode* p = head;
	printf("\n\t\t��ʾ���Ա������Ԫ�أ�");
	if (head->next == NULL || p == NULL) {
		printf("����Ϊ�գ�");
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
		printf("�������磡");
		return;
	}
	if (head->next == NULL) {
		printf("\n\t\t����Ϊ��,û���κν�㣡");
		return;
	}
	p = head->next;
	while (p != NULL && p->data != x) {
		p = p->next;
		i++;
	}
	if (p != NULL) {
		printf("\n\t\t�ڱ�ĵ�%dλ���ҵ�ֵΪ%c�Ľ�㣡", i, x);
	}
	else {
		printf("\n\t\t��Ǹ��δ�ҵ�ֵΪ%c�Ľ�㣡", x);
	}
}
int main() {
	head = NULL;
	int choice, i, j = 1;
	char x;
	while (j) {
		printf("\n");
		printf("\n\t\t          ���Ա���ϵͳ           ");
		printf("\n\t\t*********************************");
		printf("\n\t\t*         1------����           *");
		printf("\n\t\t*         2------����           *");
		printf("\n\t\t*         3------ɾ��           *");
		printf("\n\t\t*         4------��ʾ           *");
		printf("\n\t\t*         5------����           *");
		printf("\n\t\t*         6------���         *");
		printf("\n\t\t*         0------����           *");
		printf("\n\t\t*********************************");
		printf("\n\t\t��ѡ��˵��ţ�0--6����");
		scanf("%d", &choice);
		getchar();
		if (choice == 1)
			CreateLink();
		else if (choice == 2) {
			printf("\n\t\t����������λ��i�Ͳ�������ݣ������ʽ��i,x����");
			scanf_s("%d,%c", &i, &x);
			InsertList(i, x);
		}
		else if (choice == 3) {
			printf("\n\t\t������Ҫɾ������ֵ��");
			scanf_s("%c", &x);
			DelList(x);
		}
		else if (choice == 4) {
			if (head == NULL) {
				printf("\n\t\t���Ƚ������Ա�");
			}
			else {
				ShowList();
			}
		}
		else if (choice == 5) {
			printf("\n\t\t������Ҫ���ҵ�Ԫ�أ�");
			scanf_s("%c", &x);
			SearchList(x);
		}
		else if (choice == 6) {
			printf("\n\t\t���Ա�ĳ���Ϊ��%d ", n);
		}
		else if (choice == 0)
			j = 0;
		else printf("\n\t\t����������������룡");
	}
	return 0;
}