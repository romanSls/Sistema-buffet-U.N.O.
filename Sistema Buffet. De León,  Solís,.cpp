#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

/*  CONTROLADOR DE PEDIDOS  */
int generateId(int ids[]);
char generateFood(char foodTotal[], char food);
int generateCant(int cantTotal[], int cantProduct);

/*  FUNCIONES PRINCIPALES  */
bool placeOrder(int idTotal[], char foodTotal[], int cantTotal[]);
void modify(int idTotal[], char foodTotal[], int cantTotal[]);
void history(int idTotal[], char foodTotal[], int cantTotal[]);
void cancel(int idTotal[], char foodTotal[], int cantTotal[]);

/*  MOSTRADOR DE MENUS   */
void showMenuFood();
void showOrder(char name[10], char nameProduct, int cantProduct);
void showMenu();
void showMenuModify();

int main() {
    int option, idTotal[MAX] = {0}, cantTotal[MAX] = {0};
    char foodTotal[MAX] = {0};

    do {
        showMenu();
        printf("\nSeleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                placeOrder(idTotal, foodTotal, cantTotal);
                break;
            case 2:
                showMenuFood();
                system("pause");
                break;
            case 3:
                history(idTotal, foodTotal, cantTotal);
                system("pause");
                break;
            case 4:
                modify(idTotal, foodTotal, cantTotal);
                system("pause");
                break;
            case 5:
                cancel(idTotal, foodTotal, cantTotal);
                system("pause");
                break;
            default:
                if (option != 0) {
                    printf("\nNo existe esa opcion\n\n");
                    system("pause");
                    option = 6;
                }
                break;
        }

    } while (option != 0);

    return 0;
}

void modify(int idTotal[], char foodTotal[], int cantTotal[]) {
 int id, cant, i;
    char food;
    bool idExists = false;

    printf("\n\tIngrese el ID del pedido: ");
    scanf("%d", &id);

    // Validar si el ID existe
    for (i = 0; i < MAX; i++) {
        if (idTotal[i] == id) {
            idExists = true;
            break;
        }
    }

    if (!idExists) {
        printf("\n\tEl ID ingresado no existe.\n");
        return;
    }

    showMenuFood();

    printf("\n\n\tIngrese el nuevo producto: ");
    fflush(stdin);
    scanf("%c", &food); 

    printf("\n\tIngrese la nueva cantidad: ");
    scanf("%d", &cant);


    foodTotal[i] = food;
    cantTotal[i] = cant;

    printf("\n\nPedido modificado con Exito!...\n");
}

void showMenu() {
    system("cls");
    printf("%c", 201);
    for (int i = 0; i <= 42; i++) printf("%c", 205);
    printf("%c\n", 187);

    printf("%c", 186);
    for (int i = 0; i <= 42; i++) printf(" ");
    printf("%c\n", 186);

    printf("%c              SISTEMA BUFFET               %c\n", 186, 186);

    printf("%c", 186);
    for (int i = 0; i <= 42; i++) printf(" ");
    printf("%c\n", 186);

    printf("%c", 204);
    for (int i = 0; i <= 42; i++) printf("%c", 205);
    printf("%c\n", 185);

    printf("%c                                           %c\n", 186, 186);
    printf("%c       1 - REALIZAR NUEVO PEDIDO           %c\n", 186, 186);
    printf("%c                                           %c\n", 186, 186);
    printf("%c       2 - CONSULTAR MENU                  %c\n", 186, 186);
    printf("%c                                           %c\n", 186, 186);
    printf("%c       3 - VER HISTORIAL DE PEDIDOS        %c\n", 186, 186);
    printf("%c                                           %c\n", 186, 186);
    printf("%c       4 - MODIFICAR PEDIDO                %c\n", 186, 186);
    printf("%c                                           %c\n", 186, 186);
    printf("%c       5 - CANCELAR PEDIDO                 %c\n", 186, 186);
    printf("%c                                           %c\n", 186, 186);
    printf("%c       0 - SALIR                           %c\n", 186, 186);
    printf("%c                                           %c\n", 186, 186);
    printf("%c", 200);
    for (int i = 0; i <= 42; i++) printf("%c", 205);
    printf("%c\n", 188);
}

bool placeOrder(int idTotal[], char foodTotal[], int cantTotal[]) {
char name[10], nameProduct, confirm;
    int cantProduct, option;

    do {
        system("cls");
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        scanf("%s", name);

        showMenuFood();
        printf("\nSeleccione una opcion: ");
        fflush(stdin);
        scanf("%c", &nameProduct); 
        printf("\nCantidad: ");
        scanf("%d", &cantProduct);

        showOrder(name, nameProduct, cantProduct);

        // Validar confirmacion del pedido
        do {
            printf("\nDesea confirmar el pedido? (s / n): ");
            fflush(stdin);
            scanf("%c", &confirm);
            printf("\nCaracter incorrecto..");
        } while (confirm != 's' && confirm != 'n');

        system("cls");

        if (confirm == 's') {
            generateId(idTotal);
            generateFood(foodTotal, nameProduct);
            generateCant(cantTotal, cantProduct);
            option = 0; 
        } else {
            // Validar opcion
            do {
                printf("\n Pedido rechazado, seleccione una opcion: ");
                printf("\n\n 1 - Repetir Pedido");
                printf("\n 0 - Volver al menu");
                printf("\nOpcion: ");
                scanf("%d", &option);
                printf("\n Opcion incorrecta...");
            } while (option != 0 && option != 1);
        }

    } while (option != 0);

    return true;
}

