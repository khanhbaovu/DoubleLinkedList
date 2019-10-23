#include <iostream>
#include <stdio.h>
using namespace std;

struct hitman {
    char name [10];
    int id;
};

struct node {
    hitman info;
    node *next;
   node *behind;
};

class killerList {
public:
    static int num;
    killerList();
    ~killerList();
    friend void khanh();
    node *createNode();
    void addfirst();
    void addlast();
    void seefromfirst();
    void seefromlast();
    void addx();
private:
    node *first;
    node *last;
};
int killerList::num = 0;

killerList::killerList() {
    last = NULL;
    first = NULL;
}
killerList::~killerList() {
   cout<<"END";
}
node *killerList::createNode(){
    node *p = new node;
    num++;
    cout<<"Nhap ten: ";
    fflush(stdin);
    cin.getline(p->info.name, 10);
    cout<<"Nhap id: ";
    cin>>p->info.id;
    return p;
}

void killerList::addfirst() {
    node *k;
    k = createNode();
    if(first == NULL) {
        first = last = k;
    }
    else {
        k->next = first;
        first->behind = k;
        first = k;
    }
}

void killerList::addlast() {
    node *k;
    k = createNode();
    if(last == NULL) {
        first = last = k;
    }
    else {
        k->behind = last;
        last->next = k;
        last = k;
    }
}

void killerList::addx() {
   node *p = first;
   node *j;
   node *n = createNode();
   int c=1, k;
   cout<<"VI TRI: ";
   cin>>k;
   while(c != k) {
    j = p;
    p = p->next;
    c++;
   }
   n->next = p;
   p->behind = n;
   j->next = n;
   n->behind = j;
}
 void killerList::seefromfirst() {
  for(node *k = first; k!=NULL; k = k->next) {
    cout<<"Ten HITMAN: "<<k->info.name<<endl;
    cout<<"ID: "<<k->info.id<<endl;
  }
 }

 void killerList::seefromlast() {
  for(node *k = last; k!=NULL; k = k->behind) {
    cout<<"Ten HITMAN: "<<k->info.name<<endl;
    cout<<"ID: "<<k->info.id<<endl;
  }
 }
int main()
{
    killerList kl;

    int m;

    while(m){

    cout<<"Nhap m: ";
    cin>>m;

    switch (m) {
      case 1:
       {
          kl.addfirst();
          cout<<"----------"<<endl;
          break;
       }
      case 2:
       {
          kl.addlast();
          cout<<"----------"<<endl;
          break;
       }
      case 3:
       {
          kl.seefromfirst();
          cout<<"----------"<<endl;
          break;
       }
      case 4:
       {
          kl.seefromlast();
          cout<<"----------"<<endl;
          break;
       }
      case 5:
       {
          kl.addx();
          cout<<"----------"<<endl;
          break;
       }
    }
    }

    return 0;
}
