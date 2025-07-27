#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;

}node;


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
        system("cls");
        printf("Select operation:\n prepend (p)\n append (a)\n insert_sorted (s)\n insert_after (i)\n destroy (d)\n delete_node (n)\n delete_front (f)\n delete_back (b)\n print_list (l)\n find (x)\n quit (q)\n\n====>");
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
            int pred;
            scanf("%d %d",&x,&pred);
            //insert_after(x,pred);
            break;

        // case 'd':
        //       
        //     scanf("%d",&x);
        //     destroy(x);
        //     break;

        case 'n':
              
            scanf("%d",&x);
            //delete_node(x);
            break;
        
        case 'f':
              
            //scanf("%d",&x);
            //delete_front();
            break;

        case 'b':
              
            //scanf("%d",&x);
            //delete_back();
            break;

        case 'l':
              
            //scanf("%d",&x);
            print_list();
            break;

        case 'x':
              
            scanf("%d",&x);
            //find(x);
            break;

        case 'q':
              
            scanf("%d",&x);
            loop=0;
            break;
    
            
        default:
            break;
        }
        printf("\ncontinue? ==>");
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

// void sort(){
//     node* last=list;
//     int n=0;
//     for (node*temp=list; temp!=NULL; temp=temp->next)
//     {
//         n++;
//         //printf("%d ",temp->data);
//     }
//     node* a1=list;
//     node* a2=list->next;
//     for (int i=0; i<n-1; i++)
//     {   
//         int swap=0;
//         for (int j = 0; j < n-1-i; j++)
//         {   
//             if (a1->data>a2->data)
//             {   
//                 printf("swapping %d and %d\n",a1->data,a2->data);
//                 node temp;
//                 temp.next=a2->next;
//                 temp.prev=a2->prev;
//                 a2->next=a1->next;
//                 a2->prev=a1->prev;
//                 a1->next=temp.next;
//                 a2->prev=temp.prev;
//                 swap++;
//             }
//             a1=a1->next;
//             a2=a2->next;
//         }
//         if (!swap)
//         {
//             break;
//         }   
//     }
// }

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
                printf("Swapping %d and %d\n", a1->data, a2->data);

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
        n->next = list;
        list = n;
    }
    else
    {
        for(node* curr = list; curr != NULL; curr = curr->next)
        {
            if(curr->next == NULL)
            {
                curr->next = n;
                break;
            }
            if(n->data < curr->next->data)
            {
                n->next = curr->next;
                curr->next = n;
                break;
            }
        }
    }
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