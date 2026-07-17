---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 22-10-2023 21:25:50
links:
  - "[[lecture-19102023130600|Lecture 19102023130600]]"
---
# Pre-fetch
---
## Introduzione
> Il **pre-fetch** è una tecnica sviluppata per ottenere una maggiore efficienza del [[ciclo-di-fetch-decode-execute|ciclo fetch-decode-execute]] della [[cpu|CPU]].

## Funzionamento
> Il pre-fetch, come suggerisce il nome stesso, _carica l'istruzione successiva in CPU mentre l'istruzione corrente viene eseguita_.

Se si sta eseguendo l'istruzione 85, c'è un'alta probabilità (non 100% per via dei _salti_) che la successiva sia l'86.

Viene utilizzato un apposito hardware per questo: [[ifu|IFU]], **Instruction Fetch Unit**.

## Referenze