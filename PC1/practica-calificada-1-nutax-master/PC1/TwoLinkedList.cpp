//
// Created by ruben on 4/12/19.
//

#include "TwoLinkedList.h"
#include <string>
#include <fstream>

UTEC::TwoLinkedList::TwoLinkedList() {
    head1 = nullptr;
    head2 = nullptr;
    tail1 = nullptr;
    tail2 = nullptr;
    tail = nullptr;
}

void UTEC::TwoLinkedList::push_back1(int v) {
    if (!is_merge()) {
        Node *temp = new Node(v);
        if (empty1()) {
            tail1 = temp;
            head1 = temp;
        } else {
            tail1->next = temp;
            tail1 = temp;
        }
    }else{
        push_back(v);
    }
}

void UTEC::TwoLinkedList::push_back2(int v) {
    if (!is_merge()) {
        Node *temp = new Node(v);
        if (empty2()) {
            tail2 = temp;
            head2 = temp;
        } else {
            tail2->next = temp;
            tail2 = temp;
        }
    }else{
        push_back(v);
    }
}


string UTEC::TwoLinkedList::getlist(int v) {
    using namespace std;
    string s="";
    if (v==0){
        if (is_merge()){

                Node* temp = tail1->next;
                while(temp!=tail){
                    string n = to_string(temp->value);
                    s = s + n + " ";
                    temp=temp->next;
                }
                string n = to_string(temp->value);
                s = s + n + " ";

        }
    }
    if (v==1 && !empty1()){
        Node* temp = head1;
        while(temp!=tail1){
            string n = to_string(temp->value);
            s = s + n + " ";
            temp=temp->next;
        }
        string n = to_string(temp->value);
        s = s + n + " ";
    }
    if (v==2 && !empty2()){
        Node* temp = head2;
        while(temp!=tail2){
            string n = to_string(temp->value);
            s = s + n + " ";
            temp=temp->next;
        }
        string n = to_string(temp->value);
        s = s + n + " ";
    }
    return s;
}



string UTEC::TwoLinkedList::merge(int v) {
    if (is_merge()) {
        return std::__cxx11::string("Operación duplicada");
    }else{
        Node* temp = new Node(v);
        if (!is_merge()) {
            tail1->next = temp;
            tail2->next = temp;
            tail = temp;
        }
        return std::__cxx11::string("Operación Exitosa");
    }
}




bool UTEC::TwoLinkedList::empty1() {
    return head1 == nullptr;
}

bool UTEC::TwoLinkedList::empty2() {
    return head2 == nullptr;
}

bool UTEC::TwoLinkedList::is_merge() {
    return (tail1!=nullptr && tail2!=nullptr && tail1->next==tail2->next);
}

void UTEC::TwoLinkedList::push_back(int v) {
    Node *temp = new Node(v);
    tail->next = temp;
    tail = temp;
}

void UTEC::TwoLinkedList::save(string a) {
    using namespace std;
    ofstream archivo;
    archivo.open(a);
    string s1 = getlist(1);
    for (int i = 0; i<(s1.length()-1); i++){
        if (s1[i]==' '){
            s1[i]=',';
        }
    }
    string s2 = getlist(2);
    for (int i = 0; i<(s2.length()-1); i++){
        if (s2[i]==' '){
            s2[i]=',';
        }
    }
    string s0 = getlist(0);
    for (int i = 0; i<(s0.length()-1); i++){
        if (s0[i]==' '){
            s0[i]=',';
        }
    }
    archivo<<s1<<endl<<s2<<endl<<s0;
    archivo.close();
}

UTEC::Node *UTEC::TwoLinkedList::search(int v) {
    Node* resultado = nullptr;
    Node* temp = head1;
    while(temp!=tail1){
        if (temp->value==v) {
            resultado = temp;
        }
        temp=temp->next;
    }
    if (temp->value==v){
        resultado = temp;
    }
    temp = head2;
    while(temp!=tail2){
        if (temp->value==v) {
            resultado = temp;
        }
        temp=temp->next;
    }
    if (temp->value==v){
        resultado = temp;
    }
    return resultado;
}


UTEC::Node::Node(int value) : value(value) {}
