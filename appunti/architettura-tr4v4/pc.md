---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 10:35:15
links:
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# PC
---
## Introduzione
> Il **PC** (_Program Counter_) è uno dei [[registro-registri-speciali|registri speciali]] della [[cpu|CPU]].

## Implementazione
Si differenzia dagli altri registri proprio per la sua implementazione. Dovendo incrementare il suo valore ad ogni esecuzione di istruzione, si possono scegliere due strade:
- la [[alu|ALU]] incrementa il valore di PC
- il PC autonomamente si incrementa

Solitamente si opta per la seconda via. Per questo motivo non può essere implementato come un normale [[w-bit-register|w-bit register]]:
![[program-counter.png]]

### Regole
Ci sono 4 casi:
- `reset=1` --> metto a 0 PC, `out(t)=0` (si utilizza prettamente durante la prima fase di accensione del computer, per evitare che parta da un valore "a caso")
- `load=1` --> quando devo fare un _salto_, `out(t)=in(t-1)`
- `inc=1` --> incremento di 1 il valore precedente, `out(t)=out(t-1)+1`
- `*=0` --> rimango fermo, `out(t)=out(t-1)`

## Referenze