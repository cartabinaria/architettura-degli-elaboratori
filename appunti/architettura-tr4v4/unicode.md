---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
  - topic/tecnologie-web
date: 12-10-2023 20:02:53
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# UNICODE
---
## Introduzione
I problemi dell'[[ascii|ASCII]] hanno portato alla formulazione di una nuova codifica, _retrocompatibile_, **che comprendesse però tutti gli alfabeti e che garantisse l'aggiunta futura di nuovi caratteri**. Questa [[codifica-dei-caratteri|codifica]] si chiama **UNICODE**.

## Definizione
> **UNICODE**, insieme a [[iso-10646|ISO 10646]] (/IEC), rappresentano il _tentativo di creazione di uno standard unico per la codifica di tutti caratteri di tutti gli alfabeti_.

### Principi
- repertorio universale
- efficienza
- caratteri, non glifi
- semantica
- testo semplice
- ordine logico
- unificazione
- composizione dinamica
- stabilità
- convertibilità

## Composizione
Attualmente, la versione più moderna di UNICODE, definisce:
- 154998 caratteri in 168 script diversi
- ~140000 caratteri per scopi privati

divisi in 3 categorie:
1. _script moderni_
2. _script antichi_
3. _segni speciali_

Si compone di 16 bit.

## Problemi
Pur essendo un grande passo in avanti rispetto all'ASCII esso comporta 2 principali problemi:
- gli spazi liberi oramai sono in esaurimento
- si usano sempre 16 bit anche per inviare i caratteri più comuni (proprio quelli dell'ASCII)

## Referenze