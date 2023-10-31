#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
//esta funcion verifica que a sea diferente de 0
bool isreal(float a){
  if(a!=0){
    return true;
  }
//si los parametros no coinciden se imprime un mensaje 
  printf ("Su numero debe ser diferente de 0.");
//getchar para evitar bucles
  getchar();
  return false;
}
//funcion para verificar que una opcion este en los parametros 
bool isop(int a){
  //solo puede ser 1 o 2
  if (a==1 || a==2){
    return true;
  }
    printf("Su numero debe ser 1 o 2: ");
  getchar();
    return false;
}
//la funcion utiliza 3 variables
float square(float a, float b, float c ){
//d va a ser el detereminante
  float d;
  d= (pow(b,2)-4*a*c);
//primero se verifica si el determinante es positivo
  if (d<0){
//si no lo es, retorna un mensaje
   printf ("Su numero es imaginario.");
    return false;
//cuando es positivo, se toma la raiz
  } else{
    d=sqrt(d);
  }
  //se retorna el determinante
   return d;
}
//el main
int main(void) {
//a,b y c son los numeros que usara la funcion
//sq es el determinante
//las 2x's respectivamente
float a,b,c, sq, x1,x2;
int op;
//se usa un "do" para verificar que el primer numero sea diferente de 0
  printf ("\nCalculadora: Formula General. Desea comenzar? (1=si, 2=no) ");
  do{
    scanf ("%d", &op);
    }while (isop(op)==false);
  switch (op){
    case 1: {
       do{
        do{
          printf ( "\nIngrese el primer numero:");
          scanf ("%f", &a);
          }while (isreal(a)==false);
        //ingreso de los otros 2 numeros
        printf ( "\nIngrese el segundo numero:");
        scanf ("%f", &b);
        printf ( "\nIngrese el tercer numero:");
        scanf ("%f", &c);
        //uso de la funcion square para sacar el determinante
        sq= square(a,b,c);
        if (sq!= false){
          //aqui se calcula las 2 x
          x1=(-b-sq)/(2*a);
          x2=(-b+sq)/(2*a);
          //impresion de las 2x
          printf ( "\nx1=%.2f, x2=%.2f", x1, x2);
        }
        printf("\nQuisiera ingresar de nuevo? (1=si, 2=no)");
         do{
           scanf("%d", &op);
         }while (isop(op)==false);
       }while (op==1);
        }
    break;
  case 2: {
    printf("\nGracias por usar el programa.");
    break;
    }
  }
  return 0;
}