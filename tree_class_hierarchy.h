#ifndef TREE_CLASS_HIERARCHY_H
#define TREE_CLASS_HIERARCHY_H

#include <iostream>

class BaseHolder {
public:
    virtual void* get() { return nullptr; };
    virtual void set(void* x) {};
    virtual void print() {};
    virtual ~BaseHolder() {}
};

class IntHolder : public BaseHolder {
    int a;
public:
    void set(int x) { a = x; }
    void* get() { return &a; }
    void print() { printf("%d\n", a); }
    IntHolder(int x) {
        set(x);
    }
    ~IntHolder() {}
};

class CharArrayHolder : public BaseHolder {
    char * a = nullptr;
public:
    void set(char* x) 
    { 
        a = new char[10]; 
        for (int i = 0; i < 10; i++)
            a[i] = x[i]; 
    }
    void* get() { return &a; }
    void print() { printf("%s\n", a); }
    CharArrayHolder(char* x) { set(x); }
    ~CharArrayHolder() {
    //    delete get();
    }
};

class DoubleHolder : public BaseHolder {
    double a;
public:
    void set(double x) { a = x; }
    void* get() { return &a; }
    void print() { printf("%f\n", a); }
    DoubleHolder(double x) { set(x); }
    ~DoubleHolder() {}
};

class Tree {
    struct tree_node {
        ~tree_node() {
            delete value;
        }
        BaseHolder* value = nullptr;
        tree_node* left = nullptr;
        tree_node* right = nullptr;
    };

    tree_node* top = nullptr;

public:
    void push(BaseHolder* value, tree_node* curr = nullptr)
    {
        if (top != nullptr && curr == nullptr)
            curr = top;

        if (curr == nullptr)
        {
            curr = new tree_node;
            if (top == nullptr)
                top = curr;
            curr->value = value;
        }
        else
        {
            if (curr->value == nullptr)
            {
                curr->value = value;
            }
            else {
                if (rand() % 2)
                {
                    if (curr->left == nullptr)
                        curr->left = new tree_node;
                    push(value, curr->left);
                }
                else
                {
                    if (curr->right == nullptr)
                        curr->right = new tree_node;
                    push(value, curr->right);
                }
            }  
        }
    }

    void show(tree_node* curr = nullptr)
    {
        if (curr == nullptr)
        {
            if(top == nullptr)
            {
                std::cout << "Empty tree\n";
                return;
            } 
            else 
            {
                curr = top;
            }
        }
        
        curr->value->print();
        if (curr->left != nullptr)
        {
            show(curr->left);
        }
            
        if (curr->right != nullptr)
        {
            show(curr->right);
        }
    }

    void clear(tree_node* curr = nullptr)
    {
        if (curr == nullptr && top != nullptr)
            curr = top;

        if (curr != nullptr)
        {
            if (curr->left != nullptr)
                clear(curr->left);
            if (curr->right != nullptr)
                clear(curr->right);
            delete curr;
        }
    }

    ~Tree() {
        clear();
    }
};

#endif