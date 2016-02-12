#include "list.h"

NODE *head = NULL;

void add(int num)
{
	NODE *temp;
	NODE *holder;
	holder = (NODE *)malloc(sizeof(NODE));
	holder = head;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->value=num;
	if(head == NULL)
	{
		head=temp;
		head->previous=NULL;
		head->next=NULL;
	}
	else
	{
		while(holder->next != NULL)
		{
			holder=holder->next;
		}
		holder->next=temp;
		temp->next=NULL;
		temp->previous=holder;
	}
}

void prettyPrint()
{
	NODE *holder;
	holder = (NODE *)malloc(sizeof(NODE));
	holder = head;
	while(holder != NULL)
	{
		printf("%d\n",holder->value);
		holder=holder->next;
	}
}

NODE *find(int input)
{
        NODE *holder;
        holder = (NODE *)malloc(sizeof(NODE));
        holder = head;
        if(holder->value == input)
        {
                return holder;
        }
        else
        {
                while(holder->next != NULL)
                {
                        holder = holder->next;
                        if(holder->value == input)
                        {
                                return holder;
                        }
                }
        }
        return NULL;
}

BOOLEAN delete(int input)
{
	NODE *holder;
	holder = (NODE *)malloc(sizeof(NODE));
	holder = find(input);
	if(holder != NULL)
	{
		if(holder->next == NULL && holder->previous == NULL)
		{
			;
		}
		else if(holder->next != NULL && holder->previous == NULL)
		{
			head=head->next;
			head->previous=NULL;
		}
		else if(holder->next == NULL && holder->previous != NULL)
		{
			holder->previous->next=NULL;
		}
		else
		{
			holder->previous->next=holder->next;
			holder->next->previous=holder->previous;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
