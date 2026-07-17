---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 12-10-2023 22:40:40
links:
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
---
# Distanza di Hamming
---
## Introduzione
> La **distanza di Hamming** tra due sequenze di bit è il _numero di bit rispetto ai quali le due parole differiscono_. Nel caso di un [[codici-correttori|codice correttore]], la distanza di Hamming è la _minima distanza di Hamming_ tra _parole di codice_ (cioè quelle corrette).

## Regole
- per rilevare $d$ bit errati è necessario un codice con distanza di Hamming $\geq d+1$
- per correggere $d$ bit errati è necessario un codice con distanza di Hamming $\geq 2d+1$

## Referenze