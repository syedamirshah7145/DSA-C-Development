#include <iostream>

using namespace std;

struct edge{
    int data;
    edge *next;
    int weight;
};

struct node{
    int data;
    edge *head;
    edge *tail;
    node *next;
};

node *head = nullptr;
node *tail = nullptr;

void insertVertex(int vdata){
    node *temp = new node;
    temp->data = vdata;
    temp->head = nullptr;
    temp->tail = nullptr;

    if(head == nullptr){
        temp->next = nullptr;
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
    }
}

bool checkVName(int data){
    node *temp = head;
    while(temp->data != data && temp!=tail){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Not found!";
        return false;
    }
    return true;
}

void addEdge(int vData,int eData,int weight){
    node *temp = head;
    while(temp->data != vData && temp != nullptr){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Not Found!";
        return;
    }
    if(temp != nullptr && checkVName(eData)){
        edge *etemp = new edge;
        etemp->data = eData;
        etemp->weight = weight;
        etemp->next = nullptr;
        if(temp->head == nullptr){
            temp->head = temp->tail = etemp;
        }
        else{
            temp->tail->next = etemp;
            temp->tail = etemp;
        }
    }
}

void deleteEdge(int vData,int eData){
    node *temp = head;
    while(temp != nullptr){
        if(temp->data == vData){
            break;
        }
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Vertex Not Found!";
        return;
    }
    else{
        edge *etemp = temp->head;
        if(etemp->data == eData){
            if(temp->head == temp->tail){
                temp->head = temp->tail = nullptr;
                return;
            }
            temp->head = temp->head->next;
            return;
        }
        etemp = etemp->next;
        while(etemp != nullptr){
            if(etemp->data == eData){
                etemp = etemp->next;
                return;
            }
            etemp = etemp->next;
        }
        if(etemp == nullptr){
            cout<<"Edge Not Found!"<<endl;
        }
    }
}

void display(){
    node *temp = head;
    edge *etemp;
    while(temp != nullptr){
        cout<<temp->data<<" : ";
        etemp = temp->head;
        while(etemp != nullptr){
            cout<<"("<<etemp->data<<" , "<<etemp->weight<<")";
            etemp = etemp->next;
        }
        cout<<endl;
        temp = temp->next;
    }
}

int main(){
    insertVertex(1);
    insertVertex(2);
    insertVertex(0);
    addEdge(1,0,7);
    addEdge(0,2,8);
    addEdge(1,2,9);
    display();
}