int generateId(int ids[]) {
    for (int i = 0; i < MAX; i++) {
        if (ids[i] == 0) {
            ids[i] = i + 1;
            return ids[i];
        }
    }
    return 0;
}

void showMenuFood() {
    system("cls");
    printf("%c", 201);
    for (int i = 0; i <= 42; i++) printf("%c", 205);
    printf("%c\n", 187);

    printf("%c", 186);
    for (int i = 0; i <= 42; i++) printf(" ");
    printf("%c\n", 186);

    printf("%c                MENU DE COMIDAS            %c\n", 186, 186);

    printf("%c", 186);
    for (int i = 0; i <= 42; i++) printf(" ");
    printf("%c\n", 186);

    printf("%c", 204);
    for (int i = 0; i <= 42; i++) printf("%c", 205);
    printf("%c\n", 185);

    printf("%c  A. Empanadas Veggies                500$ %c\n", 186, 186);
    printf("%c  B. Pizza individual                 600$ %c\n", 186, 186);
    printf("%c  C. Pebete JyQ                       200$ %c\n", 186, 186);
    printf("%c  D. Super pancho                     100$ %c\n", 186, 186);
    printf("%c  E. Hamburguesa con fritas           550$ %c\n", 186, 186);

    printf("%c", 200);
    for (int i = 0; i <= 42; i++) printf("%c", 205);
    printf("%c\n", 188);
}

void showMenuModify() {
    system("cls");
    printf("%c", 201);
    for (int i = 0; i <= 20; i++) printf("%c", 205);
    printf("%c\n", 187);

    printf("%c", 186);
    for (int i = 0; i <= 20; i++) printf(" ");
    printf("%c\n", 186);

    printf("%c      MODIFICAR      %c\n", 186, 186);

    printf("%c", 186);
    for (int i = 0; i <= 20; i++) printf(" ");
    printf("%c\n", 186);

    printf("%c", 204);
    for (int i = 0; i <= 20; i++) printf("%c", 205);
    printf("%c\n", 185);

    printf("%c                     %c\n", 186, 186);
    printf("%c   1  - PRODUCTO     %c\n", 186, 186);
    printf("%c   2  - CANTIDAD     %c\n", 186, 186);
    printf("%c                     %c\n", 186, 186);

    printf("%c", 200);
    for (int i = 0; i <= 20; i++) printf("%c", 205);
    printf("%c\n\n", 188);
}

void showOrder(char name[10], char nameProduct, int cantProduct) {
    char comida[30];
	int monto;
    switch (nameProduct) {
        case 'A':
            strcpy(comida, "Empanadas Veggies");
            monto= 500 * cantProduct;
            break;
        case 'B':
            strcpy(comida, "Pizza individual");
            monto= 600 * cantProduct;
            break;
        case 'C':
            strcpy(comida, "Pebete JyQ");
            monto= 200 * cantProduct;
            break;
        case 'D':
            strcpy(comida, "Super pancho");
            monto= 100 * cantProduct;
            break;
        case 'E':
            strcpy(comida, "Hamburguesa con fritas");
            monto= 550 * cantProduct;
            break;
        default:
            printf("\n No existe esa opcion ");
    }

    printf("\n");
    printf("+--------------------------------------+\n");
    printf("|            TICKET DE COMPRA          |\n");
    printf("|--------------------------------------|\n");
    printf("| Cliente: %-27s |\n", name);
    printf("|--------------------------------------|\n");
    printf("| Producto: %-26s |\n", comida);
    printf("| Cantidad: %-26d |\n", cantProduct);
    printf("| Monto   : %-26d$|\n", monto);
    printf("|--------------------------------------|\n");
    printf("|        ¡Gracias por su compra!       |\n");
    printf("+--------------------------------------+\n");
}

char generateFood(char foodTotal[], char food) {
    for (int i = 0; i < MAX; i++) {
        if (foodTotal[i] == 0) {
            foodTotal[i] = food;
            return foodTotal[i];
        }
    }
    return 0;
}

int generateCant(int cantTotal[], int cantProduct) {
    for (int i = 0; i < MAX; i++) {
        if (cantTotal[i] == 0) {
            cantTotal[i] = cantProduct;
            return cantTotal[i];
        }
    }
    return 0;
}

void history(int idTotal[], char foodTotal[], int cantTotal[]) {
    system("cls");

    if (idTotal[0] <= 0) {
        printf("\n\t\tTodavia no hay pedidos!\n\n");
    } else {
        for (int i = 0; i < MAX; i++) {
            if (idTotal[i] != 0) {
                char food[15];
                switch (foodTotal[i]) {
                    case 'A':
                        strcpy(food, "Empanadas Veggies");
                        break;
                    case 'B':
                        strcpy(food, "Pizza individual");
                        break;
                    case 'C':
                        strcpy(food, "Pebete JyQ");
                        break;
                    case 'D':
                        strcpy(food, "Super pancho");
                        break;
                    case 'E':
                        strcpy(food, "Hamburguesa con fritas");
                        break;
                }

                printf("\n\n\t[%d]  - %s  - %d UNIDADES \n", idTotal[i], food, cantTotal[i]);
            }
        }
    }
}


void cancel(int idTotal[], char foodTotal[], int cantTotal[]) {
   int id;
    printf("\n\tIngrese el ID del pedido: ");
    scanf("%d", &id);

    // Validar si el ID existe
    if (id <= 0 || id > MAX || idTotal[id - 1] == 0) {
        printf("\n\tEl ID ingresado no existe.\n");
        return;
    }

    idTotal[id - 1] = 0;
    foodTotal[id - 1] = 0;
    cantTotal[id - 1] = 0;

    printf("\n\nPedido cancelado con Exito!...\n");
}

