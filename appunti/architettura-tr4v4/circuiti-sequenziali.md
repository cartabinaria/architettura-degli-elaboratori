---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 12-10-2023 22:59:03
links:
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# Circuiti sequenziali
---
## Introduzione
A differenza di quelli [[circuiti-combinatori|combinatori]], _l'output dei **circuiti sequenziali** non dipende solo dagli ingressi ma anche dal loro stato_. Per questo cose come la [[tabella-di-verita|tabella di verità]] o [[mappe-di-karnaugh|mappe di Karnaugh]] non valgono per loro.

Lo stato dipende, solitamente, dal risultato ottenuto in precedenza, o comunque dagli eventi del passato. Per esempio le [[memorie|memorie]] funzionano con circuiti sequenziali.

## Tipologie
- [[sr-latch|SR Latch]]
- [[d-latch|D Latch]]
- [[dff-latch|DFF Latch]]
- [[1-bit-register|1-bit register]]
- [[w-bit-register|w-bit register]]
- [[ram|RAM]]

## Schema realizzativo
Lo schema realizzativo di un qualunque circuito sequenziale, _di norma_, segue la seguente forma
![[schema-circuito-sequenziale.png]]

In questo modo l'output del circuito dipende dal suo input e dall'output all'istante precedenti (`out(t) = f(out(t-1), in(t-1))`).

## Referenze