---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 08-10-2023 19:59:33
links:
  - "[[lecture-05102023130513|Lecture 05102023130513]]"
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# Complemento a 2
---
## Introduzione
A differenza del [[complemento-a-1|complemento a 1]], quello a 2 al numero invertito di tutti i bit aggiunge 1. Grazie a questa "mossa" le somme (tra negativi e positivi) funziona perfettamente, e _non è necessario aggiungere il riporto finale al risultato_.

![[somma-binaria-in-complemento.png]]

## Conversione
Per passare da un numero al suo opposto in complemento a 2 è quindi molto facile:
1. inverto tutti i bit
2. sommo 1 al risultato

Per convertire un numero negativo in complemento a 2 usando la [[codifica-numeri-interi-introduzione|sommatoria]] standard è necessario introdurre dei cambiamenti:
$$-b_{k-1} \times 2^{k-1} + \sum\limits_{i=0..k-2} b_{i} \times 2^{i}$$

Con questa tecnica è possibile rappresentare i numeri da $-2^{k-1}$ a $-2^{k-1}-1$ (una cifra in più rispetto al [[modulo-e-segno|modulo e segno]] e [[complemento-a-1|complemento a 1]]). Esiste una sola codifica per lo 0.

## Rappresentazione
La facilità di rappresentazione dei numeri in complemento a 2 sta nel fatto che i segni dei numeri sono facilmente riconoscibili dal bit più significativo (un po' come per il [[modulo-e-segno|modulo e segno]]):
- _i numeri positivi iniziano con uno 0_
- _i numeri negativi iniziano con un 1_
![[complemento-a-2.png]]

## Utilizzi
Questa è la tecnica utilizzata da [[c|C]] e [[c|C++]] per codificare i numeri negativi, perché molto efficiente.

## Referenze