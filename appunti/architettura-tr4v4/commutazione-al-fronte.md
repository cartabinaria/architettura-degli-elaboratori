---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 09:33:19
links:
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# Commutazione al fronte
---
## Introduzione
I circuiti a **commutazione al fronte** utilizzano, come quelli a [[commutazione-a-livello|commutazione a livello]], il [[clock|clock]] per scandire il tempo di accensione e di spegnimento degli stessi, ma solo per una certa frazione di tempo.

Per realizzare una cosa del genere sfrutta una proprietà del [[not|NOT]]: la _lentezza_. Per un generico circuito a commutazione al fronte il segnalo del clock viene anticipato da struttura simile:
![[clock-flip-flop.png]]
In questo modo
> Nel momento in cui `clock=1` prima ancora che il NOT abbia invertito il valore in 0, l'[[and|AND]] calcola in uscita 1. C'è quindi un piccolo istante in cui l'AND produce 1; subito dopo il NOT compie la sua inversione facendo tornare il risultato dell'AND a 0.

## Segnale
![[segnale-commutazione-al-fronte.png]]

## Referenze