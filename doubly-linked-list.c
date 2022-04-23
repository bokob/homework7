#include<stdio.h>
#include<stdlib.h>

typedef struct Node 	// ����ü Node ����
{
	int key;			// int�� ���� key
	struct Node* llink;	// ����ü Node�� ���� ������ llink
	struct Node* rlink;	// ����ü Node�� ���� ������ rlink
} listNode;				// ������ ����ü Node�� listNode�� ����



typedef struct Head 	// ����ü Head ����
{
	struct Node* first;	// ����ü Node�� ���� ������ first
}headNode;				// ������ ����ü Head�� headNode�� ����

/* note: initialize�� ���������͸� �Ű������� ����
         singly-linked-list�� initialize�� �������� ���� �Ұ� */
int initialize(headNode** h);
/*	singly-linked-list������ initialize�� ����ü ���������� �Լ�����
�Ű������� �̱������Ϳ���. ����� ����������ó�� �ۿ��ϰ� �ȴ�.
������ doubly-linked-list�� initialize�� int�� �Լ���. 
�׷��Ƿ� �����ϱ� ���ؼ��� ���� �����ͷ� �Ű������� �޾ƾ��Ѵ�.*/

/* note: freeList�� �̱������͸� �Ű������� ����
        - initialize�� �� �ٸ��� ���� �Ұ�
         - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
int freeList(headNode* h);
/* freelist�� �̱������͸� �Ű������� �޴� ������ 
headNode h�� ���� �����ϴ� ���� �ƴ�
h�� ���� ������ �� �ִ� ������ �����ϱ� �����̴�.
 ���������͸� �Ű������� �޾� �����ϴ� ���� 
 h�� �̿��� �����ϴ� ��Ŀ��� ����Ű�� ���� ����Ű�� ��
 ��, ���� �츮�� �̱������͸� �̿��� ������ ������ ���������ͷ� ���� �����ϰԲ� �ٲ��ָ� �ȴ�.
*/

int insertNode(headNode* h, int key);	// �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ����
int insertLast(headNode* h, int key);	// ����Ʈ�� �� �ڿ� �Է¹��� key�� ���� ��� �ϳ� �߰�
int insertFirst(headNode* h, int key);	// ����Ʈ�� �� �տ� �Է¹��� key�� ���� ��� �ϳ� �߰�
int deleteNode(headNode* h, int key);	// �Է¹��� key�� ���� ��� ����
int deleteLast(headNode* h);			// ����Ʈ�� �� �ڿ� �ִ� ��� �ϳ� ����
int deleteFirst(headNode* h);			// ����Ʈ�� �� �տ� �ִ� ��� �ϳ� ����
int invertList(headNode* h);			// ����Ʈ�� ������ ���ġ

void printList(headNode* h);			// ����Ʈ�� ���� ���

int main()
{
	char command;			 // ��ɾ �Է¹��� char�� ���� command
	int key;				 // int�� ���� key
	headNode* headnode=NULL; //	�޸��� Stack ������ headNode�� ����� NULL�� ����Ű���� �Ѵ�.
	int flag = 0; // initialize �Լ��� ����ߴٴ� ���� ��Ÿ���� ����

	printf("[------------------- [����â] [2021040021] -------------------]\n");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);		// ��ɾ �Է¹޴´�.

		switch(command) {
		case 'z': case 'Z':			// z �Ǵ� Z �Է¹��� ���
			initialize(&headnode);	// initialize �Լ� ȣ��
			flag=1;					// initialize �Լ� ���
			break;
		case 'p': case 'P':			// p �Ǵ� P �Է¹��� ���
			printList(headnode);	// printList �Լ� ȣ��
			break;
		case 'i': case 'I':			// i �Ǵ� I �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);	// insertNode �Լ� ȣ��
			break;
		case 'd': case 'D':				// d �Ǵ� D �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);	// deleteNode �Լ� ȣ��
			break;
		case 'n': case 'N':				// n �Ǵ� N �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);	// insertLast �Լ� ȣ��
			break;
		case 'e': case 'E':				// e �Ǵ� E �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			deleteLast(headnode);		// deleteLast �Լ� ȣ��
			break;
		case 'f': case 'F':				// f �Ǵ� F �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");		
			scanf("%d", &key);
			insertFirst(headnode, key);	// insertFirst �Լ� ȣ��
			break;
		case 't': case 'T':				// t �Ǵ� T �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			deleteFirst(headnode);		// deleteFirst �Լ� ȣ��
			break;
		case 'r': case 'R':				// r �Ǵ� R �Է¹��� ���
			if(flag==0)				// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			invertList(headnode);		// invertList �Լ� ȣ��
			break;
		case 'q': case 'Q':				// q �Ǵ� Q �Է¹��� ���
			freeList(headnode);			// freeList �Լ� ȣ��
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // q �Ǵ� Q�� �Է¹��� ���� ������ �ݺ�

	return 1;
}


