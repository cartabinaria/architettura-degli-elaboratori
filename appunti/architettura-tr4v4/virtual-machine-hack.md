---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 25-11-2023 13:11:06
links:
  - "[[lecture-22112023151203|Lecture 22112023151203]]"
  - "[[lecture-23112023130836|Lecture 23112023130836]]"
---
# Virtual machine HACK
---
## Introduzione
> La **virtual machine HACK** è una [[virtual-machine|virtual machine]] che funge da _livello intermedio tra programmi scritti ad alto livello e l'[[isa-hack|ISA]] del [[computer-hack|computer HACK]]_.

In particolare la VM HACK viene impegnata nella fase di [[compilazione-a-2-livelli|compilazione a 2 livelli]]. Infatti:
- _prima compilazione_, linguaggio _ad alto livello_ ([[jack|JACK]]) --> linguaggio della _virtual machine_;
- _seconda compilazione_, linguaggio della _virtual machine_ --> linguaggio _[[assembly|assembly]]_.

## Caratteristiche
La virtual machine HACK viene implementata a [[stack|stack]] ([[pila|pila]]): ogni istruzione si realizza mediante il `push` e il `pop` dei dati in un _segmento di memoria virtuale_ (appunto lo _stack_).

### Comandi
I comandi, essendo strutturati a pila, seguono la [[notazione-prefissa|notazione polacca]].
![[comandi-virtual-machine-hack.png]]

Caricati quindi due generici `x` e `y` in stack (con due `push`), mediante un `add` i due valori vengono sommati e il risultato viene sovrascritto in `x` (`y` viene perso).
![[somma-virtual-machine-hack.png]]

Allo stesso modo, le operazioni di confronto quali `eq`, `gt` e `lt`, confrontano i due valori antecedenti lo [[sp|stack pointer]] e scrivono un risultato booleano (`1` o `0`) al posto del 1° operando.

![[operazioni-aritmetico-logiche-vm-hack.png]]

#### Esempio
```nasm
push 5    ; mette in stack 5, SP++
push b    ; mette in stack il valore di 'b', SP++
add       ; somma stack[SP-1] a stack[SP-2], SP--
pop a     ; SP--, salva il valore di stack[SP] in 'a'
```

### [[segmentazione|Segmentazione]]
La _virtual machine HACK sfrutta la segmentazione per astrarre ancora di più la memoria virtuale da quella fisica_: ogni variabile non fa riferimento alla [[ram|RAM]], ma al segmento specifico a cui appartiene in memoria.

Per cui si introdurranno spazi di indirizzamento virtuali usati per scopi diversi, tra cui:
- `argument` - _parametri formali della funzione invocata_
- `local` - _variabili locali della funzione invocata_
- `static` - _variabili globali, condivise da tutte le funzioni_
- `constant` - _costanti (read-only), [[numeri-naturali|numeri naturali]]_
	- trucchetto usato per semplificare l'utilizzo di numeri diretti nelle istruzioni VM
	- per esempio `push 5` prende il `5` da `constant`

Perciò per ogni [[invocazione-di-procedura|funzione invocata]] verranno _allocati due segmenti specifici_ `argument` e `local` che saranno deallocati a fine esecuzione. Agiranno, insomma, da _veri e propri [[record-di-attivazione|record di attivazione]]_.

<u>Osservazione</u>: la segmentazione _complica la gestione della memoria a livello di compilazione del secondo livello_ (da VM a ISA), ma _semplifica la compilazione del primo livello_ (da JACK a VM).

#### Esempio
Rifacendoci all'esempio di prima, le istruzioni con segmentazione assumerebbero la seguente forma:
```nasm
push constant 5
push static 1    ; dove 1 è l'indirizzo nel segmento static di 'b'
add
pop static 0     ; dove 0 è l'indirizzo nel segmento static di `a`
```

### Funzioni
Le _subroutine_ giocano un ruolo primario nella scrittura di codice VM. Si hanno 3 principali comandi relativi ad esse:
- `function g nVars`
- `call g nArgs`
- `return`

Ognuno di questi lavora in background per garantire una corretta creazione dei record di attivazione delle funzioni. In particolare ci si basa sul **protocollo call-and-return**, secondo cui:
- il _chiamante_, deve:
	- pushare gli argomenti in cima allo stack
	- invocare la funzione con `call`
	- aspettare il `return`
	- recuperare dalla cima dello stack il valore di ritorno
- il _chiamato_, deve
	- usare gli argomenti passati dal chiamante nel suo segmento `argument`
	- usare le variabili locali nel suo segmento `local` inizializzate tutte a 0
	- svolgere il suo compito usando lo stack del suo _working set_
	- eseguire il `return` solo quando so di aver lasciato nello stack del working set solo il valore di ritorno

#### Nel dettaglio
![[implementazione-call-vm-hack.png]]
![[implementazione-function-vm-hack.png]]
![[implementazione-return-vm-hack.png]]

che come effetto finale producono:
![[implementazione-invocazione-di-procedura-vm-hack.png]]

## Implementazione fisica
La virtual machine HACK come visto è estremamente virtualizzata, e **richiede un lavoro un più nell'implementazione fisica della memoria**, in particolare in merito alla segmentazione.
![[implementazione-fisica-vm-hack.png]]

Dall'immagine notiamo la presenza di una serie di puntatori inizializzati ai primi indirizzi della RAM, tra cui:
- `SP`, lo [[sp|stack pointer]] che contiene l'indirizzo corrente dello stack
- `LCL`, che contiene l'indirizzo corrente della prima cella del segmento `local` della funzione invocata
- `ARG`, che contiene l'indirizzo corrente della prima cella del segmento `argument` della funzione invocata
- `THIS`, `THAT` riguardano l'`heap`

Quindi si ha il primo segmento `static`, che contiene tutte le _variabili globali mappate e gestite dall'assemblatore_[^1].

Poi il segmento `stack`, che conterrà sia i _record di attivazione delle funzioni invocate_ (quindi `argument` e `local`) sia lo _stack virtuale usato dalla funzione in esecuzione_, detto **stack del working set**.

## Referenze
[^1]: ricorda che `@x` in ISA HACK assegna alla prima cella libera da RAM[16] in poi una nuova locazione