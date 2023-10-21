#include<stdio.h>
#define MAXQ 7
typedef struct
{
	int rear;
	int front;
	int item[MAXQ];
}Queue;

int IsEmpty(Queue*);
int IsFull(Queue *);
void Insert_rear(Queue *,int);
void Insert_front(Queue *,int);
int Delete_rear(Queue *);
int Delete_front(Queue *);
void Display(Queue *);

int main()
{
	Queue q;
	int x,ch,ele;
	q.front = -1;
	q.rear = -1;
	
	do
	{
		printf("\n1-Insert from rear");
		printf("\n2-Insert from front");
		printf("\n3-Delete from rear");
		printf("\n4-Delete from front");
		printf("\n5-Display");
		printf("\n6-OUIT");
		printf("\nEnter your choice : ");
		fflush(stdin);
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("\nEnter the elements to be inserted from rear : ");
					scanf("%d",&ele);
					Insert_rear(&q,ele);
					break;
			case 2: printf("\nEnter the elements to be inserted from front : ");
					scanf("%d",&ele);
					Insert_front(&q,ele);
					break;
			case 3: ele = Delete_rear(&q);
					if(ele==-1)
						printf("\nQueue is empty!");
					else
						printf("\nThe Deleted element is %d",ele);
					break;
			case 4: ele = Delete_front(&q);
					if(ele==-1)
						printf("\nQueue is empty!");
					else
						printf("\nThe Deleted element is %d",ele);
					break;
			case 5: Display(&q);
					break;
			case 6: break;
			default: printf("\nWrong choice : Try again");
		}
	}while(ch!=6);
	return 0;
}
int IsEmpty(Queue *q)
{
	if(q->front == -1)
		return 1;
	else
		return 0;
}
int IsFull(Queue *q)
{
	if((q->front == 0 && q->rear == MAXQ-1) || (q->front == q->rear+1))
		return 1;
	else
		return 0;
}
void Insert_rear(Queue *q, int x)
{
	if(IsFull(q))
	{
		printf("\n Queue is Full");
		return;
	}
	if(q->front == -1)
	{
		q->front = 0;
		q->rear = 0;
	}
	else if(q->rear == MAXQ-1)
		q->rear = 0;
	else
		q->rear++;
	q->item[q->rear] = x;
}
void Insert_front(Queue *q,int x)
{
	if(IsFull(q))
	{
		printf("\n Queue is Full");
		return;
	}
	if(q->front == -1)
	{
		q->front = 0;
		q->rear = 0;
	}
	else if(q->front == 0)
		q->front = MAXQ-1;
	else
		q->front--;
	q->item[q->front] = x;
}
int Delete_rear(Queue *q)
{
	int x;
	if(IsEmpty(q))
		return -1;
	
	x = q->item[q->rear];
	if(q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		if(q->rear == 0)
			q->rear = MAXQ-1;
		else
			q->rear--;
	}
	return x;
}
int Delete_front(Queue *q)
{
	int x;
	if(IsEmpty(q))
		return -1;
	
	x = q->item[q->front];
	if(q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		if(q->front == MAXQ-1)
			q->front = 0;
		else
			q->front++;
	}
	return x;
}
void Display(Queue *q)
{
	int i;
	if(IsEmpty(q))
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nThe Elements in the Queue are : ");
	
	if(q->front <= q->rear)
	{
		for(i=q->front;i<=q->rear;i++)
			printf("\n%d ",q->item[i]);
	}
	else
	{
		for(i=q->front;i<=MAXQ-1;i++)
			printf("\n%d ",q->item[i]);
		for(i=0;i<=q->rear;i++)
			printf("\n%d ",q->item[i]);
	}
}
