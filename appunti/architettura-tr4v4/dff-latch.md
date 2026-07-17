---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 14-10-2023 16:24:50
links:
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# DFF Latch
---
## Introduzione
Il **Data Flip-Flop** è una variante del [[d-latch|D Latch]] che sfrutta il meccanismo dei circuiti [[flip-flop|Flip-Flop]]: la [[commutazione-al-fronte|commutazione al fronte]]. Grazie alla proprietà di questi circuiti, a differenza degli altri latch[^1], _il tempo in cui il latch assume il valore di input_ (`clock=1`) _è solo una piccola frazione del tempo in cui mantiene tale valore_ (`clock=0`). Vale infatti che:
> Minore è il tempo di cambio di stato, maggiore è la velocità del circuito.

## Implementazione
![[dff-latch.png]]

I vantaggi sono notevoli, in termini sia di velocità che di precisione del risultato. Se solo una frazione di clock a 1 (_fronte di salita_) viene utilizzata per far assumere il valore al latch, vuol dire che la [[alu|ALU]] che calcola il risultato da impostare al latch ha più tempo per "calcolarlo bene"[^2].

### Output
![[flip-flop.png]]
L'output dell'istante `t` sarà uguale all'input dell'istante precedente (`t-1`)[^3].

## Referenze
[^1]: [[sr-latch|SR Latch]] e [[d-latch|D Latch]]
[^2]: ricordiamo sempre l'effetto delle interferenze elettroniche
[^3]: riferimento al [[commutazione-al-fronte-segnale|segnale della commutazione al fronte]]