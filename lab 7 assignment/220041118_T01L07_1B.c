#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Doubly linked list

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *list = NULL;
void prepend(int element)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = element;
    new->prev = NULL;
    new->next = list;
    if (list != NULL)
        list->prev = new;
    list = new;
}
void append(int element)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = element;
    new->next = NULL;
    if (list == NULL)
    {
        new->prev = NULL;
        list = new;
        return;
    }

    node *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    new->prev = temp;
    temp->next = new;
}

void insert_sorted(int element)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = element;
    new->next = NULL;
    new->prev = NULL;
    node *temp = list;
    if (list == NULL){
        list = new;
        return;
    }
    else if (list->data >= new->data){
        list->prev = new;
        new->next = list;
        list = new;
        return;
    }
    else{
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {

                temp->next = new;
                new->prev = temp;

                break;
            }
            if (temp->next->data >= new->data)
            {
                new->next = temp->next;
                new->prev = temp->next->prev;
                temp->next = new;
                new->next->prev = new;
                break;
            }
            temp = temp->next;
        }
    }
}

void insert_after(int element, int pred)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = element;
    node *temp = list;
    while (temp->data != pred)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
    if (new->next != NULL)
        new->next->prev = new;
}

void destroy(node *n)
{
    if (n == NULL)
        printf("List is empty");
    node *temp = n;
    destroy(temp->next);
    free(temp);
}

void delete_node(int element)
{
    node *temp = list;
    node *previous;
    while (temp->data != element)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
    temp->next->prev = previous;
    free(temp);
}

void delete_front()
{
    node *temp = list;
    temp->next->prev = NULL;
    list = list->next;
    free(temp);
}

void delete_back()
{
    node *temp = list;
    node *previous;
    while (temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    free(temp);
}

void print_list()
{
    node *temp = list;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool find(int element)
{
    node *temp = list;
    while (temp->next != NULL)
    {
        if (temp->data == element)
            return true;
    }
    return false;
}

int main()
{
    insert_sorted(1);
    insert_sorted(2);
    insert_sorted(9);
    insert_sorted(10);
    insert_sorted(97);
    insert_sorted(71);
    insert_sorted(32);
    print_list();
    destroy(list);
}