int initialize(headNode** h) 
{
	if (*h != NULL)		// h�� ����Ű�� ���� NULL�� ������� �ʴٸ�
		freeList(*h);	// freeList�� ȣ���� h�� ����Ű�� ���� ����Ű�� ������ �����Ѵ�.

	*h = (headNode *)malloc(sizeof(headNode));
	// �޸��� Heap ������ headNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� h�� ����Ű�� ���� �ִ´�.
	(*h)->first = NULL;
	// h�� ����Ű�� ���� ����Ű�� ���� first�� NULL�� �ִ´�.

	return 1;
}

int freeList(headNode* h)
{
	listNode *p= h->first;
	// �޸��� Stack ������ p�� �����
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� p�� �ִ´�.

	listNode *prev=NULL;
	// �޸��� Stack ������ prev�� �����
	// prev�� NULL�� �ִ´�.

	while(p!=NULL)	// p�� �ִ� ���� NULL�� �ƴ� �������� �ݺ�
	{
		prev=p;		// prev�� p�� ����ִ� �ּҸ� �ִ´�.
		p=p->rlink;	// p�� p�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
		free(prev);	// prev�� �����Ѵ�.
	}
	free(h); // h�� �����Ѵ�.

	return 0;
}


void printList(headNode* h) 
{
	int i = 0;
	listNode* p;
	// �޸��� Stack ������ p�� �����.

	printf("\n---PRINT\n");

	if(h == NULL)	// h�� ����Ű�� ���� NULL�̶�� 
	{
		printf("Nothing to print....\n");	// ����� ���� ���ٴ� ���� ���
		return;
	}

	p = h->first;	// p�� h�� ����Ű�� ���� first�� ����ִ� �ּҸ� �ִ´�.

	while(p != NULL)	// p�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ� 
	{
		printf("[ [%d]=%d ] ", i, p->key); // p�� ����Ű�� ���� key ���
		p = p->rlink;	// p�� p�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
		i++;	// i�� 1�� ������Ų��.
	}

	printf("  items = %d\n", i);	// �� ��° ������� ���
}




/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) 
{	
	listNode *node=(listNode*)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� �޸��� Stack ������ node�� �Ҵ��Ѵ�.

	node->key=key;		// node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->llink=NULL;	// node�� ����Ű�� ���� llink�� NULL�� �ִ´�.
	node->rlink=NULL;	// node�� ����Ű�� ���� rlink�� NULL�� �ִ´�.

	if(h->first == NULL)
	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		h->first = node;	
		// h�� ����Ű�� ���� first�� node�� ����Ű�� �ִ� ���� �ּҸ� �ִ´�.
		return 0;
	}

	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.

	while(n->rlink != NULL)
	// n�� ����Ű�� ���� rlink�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		n = n->rlink;	// n�� n�� ����Ű�� ���� rlink�� ����Ű�� ���� �ּҸ� �ִ´�.
	}
	n->rlink = node;	// n�� ����Ű�� ���� rlink�� node�� ����Ű�� ���� �ּҸ� �ִ´�.
	node->llink = n;	// node�� ����Ű�� ���� llink�� n�� ����Ű�� ���� �ּҸ� �ִ´�.

	return 0;
}



