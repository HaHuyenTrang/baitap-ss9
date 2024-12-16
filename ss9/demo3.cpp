#include<stdio.h>
#define MAX 100

//	khai bao danh sach ke

int graph[MAX][MAX];
int visted[MAX];
int queue[MAX];
int  front = -1;
int rear = -1;

//	them vao hang doi
void enqueue(int value){
	if(rear == MAX -1){
		return;
	}
	if(front == -1){
		front = 0;
	}
	queue[++rear] = value;
}

//	lay phan tu khoi hang doii
int dequeue(){
	if(front == -1 || front > rear){
		return -1;
	}
	return queue[front++];
}

//	thuat toan
void BFSFunction(int start, int n){
	for(int i = 0; i < n; i++){
		visted[i] = 0;
	}
	enqueue(start);
	visted[start] = 1;
	while(front <= rear){
		int current = dequeue();
		printf("%d", current);
		for(int i = 0; i< n; i++){
			if(graph[current][i] == 1 && !visted[i]){
				enqueue(i);
				visted[i] = 1;
				
			}
		}
	} 
}

int main(){
	reuturn 0;
}
