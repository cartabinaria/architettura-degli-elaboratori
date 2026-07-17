---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 12-10-2023 23:00:54
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# ALU HACK
---
## Introduzione
All'interno dell'[[architettura-hack|architettura HACK]] troviamo nel processore la [[alu|ALU]], raffigurata nella seguente immagine.
![[alu-hack.png]]
## Composizione
L'[[interfaccia|interfaccia]] si compone quindi di:
- `x`, `y` --> _dati di input_ su cui svolgere le operazioni (a 16 bit)
- `zx`, `nx`, `zy`, `ny`, `f`, `no` --> _controlli_ per decidere le operazioni da fare
- `out` --> _dati di output_ (a 16 bit)
- `zr`, `ng` --> _flag di output_

Internamente, però, **la ALU è in grado di fare principalmente somme**. Non ha altri circuiti per le altre operazioni matematiche, per intenderci... Il [[circuiti-combinatori|circuito combinatorio]] che consente di fare la somma tra due numeri a 16 bit si chiama [[adder|Adder]].

Oltre agli Adder, la ALU si compone di [[not|NOT]] e [[and|AND]]: può quindi anche _nottare_ dei bit e fare _and_ bit-a-bit.

### Bit di controllo
> Il tipo di operazione da svolgere sui due ingressi è stabilito dalla combinazione dei bit di controllo.

![[bit-controllo-alu-hack.png]]

Si nota come si utilizzi un _sistema di combinazioni di bit di controllo per svolgere tutte le 18 operazioni implementate dalla ALU_. L'alternativa sarebbe stata fare 18 circuiti separati ognuno capace di svolgere la sua operazione e un grande [[multiplexer|multiplexer]] per indirizzare A e B sull'operazione richiesta. Insomma, non particolarmente efficiente...

Importante, per esempio, notare che per fare l'[[or|OR]] si utilizzino le [[leggi-di-de-morgan|leggi di De Morgan]] così da sfruttare i soli circuiti AND e OR presenti nella ALU.

### Flag di output
I flag di output rappresentano lo **stato** della ALU, ovvero il risultato dell'ultima operazione eseguita. In particolare:
- `zr` è a 1 quando il risultato dell'ultima operazione è 0
- `ng` è a 1 quando il risultato dell'ultima operazione è minore di 0

### Output
Gli output che l'ALU HACK può avere sono:
- `x+y`, `x-y`, `y-x`
- `0`, `1`, `-1`
- `x`, `y`, `-x`, `-y`
- `!x`, `!y`
- `x+1`, `y+1`, `x-1`, `y-1`
- `x&y`, `x|y`

## Caratteristiche
La ALU HACK funziona in [[complemento-a-2|complemento a 2]], ed essendo solo in grado di fare somme, per fare le differenze bisogna usare un po' di [[algebra-di-boole|algebra booleana]]. Lo stesso vale per esempio per l'incremento: se si vuole fare `x+1`, l'1 da dove si prende? E' difficile da ottenere, mentre è più semplice avere -1 (perché in complemento a 2 sono tutti i bit a 1). Come trasformiamo `x+1` in un'espressione che utilizzi `-1`?

### Sottrazioni
Se vogliamo fare `x-y` ma abbiamo a disposizione solo [[circuiti-combinatori|circuiti combinatori]] in grado di fare la somma, trasformiamo l'espressione:
```
x-y = 
-(-x+y) = 
-(!x+1+y) = //per la conversione del complemento a 2
-(!x+y)-1 =
!(!x+y)+1-1 =
!(!x+y)
```

Quindi `x-y`, in ALU verrà eseguito come `!(!x+y)`.

### Incremento
Per passare da `x+1` a un'espressione che utilizzi -1 seguiamo i seguenti step:
```
x+1 =
x-(-1) =
!(!x+(-1)) //sfruttiamo la formula per la sottrazione sopra dimostrata
```

Quindi `x+1` diventerà `!(!x+(-1))`.

## Referenze