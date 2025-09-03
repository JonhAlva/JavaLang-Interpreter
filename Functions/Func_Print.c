#include "AST.h"

int Evaluar(Nodo* n) {
    if (!n) return 0;

    switch (n->tipo) {

    case NODO_INT:
        return n->valor.i_val;

    case NODO_FLOAT:
        return n->valor.f_val;

    case NODO_STRING:
        return 0;

    case NODO_BOOL:
        return n->valor.b_val;

    case NODO_CHAR:
        return n->valor.c_val;

    case NODO_OPERACION:{
        int izq = Evaluar(n->izq);
        int der = Evaluar(n->der);
        switch (n->valor.op) {
            case '+': return izq + der;
            case '-': return izq - der;
            case '*': return izq * der;
            case '/': return der != 0 ? izq / der : 0; // ! Evita divisiones por 0
            case '%': return izq % der;
            case '<': return izq < der;
            case '>': return izq > der;
            case '<=': return izq <= der;
            case '>=': return izq >= der;
            case '==': return izq == der;
            case '!=': return izq != der;
            case '&&': return izq && der;
            case '||': return izq || der;
            // ! ver como implementar el negado '!'
            }
            break;
        }
        
    case NODO_PRINT: {
        Nodo* expr = n->izq;
        if (!expr) return 0;

        if(expr->tipo == NODO_INT) {

        }
    }
    // ! AQUI SE AÑADEN MAS CASES PARA LOS DISTINTOS NODOS Y LO QUE QUIERO QUE SALGA
    }
}

