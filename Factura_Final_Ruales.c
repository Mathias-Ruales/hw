#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funcion para verificar si la fecha es valida (el año debe ser 23 porque es una factuar actual)
bool check_date(int mm, int day, int year) {
    if (year == 23) {
      if((day >= 1 && day <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)) {
        return true;
      }else if ((day >= 1 && day <= 30) &&
         (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
        return true;
          }else if ((day >= 1 && day <= 28) && (mm == 2)) {
        //el retorno sera verdadero si los parametros son correctos
          return true;
            }
        }
  printf("La fecha no es valida.");
  //sino, el retorno sera falso
  return false;
}

//funcion para verificar si un numero es positivo
bool positivo(int a){
  if (a>0){
    return true;
  }
  printf("Por favor ingrese un numero positivo.\n");
  return false;
} 

//funcion para la verificacion de cedula 
bool verificador_cedula(char cedula_ingreso[]) {
  int cedula[10];
  int i, odd = 0, odd_t = 0, odd_m = 0, even = 0, even_t = 0, total_f,
         total_mod, ultimo_num;
  //este "for" guarda los digitos de la cedula en un arreglo
  for (int i = 0; i <= 9; i++) {
    cedula[i] = cedula_ingreso[i] - '0';
  }
  //este "for" hace los calculos de los numeros pares
  for (i = 1; i <= 8; i += 2) {
    even = cedula[i];
    even_t = even_t + even;
  }
  //este for hace los calculos para los numeros impares
  for (i = 0; i <= 9; i += 2) {
    odd = cedula[i];
    odd_m = (odd * 2);
    if (odd_m >= 9) {
      odd_m = odd_m - 9;
    }
    odd_t = odd_t + odd_m;
  }
  //el calculo del total
  total_f = (odd_t + even_t);
  //el modulo
  total_mod = (total_f % 10);
  //el calculo para sacar el ultimo numero
  ultimo_num = 10 - total_mod;
  //por si el ultimo numero es 0
  if (ultimo_num == 10) {
    ultimo_num = 0;
  }
  //2 partes- primero se verifica si la suma de el modulo mas el ultimo numero es 10 (y subsecuentemente que su modulo sea 0)
  if ((total_mod + ultimo_num) % 10 == 0) {
    //despues se verifica que el ultimo numero sea igual al ultimo numero de la cedula
    if (ultimo_num == cedula[9]) {
      //una vez que estos parametros sean correctos, el retorno sera verdadero
      return true;
    }
  }
  //caso contrario
  printf("La cedula no es valida\n");
  return false;
}
//funcion isdigit para un arreglo de numeros
bool es_numero(char cedula_ingreso[]) {
  int length = strlen(cedula_ingreso);
  for (int i = 0; i < length; i++) {
    if (isdigit(cedula_ingreso[i]) == 0) {
      //si el usuario ingresa algo que no sea un numero
      printf("Su ingreso solo deberia contener numeros\n");
      return false;
    }
  }
  return true;
}

//el main
int main(void) {
  int llantas, pastillas, embrague, faro, radiador, op, id, yn, cant,
      ll_t = 0, p_t = 0, e_t = 0, f_t = 0, r_t = 0, precio_total;
  int pt_ll = 0, pt_p = 0, pt_e = 0, pt_f = 0, pt_r = 0, pt_t = 0;
  float descuento;
  float tot;
  char nm[100];
  char name[100];
  int d, m, year;
  char dir[20];
  char telf[11];
  char codigo_ll[5] = "ABCD";
  char codigo_pas[5] = "BCDE";
  char codigo_em[5] = "CDEF";
  char codigo_faro[5] = "DEFG";
  char codigo_ra[5] = "EFGH";
  bool verificador = false;
  char cedula_ingreso[14];
  bool es_cedula = false;

  //primer menu
  printf("Desea generar una factura? (1. Si 2. No) ");
//para prevener ingresos erroneos o fuera de los parametros
  do {
    scanf("%d", &yn);
    //se usa isdigit porque el usuario solo ingresara 1 numero
    if ((yn < 1 || yn > 2) || isdigit(yn!=0)) {
      getchar();
      printf("Por favor ingrese 1 o 2.");
    }
  } while (yn < 1 || yn > 2);
//primer switch (2 opciones)
  switch (yn) {
  //case 1 es todo lo que pasara con la factura
  case 1:
  //ingreso y verificacion de cedula
    do {
      do {
        printf("Ingrese su numero de cedula: ");
        scanf("%s", cedula_ingreso);
        verificador = es_numero(cedula_ingreso);
      } while (verificador == false);
      es_cedula = verificador_cedula(cedula_ingreso);
    } while (es_cedula == false);
    
    getchar();
    //ingreso de nombre. Se usa [^\n] para poder usar espacios con el scanf
    printf("Ingrese su nombre: ");
    scanf("%[^\n]s", name);
    getchar();
    //sector
    printf("Ingrese su sector: ");
    scanf("%[^\n]s", dir);
//ingreso y verificacion de numero de telefono
    do{
    printf("Ingrese su numero de telefono: ");
    scanf("%s", telf);
    //se usa es_numero porque "telf" tiene varios digitos
    } while (es_numero(telf)== false);
  
  //la fecha y su verificacion
    do {
        printf("Ingrese la fecha (mm/dd/23): ");
        scanf("%d/%d/%d", &m, &d, &year);
      //se usa la funcion check_date para verificacr la fecha
    } while (check_date(m, d, year) == false);
 
  //el menu
    do {
      printf("Escoja el producto:\n");
      printf("1. Llantas ($150).\n");
      printf("2. Kit Pastillas de freno ($55).\n");
      printf("3. Kit de Embrague ($70).\n");
      printf("4. Faro ($150).\n");
      printf("5. Radiador ($120).\n");
      printf("6. Salir.\n");
      scanf("%d", &op);
//segundo switch (6 opciones)
      //las primeras 5 opciones tienen los mismos parametros
      switch (op) {
        case 1:
          do{
          printf("Ingrse la cantidad que va a comprar: ");
          scanf("%d", &cant);
            getchar();
          } while ((positivo(cant) == false) || isdigit(cant)!=0);
            ll_t = cant;
          pt_ll = (150 * ll_t);
          cant = 0;
          break;
  
        case 2:
          do {
          printf("Ingrse la cantidad que va a comprar: ");
          scanf("%d", &cant);
            getchar();
          } while ((positivo(cant) == false) || isdigit(cant)!=0);
            p_t = cant;
          pt_p = (55 * p_t);
          cant = 0;
          break;
  
        case 3:
          do{
          printf("Ingrse la cantidad que va a comprar: ");
          scanf("%d", &cant);
          getchar();
          } while ((positivo(cant) == false) || isdigit(cant)!=0);
            e_t = cant;
          pt_e = (70 * e_t);
          cant = 0;
          break;
  
        case 4:
          do{
          printf("Ingrse la cantidad que va a comprar: ");
          scanf("%d", &cant);
          getchar();
          } while ((positivo(cant) == false) || isdigit(cant)!=0);
            f_t = cant;
          pt_f = (150 * f_t);
          cant = 0;
          break;
  
        case 5:
          do{
          printf("Ingrse la cantidad que va a comprar: ");
          scanf("%d", &cant);
          getchar();
          } while ((positivo(cant) == false) || isdigit(cant)!=0);
            r_t = cant;
          pt_r = (120 * r_t);
          cant = 0;
          break;
        //la sexta opcion es lo que finaliza el case y sale del menu
        case 6:
          printf("\n\nGenerando factura...\n");
          getchar();
          pt_t = (pt_e + pt_f + pt_p + pt_r + pt_ll);
          break;
        //el default por ingresos erroneos
        default:
          printf("Ingreso incorrecto. Por favor, ingrese nuevamente:\n ");
          break;
        } //fin del segundo case
    } while (op != 6);

  //impresion de la factura 
    printf("------------------   DETALLE   ------------------\n");
  //los datos del usuario
    printf("%d/%d/%d\n", d, m, year);
    printf("Nombre: %s\n", name);
    printf("C.I: %s\n", cedula_ingreso);
    printf("Numero de telefono: %s\n", telf);
    printf("Sector: %s\n", dir);
//la factura
    printf("\n\nDetalle \t Cantidad \t Codigo \t P/U \t \t P/T\n");
    if (ll_t >= 1) {
      printf("Llantas \t \t %d \t \t %s \t \t $150 \t \t $%d\n", ll_t, codigo_ll,
             pt_ll);
    };
    if (p_t >= 1) {
      printf("Pastillas \t \t %d \t \t %s \t \t $55 \t \t $%d\n", p_t,
             codigo_pas, pt_p);
    };
    if (e_t >= 1) {
      printf("Kit de E. \t \t %d \t \t %s \t \t $70 \t \t $%d\n", e_t, codigo_em,
             pt_e);
    };
    if (f_t >= 1) {
      printf("Faro \t \t \t %d \t \t %s \t \t $150 \t \t $%d\n", f_t,
             codigo_faro, pt_f);
    };
    if (r_t >= 1) {
      printf("Radiador \t \t %d \t \t %s \t \t $120 \t \t $%d\n", r_t, codigo_ra,
             pt_r);
    };
//el descuento
    if (pt_t >= 501 && pt_t < 1000) {
      descuento = pt_t * 0.04;
    } else if (pt_t >= 1001 && pt_t < 5001) {
      descuento = pt_t * 0.07;
    } else if (pt_t >= 5001) {
      descuento = pt_t * 0.09;
    }
    //separador
    printf("\n\n");
    //impresion del descuento y el subtotal (si lo hay)
    if (descuento > 0) {
      printf("Descuento: \t \t \t \t \t \t \t \t \t \t$%.2f\n", descuento);
      printf("Subtotal: \t \t \t \t \t \t \t \t \t \t$%d\n", pt_t);
    }
    //impresion del total
    printf("Total: \t \t \t \t \t \t \t \t \t \t \t$%.2f\n", pt_t - descuento);
    //agradecimiento
    printf("Gracias por su compra.");
    break;
  //case 2. Consumidor final
  case 2:
    printf("Gracias por su compra.");
    break;
  }
  return 0;
}