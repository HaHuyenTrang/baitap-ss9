#include<stdio.h>
#include<stdlib.h> 
//#define V 4
// them canh 
void addEdge(int** matrix, int i, int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
	
} 

// in 
void printMatrix(int** matrix, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
   int vertices, edges;

    // nhap so luong canh va dinh 
    printf("so luong dinh: ");
    scanf("%d", &vertices);
    printf("so luong canh: ");
    scanf("%d", &edges);

    // ma tran ke dong 
    int** matrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        matrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    // danh sach canh 
    printf("cac canh duoi gap dinh (0 1):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            addEdge(matrix, u, v);
        } else {
            printf("loi.\n");
            i--;
        }
    }

    // In 
    printf("ma tran ke cua do thi la:\n");
    printMatrix(matrix, vertices);


	for (int i = 0; i < vertices; i++) {
	    free(matrix[i]); // giai phong  
	}
	free(matrix); 

	return 0;
}
