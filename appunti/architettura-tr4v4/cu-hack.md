---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 10:53:43
links:
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
  - "[[lecture-06112023131103|Lecture 06112023131103]]"
---
# CU HACK
---
## Introduzione
La **[[cu|CU]] HACK** non è [[microprogrammazione|microprogrammata]]: significa che _funziona a circuito_. La [[microarchitettura-hack|sua microarchitettura]], quindi, prevede l'utilizzo di [[circuiti-combinatori|circuiti combinatori]].

## Input e output
- inputs:
	- [[isa-hack-a-instruction|A-instruction]]
	- [[isa-hack-c-instruction|C-instruction]]
- outputs:
	- _OP_ALU_ ([[istruzioni-isa-composizione|opcode]] della [[alu-hack|ALU]])
	- _MUX_A_
	- _MUX_ALU_
	- _W_A_
	- _W_D_
	- _writeM_ ([[ram-implementazione|load]] della [[ram|RAM]])
	- _W_PC_ (in caso di [[salto-informatico|salto]])

## Referenze