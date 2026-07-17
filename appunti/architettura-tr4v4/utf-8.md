---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
  - topic/tecnologie-web
date: 12-10-2023 20:06:22
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# UTF-8
---
## Introduzione
La [[codifica-dei-caratteri|codifica]] **UTF-8** risolve i problemi dell'[[unicode|UNICODE]], sia in termini di terminazione dello spazio disponibile per i caratteri, sia per quanto riguarda il numero di bit per rappresentare ogni singolo carattere.

## Definizione
> **UTF** (_Unicode Transformation Format_ o _UCS Transformation Format_) è un _sistema a lunghezza variabile_ che permette di accedere a tutti i caratteri di [[iso-10646|UCS]] in maniera semplificata e più efficiente.

## Composizione
L'UTF-8 occupa per ogni carattere da un minimo di 1 a un massimo di 4 byte. Ha un'occupazione quindi _dinamica_ della memoria, a seconda della categoria a cui ogni carattere fa parte.

In particolare:
- i codici compresi tra 0 - 127 ([[ascii|ASCII]] a 7 bit), richiedono un byte, in cui ci sia 0 al primo bit;
- i codici derivati dall'alfabeto latino e tutti gli script non-ideografici richiedono 2 byte;
- i codici ideografici (orientali) richiedono 3 byte;
- i codici dei piani alti richiedono 4 byte;

![[utf-8.png]]

## Problemi comuni
![[utf-8-to-latin-1.png]]

Qui avviene che il carattere `è` è rappresentato in due byte come `00E9` dall'UCS-2 ([[iso-10646|ISO 10646]]) e scritto come `C3A9` dall'UTF-8 (con il meccanismo sopra spiegato). Ma `C3A9` dall'[[iso-latin-1|ISO Latin 1]] viene interpretato come due byte, e quindi caratteri, distinti.

![[error-utf-8-to-latin-1.png]]

![[latin-1-to-utf-8.png]]

## Referenze