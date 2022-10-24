#include <stdio.h>
#include <stdlib.h>

void def_arr(int arr[], int n);
void quicksort(int arr[], int l, int r);
int particion(int arr[], int l, int r);
void swap(int *arr, int *arrG);
void imprime_arr(int arr[], int n);

int main()
{
    int n;
    printf("Tam del arreglo: ");
    scanf("%d", &n);
    int arr[100];
    def_arr(arr,n);
    quicksort(arr,0,n-1);
    imprime_arr(arr,n);
    return 0;
}

void def_arr(int arr[], int n){
    printf("Datos del arreglo: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void quicksort(int arr[], int l, int r){
    if(r<=l){
        return;
    }
    int p=particion(arr, l, r);
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
}

int particion(int arr[], int l, int r){
    int i=l;
    for (int j=l;j<=r-1;j++){
        if(arr[j]<=arr[r]){
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

void swap(int *arr, int *arrG){
    int t=*arr;
    *arr=*arrG;
    *arrG=t;
}

void imprime_arr(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
        printf(" ");
    }
}
