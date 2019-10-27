#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int key;
    struct node *next;
}node;

node *head;

struct node * linit(){
    head = (struct node *) malloc (sizeof *head);
    head->next = NULL;
    head->key = 0;
}

int isempty(struct node * t){

    if(t->next == NULL) {
        printf("Liste ist leer.\n\n");
        return 1;
    }
    return 0;
}

void linsert(struct node * t, int key){

    if(t == NULL){
        printf("Fehler Passiert");
        exit(1);
    }

    node *new = (struct node *) malloc(sizeof(struct node));

    if(t->next == NULL) {
        new->key = key;
        new->next = t->next;
        t->next = new;
    }else{

    while(t->next !=NULL && t->next->key < new->key){
        t = t->next;
    }
    new->next = t->next;
    t->next = new;
    }

}

int ldelete(struct node * t, int key){

    if(isempty(t))
        return 1;

    node *tmp;

    while(t != NULL){
        if(t->key == key){
            tmp = t->next;
            printf("%d wurde geloescht!",key);
            t->next = tmp->next;
            return 1;
        }
        t = t->next;
    }

    return 0;
}


void printList(struct node * t){

    if(isempty(t))
        return;

    node * current = t->next;

    printf("\n\n");
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n\n");
}


int main() {

    int menu, value,loop = 1;
    linit();

while(loop){
    printf("1.Sortiertes Einfuegen eines Elementes \n"
           "2.Loeschen und Ausgeben des Elementes mit Schluessel key \n"
           "3.Ausgeben der Liste\n"
           "4.Beenden \n\n");

    if (scanf("%d",&menu)){

        switch (menu) {
            case 1:
                printf("Key eingeben:\n");
                scanf("%d",&value);
                linsert(head,value);
                break;

            case 2:
                printf("Key zum loeschen eingeben:\n\n");
                scanf("%d",&value);
                ldelete(head,value);
                break;

            case 3: printList(head);
            break;

            case 4: loop = 0;
            break;

            default: break;
        }
    }

}
return 0;
}