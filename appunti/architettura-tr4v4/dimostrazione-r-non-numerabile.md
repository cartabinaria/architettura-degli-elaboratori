---
tags:
  - category/note
  - status/finished
  - topic/analisi-I
  - topic/logica-per-informatica
  - topic/programmazione
  - topic/architettura-degli-elaboratori
date: 01-10-2023 12:11:41
links:
  - "[[lecture-29092023135952|Lecture 29092023135952]]"
  - "[[lecture-12102023091734|Lecture 12102023091734]]"
---
# Dimostrazione R non numerabile
---
## Introduzione
Vogliamo dimostrare che $\mathbb{R}$, l'insieme dei [[numeri-reali|numeri reali]] appartenga ad un **ordine di infinito superiore** a $\mathbb{N}$, l'insieme dei [[numeri-naturali|numeri naturali]]. Per farlo dobbiamo dimostrare che non può esistere una [[funzione-biiettiva|funzione biunivoca]] tra $\mathbb{N}$ e $\mathbb{R}$.

## Dimostrazione
[[dimostrazione-per-assurdo|Per assurdo]], supponiamo che tale funzione esista, dimostrando che l'intervallo $[0, 1[$ sia numerabile. Quindi
$$f: \mathbb{N} \to [0, 1[ \ su \ ,1-1$$
per cui
$$f(n) \in [0, 1[$$
dove $n \in \mathbb{N}$.
Ad ogni numero naturale associamo allora un numero nell'intervallo $[0, 1[$, ottenendo una struttura algebrica del genere:
![[n-to-r.png]]

Per "rompere" la biiettività ci basta dimostrare l'esistenza di un numero $r$ che non esiste in questa successione. Quindi
$$r \in [0, 1[ : f(n) \neq r \ \forall n \in \mathbb{N}$$
La prova di questo enunciato va al matematico [[georg-cantor|Cantor]], che utilizza il cosiddetto **procedimento diagonale**. Definisce $r$ come
$$r := 0, r_{1} \ r_{2} \ r_{3} \ ...$$
e tutte le $r_{j}$ cifre di $r$ come
$$r_{j} = \begin{cases} 5 & \text{se } b_{jj} \neq 5 \\ 6 & \text{se } b_{jj} = 5 \end{cases}$$
Con questo algoritmo si garantisce che $r_{j} \neq b_{jj}$, il risultato più importante.
![[procedimento-diagonale-cantor.png]]

Si dimostra quindi che
$$r \neq f(n) \ \forall n \in \mathbb{N}$$
per cui $f: \mathbb{N} \to [0, 1[$ **non è suriettiva**. Assurdo.

## Conseguenze
Con questa dimostrazione si ottiene un risultato sbalorditivo: i buchi di $\mathbb{Q}$ coperti da $\mathbb{R}$ sono molti di più di quanto ci si potesse aspettare. Se si prende un punto a caso della "retta completa $\mathbb{R}$" **c'è molta più probabilità di beccare un numero reale che razionale**!

Anzi, **la probabilità di pescare tra i numeri reali un numero naturale è 0**.

### In informatica
L'informatico in [[ram|memoria]] può rappresentare solo insiemi numerabili, _non ci sono modi per rappresentare i reali_. Tutto **ciò che è programmabile è numerabile**, ogni funzione è programma; invece le **[[funzione-matematica|funzioni matematiche]] non sono enumerabili**.

Infatti **la probabilità di pescare una funzione matematica implementabile in informatica è sempre pari a 0**.

## Referenze
- [info](https://www.math.cmu.edu/~rcristof/pdf/Cantor_pubblicato.pdf)