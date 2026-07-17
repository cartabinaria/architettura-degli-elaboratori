---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 12-10-2023 20:14:28
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
---
# Codici correttori
---
## Introduzione
Nel momento in cui salviamo, o trasmettiamo, dei dati informatici (quindi in [[codice-binario|codifica binaria]]), si incorre molto facilmente in errori che _corrompono_ tali dati, compromettendone il loro utilizzo.

Per questo motivo si sviluppano delle **tecniche capaci di rilevare e talvolta correggere gli errori** nei dati.

## Principi base
> Per poter determinare la presenza di errori ed eventualmente correggerli, ai dati di partenza è necessario aggiungere **informazioni in più**.

Prendiamo:
- $m$ come il numero di bit di dati
- $r$ come il numero di bit di controllo
- $n = m + r$ come il numero di bit totali

Il numero di combinazioni di parole sbagliate di 1 solo bit a partire da quelle corrette sono
$$2^{m}(1+n)$$
perché:
- $1$ --> la sua versione corretta
- $n$ --> per ogni suo bit ($m + r$) modificato

Le totali combinazioni possibili di bit che formano parole sono
$$2^{n}$$

Il nostro obiettivo dev'essere quello di poter, a partire _da una qualunque parola sbagliata_ (appartenente quindi a quel $2^{n}$), ricavare _a quale parola giusta si avvicina di più_. Se il numero di combinazioni possibili è più piccolo del numero di combinazioni di parole sbagliate di 1 solo bit a partire da quelle corrette allora non siamo più in grado di sapere, a partire da una parola sbagliata, da quale parola giusta sia partita. Vorrebbe infatti dire che una sola parola sbagliata può essere derivante da due giuste. _Le soluzioni si overlappano_!

Per questo dobbiamo trovare un valore di $r$ che ci consenta di soddisfare la disuguaglianza
$$2^{m}(n+1) \leq 2^{n}$$

Se la disuguaglianza è soddisfatta allora significa che per ogni parola sbagliata possiamo ricavare quella giusta. Infatti _se il numero di parole sbagliate di un bit ottenuto da quelle giuste è minore di tutte le parole possibili, allora vuol dire che queste sono tutte diverse_, e quindi distinguibili (non hanno possibilità in comune).

Dalla disequazione si ricava che
$$1 + m + r \leq 2^{r}$$

Da questo presupposto si costruiscono tutte le tecniche sotto-elencate.

## Tecniche principali
Prima di entrare nel vivo delle tecniche occorre conoscere bene la [[distanza-di-hamming|distanza di Hamming]].
- [[bit-di-parita|Bit di parità]]
- [[codice-di-hamming|Codice di Hamming]]

## Referenze