#include <stdio.h>
#include <stdlib.h>

// vector.h
typedef struct Vector{
    int *arr;
    int size;
    int capacity;
} vector;
 
void Init(vector *vec, int size, int number);
int Size(vector *vec);
int Capacity(vector *vec);
void Push_back(vector *vec, int number);
void Pop_back(vector *vec);
void Clear(vector *vec);
void Shrink_to_fit(vector *vec);
void Reserve(vector *vec, int capicity);
void Resize(vector *vec, int size, int number);

// vector.c
void Init(vector *vec, int size, int number){
    vec->arr = malloc(size * sizeof(int));
    vec->size = size;
    vec->capacity = size;
    for (int i = 0; i < vec->size; i++) {
        vec->arr[i] = number;
    }
}
 
int Size(vector *vec){
    return vec->size;
}
 
int Capacity(vector *vec){
    return vec->capacity;
}
 
void Push_back(vector *vec, int number){
    if (vec->size == vec->capacity) {
        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        vec->arr = realloc(vec->arr, vec->capacity * sizeof(int));
    }
    vec->arr[vec->size] = number;
    vec->size++;
}
 
void Pop_back(vector *vec){
    if (vec->size > 0) vec->size--;
}
 
void Clear(vector *vec){
    free(vec->arr);
    vec->arr = NULL;
    vec->size = 0;
}
 
void Shrink_to_fit(vector *vec){
    vec->capacity = vec->size;
}
 
void Reserve(vector *vec, int capacity){
    if (capacity > vec->capacity) {
        vec->capacity = capacity;
        vec->arr = realloc(vec->arr, vec->capacity * sizeof(int));
    }
}
 
void Resize(vector *vec, int size, int number){
    if (vec->size < size) {
        vec->capacity = ((vec->size * 2) >= size) ? vec->size * 2 : size;
    }
    vec->size = size;
    vec->arr = realloc(vec->arr, vec->capacity * sizeof(int));
    for (int i = 0; i < size; i++) {
        vec->arr[i] = number;
    }
}

// main.c
int main() {
    int N = 0;
    scanf("%d", &N);
    vector vec;
    while(N--) {
        int operation = 0;
        scanf("%d", &operation);
        int size = 0, number = 0, capacity = 0;
        switch(operation) {
            case 0:
                scanf("%d %d", &size, &number);
                Init(&vec, size, number);
                break;
            case 1:
                printf("%d\n", Size(&vec));
                break;
            case 2:
                printf("%d\n", Capacity(&vec));
                break;
            case 3:
                scanf("%d", &number);
                Push_back(&vec, number);
                break;
            case 4:
                Pop_back(&vec);
                break;
            case 5:
                Clear(&vec);
                break;
            case 6:
                Shrink_to_fit(&vec);
                break;
            case 7:
                scanf("%d", &capacity);
                Reserve(&vec, capacity);
                break;
            case 8:
                scanf("%d %d", &size, &number);
                Resize(&vec, size, number);
                break;
            case 9:
                for(int i = 0; i < vec.size; i++) {
                    printf("%d ", vec.arr[i]);
                }
                printf("\n");
                break;
            default:
                break;
        }
    }
}