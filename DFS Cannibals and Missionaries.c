#include <stdio.h>

typedef struct{
    int m,c,boat;
} State;

State stack[100];
int top = -1;

void push(State s){
    stack[++top] = s;
}

State pop(){
    return stack[top--];
}

int main(){

    State start = {3,3,0};
    push(start);

    while(top >= 0){

        State cur = pop();

        printf("State: (%d,%d,%d)\n",cur.m,cur.c,cur.boat);

        if(cur.m==0 && cur.c==0 && cur.boat==1){
            printf("Goal reached\n");
            break;
        }

        State next = {cur.m-1,cur.c,cur.boat^1};

        if(next.m >= 0)
            push(next);
    }

    return 0;
}
