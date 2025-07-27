#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Circular Linked List

typedef struct node
{
    int data;
    struct node *next;
} node;

node *list;
void prepend(int element)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = element;
    n->next = list;

    if (list == NULL)
    {
        list = n;
        return;
    }
    node *curr = list;
    for (curr = list; curr->next != list; curr = curr->next)
    {
    }
    curr->next = n;

    n->next = list;
    list = n;
}

void append(int element)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = element;

    if (list == NULL)
    {

        list = n;
        list->next = list;
        return;
    }

    node *curr = list;
    while (curr->next != list)
    {
        curr = curr->next;
    }
    n->next = list;
    curr->next = n;
}

void delete_front()
{
    if (list == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (list->next == list)
    {
        free(list);
        list = NULL;
        return;
    }
    node *curr = list;
    node *front = list;
    while (curr->next != list)
    {
        curr = curr->next;
    }
    curr->next = front->next;
    list = front->next;
    free(front);
}

void delete_back()
{
    if (list == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (list->next == list)
    {
        free(list);
        list = NULL;
        return;
    }
    node *curr = list;
    node *prev = NULL;
    while (curr->next != list)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL)
    {
        prev->next = curr->next;
    }
    free(curr);
}

node *address_of_the_found_element = NULL;
bool find(int element)
{
    node *trav = list;
    for (; trav->next != list; trav = trav->next)
    {
        if (trav->data == element)
        {
            address_of_the_found_element = trav;
            return true;
        }
    }
    if (trav->data == element)
    {
        address_of_the_found_element = trav;
        return true;
    }
    return false;
}

void delete_node(int element)
{
    if (list == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (list->next == list && list->data == element)
    {
        free(list);
        list = NULL;
        return;
    }
    if (list->data == element)
    {
        delete_front();
        return;
    }
    if (find(element))
    {
        node *curr = list;
        while (curr->next != address_of_the_found_element)
        {
            curr = curr->next;
        }
        curr->next = address_of_the_found_element->next;
        free(address_of_the_found_element);
    }
    else
    {
        printf("%d is not present in the list!\n", element);
    }
}

void insert_after(int element, int pred)
{
    node *first = list;
    node *n = (node *)malloc(sizeof(node));
    n->data = element;
    n->next = NULL;

    node *curr = list;
    while (curr->data != pred && curr->next != first)
    {
        curr = curr->next;
    }
    if (curr->next == first)
    {
        printf("%d is not present in the list!\n", pred);
        return;
    }

    n->next = curr->next;
    curr->next = n;
}

void sort_1st_element_again()
{
    if (list->data > list->next->data)
    {
        int element = list->data;
        int i = 0;
        delete_front();
        while (1)
        {
            if (find(element - i))
            {
                insert_after(element, element - i);
                break;
            }
            else
            {
                i++;
            }
        }
    }
}

void insert_sorted(int element)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = element;

    if (list == NULL)
    {

        list = new_node;
        list->next = list;
        return;
    }

    node *curr = list;
    node *prev = NULL;

    do
    {
        prev = curr;
        curr = curr->next;
        if (curr->data >= element)
        {
            break;
        }
    } while (curr != list);

    prev->next = new_node;
    new_node->next = curr;

    if (curr == list && prev->data > element)
    {
        list = new_node;
    }
    sort_1st_element_again();
}

void destroy(node *n)
{
    if (n == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node *curr = n;
    node *temp;
    while (curr->next != n)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(curr);
}

void print_list()
{
    if (list == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node *ptr = list;
    for (ptr = list; ptr->next != list; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    printf("%d ", ptr->data);
    printf("\n");
}

int main()
{
    int x;
    while(scanf("%d", &x) != EOF)
    {
        insert_sorted(x);
    }
    print_list();
    delete_front();
    print_list();
    delete_back();
    print_list();
    delete_node(3);
    print_list();

    destroy(list);
    return 0;
}
