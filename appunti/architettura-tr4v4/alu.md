---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 22-09-2023 19:22:55
links:
  - "[[lecture-20092023151652|Lecture 20092023151652]]"
---
# ALU
---
## Introduzione
> La **ALU** (_Arithmetic Logic Unit_) è una delle principali componenti della [[cpu|CPU]] che ha il compito di _eseguire le operazioni_, come [[and|AND]], [[or|OR]], addizione, ecc.

Quella zona della CPU che comprende ALU e [[registro|registri generali]] (quindi i suoi _input_ e _output_) viene chiamata **Data Path**.
![[data-path.png]]
In un **ciclo di data path** i valori scritti nell'_ALU output register_ si riscrivono nel registro del risultato (in cima a quelli generali). Questo suddetto ciclo è governato da un [[clock|clock]].

## Referenze