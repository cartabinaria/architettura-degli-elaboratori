---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 05-11-2023 21:44:43
links:
  - "[[lecture-02112023130607|Lecture 02112023130607]]"
---
# Modalità di indirizzamento
---
## Introduzione
Per reperire gli operandi delle [[istruzioni-isa|istruzioni ISA]] esistono 6 modalità di indirizzamento differenti:
- **indirizzamento immediato** --> l'operando si trova già integrato nell'istruzione[^1]
- **indirizzamento diretto** --> l'istruzione contiene l'indirizzo completo della cella da cui reperire l'operando
- **indirizzamento a [[registro|registro]]** --> l'operando viene prelevato da un registro
- **indirizzamento a registro indiretto** --> l'operando viene prelevato dalla [[ram|memoria]] a un indirizzo puntato da un registro[^2]
- **indirizzamento indicizzato** --> l'istruzione include un _offset_ che viene sommato al contenuto di un registro per ottenere l'indirizzo di memoria da cui prelevare l'operando[^3][^4]
- **indirizzamento a [[stack|stack]]** --> l'istruzione compie operazioni sullo stack, effettuando operazioni di _push_ e _pop_[^4]

## Referenze
[^1]: come avviene per le _A-instruction_ dell'[[isa-hack|ISA HACK]]
[^2]: sempre come nel caso del ruolo del registro A nelle _C-instruction_ dell'ISA HACK
 [^3]: utili per gli [[array|array]]
 [^4]: utili nella gestione dei [[record-di-attivazione|record di attivazione]]