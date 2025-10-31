// lecture assignmnet
struct node{
    datatype data;
    int priority;
};

struct PQ{
    node P[Max];
    int front;
    int rear;
};

void Move_Q_Down(struct PQ* Q, int start)
{
    if (Q->front == -1 || start < 0 || start >= Max){
        return;
    }
    int i = start;
    while (i != Q->rear)
    {
        int next = (i + 1) % Max;  
        Q->P[i] = Q->P[next];
        i = next;
    }

    Q->rear = (Q->rear - 1 + Max) % Max;
    if (Q->front == (Q->rear + 1) % Max)
    {
        Q->front = -1;
        Q->rear = -1;
    }
}
