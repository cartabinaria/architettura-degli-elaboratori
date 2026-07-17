---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 10:52:17
links:
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
  - "[[lecture-18102023151217|Lecture 18102023151217]]"
  - "[[lecture-25102023150405|Lecture 25102023150405]]"
---
# Microarchitettura HACK
---
## Introduzione
![[microarchitettura-hack.png]]

La [[microarchitettura|microarchitettura]] HACK ([[cpu-hack|CPU HACK]]) è una **macchina a 16-bit** molto simile a quella dei nostri computer: è solo, a parità di cicli di [[clock|clock]], _estremamente più lenta perché non ottimizzata_. Essa dipende, ovviamente, dal linguaggio [[assembly|assembly]] ([[isa|ISA]]) con cui è implementata.

## Componenti
Sono presenti rispettivamente:
- [[alu|ALU]] ([[alu-hack|ALU HACK]])
	- il secondo input può essere il registro `A` oppure un dato proveniente dalla [[ram|RAM]]
- un [[registro-registri-generali|registro generale]] `D`, che contiene uno dei due operandi della ALU e può memorizzare un precedente output
- un altro registro generale `A`, che contiene un dato che fa parte delle istruzioni, un precedente output o è utilizzato per puntare a un indirizzo di memoria
- un [[pc|PC]], cui valore può essere impostato dal registro `A` (in caso di _salto_)

Il flusso di dati tra tutte queste componenti è regolato da [[multiplexer|Multiplexer]] e _bit di controllo_ (segnati con `c`): il tutto è **gestito da una microarchitettura composta da [[circuiti-combinatori|circuiti combinatori]]**.
Infatti il [[ciclo-di-fetch-decode-execute|ciclo di fetch-decode-execute]] viene eseguito in un solo ciclo di clock: l'istruzione in ingresso al tempo `t` viene completamente eseguita al tempo `t+1`.

<u>Nota bene</u>: il bus indicato con `writeM` è il `load` della [[ram|RAM]] (a `1` quando si scrive, a `0` quando si legge).

## Vantaggi e svantaggi
L'utilizzo di soli due registri generali `D` e `A`, pur semplificando l'architettura della ALU, di certo complica molto l'implementazione di alcune istruzioni di alto livello. Per esempio, _l'unica maniera per salvare risultati temporanei della ALU sarebbe quella di utilizzare celle di RAM "innocue"_.

## Referenze