---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 05-11-2023 21:37:44
links:
  - "[[lecture-02112023130607|Lecture 02112023130607]]"
---
# Istruzioni ISA
---
## Introduzione
Il [[isa|livello ISA]] si compone di una serie ben definita di istruzioni, a seconda della microarchitettura dello specifico processore in questione.

## Composizione
Le istruzioni ISA si compongono di due principali parti:
- **opcode** (_codice operativo_) --> indica il tipo di istruzione da eseguire[^1], e può essere riferito a
	- _operazioni di trasferimento dati_
	- _operazioni aritmetico-logiche binarie_ (quelle previste dalla [[alu|ALU]])
	- _operazioni unarie_
	- _[[salto-informatico|salti]]_
	- _[[invocazione-di-procedura|invocazione di procedura]]_
- **address** (_indirizzo/i_) --> indica gli operandi da utilizzare, in funzione delle diverse [[modalita-di-indirizzamento|modalità di indirizzamento]]

### Formati
A seconda dei diversi _codici operativi_ si distinguono diversi formati di istruzioni ISA:
- `opcode`
- `opcode address`
- `opcode address1 address2`
- `opcode address1 address2 address3`

<u>Nota bene</u>: a seconda del tipo di formato, _il campo dedicato ad ogni parte dell'istruzione potrebbe dedicare più o meno spazio_; vale quindi sia per il codice operativo che per gli indirizzi.

## Referenze
[^1]: nel caso dell'[[isa-hack|ISA HACK]] questo occupa 1 solo bit (per distinguere da _A-instruction_ a _C-instruction_)