---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 08-10-2023 19:50:22
links:
  - "[[lecture-05102023130513|Lecture 05102023130513]]"
---
# Modulo e segno
---
## Introduzione
Con questa tecnica per [[codifica-numeri-interi|codificare numeri interi]] anche negativi **si prende il modulo del numero e si usa il bit più significativo per rappresentarne il segno**.

Quindi, se per esempio dobbiamo rappresentare `-6` con 8 bit, scriveremo `6` in binario `00000110` e metteremo a 1 il bit più significativo, per ottenere `10000110`.

Con questa tecnica è possibile rappresentare i numeri da $-2^{k-1}+1$ a $2^{k-1}-1$, ed esistono due codifiche per lo 0 (+0 e -0).

## Referenze