#include <stdio.h>
int fib(num){
  int n1=0,n2=1,n3,c;
  //n1=primer numero, n2= segundo numero, n3= tercer numero, c=contador
  //el numero 1 va a ser 0, y el numero 2 va a ser 1 
  for (c=0; c<=num; c++){
    if (c<=1){
    //el numero impreso tendra el mismo valor que el contador en 0 y 1
      n3=c;
    }else{
    //despues de esto, el numero impreso sera la suma entre el primer numero y el segundo numero (con sus valores definidos)
      n3=n1+n2;
  //el primer numero toma el valor del segundo numero
      n1=n2;
  //el segundo numero toma el valor del tercer numero
      n2=n3;
    }
  printf ("%d: %d \n", c, n3);
  }
  return c;
}
//El main
int main(void) {
  int num, op;
  //num=la posicion en la secuencia que eligira el usuario
  //op=opcion para seguir/salir del programa
  printf("Secuencia de Fibonacci.\n");
  printf("-----------------------\n");
  //primer do dicta si se repite el programa
  do{
    //segundo do verifica que el numero ingresado sea valido
    do{
      printf("Ingrese un numero: " );
      scanf("%d", &num);
        if (num<0){
          printf ("Su numero debe ser mayor o igual a 0.\n");
        }
      }while (num<0);
    printf("Generando resultados...\n");
    //se usa la funcion para generar la secuencia
    fib(num);
    printf ("Desea inrgesar otro numero?. (1. si 2. no) ");
      //tercer do verifica que la opcion ingresada sea 1 o 2
      do{
        scanf ("%d", &op);
          if (op!=1 && op!=2)
          printf("Numero invalido. Por favor ingrese 1 o 2: ");
        }while (op!=1 && op!=2);
    }while (op==1);
  printf("Gracias por usar el programa.");
return 0;
}