#include <iostream>
using namespace std;
#define MAX_SIZE 10
#define ERR_VAL 999999.0

struct stack {
    int8_t TOP;
    float items[MAX_SIZE];
};

// Function Prototypes
void push(stack*, float);
float pop(stack*);
bool isEmpty(stack*);
bool isFull(stack*);
float peek(stack*);
void newStack(stack*);
void printStack(stack*);

int main () {
    stack* s = new stack;
    newStack(s);

    for (int i=0; i<10; i++) {
        push(s, i);
    }
    printStack(s);

    cout << "Popping " << pop(s) << endl;
    cout << "Popping " << pop(s) << endl;
    printStack(s);

    return 0;
}

void newStack (stack* s) {
    s->TOP = -1;
}

bool isEmpty (stack* s) {
    if (s->TOP == -1)
        return true;
    return false;
}

bool isFull (stack* s) {
    if (s->TOP >= MAX_SIZE - 1)
        return true;
    return false;
}

void push(stack* s, float newItem) {
    if (!isFull(s)) {
        s->TOP++;
        s->items[s->TOP] = newItem;
    }
    else
        cout << "Stack size exceeded!\n";
}

float pop (stack* s) {
    if (!isEmpty(s)) {
        float r = s->items[s->TOP];
        s->TOP--;
        return r;
    }
    
    cout << "Stack is empty :(\n";
    return ERR_VAL;

}

float peek (stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->TOP];
    }

    cout << "Stack is empty :(\n";
    return ERR_VAL;
}

void printStack(stack* s) {
    int8_t len = s->TOP + 1;
    cout << "First In -> ";
    for (int i=0; i<len; i++) {
        cout << s->items[i] << " -> ";
    }
    cout << "\n";
}