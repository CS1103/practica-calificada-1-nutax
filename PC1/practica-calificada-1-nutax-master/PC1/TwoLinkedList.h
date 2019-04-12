//
// Created by ruben on 4/12/19.
//

#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

namespace UTEC {
    struct Node {
        int value;
        Node *next;

        Node(int value);
    };

    class TwoLinkedList {
        Node* head1;
        Node* head2;
        Node* tail1;
        Node* tail2;
        Node* tail;
    public:
        TwoLinkedList();
        void push_back1(int v);
        void push_back2(int v);
        void push_back(int v);
        string getlist(int v);
        string merge(int v);
        bool empty1();
        bool empty2();
        bool is_merge();
        void save(string a);
        Node* search(int v);

};
}


#endif //PC1_TWOLINKEDLIST_H
