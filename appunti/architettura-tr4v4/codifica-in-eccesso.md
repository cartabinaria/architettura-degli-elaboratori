---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 08-10-2023 20:11:39
links:
  - "[[lecture-05102023130513|Lecture 05102023130513]]"
---
# Codifica in eccesso
---
## Introduzione
Se per esempio si volessero rappresentare i numeri da -128 a 127, al numero da rappresentare si somma 128 ottenendo valori da 0 a 255 rappresentabili in [[codice-binario|codice binario]] standard, poi quando si vuole sapere il vero valore di quel numero si sottrae 128 da esso.

<u>Curiosità</u>: in questo caso, ovviamente, lo 0 non è rappresentato come una sequenza di 0 ma come 128.

Con questa tecnica è possibile rappresentare i numeri da $-2^{k-1}$ a $2^{k-1}-1$.

## Referenze