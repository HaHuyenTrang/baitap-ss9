#include<stdio.h>
#include<limits.h> // Thu vien cho gia tri vo cung (INF)
#define V 4 // So luong dinh cua do thi

// Ham them canh vao ma tran ke
void addEdge(int matrix[V][V], int i, int j, int weight) {
    matrix[i][j] = weight;  // Them trong so cua canh tu dinh i den dinh j
    matrix[j][i] = weight;  // Vi do thi vo huong, nen them canh nguoc lai
}

// Ham in ma tran ke
void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INT_MAX) { // Kiem tra truong hop vo cung
                printf("INF\t");
            } else {
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Ham trien khai thuat toan Dijkstra
void dijkstra(int matrix[V][V], int start) {
    int dist[V]; // Mang luu tru khoang cach tu dinh nguon den cac dinh khac
    bool visited[V] = {0}; // Mang danh dau cac dinh da tham

    // Khoi tao khoang cach cua cac dinh: vo cung (INF) ngoai tru dinh nguon
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0; // Khoang cach tu dinh nguon den chinh no la 0

    // Tien hanh thuat toan Dijkstra
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;
        
        // Tim dinh chua tham co khoang cach nho nhat
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        
        // Danh dau dinh u da tham
        visited[u] = 1;

        // Cap nhat khoang cach cua cac dinh ke cua dinh u
        for (int v = 0; v < V; v++) {
            if (!visited[v] && matrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
    }

    // In ket qua khoang cach ngan nhat tu dinh nguon
    printf("Khoang cach ngan nhat tu dinh %d den cac dinh khac:\n", start);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("Dinh %d: INF\n", i); // Neu khong the den dinh i, in INF
        } else {
            printf("Dinh %d: %d\n", i, dist[i]); // In khoang cach ngan nhat
        }
    }
}

int main() {
    int matrix[V][V]; // Ma tran ke bieu dien do thi
    // Khoi tao ma tran ke voi gia tri vo cung (INF)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                matrix[i][j] = 0; // Khoang cach tu dinh den chinh no la 0
            } else {
                matrix[i][j] = INT_MAX; // Khoang cach ban dau giua cac dinh la vo cung
            }
        }
    }

    // Them cac canh vao do thi (dinh 1, dinh 2, trong so)
    addEdge(matrix, 0, 1, 10);
    addEdge(matrix, 0, 2, 5);
    addEdge(matrix, 1, 2, 2);
    addEdge(matrix, 1, 3, 1);
    addEdge(matrix, 2, 3, 9);

    // In ma tran ke
    printf("Ma tran ke cua do thi:\n");
    printMatrix(matrix);

    // Nhap dinh nguon va thuc hien thuat toan Dijkstra
    int start;
    printf("Nhap dinh nguon: ");
    scanf("%d", &start);
    dijkstra(matrix, start);

    return 0;
}

