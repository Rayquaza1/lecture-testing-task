#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "stack.c"


//Test destroyStack()
void test_destroyStack(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);

    destroyStack(&stack);
    assert(stack.top == NULL);

    printf("test_destroyStack() passed\n");

}

void test_destroyStack_empty(){
    Stack stack;
    initStack(&stack);

    destroyStack(&stack);
    assert(stack.top == NULL);

    printf("test_destroyStack_empty() passed\n");

}

//Test push()
void test_push(){

    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    assert(stack.top != NULL);

    printf("test_push() passed\n");

}

//Test pop()
void test_pop(){

    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    pop(&stack);
    assert(stack.top == NULL);

    printf("test_pop() passed\n");

}

void test_pop_empty(){

    Stack stack;
    initStack(&stack);

    pop(&stack);

    printf("test_pop_empty() passed\n");

}

//Test searchByValue()
void test_searchByValue_existing(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    Node* result = searchByValue(&stack, 5);
    assert(result != NULL && result->data == 5);

    printf("test_searchByValue_existing() passed\n");

}

void test_searchByValue_nonexisting(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    Node* result = searchByValue(&stack, 10);
    assert(result == NULL);

    printf("test_searchByValue_nonexisting() passed\n");

}

void test_searchByValue_empty(){
    Stack stack;
    initStack(&stack);

    Node* result = searchByValue(&stack, 10);
    assert(result == NULL);

    printf("test_searchByValue_empty() passed\n");

}

//Test searchByIndex()
void test_searchByIndex_existing(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    Node* result = searchByIndex(&stack, 2);
    assert(result != NULL && result->data == 3);

    printf("test_searchByIndex_existing() passed\n");

}

void test_searchByIndex_nonexisting(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    Node* result = searchByIndex(&stack, 10);
    assert(result == NULL);

    printf("test_searchByIndex_nonexisting() passed\n");

}

void test_searchByIndex_empty(){
    Stack stack;
    initStack(&stack);

    Node* result = searchByIndex(&stack, 10);
    assert(result == NULL);

    printf("test_earchByIndex_empty() passed\n");

}

//Test getTop()
void test_getTop(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    Node* result = getTop(&stack);
    assert(result != NULL && result->data == 5);

    printf("test_getTop() passed\n");

}

void test_getTop_empty(){
    Stack stack;
    initStack(&stack);

    Node* result = getTop(&stack);
    assert(result == NULL);

    printf("test_getTop_empty() passed\n");

}

//Test traverseStack()
void test_traverseStack(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("Expected result: 5 4 3 2 1\n");
    printf("Function output:");
    traverseStack(&stack);

    printf("test_traverseStack() passed\n");

}

void test_traverseStack_empty(){
    Stack stack;
    initStack(&stack);

    printf("Expected result: ' '\n");
    printf("Function output:");
    traverseStack(&stack);

    printf("test_traverseStack_empty() passed\n");

}

//Test isEmpty()
void test_isEmpty(){
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    assert(isEmpty(&stack) == false);

    printf("test_isEmpty() passed\n");
}

void test_isEmpty_empty(){
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    printf("test_isEmpty_empty() passed\n");
}

int main(){

    printf("\n");
    test_destroyStack();
    test_destroyStack_empty();

    printf("\n");
    test_push();
    test_pop();
    test_pop_empty();

    printf("\n");
    test_searchByValue_existing();
    test_searchByValue_nonexisting();
    test_searchByValue_empty();

    printf("\n");
    test_searchByIndex_existing();
    test_searchByIndex_nonexisting();
    test_searchByIndex_empty();

    printf("\n");
    test_getTop();
    test_getTop_empty();

    printf("\n");
    test_traverseStack();
    test_destroyStack_empty();

    printf("\n");
    test_isEmpty();
    test_isEmpty_empty();
    
    printf("\n");
    printf("All tests passed\n");

}