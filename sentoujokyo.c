#include <stdio.h>
#include <stdlib.h>

struct node{
    char element;
    struct node *next;
};

struct node *initlist() {
    struct node *n;
      n=(struct node*)malloc(sizeof(struct node));
      n->next=NULL;
    return n;
}

void insert(struct node *p, char x) {
 struct node *n; 
     n=p;
  
     while(n->next!=NULL){
      n=n->next;
      }
      n->next=(struct node*)malloc(sizeof(struct node));
      n->next->element=x;
      n->next->next=NULL;

}

void printlist(struct node *p) {
    p = p->next;
    while (p) {
        putchar(p->element);
        p = p->next;
    }
    putchar('\n');
}

void remove_1st(struct node *p) {
  struct node *q = p->next->next;
  struct node *prev=p->next;
  struct node *r;
  while(q!= NULL){
    if(q->element == p->next->element){
    prev->next=q->next;
    free(q);
    q=q->next;
    }
    else{
    prev = q;
    q = q->next;
    }
  }
r= p->next;
p->next=r->next;
free(r);
}
int main(int argc, char *argv[]) {
    struct node *list, *head;
    char *p;

    if (argc<2)
        exit(-1);

    list = initlist();
    p = argv[1];
    for (; *p; p++)
        insert(list, *p);

    remove_1st(list);
    printlist(list);

    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
    return 0;
}

