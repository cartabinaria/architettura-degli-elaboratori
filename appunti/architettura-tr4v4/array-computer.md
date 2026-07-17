---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 21:54:52
links:
  - "[[lecture-21092023130150|Lecture 21092023130150]]"
---
# Array computer
---
## Introduzione
Per array computer si intende un speciale tipo di architettura di [[cpu|CPU]] in cui è prevista una singola CU che ordina attraverso segnali _broadcast_ a una serie di _unità processori-memorie_ di eseguire una stessa istruzione ma su dati differenti.
![[simd.png]]

Chiamata anche **[[simd|SIMD]]** (_Single Instruction-stream Multiple Data-stream_), quest'architettura risulta estremamente efficiente quando si vuole **eseguire una stessa operazione su più dati**: per esempio con la _sfocatura di una griglia di pixels_. Infatti le [[gpu|GPU]] sono di per sé composte in parte da array computer.

Se si dovesse fare con una normale architettura bisognerebbe eseguire la stessa operazione tante volte tanti quanti sono i pixels; con SIMD invece **l'istruzione si esegue tante volte tanti quanti sono i pixels/numero di unità p-m** (processori-memorie).

In compiti in cui invece vige la diversità sia dei dati che delle istruzioni, quest'architettura risulta inefficiente.

## Referenze