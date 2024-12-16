#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    if (n <= 560000) {
        printf("全年應繳稅額為： %.0f 元\n", n * 0.05 - 0);
    } else if (n <= 1260000) {
        printf("全年應繳稅額為： %.0f 元\n", n * 0.12 - 39200);
    } else if (n <= 2520000) {
        printf("全年應繳稅額為： %.0f 元\n", n * 0.2 - 140000);
    } else if (n <= 4720000) {
        printf("全年應繳稅額為： %.0f 元\n", n * 0.3 - 392000);
    } else {
        printf("全年應繳稅額為： %.0f 元\n", n * 0.4 - 864000);
    }
    
    return 0;
}