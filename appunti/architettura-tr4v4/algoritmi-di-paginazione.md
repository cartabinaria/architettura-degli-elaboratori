---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 24-11-2023 15:05:49
links:
  - "[[lecture-16112023133640|Lecture 16112023133640]]"
---
# Algoritmi di paginazione
---
## Introduzione
> Gli **algoritmi di paginazione** sono [[algoritmo|algoritmi]] che, a seguito della scatenazione della [[trap|trap]] _[[page-fault|page fault]]_ nella fase di traduzione di un indirizzo virtuale a fisico nel contesto della [[paginazione|paginazione]], _determinano quale tra le pagine del working set (in [[ram|RAM]]) è da togliere per sovrascrivere quella richiesta_.

E' ovvio che nel caso migliore, in cui la RAM abbia dei blocchi liberi, questo problema non si verifichi:
![[page-fault.png]]

## Obiettivi
L'obiettivo di un algoritmo di paginazione è quello di **minimizzare il numero di page fault** e quindi il numero di accessi alla memoria secondaria, che sono molto più lenti rispetto agli accessi alla memoria principale.

Tali algoritmi sono valutati sulla base del numero di accessi alla memoria secondaria data una certa sequenza di accessi alla memoria virtuale, detta **stringa di riferimenti** (generata casualmente o in modo deterministico).

<u>Nota bene</u>: della stringa di riferimenti si considera solo la parte che riguarda le pagine, non gli offset.

Ci si aspetta che piu' frame abbiamo, meno page fault si verifichino. In realta' non e' cosi': [[anomalia-di-belady|anomalia di Belady]].

## Algoritmi
- [[fifo-paginazione|FIFO paginazione]]
- [[min-paginazione|MIN paginazione]]
- [[lru|LRU]]
- [[lfu|LFU]]

Per entrambe le politiche si utilizza, in aggiunta, una tecnica chiamata [[dirty-bit|dirty bit]].

## Referenze
- [slide di approfondimento](https://cs.unibg.it/gherardi/so2013/slides/10.pdf)
- [[algoritmo-a-stack|Algoritmo a stack]]