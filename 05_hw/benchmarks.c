#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"
#include "stack.c"

void benchmark_push(Stack* stack, int ITEMS){
    //Start the clock
    clock_t start = clock();

    //Push X elements
    for (int i = 0; i < ITEMS; i++){
        push(stack, i);
    }

    //Stop the clock
    clock_t end = clock();

    //Calculate the time
    float benchmark_time = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to complete push benchmark (%d elements): %.5f seconds\n", ITEMS, benchmark_time);

}

void benchmark_pop(Stack* stack, int ITEMS){

    //Start the clock
    clock_t start = clock();


    //Pop X elements
    for (int i = 0; i < ITEMS; i++){
        pop(stack);
    }

    //Stop the clock
    clock_t end = clock();

    //Calculate the time
    float benchmark_time = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to complete pop benchmark (%d elements): %.5f seconds\n", ITEMS, benchmark_time);

}

int main(){

    //Test with different num of elements
    int NUMBER_TESTS[] = {1000, 10000, 1000000};
    
    
    //Do 3 benchmarks
    for (int i = 0; i < 3; i++){
        //Stack init
        Stack stack;
        initStack(&stack);

        benchmark_push(&stack, NUMBER_TESTS[i]);

        for (int i = 0; i < NUMBER_TESTS[i]; i++){
            push(&stack, i);
        }

        benchmark_pop(&stack, NUMBER_TESTS[i]);
        
        destroyStack(&stack);
    }
    
    return 0;  

}