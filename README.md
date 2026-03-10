## Universidad de San Carlos de Guatemala - Facultad de Ingenieria
---
## Proyecto 2 - JavaLang Interpreter
---

#### Implementacion de un interprete de lenguaje Java simplificado
Utilizando técnicas de análisis léxico, sintáctico y semántico mediante la construccion de un AST que genera reportes asociados al código fuente procesado.

#### Resumen Ejecutivo
Este proyecto consiste en el desarrollo de un intérprete funcional para el lenguaje JavaLang, una sintaxis inspirada en Java que fue diseñado para fines educativos en el estudio de compiladores.

El objetivo principal es desarrollar un sistema capaz de analizar, validar e interpretar programas escritos en JavaLang, permitiendo comprender e implementar los principales componentes de un compilador.

El proyecto busca enfrentar la dificultad de visualizar y aplicar de manera practica los conceptos teóricos relacionados con compiladores que suelen ser abstractos y complejos en un ambito estudiantil.

El sistema espera aceptar archivos con extension .usl y generará reportes del arból AST, tabla de simbolos y errores detectados, brindando una experiencia interactiva para el aprendizaje de los fundamentos de los compiladores.


#### Objetivos Específicos
* Desarrollar una interfaz funcional y multiplataforma Linux que permita crear, editar y ejecutar archivos con extension .usl

* Contruir gramática del lenguaje JavaLang utilizando Bison que permitan la generación automática de analizadores léxicos y sintácticos.

* Implementar un sistema de recorrido AST, capaz de validar estructuras, tipos de datos y contextos del código fuente.
---
#### Requerimientos Tecnicos

Lenguaje de entrada: **Java** 
Lenguaje de implementación: **C**
Herramientas de construccion y dependencias: **Makefile**
Generacion de analizadores: **Flex (Análisis léxico)**
**Bison (Análisis sintáctico)**
Interfaz Grafica de Usuario: **Gtk3**
