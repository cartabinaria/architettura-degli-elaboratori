---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 14-10-2023 15:31:03
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# Full-adder
---
## Introduzione
Un **full-adder** consente di ottenere da 3 bit il risultato della loro somma, sfruttando lo stesso principio dell'[[half-adder|half-adder]].

| A   | B   | C   | sum | carry |
| --- | --- | --- | --- | ----- |
| 0   | 0   | 0   | 0   | 0     |
| 0   | 0   | 1   | 1   | 0     |
| 0   | 1   | 0   | 1   | 0     |
| 0   | 1   | 1   | 0   | 1     |
| 1   | 0   | 0   | 1   | 0     |
| 1   | 0   | 1   | 0   | 1     |
| 1   | 1   | 0   | 0   | 1     |
| 1   | 1   | 1   | 1   | 1     |

## Implementazione
Per ottenere un full-adder da un half-adder bisogna disporre le componenti nel seguente modo:
![[full-adder.png]]

## Referenze