/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) 
{
	if(h->first==NULL)	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL �̶��
	{
		printf("nothing to delete.\n"); // ������ ���� ���ٴ� ���� ���
		return 0;
	}

	listNode* n= h->first;
	// �޸��� Stack ������ n�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.
	listNode* trail=NULL;
	// �޸��� Stack ����dp trail�� ����� NULL�� �ִ´�.

	if(n->rlink==NULL)	// n�� ����Ű�� ���� rlink�� NULL�� ����ִٸ�
	{
		h->first=NULL;	// h�� ����Ű�� ���� first�� NULL�� �ִ´�.
		free(n);		// n�� �����Ѵ�.
		return 0;
	}

	while(n->rlink!=NULL)
	// n�� ����Ű�� ���� rlink�� NULL�� ����Ű�� ���� ������ �ݺ�
	{
		trail=n;	// trail�� n�� ����ִ� �ּҸ� �ִ´�.
		n=n->rlink;	// n�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
	}

	trail->rlink=NULL;	// trail�� ����Ű�� ���� rlink�� NULL�� �ִ´�.
	free(n);			// n�� �����Ѵ�.

	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) 
{	
	listNode* node= (listNode*)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� �޸��� Stack ������ node�� �Ҵ��Ѵ�.

	node->key=key;	// node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->rlink = node->llink = NULL;	// node�� ����Ű�� ���� rlink�� llink�� NULL�� �ִ´�.

	if(h->first == NULL)	// h�� ����Ű�� ���� first�� NULL�� ����Ų�ٸ�
	{
		h->first = node;	// h�� ����Ű�� ���� first�� node�� ����ִ� �ּҸ� �ִ´�.
		return 1;
	}
	node->rlink=h->first;	
	// node�� ����Ű�� ���� rlink�� h�� ����Ű�� ���� first�� ����ִ� �ּҸ� �ִ´�.
	node->llink=NULL;	// node�� ����Ű�� ���� llink�� NULL�� �ִ´�.

	listNode *p= h->first;
	// �޸��� Stack ������ p�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� p�� �ִ´�.
	p->llink=node;	// p�� ����Ű�� ���� llink�� node�� ����ִ� �ּҸ� �ִ´�.
	h->first=node;	// h�� ����Ű�� ���� first�� node�� ����ִ� �ּҸ� �ִ´�.

	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) 
{
	if(h->first == NULL)	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to delete.\n");	// ������ ���� ���ٴ� ���� ���
		return 0;
	}
	listNode* n = h->first;
	// �޸��� Stack ������ n�� �����,
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� n�� �ִ´�.
	h->first=n->rlink;	// h�� ����Ű�� ���� first�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.

	free(n);	// n�� �����Ѵ�.

	return 0;
}



