#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"
#define MAX_ITEMS 4

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void){
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 300,2}; 
    Producto l = {"Leche", 350, 2};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, l);
    carrito_agregar(&c, l);
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
    //ASSERT_IGUAL(1300, carrito_total(&c));

}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(){
        Carrito c;
    carrito_init(&c);
    Producto l = {"Leche", 350, 4};
    for(int i=0; i<=MAX_ITEMS; i++ )
    {
        carrito_agregar(&c,l);
    }
    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);
    ASSERT_IGUAL(0,carrito_agregar(&c,l));

    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);

}


int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
