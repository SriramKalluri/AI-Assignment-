#include <stdio.h>

typedef struct {
    int m,c,boat;
} State;

State queue[100];
int front=0,rear=0;

void enqueue(State s){
    queue[rear++] = s;
}

State dequeue(){
    return queue[front++];
}

int isGoal(State s){
    return (s.m==0 && s.c==0 && s.boat==1);
}

int main(){

    State start = {3,3,0};
    enqueue(start);

    while(front < rear){

        State cur = dequeue();

        printf("State: (%d,%d,%d)\n",cur.m,cur.c,cur.boat);

        if(isGoal(cur)){
            printf("Goal reached\n");
            break;
        }

        State next = {cur.m-1,cur.c,cur.boat^1};

        if(next.m >= 0)
            enqueue(next);
    }

    return 0;
}