/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) 
{
	if(h->first==NULL)	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to invert...\n");	// �������� �� ���� ���ٴ� ���� ���
		return 0;
	}
	listNode *n=h->first;
	// �޸��� Stack ������ n�� �����
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� n�� �ִ´�.
	listNode *trail=NULL;
	// �޸��� Stack ������ trail�� ����� NULL�� �ִ´�.
	listNode *middle=NULL;
	// �޸��� Stack ������ middle�� ����� NULL�� �ִ´�.

	while(n!=NULL)	// n�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		trail=middle;	// trail�� middle�� ����ִ� �ּҸ� �ִ´�.
		middle=n;		// middle�� n�� ����ִ� �ּҸ� �ִ´�.
		n=n->rlink;		// n�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
		middle->rlink=trail;	// middle�� ����Ű�� ���� rlink�� trail�� ����ִ� �ּҸ� �ִ´�.
		middle->llink=n;	// middle�� ����Ű�� ���� llink�� n�� ����ִ� �ּҸ� �ִ´�.
	}
	h->first=middle;	// h�� ����Ű�� ���� first�� middle�� ����ִ� �ּҸ� �ִ´�.

	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) 
{
	listNode* node=(listNode*)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ������ �����
	// �װ��� �ּҸ� �޸��� Stack ������ node�� �Ҵ��Ѵ�.
	node->key=key;					// node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->llink=node->rlink=NULL;	// node�� ����Ű�� ���� llink�� rlink�� NULL�� �ִ´�.

	if(h->first==NULL)	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		h->first=node;	// h�� ����Ű�� ���� first�� node�� ����ִ� �ּҸ� �ִ´�.
		return 0;
	}

	listNode* n =h->first;
	// �޸��� Stack ������ n�� �����
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� n�� �ִ´�.

	while(n!=NULL)	// n�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		if(n->key >= key)	// n�� ����Ű�� ���� key�� �Է¹��� key���� ũ�ٸ�
		{
			if(n == h->first)	// n�� ����Ű�� ���� h�� ����Ű�� ���� first�� ����Ű�� ���� ���ٸ�
			{
				insertFirst(h,key);		// insertFirst �Լ��� ȣ���Ѵ�.
			}
			else	// n�� ����Ű�� ���� h�� ����Ű�� ���� first�� ����Ű�� ���� �ٸ���
			{
				node->rlink=n;			// node�� ����Ű�� ���� rlink�� n�� ����ִ� �ּҸ� �ִ´�.
				node->llink = n->llink;	// node�� ����Ű�� ���� llink�� n�� ����Ű�� ���� llink�� ����ִ� �ּҸ� �ִ´�.
				n->llink->rlink = node;	// n�� ����Ű�� ���� llink�� ����Ű�� ���� rlink�� node�� ����ִ� �ּҸ� �ִ´�.
			}
			return 0;
		}

		n = n->rlink; // n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� n�� �ִ´�.
	}

	insertLast(h,key);	// insertLast �Լ��� ȣ���Ѵ�.
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) 
{
	if(h->first == NULL)	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to delete.\n");	// ������ ���� ���ٴ� ���� ���
		return 1;
	}

	listNode* n = h->first;
	// �޸��� Stack ������ n�� �����
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� n�� �ִ´�.

	while(n!=NULL)	// n�� NULL�� ����Ű�� ���� ������ �ݺ�
	{
		if(n->key == key)	// n�� ����Ű�� ���� key�� �Է¹��� key�� ���ٸ�
		{
			if(n == h->first)	// n�� ����Ű�� ���� h�� ����Ű�� ���� first�� ����Ű�� ���� ���ٸ�
			{
				deleteFirst(h);		// deleteFirst �Լ� ȣ��
			}
			else if(n->rlink==NULL)	// ���� if���� ������ �������� �����鼭 n�� ����Ű�� ���� rlink�� ����Ű�� ���� NULL �̶��
			{
				deleteLast(h);	// deleteLast �Լ� ȣ��
			}
			else // ���� if���� else if���� �������� �ʴ´ٸ�
			{
				n->llink->rlink=n->rlink;	// n�� ����Ű�� ���� llink�� ����Ű�� ���� rlink�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
				n->rlink->llink=n->llink;	// n�� ����Ű�� ���� rlink�� ����Ű�� ���� llink�� n�� ����Ű�� ���� llink�� ����ִ� �ּҸ� �ִ´�.
				free(n);	// n�� �����Ѵ�.
			}
			return 1;
		}
		n=n->rlink;	// n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� n�� �ִ´�.
	}

	printf("cannot find the node for key = %d\n", key);	// ������ Ű�� ���� ��带 ��ã�ڴٴ� ���� ���
	
	return 1;
}