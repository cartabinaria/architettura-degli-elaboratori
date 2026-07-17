---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 24-11-2023 15:33:48
links:
  - "[[lecture-16112023133640|Lecture 16112023133640]]"
---
# Dirty bit
---
## Introduzione
> Il **dirty bit** è una tecnica usata nella fase di _swapping_ di un [[algoritmi-di-paginazione|algoritmo di paginazione]] per rendere più efficiente tale processo. _Se il blocco nel working set da sostituire non è stato modificato, non ha senso ricopiarlo in memoria di massa_; sarebbe tempo sprecato ri-scrivere la stessa cosa. Quindi ad _ogni blocco di memoria viene associato un bit a 0, che viene modificato a 1 se il blocco è acceduto in scrittura_, per l'appunto sporcato.

## Referenze