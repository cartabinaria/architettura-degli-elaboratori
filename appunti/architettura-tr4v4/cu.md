---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 22-09-2023 19:21:53
links:
  - "[[lecture-20092023151652|Lecture 20092023151652]]"
---
# CU
---
## Introduzione
> La **CU** (_Control Unit_) è una delle componenti principali della [[cpu|CPU]] che ha il fondamentale compito di _leggere e interpretare le istruzioni_ lette dalla [[ram|RAM]].

Per costruire una componente simile ci sono due alternative[^1]:
- _circuito hardware compatibile con un insieme fissato di istruzioni_ (obsoleto)
	- si costruisce il circuito logico a partire dalla tabella di verità
	- più è grande il set di istruzioni più complesso e costoso diventa costruire il circuito
- _usare la [[microprogrammazione|microprogrammazione]] per determinare il comportamento della CPU_ (moderno)
	- con gli stessi medesimi comportamenti si possono eseguire più istruzioni
	- per eventuali errori o aggiunta di nuove istruzioni basta modificare il microprogramma

## Referenze
[^1]: sono quelle che poi determinano se la CPU sarà di tipo [[cisc-e-risc|CISC o RISC]]