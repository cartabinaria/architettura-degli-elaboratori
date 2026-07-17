---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-09-2023 21:45:07
links:
  - "[[lecture-18092023130242|Lecture 18092023130242]]"
  - "[[lecture-27092023150312|Lecture 27092023150312]]"
---
# NAND
---
## Definizione
> Il **NAND** (_NOT-AND_) è una delle [[porte-logiche|porte logiche]] dell'[[algebra-di-boole|algebra booleana]].

[[tabella-di-verita|Tabella di verità]]:

| A   | B   | NAND(A, B) |
| --- | --- | ---------- |
| 0   | 0   | 1          |
| 0   | 1   | 1          |
| 1   | 0   | 1          |
| 1   | 1   | 0          |

## Caratteristiche
Il NAND è una **porta universale**, il che significa che consente di realizzare tutte le altre porte logiche _a partire da se stessa_. E' inoltre estremamente facile da realizzare attraverso l'utilizzo di [[transistor|transistors]], e per questo solitamente utilizzata in tutti i [[circuiti-combinatori|circuiti combinatori]].

### Universalità
#### NOT
![[not-nand.png]]

#### AND
![[and-nand.png]]

#### OR
![[or-nand.png]]

## Dimostrazione
Cerchiamo di dimostrare perché il NAND è una porta universale. Intanto, partiamo dal fatto che se è universale significa che _con una combinazione di esse posso rappresentare ogni tabella di verità_ (e quindi risolvere ogni circuito combinatorio). Ebbene noi sappiamo che a partire _da una qualsiasi tabella di verità possiamo ricondurci sempre alla [[forma-canonica-booleana|forma canonica]]_, che a sua volta è una _espressione composta da una combinazione standard di soli NOT, AND e OR_.

Sapendo che queste 3 porte logiche sono implementabili con il NAND **abbiamo dimostrato che il NAND è una porta universale**.

## Referenze