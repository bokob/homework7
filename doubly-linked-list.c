#include<stdio.h>
#include<stdlib.h>

typedef struct Node 	// 구조체 Node 선언
{
	int key;			// int형 변수 key
	struct Node* llink;	// 구조체 Node에 대한 포인터 llink
	struct Node* rlink;	// 구조체 Node에 대한 포인터 rlink
} listNode;				// 선언한 구조체 Node를 listNode라 정의



typedef struct Head 	// 구조체 Head 선언
{
	struct Node* first;	// 구조체 Node에 대한 포인터 first
}headNode;				// 선언한 구조체 Head를 headNode라 정의

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);
/*	singly-linked-list에서의 initialize는 구조체 포인터형의 함수였고
매개변수는 싱글포인터였다. 결론은 더블포인터처럼 작용하게 된다.
하지만 doubly-linked-list의 initialize는 int형 함수다. 
그러므로 접근하기 위해서는 더블 포인터로 매개변수를 받아야한다.*/

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
         - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);
/* freelist가 싱글포인터를 매개변수로 받는 이유는 
headNode h를 직접 조작하는 것이 아닌
h를 통해 접근할 수 있는 노드들을 해제하기 때문이다.
 이중포인터를 매개변수로 받아 해제하는 법은 
 h를 이용해 접근하는 방식에서 가리키는 곳의 가리키는 곳
 즉, 원래 우리가 싱글포인터를 이용해 해제할 공간을 이중포인터로 직접 해제하게끔 바꿔주면 된다.
*/

int insertNode(headNode* h, int key);	// 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int insertLast(headNode* h, int key);	// 리스트의 맨 뒤에 입력받은 key를 지닌 노드 하나 추가
int insertFirst(headNode* h, int key);	// 리스트의 맨 앞에 입력받은 key를 지닌 노드 하나 추가
int deleteNode(headNode* h, int key);	// 입력받은 key를 지닌 노드 삭제
int deleteLast(headNode* h);			// 리스트의 맨 뒤에 있는 노드 하나 삭제
int deleteFirst(headNode* h);			// 리스트의 맨 앞에 있는 노드 하나 삭제
int invertList(headNode* h);			// 리스트를 역순을 재배치

void printList(headNode* h);			// 리스트의 내용 출력

