/*Write a function rotate (int a[], int n, char d, int cr) to rotate given array elements.
The function will take the array, number of elements in the array, direction of rotation(l-left r-right) and count of rotation( how many times to rotate)
Eg:
Input array a[]=2 3 4 5 6 7 rotate(a,6,l,2)
output:4 5 6 7 2 3 rotate(a,6,r,2) output:6 7 2 3 4 5*/
#include <stdio.h>
#include <stdlib.h>

void rotate(int a[], int n, char d, int cr);

int main(){
    int n, i, cr;
    char d;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    if (n <= 0){
        printf("You need atleast one element in the array.\n");
        exit(0);
    }
    int a[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the direction of rotation l or r: ");
    scanf(" %c", &d);
    printf("Enter the number of rotations: ");
    scanf("%d", &cr);
    rotate(a, n, d, cr);
    printf("The rotated array is ");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void rotate(int a[], int n, char d, int cr){

    int rotations = cr % n;

    if (d == 'l'){
        int temp[rotations];
        int i;
        for(i = 0; i < rotations; i++){
            temp[i] = a[i];
        }
        for(i = 0; i < n - rotations; i++){
            a[i] = a[i + rotations];
        }
        for(i = 0; i < rotations; i++){
            a[n - rotations + i] = temp[i];
        }
    }
    else if (d == 'r'){
        int temp[rotations];
        int i;
        for(i = 0; i < rotations; i++){
            temp[i] = a[n - rotations + i];
        }
        for(i = n - rotations - 1; i >= 0; i--){
            a[i + rotations] = a[i];
        }
        for(i = 0; i < rotations; i++){
            a[i] = temp[i];
        }
    }
    else{
        printf("Invalid direction");
        exit(0);
    }

}
