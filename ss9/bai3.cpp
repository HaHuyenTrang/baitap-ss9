#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // So luong dinh cua do thi

// Ham them canh vao ma tran ke
void addEdge(int matrix[V][V], int i, int j, bool directed) {
    matrix[i][j] = 1; // Them canh i -> j
    if (!directed) {
        matrix[j][i] = 1; // Neu do thi vo huong, them canh nguoc lai j -> i
    }
}

// Ham DFS kiem tra chu ky cho do thi co huong
bool dfsDirected(int matrix[V][V], int visited[V], int recStack[V], int v) {
    visited[v] = 1; // Danh dau dinh da duyet
    recStack[v] = 1; // Danh dau dinh hien tai trong ngan xep de quy

    for (int i = 0; i < V; i++) {
        if (matrix[v][i] == 1) { // Neu co canh tu v den i
            if (!visited[i] && dfsDirected(matrix, visited, recStack, i)) {
                return true; // Neu i chua duyet va tim thay chu ky, tra ve true
            } else if (recStack[i]) {
                return true; // Phat hien chu ky khi dinh i dang trong ngan xep de quy
            }
        }
    }

    recStack[v] = 0; // Quay lai, bo dinh khoi ngan xep de quy
    return false;
}

// Ham kiem tra chu ky trong do thi co huong
bool containsCycleDirected(int matrix[V][V]) {
    int visited[V] = {0}; // Mang danh dau cac dinh da duyet
    int recStack[V] = {0}; // Mang danh dau cac dinh trong ngan xep de quy

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsDirected(matrix, visited, recStack, i)) {
                return true; // Tim thay chu ky
            }
        }
    }
    return false; // Khong tim thay chu ky
}

// Ham DFS kiem tra chu ky cho do thi vo huong
bool dfsUndirected(int matrix[V][V], int visited[V], int parent, int v) {
    visited[v] = 1; // Danh dau dinh da duyet

    for (int i = 0; i < V; i++) {
        if (matrix[v][i] == 1) { // Neu co canh tu v den i
            if (!visited[i]) {
                if (dfsUndirected(matrix, visited, v, i)) {
                    return true; // Neu i chua duyet va tim thay chu ky
                }
            } else if (i != parent) {
                return true; // Phat hien chu ky khi i da duyet va khong phai la cha cua v
            }
        }
    }
    return false;
}

// Ham kiem tra chu ky trong do thi vo huong
bool containsCycleUndirected(int matrix[V][V]) {
    int visited[V] = {0}; // Mang danh dau cac dinh da duyet

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsUndirected(matrix, visited, -1, i)) {
                return true; // Tim thay chu ky
            }
        }
    }
    return false; // Khong tim thay chu ky
}

// Ham in ma tran ke
void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]); // In gia tri ma tran kieu ma tran ke
        }
        printf("\n"); // Xuat hien dong moi
    }
}

int main() {
    int matrix[V][V] = {0}; // Khoi tao ma tran ke

    // Nhap cac canh
    addEdge(matrix, 0, 1, false); // Them canh (0-1)
    addEdge(matrix, 0, 2, false); // Them canh (0-2)
    addEdge(matrix, 1, 2, false); // Them canh (1-2)
    addEdge(matrix, 2, 3, false); // Them canh (2-3)

    // In ma tran ke
    printf("Ma tran ke cua do thi vo huong:\n");
    printMatrix(matrix);

    // Kiem tra chu ky
    if (containsCycleUndirected(matrix)) {
        printf("Do thi vo huong co chu ky.\n");
    } else {
        printf("Do thi vo huong khong co chu ky.\n");
    }

    // Reset ma tran ke cho do thi co huong (neu can)
    int matrixDirected[V][V] = {0}; 
    addEdge(matrixDirected, 0, 1, true); // Them canh (0 -> 1)
    addEdge(matrixDirected, 1, 2, true); // Them canh (1 -> 2)
    addEdge(matrixDirected, 2, 0, true); // Them canh (2 -> 0)

    // In ma tran ke
    printf("Ma tran ke cua do thi co huong:\n");
    printMatrix(matrixDirected);

    // Kiem tra chu ky trong do thi co huong
    if (containsCycleDirected(matrixDirected)) {
        printf("Do thi co huong co chu ky.\n");
    } else {
        printf("Do thi co huong khong co chu ky.\n");
    }

    return 0;
}

