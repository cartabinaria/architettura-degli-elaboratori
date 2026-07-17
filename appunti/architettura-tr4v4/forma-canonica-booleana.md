---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 27-09-2023 20:14:01
links:
  - "[[lecture-27092023150312|Lecture 27092023150312]]"
---
# Forma canonica booleana
---
## Introduzione
La **forma canonica** nell'[[algebra-di-boole|algebra booleana]] è uno dei metodi standard per passare da una [[tabella-di-verita|tabella di verità]] alla costruzione del circuito che la implementa.

Nonostante la usuale complessità del circuito risultante, con la forma canonica si è certi che per quanto lunga e complicata sia corretta.

## Composizione
Si ottiene con i seguenti passi:
1. componiamo per ogni riga un _mintermine_ (mettendo in [[and|AND]] gli ingressi tra di loro e negandoli così da far venire 1)
2. mettiamo in [[or|OR]] i mintermini che in uscita si vuole diano 1

### Esempio
Se abbiamo una funzione booleana
$$s(a, m, w) = \neg a (m + w)$$la sua tabella di verità è:

| a   | m   | w   | minterm                | s(a,m,w) |
| --- | --- | --- | ---------------------- | -------- |
| 0   | 0   | 0   | $\neg a \neg m \neg w$ | 0        |
| 0   | 0   | 1   | $\neg a \neg m w$      | 1        |
| 0   | 1   | 0   | $\neg a m \neg w$      | 1        |
| 0   | 1   | 1   | $\neg a m w$           | 1        |
| 1   | 0   | 0   | $a \neg m \neg w$      | 0        |
| 1   | 0   | 1   | $a \neg m w$           | 0        |
| 1   | 1   | 0   | $a m \neg w$           | 0        |
| 1   | 1   | 1   | $a m w$                | 0        |

Per cui la forma canonica verrebbe
$$s(a,m,w) = (\neg a \neg m w) + (\neg a m \neg w) + (\neg a m w)$$

## Referenze
- [[pla|PLA]]