#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;

}node;

//Declearing the fucntions for better management of the functions.
void prepend(int element);
void append(int element);
void insert_sorted(int element);
void insert_after(int element, int pred);
void destroy(node* n);
void delete_node(int element);
void delete_front();
void delete_back();
void print_list();
bool find(int element);


//MY NECESSARY FUNCTIONS========>
void list_init();
void sort();
//==============================>


//GLOBAL VARIABLE DECLERATION-------->
node* list;
bool isSorted =false;
//----------------------------------->


int main(){

    list_init();
    int loop=1;
    while (loop)
    {   
        //lrscr();
        int x;
        //system("cls");
        printf("Select operation:\n prepend (p)\n append (a)\n insert_sorted (s)\n insert_after (i)\n destroy (d)\n delete_node (n)\n delete_front (f)\n delete_back (b)\n print_list (l)\n find (x)\n sort(o)\n quit (q)\n\n====>");
        char dec;
        fflush(stdin);
        scanf("%c",&dec);
        switch (dec)
        {
        case 'p':
            
            printf("Insert the value :");
            scanf("%d",&x);
            prepend(x);
            break;

        case 'a':
              

            printf("Insert the value :");
            scanf("%d",&x);
            append(x);
            break;

        case 's':
            
            printf("Insert the value :");
            scanf("%d",&x);
            insert_sorted(x);
            break;

        case 'i':
            printf("Give the new element: ");
            int pred;
            
            scanf("%d",&x);
            printf("Give the targeted element: ");
            scanf("%d",&pred);
            insert_after(x,pred);
            break;

        case 'd':

            destroy(list);
            list_init();
            break;

        case 'n':
            
            printf("Insert the value to delete :");
            scanf("%d",&x);
            delete_node(x);
            break;
        
        case 'f':
            
            delete_front();
            break;

        case 'b':
              
            delete_back();
            break;

        case 'l':

            print_list();
            break;

        case 'x':
            
            printf("Insert the value to find :");
            scanf("%d",&x);
            find(x);
            break;

        case 'o':
              
            sort();
            printf("List was sorted\n");
            break;

        case 'q':
              
            scanf("%d",&x);
            loop=0;
            break;
    
            
        default:
            break;
        }
        printf("\ncontinue? (y/n)==>");
        fflush(stdin);
        scanf("%c",&dec);
        if (dec=='y')
        {   

            continue;
        }
        else
        {
            return 0;
        }
                
    }

}


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

                // Swap data without modifying next and prev pointers
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


void prepend(int element){

    if (list==NULL)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->data=element;
        temp->next=NULL;
        temp->prev=NULL;
        list=temp;
    }
    else{

        if (isSorted)
        {
            if (element>list->data)
            {
                printf("The list is now unsorted\n");
                isSorted=false;
            }
            
        }
        node *temp=(node*)malloc(sizeof(node));
        temp->data=element;
        temp->prev=NULL;
        temp->next=list;
        list->prev=temp;
        list=temp;
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



void insert_sorted(int element){

    if (!isSorted)
    {
        sort();
        isSorted=true;
    }
    
    node* n = (node*)malloc(sizeof(node));
    n->data = element;
    n->next = NULL;

    if(list == NULL)
    {
        list = n;
        return;
    }
    else if(n->data < list->data)
    {   
        list->prev=n;
        n->next = list;
        n->prev=NULL;
        list = n;
    }
    else
    {
        for(node* curr = list; curr != NULL; curr = curr->next)
        {
            if(curr->next == NULL)
            {
                curr->next = n;
                n->prev=curr;
                break;
            }
            if(n->data < curr->next->data)
            {
                n->next=curr->next;
                n->prev=curr;
                curr->next->prev=n;
                curr->next = n;

                break;
            }
        }
    }
}



void insert_after(int element, int pred)
{   
    node *n = (node*)malloc(sizeof(node));
    n->data = element;
    n->next = NULL;
    n->prev = NULL;

    node* curr = list;
    while(curr->data != pred && curr->next!=NULL)
    {
        curr = curr->next;
    }
    if (isSorted)
    {
        if (element<curr->data || element>curr->next->data)
        {
            printf("The list is now unsorted\n");
            isSorted=false;
        }
        
    }
    curr->next->prev=n;
    n->next = curr->next;
    curr->next = n;
    n->prev = curr;
}



void destroy(node* n)
{
    if(n == NULL)
    {
        printf("List destroyed, all data deleted\n");
        return;
    }
    destroy(n->next);
    free(n);
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


void delete_front(){

    if(list == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node* temp;
    temp = list;
    list = list->next;
    list->prev=NULL;
    free(temp);
}


void delete_back(){

    if(list == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node* curr = list;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next=NULL;
    free(curr);
}



void print_list(){

    if (list==NULL)
    {
        printf("The list is empty\n");
    }
    else{
        printf("The list is:");
        for (node*temp=list; temp!=NULL; temp=temp->next)
        {
            printf("%d ",temp->data);
        }
    }
}


bool find(int element){

    node* curr=list;
    int i=0;
    for(node* trav = list; trav != NULL; trav = trav->next)
    {   
        if(trav->data == element)
        {   
            curr=trav;
            //DEBUG printf("found the element: %d\n",trav->data);
            //DEBUG printf("found the element: %d\n",curr->data);
            break;
        }
        i++;
    }
    if (curr==NULL)
    {
        printf("The targeted element is not present");
        return false;
    }
    else {
        printf("found the element= %d at index=%d",curr->data,i);
        return true;
    }
}