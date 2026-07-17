---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 10:12:27
links:
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# 1-bit register
---
## Introduzione
Sfruttando le potenzialità del [[dff-latch|DFF Latch]] si può sviluppare un **registro a 1 bit**, che ha una struttura del tipo
![[1-bit-register.png]]
dove:
- `in` è l'input che si vuole settare al registro
- `out` è il valore memorizzato dal registro
- `load` è il segnale che permette di scegliere se far prendere al registro il valore di `in` o mantenere il suo valore (`out`)

## Implementazione
Internamente, un registro a 1 bit si presenta così:
![[1-bit-register-inside.png]]

<u>Nota bene</u>: il [[multiplexer|multiplexer]] necessario per la _scelta_ del valore del registro.

## Referenze