int main()
{
	char command;			 // 명령어를 입력받을 char형 변수 command
	int key;				 // int형 변수 key
	headNode* headnode=NULL; //	메모리의 Stack 영역에 headNode를 만들고 NULL을 가리키도록 한다.
	int flag = 0; // initialize 함수를 사용했다는 것을 나타내줄 변수

	printf("[------------------- [복무창] [2021040021] -------------------]\n");

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
		scanf(" %c", &command);		// 명령어를 입력받는다.

		switch(command) {
		case 'z': case 'Z':			// z 또는 Z 입력받은 경우
			initialize(&headnode);	// initialize 함수 호출
			flag=1;					// initialize 함수 사용
			break;
		case 'p': case 'P':			// p 또는 P 입력받은 경우
			printList(headnode);	// printList 함수 호출
			break;
		case 'i': case 'I':			// i 또는 I 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);	// insertNode 함수 호출
			break;
		case 'd': case 'D':				// d 또는 D 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);	// deleteNode 함수 호출
			break;
		case 'n': case 'N':				// n 또는 N 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);	// insertLast 함수 호출
			break;
		case 'e': case 'E':				// e 또는 E 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			deleteLast(headnode);		// deleteLast 함수 호출
			break;
		case 'f': case 'F':				// f 또는 F 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");		
			scanf("%d", &key);
			insertFirst(headnode, key);	// insertFirst 함수 호출
			break;
		case 't': case 'T':				// t 또는 T 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			deleteFirst(headnode);		// deleteFirst 함수 호출
			break;
		case 'r': case 'R':				// r 또는 R 입력받은 경우
			if(flag==0)				// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			invertList(headnode);		// invertList 함수 호출
			break;
		case 'q': case 'Q':				// q 또는 Q 입력받은 경우
			freeList(headnode);			// freeList 함수 호출
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // q 또는 Q가 입력받지 않을 때까지 반복

	return 1;
}


int initialize(headNode** h) 
{
	if (*h != NULL)		// h가 가리키는 곳에 NULL이 들어있지 않다면
		freeList(*h);	// freeList를 호출해 h가 가리키는 곳이 가리키는 공간을 해제한다.

	*h = (headNode *)malloc(sizeof(headNode));
	// 메모리의 Heap 영역에 headNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 h가 가리키는 곳에 넣는다.
	(*h)->first = NULL;
	// h가 가리키는 곳이 가리키는 곳의 first에 NULL을 넣는다.

	return 1;
}

int freeList(headNode* h)
{
	listNode *p= h->first;
	// 메모리의 Stack 영역에 p를 만들고
	// h가 가리키는 곳의 first에 들어있는 주소를 p에 넣는다.

	listNode *prev=NULL;
	// 메모리의 Stack 영역에 prev를 만들고
	// prev에 NULL을 넣는다.

	while(p!=NULL)	// p에 있는 값이 NULL이 아닐 때까지만 반복
	{
		prev=p;		// prev에 p에 들어있는 주소를 넣는다.
		p=p->rlink;	// p에 p가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
		free(prev);	// prev를 해제한다.
	}
	free(h); // h를 해제한다.

	return 0;
}


void printList(headNode* h) 
{
	int i = 0;
	listNode* p;
	// 메모리의 Stack 영역에 p를 만든다.

	printf("\n---PRINT\n");

	if(h == NULL)	// h가 가리키는 곳이 NULL이라면 
	{
		printf("Nothing to print....\n");	// 출력할 것이 없다는 문구 출력
		return;
	}

	p = h->first;	// p에 h가 가리키는 곳의 first에 들어있는 주소를 넣는다.

	while(p != NULL)	// p가 가리키는 곳이 NULL이 아닐 때까지 반복 
	{
		printf("[ [%d]=%d ] ", i, p->key); // p가 가리키는 곳의 key 출력
		p = p->rlink;	// p에 p가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
		i++;	// i를 1씩 증가시킨다.
	}

	printf("  items = %d\n", i);	// 몇 번째 노드인지 출력
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) 
{	
	listNode *node=(listNode*)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 메모리의 Stack 영역의 node에 할당한다.

	node->key=key;		// node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->llink=NULL;	// node가 가리키는 곳의 llink에 NULL을 넣는다.
	node->rlink=NULL;	// node가 가리키는 곳의 rlink에 NULL을 넣는다.

	if(h->first == NULL)
	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		h->first = node;	
		// h가 가리키는 곳의 first에 node가 가리키고 있는 곳의 주소를 넣는다.
		return 0;
	}

	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.

	while(n->rlink != NULL)
	// n이 가리키는 곳의 rlink가 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		n = n->rlink;	// n에 n이 가리키는 곳의 rlink가 가리키는 곳의 주소를 넣는다.
	}
	n->rlink = node;	// n이 가리키는 곳의 rlink에 node가 가리키는 곳의 주소를 넣는다.
	node->llink = n;	// node가 가리키는 곳의 llink에 n이 가리키는 곳의 주소를 넣는다.

	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) 
{
	if(h->first==NULL)	// h가 가리키는 곳의 first가 가리키는 곳이 NULL 이라면
	{
		printf("nothing to delete.\n"); // 삭제할 것이 없다는 문구 출력
		return 0;
	}

	listNode* n= h->first;
	// 메모리의 Stack 영역에 n을 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.
	listNode* trail=NULL;
	// 메모리의 Stack 영역dp trail을 만들고 NULL을 넣는다.

	if(n->rlink==NULL)	// n이 가리키는 곳의 rlink에 NULL이 들어있다면
	{
		h->first=NULL;	// h가 가리키는 곳의 first에 NULL을 넣는다.
		free(n);		// n을 해제한다.
		return 0;
	}

	while(n->rlink!=NULL)
	// n이 가리키는 곳의 rlink가 NULL을 가리키지 않을 때까지 반복
	{
		trail=n;	// trail에 n에 들어있는 주소를 넣는다.
		n=n->rlink;	// n에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
	}

	trail->rlink=NULL;	// trail이 가리키는 곳의 rlink에 NULL을 넣는다.
	free(n);			// n을 해제한다.

	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) 
{	
	listNode* node= (listNode*)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 메모리의 Stack 영역의 node에 할당한다.

	node->key=key;	// node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->rlink = node->llink = NULL;	// node가 가리키는 곳의 rlink와 llink에 NULL을 넣는다.

	if(h->first == NULL)	// h가 가리키는 곳의 first가 NULL을 가리킨다면
	{
		h->first = node;	// h가 가리키는 곳의 first에 node에 들어있는 주소를 넣는다.
		return 1;
	}
	node->rlink=h->first;	
	// node가 가리키는 곳의 rlink에 h가 가리키는 곳의 first에 들어있는 주소를 넣는다.
	node->llink=NULL;	// node가 가리키는 곳의 llink에 NULL을 넣는다.

	listNode *p= h->first;
	// 메모리의 Stack 영역에 p를 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 p에 넣는다.
	p->llink=node;	// p가 가리키는 곳의 llink에 node에 들어있는 주소를 넣는다.
	h->first=node;	// h가 가리키는 곳의 first에 node에 들어있는 주소를 넣는다.

	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) 
{
	if(h->first == NULL)	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to delete.\n");	// 삭제할 것이 없다는 문구 출력
		return 0;
	}
	listNode* n = h->first;
	// 메모리의 Stack 영역에 n을 만들고,
	// h가 가리키는 곳의 first에 들어있는 주소를 n에 넣는다.
	h->first=n->rlink;	// h가 가리키는 곳의 first에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.

	free(n);	// n을 해제한다.

	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) 
{
	if(h->first==NULL)	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to invert...\n");	// 역순으로 할 것이 없다는 문구 출력
		return 0;
	}
	listNode *n=h->first;
	// 메모리의 Stack 영역에 n을 만들고
	// h가 가리키는 곳의 first에 들어있는 주소를 n에 넣는다.
	listNode *trail=NULL;
	// 메모리의 Stack 영역에 trail을 만들고 NULL을 넣는다.
	listNode *middle=NULL;
	// 메모리의 Stack 영역에 middle을 만들고 NULL을 넣는다.

	while(n!=NULL)	// n이 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		trail=middle;	// trail에 middle에 들어있는 주소를 넣는다.
		middle=n;		// middle에 n에 들어있는 주소를 넣는다.
		n=n->rlink;		// n에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
		middle->rlink=trail;	// middle이 가리키는 곳의 rlink에 trail에 들어있는 주소를 넣는다.
		middle->llink=n;	// middle이 가리키는 곳의 llink에 n에 들어있는 주소를 넣는다.
	}
	h->first=middle;	// h가 가리키는 곳의 first에 middle에 들어있는 주소를 넣는다.

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) 
{
	listNode* node=(listNode*)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 공간을 만들고
	// 그곳의 주소를 메모리의 Stack 영역의 node에 할당한다.
	node->key=key;					// node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->llink=node->rlink=NULL;	// node가 가리키는 곳의 llink와 rlink에 NULL을 넣는다.

	if(h->first==NULL)	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		h->first=node;	// h가 가리키는 곳의 first에 node에 들어있는 주소를 넣는다.
		return 0;
	}

	listNode* n =h->first;
	// 메모리의 Stack 영역에 n을 만들고
	// h가 가리키는 곳의 first에 들어있는 주소를 n에 넣는다.

	while(n!=NULL)	// n이 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		if(n->key >= key)	// n이 가리키는 곳의 key가 입력받은 key보다 크다면
		{
			if(n == h->first)	// n이 가리키는 곳이 h가 가리키는 곳의 first가 가리키는 곳과 같다면
			{
				insertFirst(h,key);		// insertFirst 함수를 호출한다.
			}
			else	// n이 가리키는 곳이 h가 가리키는 곳의 first가 가리키는 곳과 다르면
			{
				node->rlink=n;			// node가 가리키는 곳의 rlink에 n에 들어있는 주소를 넣는다.
				node->llink = n->llink;	// node가 가리키는 곳의 llink에 n이 가리키는 곳의 llink에 들어있는 주소를 넣는다.
				n->llink->rlink = node;	// n이 가리키는 곳의 llink가 가리키는 곳의 rlink에 node에 들어있는 주소를 넣는다.
			}
			return 0;
		}

		n = n->rlink; // n이 가리키는 곳의 rlink에 들어있는 주소를 n에 넣는다.
	}

	insertLast(h,key);	// insertLast 함수를 호출한다.
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) 
{
	if(h->first == NULL)	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to delete.\n");	// 삭제할 것이 없다는 문구 출력
		return 1;
	}

	listNode* n = h->first;
	// 메모리의 Stack 영역에 n을 만들고
	// h가 가리키는 곳의 first에 들어있는 주소를 n에 넣는다.

	while(n!=NULL)	// n이 NULL을 가리키지 않을 때까지 반복
	{
		if(n->key == key)	// n이 가리키는 곳의 key가 입력받은 key와 같다면
		{
			if(n == h->first)	// n이 가리키는 곳과 h가 가리키는 곳의 first가 가리키는 곳이 같다면
			{
				deleteFirst(h);		// deleteFirst 함수 호출
			}
			else if(n->rlink==NULL)	// 위의 if문의 조건이 충족하지 않으면서 n이 가리키는 곳의 rlink가 가리키는 곳이 NULL 이라면
			{
				deleteLast(h);	// deleteLast 함수 호출
			}
			else // 위의 if문과 else if문이 충족하지 않는다면
			{
				n->llink->rlink=n->rlink;	// n이 가리키는 곳의 llink가 가리키는 곳의 rlink에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
				n->rlink->llink=n->llink;	// n이 가리키는 곳의 rlink가 가리키는 곳의 llink에 n이 가리키는 곳의 llink에 들어있는 주소를 넣는다.
				free(n);	// n을 해제한다.
			}
			return 1;
		}
		n=n->rlink;	// n이 가리키는 곳의 rlink에 들어있는 주소를 n에 넣는다.
	}

	printf("cannot find the node for key = %d\n", key);	// 삭제할 키를 지닌 노드를 못찾겠다는 문구 출력
	
	return 1;
}