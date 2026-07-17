---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 05-11-2023 22:14:28
links:
  - "[[lecture-02112023130607|Lecture 02112023130607]]"
---
# Invocazione di procedura
---
## Introduzione
Nell'esecuzione di un [[programma|programma]] informatico è estremamente frequente la chiamata di [[funzione-informatica|funzioni]]. A basso livello questo comporta una serie di operazioni che vengono svolte in quella porzione di [[ram|memoria]] [[allocazione-dinamica-della-memoria-dei-programmi|allocata]] all'esecuzione del programma chiamata [[stack|stack]].

## Fasi
L'invocazione di procedura si compone di 2 fasi:
1. **call**, l'invocazione vera e propria
2. **return**, il ritorno di eventuali valori e del controllo al processo chiamante

Graficamente, ciò che accade a un programma che prevede l'utilizzo di funzioni si presenta nel seguente modo:
![[invocazione-procedura.png]]

## Implementazione
Nel dettaglio, invocare una procedura richiede di **allocare in memoria le informazioni necessarie ad eseguire le procedure invocate**. Questo spazio viene chiamato _[[record-di-attivazione|record di attivazione]]_, ed è proprio lui che viene memorizzato nello stack del programma chiamante.

## Automazioni
Esistono casi particolari di invocazioni di procedure che sono gestite autonomamente dal [[sistema-operativo|sistema operativo]] (e non da programmi scritti da noi):
- [[trap|trap]]
- [[interrupt|interrupt]]

## Referenze