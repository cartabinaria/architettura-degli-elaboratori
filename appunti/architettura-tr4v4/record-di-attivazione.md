---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
  - topic/linguaggi-di-programmazione
date: 05-11-2023 22:34:02
links:
  - "[[lecture-02112023130607|Lecture 02112023130607]]"
  - "[[lecture-20022025131602|Lecture 20022025131602]]"
---
# Record di attivazione
---
## Introduzione
Nel contesto dell'[[invocazione-di-procedura|invocazione di procedura]], è necessario salvare una serie di informazioni necessarie all'esecuzione della [[funzione-informatica|funzione]]/procedura in uno spazio salvato in [[stack|stack]] chiamato **record di attivazione**.

## Principio di funzionamento
Esso stesso è strutturato come una _pila_, in modo tale da poter essere "impilati" uno sull'altro nello stack. L'idea di base è comprendere che **quando termina l'esecuzione di una procedura, il suo record di attivazione deve "passare la palla" alla procedura che l'ha invocata**. Nel caso, in particolare, della [[ricorsione|ricorsione]], una procedura invoca se stessa un numero indefinito di volte, fino a terminare: _l'ultima procedura invocata dovrà restituire il controllo a quella precedente, e così via fino a tornare al processo chiamante_.

Per tener traccia, all'interno dello stack, del record di attivazione attualmente in esecuzione, vi è un registro specializzato chiamato **Frame Pointer** ([[fp|FP]]).

## Composizione
Un recordo di attivazione si compone di:
- _parametri di invocazione_ --> i cosiddetti [[funzione-informatica-invocazione|parametri attuali]]
- _indirizzo di ritorno_ --> l'indirizzo del [[pc|PC]] al momento dell'invocazione della procedura, per poter rimettere in esecuzione il chiamante
- _vecchio frame pointer_ --> per ripristinare l'FP al momento del ritorno al chiamante
- _variabili locali_ --> dichiarate nella [[funzione-informatica-definizione|definizione della funzione]]

Tecnicamente, a seconda del tipo di [[blocco|blocco]] cambia il tipo di dato salvato nel record di attivazione allocato. In particolare si parla di:
- _blocchi anonimi_;
- _procedure/funzioni_.

### Blocchi anonimi
I record di attivazione dei blocchi anonimi contengono:
- [[puntatore|puntatore]] di [[catena-dinamica|catena dinamica]];
- variabili locali;
- risultati intermedi;

<u>Nota bene</u>: in realtà, in molti [[linguaggio-di-programmazione|linguaggi]] non c'è una reale manipolazione della pila per i blocchi anonimi.

### Procedure/funzioni
I record di attivazione delle funzioni, invece, contengono:
- puntatore di catena dinamica;
- puntatore di [[catena-statica|catena statica]];
- indirizzo di ritorno;
- indirizzo del risultato;
- parametri;
- variabili locali;
- risultati intermedi;

Il tutto sarà gestito come da immagine:
![[gestione-stack.png]]

Servono quindi:
- **link dinamico** --> per consentire di fare `POP` senza sapere la dimensione del record (possono avere dimensioni differenti);
- **puntatore RdA** --> per consentire di risalire facilmente alle variabili locali (con un offset, calcolato dal compilatore a _compile-time_);

## Referenze