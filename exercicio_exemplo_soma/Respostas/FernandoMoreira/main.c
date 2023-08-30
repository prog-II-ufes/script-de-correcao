#include <stdio.h>
#include "soma.h"

int main() {
    // Declaração das variáveis para os números
    double num1, num2;
    
    // Solicita ao usuário para inserir os números
    scanf("%lf", &num1);    
    scanf("%lf", &num2);
    
    // Calcula a soma dos números
    double resultado_soma = somar(num1, num2);
    
    // Imprime o resultado
    printf("A soma dos números é: %lf\n", resultado_soma);
    
    return 0;
}