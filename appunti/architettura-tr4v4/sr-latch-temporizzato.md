---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 14-10-2023 16:15:08
links:
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# SR Latch temporizzato
---
## Introduzione
Come modifica al [[sr-latch|SR Latch]], per _evitare che questo cambi il proprio stato in particolari momenti_ o che cambi per errore (_interferenze_), si mettono in [[and|AND]] i due bit d'ingresso con il segnale del [[clock|clock]], così da consentire al latch di modificarsi solo quando il segnale è a 1.
![[sr-latch-temporizzato.png]]

Insieme al [[d-latch|D Latch]], l'SR Latch fa parte dei circuiti a [[commutazione-a-livello|commutazione a livello]].

## Referenze