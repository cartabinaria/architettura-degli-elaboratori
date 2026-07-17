---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 08-10-2023 19:55:05
links:
  - "[[lecture-05102023130513|Lecture 05102023130513]]"
---
# Complemento a 1
---
## Introduzione
Per convertire usando la tecnica del _complemento a 1_ prendo il modulo del numero e inverto tutti i bit. Dopo, in caso di somma con altri numeri (negativi e non), è fondamentale **ricordarsi di sommare il riporto finale al risultato**.

![[somma-binaria-in-complemento.png]]

Con questa tecnica (come per il [[modulo-e-segno|modulo e segno]]) è possibile rappresentare i numeri da $-2^{k-1}+1$ a $2^{k-1}+1$, ed esistono due codifiche per lo 0 (+0 e -0).

## Referenze