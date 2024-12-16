#include<stdio.h>
 
struct Student{
    int m_id;
    int m_score;
};
 
int main(){
    struct Student x;
    scanf("%d", &x.m_id);
    scanf("%d", &x.m_score);
    printf("(ID: %d, score: %d)", x.m_id, x.m_score);
    return 0;
}