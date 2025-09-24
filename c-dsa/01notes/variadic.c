#include <stdarg.h>  
#include <stdio.h>   

void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);  

    while (count--) {  // Jab tak count 0 na ho jaye
        printf("%d ", va_arg(args, int));  // Next number print karo
    }

    va_end(args);
    printf("\n");
}

int main() {
    printNumbers(3, 10, 20, 30);  
    printNumbers(5, 1, 2, 3, 4, 5);  
    return 0;
}
