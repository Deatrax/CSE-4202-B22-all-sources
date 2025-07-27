#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>


typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;

}node;


//Declearing the fucntions for better management of the functions.
void append(int element);
void delete_node(int element);
void print_list();
bool find(int element);

void find_duplicates();
void list_init();
void sort();
//==============================>



//GLOBAL VARIABLE DECLERATION-------->
node* list;
bool isSorted =false;
//----------------------------------->




//=====================================>
//================MAIN=================>
int main(){

    list_init();
    int inp;
    scanf("%d",&inp);
    while (inp!=-1)
    {
        append(inp);
        scanf("%d",&inp);
    }
    
    sort();

    //print_list();
    
    find_duplicates();

    print_list();


}
//=====================================>



void list_init(){

    list=NULL;    
}


void sort() {
    if (list == NULL || list->next == NULL)
        return; // Nothing to sort if list is empty or has only one element

    int n = 0;
    node* temp;
    for (temp = list; temp != NULL; temp = temp->next)
        n++;

    node *a1, *a2;
    for (int i = 0; i < n - 1; i++) {
        int swap = 0;
        a1 = list;
        a2 = list->next;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a1->data > a2->data) {
                //DEBUG printf("Swapping %d and %d\n", a1->data, a2->data);

                int tempData = a1->data;
                a1->data = a2->data;
                a2->data = tempData;

                swap = 1;
            }
            a1 = a1->next;
            a2 = a2->next;
        }
        if (!swap)
            break;
    }
}


void append(int element){
    
    if (list==NULL)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->data=element;
        temp->next=NULL;
        temp->prev=NULL;
        list=temp;
    }
    else{

        node *temp=(node*)malloc(sizeof(node));
        temp->data=element;
        node* last=list;
        while (last->next!=NULL)
        {
            last=last->next;
        }
        
        if (isSorted)
        {
            if (element<last->data)
            {
                printf("The list is now unsorted\n");
                isSorted=false;
            }
            
        }
        last->next=temp;
        temp->next=NULL;
        temp->prev=last;
    }

}



void delete_node(int element)
{
    node* curr=list;
    for(node* trav = list; trav != NULL; trav = trav->next)
    {
        if(trav->data == element)
        {   
            curr=trav;
            //DEBUG printf("found the element: %d\n",trav->data);
            //DEBUG printf("found the element: %d\n",curr->data);
            break;
        }
    }
    if (curr==NULL)
    {
        printf("The targeted element is not present");
        return;
    }
    
    //DEBUG else printf("found the element: %d",curr->data);
    
    curr->next->prev = (node*)curr->prev;
    curr->prev->next = (node*)curr->next;
    free(curr);
    //DEBUG printf("\n%d",list->next->next->prev->data);
    //DEBUG printf("\n%d",list->next->next->next->data);
    
}



void print_list(){

    if (list==NULL)
    {
        printf("The list is empty\n");
    }
    else{
        //printf("The list is:");
        for (node*temp=list; temp!=NULL; temp=temp->next)
        {
            printf("%d ",temp->data);
        }
    }
}



void find_duplicates(){

    //traversing
    node* curr=list;
    while (curr->next!=NULL)
    {   
        if (curr->data==curr->next->data)
        {
            delete_node(curr->data);
        }
        
        curr=curr->next;
    }



}
