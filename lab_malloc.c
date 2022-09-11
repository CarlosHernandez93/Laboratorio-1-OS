/* Hehco por:
   Hugo Andres Garces Guzman
   Carlos Augusto Hernández Zamora
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RESERVAR_MAS 1

int main()
{
   //declaración de un el arreglo dinámico de enteros:
   int* int_dyn_arr;
   int tam_inicial; //tamanio inicial
   int incremento;
   int opcion;
   int validacion = 0;
   do
   {
      do{
         printf("\nMenu LAB 1\n");
         printf("1. Ingresar un valor incial para reservar en memoria\n");
         printf("2. Aumentar el tamaño\n");
         printf("3. Salir\n");
         printf("\nIngrese una opción: ");
         scanf("%d", &opcion);
         if(opcion < 1 || opcion > 3){
            printf("\n!ERROR¡ opcion no valida\n\n");
         }
      }while (opcion < 1 || opcion > 3);

      switch (opcion)
      {
         case 1:
            printf("\nIngrese la cantidad de elementos iniciales para reservar en memoria: ");
            scanf("%d", &tam_inicial);
            int_dyn_arr = (int*)malloc(tam_inicial * sizeof(int));
            if(int_dyn_arr == NULL){
               printf("\n!ERROR¡ Ahora mismo no es posible asginar espacio en memoria para esa cantiada de elementos\n");
               printf("Se recomiendo utilizar una menor cantidad de elementos\n");
            }
            else{
               validacion = 1;
            }
            
            break;
         
         case 2:
            //incremento de memoria (entero):
            if(validacion == 1){
               int sel;
               int aumento_reserva = tam_inicial;
               do
               {
                  printf("\nDesea reservar más espacio? (1 = Si): ");
                  scanf("%d",&sel);
                  if(sel == RESERVAR_MAS)
                  {
                     printf("\nDigite la cantidad de elementos desea agregar: ");
                     scanf("%d", &incremento);
                     aumento_reserva = aumento_reserva + incremento;
                     //reasignar memoria:
                     int_dyn_arr = (int*)realloc(int_dyn_arr, aumento_reserva * sizeof(int));
                     printf("\n");
                  }
                  else{
                     printf("!ERROR¡ opcion no valida");
                  }
               }while(sel == RESERVAR_MAS);
            }
            else{
               printf("\nNo puedes acceder a esta opcion..\n\n");
            }
            break;

         case 3:
            printf("Finalizando ejecucion...\n");
            opcion = 4;
            break;

         default:
            printf("!ERROR¡ opcion no valida");
            break;
      }

   } while (opcion>=1 && opcion<=3);

   free(int_dyn_arr);
   return 0;
}
