#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // So luong dinh cua do thi

// Ham them canh vao danh sach ke
void addEdge(int adjList[V][V], int i, int j) {
    adjList[i][j] = 1;  // Them canh tu dinh i den dinh j
    adjList[j][i] = 1;  // Them canh tu dinh j den dinh i (do thi vo huong)
}

// Ham duyet do thi theo thuat toan BFS
void bfs(int adjList[V][V], int start) {
    bool visited[V] = {0}; // Mang danh dau cac dinh da duyet
    int queue[V]; // Hang doi de duyet do thi
    int front = 0, rear = 0; // Chi so dau va cuoi cua hang doi
    
    // Them dinh bat dau vao hang doi va danh dau la da duyet
    visited[start] = 1;
    queue[rear++] = start;
    
    printf("Thu tu duyet BFS: ");
    
    // Duyet do thi theo BFS
    while (front < rear) {
        int current = queue[front++]; // Lay dinh dau trong hang doi
        printf("%d ", current); // In dinh hien tai
        
        // Duyet cac dinh ke cua dinh hien tai
        for (int i = 0; i < V; i++) {
            if (adjList[current][i] == 1 && !visited[i]) {
                visited[i] = 1; // Danh dau dinh ke da duyet
                queue[rear++] = i; // Them dinh vao hang doi
            }
        }
    }
    printf("\n");
}

// Ham in danh sach ke
void printAdjList(int adjList[V][V]) {
    for (int i = 0; i < V; i++) {
        printf("Dinh %d: ", i);
        for (int j = 0; j < V; j++) {
            if (adjList[i][j] == 1) {
                printf("%d ", j); // In cac dinh ke
            }
        }
        printf("\n");
    }
}

int main() {
    int adjList[V][V] = {0}; // Khoi tao danh sach ke
    
    // Nhap so luong canh va cac canh
    addEdge(adjList, 0, 1); // Them canh tu dinh 0 den dinh 1
    addEdge(adjList, 0, 2); // Them canh tu dinh 0 den dinh 2
    addEdge(adjList, 1, 2); // Them canh tu dinh 1 den dinh 2
    addEdge(adjList, 2, 3); // Them canh tu dinh 2 den dinh 3

    // In danh sach ke
    printf("Danh sach ke cua do thi:\n");
    printAdjList(adjList);
    
    // Nhap dinh bat dau BFS
    int start;
    printf("Nhap dinh bat dau de thuc hien BFS (0-3): ");
    scanf("%d", &start);
    
    // Thuc hien duyet BFS tu dinh da cho
    bfs(adjList, start);

    return 0;
}

