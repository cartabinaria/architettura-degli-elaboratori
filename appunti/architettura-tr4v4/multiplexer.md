---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 27-09-2023 20:33:16
links:
  - "[[lecture-27092023150312|Lecture 27092023150312]]"
  - "[[lecture-28092023130653|Lecture 28092023130653]]"
---
# Multiplexer
---
## Introduzione
Il **Multiplexer** è un componente fondamentale della [[cpu|CPU]] usata dalla [[cu|CU]] per instradare i dati/comandi alle altre componenti.

## Tabella di verità
| A   | B   | sel | out |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 0   |
| 0   | 1   | 0   | 0   |
| 0   | 1   | 1   | 1   |
| 1   | 0   | 0   | 1   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 1   |
| 1   | 1   | 1   | 1   |

Da cui la forma canonica
$$(\neg ABS) + (A \neg B \neg S) + (AB \neg S) + (ABS) = O$$

Riducibile in:

| sel | out |
| --- | --- |
| 0   | A   |
| 1   | B   |

Da cui la reale forma canonica
$$A \neg S + BS = O$$

## Composizione
Il multiplexer _base_ si compone di _3 pin d'ingresso_ e solo uno d'uscita, come in figura.
![[multiplexer.png]]

## Funzionamento
Il multiplexer consente attraverso una serie di **pin selettori** di scegliere quale output far passare tra tutti i normali **pin d'ingresso**. Prendendo per esempio il multiplexer base
- _l'output sarà A se il selettore varrà 0_;
- _l'output sarà B se il selettore varrà 1_.

## Referenze