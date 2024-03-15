#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[5000][5000];
int main()
{
    int n;
    int edge=0,degree=0;
    srand(time(0));
    printf("Input the number of vertex: ");
    scanf("%d",&n);
    float time=0.0;
    clock_t begin = clock();
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            arr[i][j]=rand()%2;
            arr[j][i]=arr[i][j];
        }
    }
    printf("\nOur matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(arr[i][j]==1) {
                edge++;
            }
        }
    }
    printf("The number of edges: %d",edge);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]==1) {
                degree++;
            }
            if(i==j&&arr[i][j]==1) {
                degree++;
            }
        }
    }
    printf("\nDegrees of all vertices: %d",degree);
    clock_t end = clock();
    time=(float)(end - begin)/CLOCKS_PER_SEC;
    time=time*1000;
    int hand=edge*2;
    if(hand==degree) {
        printf("\nHandshaking theorem is working.\n");
    }
    if(hand!=degree) {
        printf("\nHandshaking theorem is not working.\n");
    }
    printf("Computational time is : %.4f ms", time);
    return 0;
}
