---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 14-10-2023 16:18:52
links:
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# D Latch
---
## Introduzione
Per evitare la situazione del [[sr-latch|SR Latch]] in cui i due ingressi `S` e `R` sono entrambi a 1, si costruisce in modo da ottenere _sempre un risultato non ambiguo_: con i due bit d'ingresso diversi tra di loro.
![[d-latch-temporizzato.png]]

Si utilizza quindi un solo bit per memorizzare un valore (`D=0` o `D=1`). Non avverrà mai il caso in cui in entrata al _latch_ ci saranno due ingressi uguali.

Insieme al SR Latch, il D Latch è un circuiti a [[commutazione-a-livello|commutazione a livello]].

## Referenze