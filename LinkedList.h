#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <list>

class LinkedList {
private:
    struct Node {
        char data;
        Node *next;
    };

    Node *createNode(char data);

public:

    Node *head;

    LinkedList();

    ~LinkedList();

    void insertNodeEnd(char data);

    void insertStringAtPosition(const char *str);

    void displayList();

    void clear();

    void appendText();

    void addNewLine();

    void saveToFile();

    void readFromFile();

    void insertTextAtPosition();

    void searchSubstring();

    void Delete();

    void Cut();

    void Paste();

    void Copy();

    void InsertWithReplacement();

    void addToStack();

    void undo();

    void redo();

    void cursor();



};

#endif
