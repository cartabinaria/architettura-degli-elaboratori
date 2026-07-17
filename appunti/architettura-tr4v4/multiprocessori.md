---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 21:55:24
links:
  - "[[lecture-21092023130150|Lecture 21092023130150]]"
---
# Multiprocessori
---
## Introduzione
Un altro tipo di architettura invece è quella dei multiprocessori, che prevede una serie di singole CPU che accedono in contemporanea ad una stessa RAM condivisa.
![[mimd.png]]

I processori quindi non devono per forza eseguire la stessa istruzione (accedono ad aree di memoria differenti), per questo l'architettura **[[mimd|MIMD]]** (_Multiple Instruction-stream Multiple Data-stream_) risulta essere più flessibile della [[simd|SIMD]].

## Referenze