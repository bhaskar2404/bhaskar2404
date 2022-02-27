#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int data;
struct node *next;
};

struct node *new, *head, *tail, *temp;

void create()
{
   int value;
	char ch;
	
	do
	{
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&value);
	new->data = value;
	new->next = NULL;
	if(head == NULL)
	{
		head = new;
		tail = new;
	}
	else
	{
		tail->next = new;
		tail = new;
	}
	printf("y-continue, e- Exit");
	printf("Enter the choice:");
	//fflush(stdin);
	
	scanf(" %c", &ch);
	}while(ch == 'y');
	
    
}

void traverse()
{
   	temp = head;
    if(temp == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (temp!=NULL)  
        {  
            printf("%d-->",temp->data);  
            temp = temp -> next;  
        }  
    }  
}

void begin_insert()
{
    int value;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node to be inserted at beginning:");
    scanf("%d", &value);
    new -> data = value;
    new ->next = head;
    head = new;
    printf("Node Inserted");
}

void last_insert()
{
    int value;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node to be inserted at last:");
    scanf("%d", &value);
    new -> data = value;
    tail -> next = new;
    new -> next = NULL;
    printf("Node Inserted");
}

void specpos_insert()
{
    int pos, value,i;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position of the node to be inserted:");
    scanf("%d", &pos);
    printf("Enter the node to be inserted:");
    scanf("%d", &value);
    temp=head;  
    for(i=0;i<pos;i++)
       {temp = temp->next;}
    new -> data = value;
    new -> next = temp-> next;
    temp->next = new;
    printf("Node Inserted");
}

void del_begin()
{
    temp = head;
    head = head-> next;
    temp->next = NULL;
    printf("Node Deleted");
}

void del_end()
{
    temp = head;
    while(temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp -> next -> next = NULL;
    tail = temp;
    printf("Node Deleted");
}

void del_random()
{
    int i,pos;
    printf("Enter the position of the node to be Deleted:");
    scanf("%d", &pos);
    temp = head;
    for(i=0;i<pos;i++)
       { temp = temp->next;}
    temp->next = temp->next->next;
    //free(temp);
    printf("Node Deleted");
}

int main()
{
	
	create();
	//traverse();
	//begin_insert();
	//last_insert();
	//specpos_insert();
	del_begin();
	del_end();
	del_random();
	traverse();
    /*	temp = head;
	while(temp != NULL)
	{
		printf("%d-->",temp->data);
		temp = temp->next;
	} */
    
	return 0;
}
