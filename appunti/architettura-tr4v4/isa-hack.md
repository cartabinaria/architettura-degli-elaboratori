---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 28-10-2023 13:13:02
links:
  - "[[lecture-25102023150405|Lecture 25102023150405]]"
  - "[[lecture-26102023132035|Lecture 26102023132035]]"
  - "[[lecture-06112023131103|Lecture 06112023131103]]"
---
# ISA HACK
---
## Introduzione
Le istruzioni ISA della [[microarchitettura-hack|microarchitettura HACK]] si dividono in:
- **A-instruction**, semplici istruzioni di assegnamento di valori nel registro `A`
- **C-instruction**, tutte le restanti istruzioni che coinvolgono (_volente o nolente_) la [[alu-hack|ALU]], prelevando i valoti da `A`, `D` e `M` (ovvero `RAM[A]`)

<u>Nota bene</u>: per distinguere tra un'istruzione A e C è necessario dei 16 bit (_word_) di ogni istruzione, in ottica di una microarchitettura a [[circuiti-combinatori|circuito combinatorio]], usare **1 bit di controllo**.

### A-instruction
`@value`

#### Codifica
Il primo bit è a `0` per identificare che si tratta di una A-instruction (_bit di controllo_); i restanti 15 bit rappresentano il _numero codificato in binario_.

### C-instruction
![[c-instruction-isa-hack.png]]

#### Codifica
$$111A \ \ C_{1}C_{2}C_{3}C_{4} \ \ D_{1}D_{2}D_{3} \ \ J_{1}J_{2}J_{3}$$
dove:
- $111$ è la codifica per identificare una C-instruction (primo bit è _bit di controllo_)
- $A \ \ C_{1}C_{2}C_{3}C_{4}$ sono tutte le combinazioni di [[istruzioni-isa-composizione|opcode]] eseguibili dall'ALU e `comp`
- $D_{1}D_{2}D_{3}$ è l'indirizzo del registro `dest`
- $J_{1}J_{2}J_{3}$ è il tipo di `jump`

## Caratteristiche
- di solito i programmi _alternano istruzioni A a istruzioni C_
- fare estrema attenzione alla duplica valenza di `A`: viene sia usato per accedere in [[ram|RAM]] (attraverso `M`), sia per accedere in [[rom|ROM]] (attraverso le istruzioni di _salto_)[^1]

### Etichette
> Le **etichette** (o **labels**) si usano per far riferimento a _specifici indirizzi di memoria ROM_. In particolare, una volta definite assumono per l'[[assemblatore|assemblatore]] il _valore dell'indirizzo posizionale dell'istruzione successiva_.

Dichiarazione: `(nome)`
Utilizzo: `@nome` e quindi `;JMP`

### Variabili
> Le **variabili** si usano invece per far riferimento a _specifici indirizzi di memoria RAM_. Alcune, già predefinite come `SCREEN` e `KBD`, sono riservati a specifiche funzioni; le prime 16 sono richiamabili attraverso la dicitura `@RX` (dove `X` può andare da 0 a 15); infine dalla 16° cella di RAM in poi è possibile dedicare spazio a variabili "create" dal programmatore, assegnate automaticamente.

Variabili riservate:
- `SCREEN`: dall'indirizzo 16384, serve a gestire i pixel dello schermo;
- `KBD`: dall'indirizzo 24576, serve a gestire i codici dei tasti premuti su tastiera;

## Referenze
[^1]: fare riferimento all'[[architettura-hack|architettura HACK]]