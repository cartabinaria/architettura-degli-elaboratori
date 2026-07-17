---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 21:53:37
links:
  - "[[lecture-21092023130150|Lecture 21092023130150]]"
  - "[[lecture-19102023130600|Lecture 19102023130600]]"
---
# Pipelining
---
## Introduzione
Il **pipelining** nasce come estensione del cosiddetto [[pre-fetch|pre-fetch delle istruzioni]], sfruttandone il principio alla base per creare un'efficiente [[parallelismo|parallellizzazione]] delle fasi del [[ciclo-di-fetch-decode-execute|ciclo fetch-decode-execute]] della CPU.

## Funzionamento
Se quindi con il pre-fetch si ha in contemporanea _fetch_ ed _execute_ delle istruzioni, con il **pipelining** si sfruttano le diverse componenti della [[cpu|CPU]] coinvolte nel _ciclo di fetch-decode-execute_ per poter eseguire in contemporanea le differenti _fasi_ del ciclo, come una **catena di montaggio**.

Per esempio, se queste sono le unità coinvolte nel processo d'esecuzione di un'istruzione
![[step-ciclo-fetch-decode-execute.png]]

allora con il pipelining si potrebbe arrivare ad eseguire _fino a 5 step in contemporanea_, come in figura:
![[pipelining.png]]

<u>Nota bene</u>: **il numero di step del ciclo eseguibili contemporaneamente equivale quindi al numero di unità coinvolte nel processo**.

Quello che avviene è che se _prima in un ciclo di clock si faceva fetch-decode-execute di una singola istruzione_, _ora invece ogni fase dura 1 ciclo di clock ma questo dura 5 volte meno_!

### Esempio
Supponiamo di avere una [[microarchitettura|microarchitettura]] senza pipeline cui periodo di clock dura 3 microsecondi. Significa che un'istruzione viene eseguita in quel periodo, perché _fetch decode ed execute vengono eseguiti in sequenza_, una dopo l'altra, in un unico ciclo.

Se su questa microarchitettura implementiamo il pipeline, riducendo il periodo di clock a 1 microsecondo (uno per ogni fase), grazie alla parallellizzazione delle fasi avremo un **throughput** di 3 istruzioni eseguite in 3 microsecondi: _ogni 3 cicli di clock verranno fatti 3 fetch, 3 decode e 3 execute_.
![[Drawing 2023-10-22 21.52.03.excalidraw|500]]

### Problematiche
#### Salti
Il problema fondamentale del pipeline è la presenza di eventuali _salti_ che **dovrebbero essere "previsti" prima di eseguire l'istruzione successiva**... non vogliamo eseguire un'istruzione che non dovrebbe essere eseguita. Il problema risulta grave quando si ha presente che nella programmazione i salti sono molto frequenti[^1].

Per risolvere il problema si fa un distinguo tra i _salti condizionati_ e i _salti incondizionati_.

##### Salti incondizionati
E' possibile, una volta eseguito il _decode_ di un `JMP`, accorgersi che si tratti di un salto e quindi **scartare il fetch dell'istruzione successiva**. In questo modo, si perde un solo ciclo di clock: mentre il salto viene eseguito viene fatto il fetch dell'istruzione "giusta"; quindi il fetch dell'istruzione seguente viene fatto solo durante il decode di quella "giusta", e così via, Fondamentalmente _viene ritardata di 1 ciclo di clock tutta la pipeline_, andando a creare una sorta di _linea di gap di istruzioni_.
![[Drawing 2023-10-22 22.23.05.excalidraw|500]]

La situazione si _complica quando il salto prevede eventuali operandi_, come per `JMP X` o `JMP X+4`. In tal caso, prendendo in considerazione un reale ciclo di fetch-decode-execute composto di almeno 5 fasi, **prima del fetch dell'istruzione successiva bisognerebbe non solo aver eseguito il _decode_, ma anche il _fetch degli operandi_ ed eventualmente l'esecuzione dell'operazione**. In tal caso i cicli di clock persi aumentano, e la pipeline si ritarda.

A livello di [[compilatore|compilatore]], la soluzione più adattiva al problema consiste nell'aggiungere subito dopo i _salti_ un numero di `NOP` (_No-Operation_) tanti quanti sono i cicli di clock che andrebbero persi con quel salto. Questo semplicemente serve a _non far fare fetch inutili alla CPU_.

##### Salti condizionati
Per predirre invece salti condizionati è necessario introdurre le cosiddette **euristiche**. Infatti a differenza di quanto avviene per quelli incondizionati, in questo caso _il salto occupa tutte le fasi del ciclo di esecuzione dell'istruzione_: **non si può caricare l'istruzione successiva "corretta" prima che la condizione del salto sia stata verificata**.

Proprio per questa ragione si utilizzano tecniche e algoritmi che basano il loro funzionamento essenzialmente sulla _probabilità_. Per esempio sappiamo che _i salti all'indietro sono più frequenti di quelli in avanti_[^2]. Quindi dalla decodifica di un salto condizionato riusciamo già a predire con abbastanza sicurezza se si tratterà di un salto in avanti o all'indietro. Ci si basa anche sul "passato", ovvero sulle ultime operazioni avvenute, sulla falsa riga del [[cache-funzionamento|principio di località temporale delle cache]]. Per esempio, se si è saltato spesso indietro allora è molto probabile che il prossimo salto sarà anch'esso all'indietro.

#### Dipendenze
L'altro grave problema di questa tecnica si presenta qualora (e capita nella maggior parte dei casi) le **istruzioni non fossero indipendenti tra loro**, ma bensì il risultato di una dipendesse dal risultato di un'altra (dipendenza **RAW**, _Read After Write_).

Anche in questo caso, l'unica soluzione sembrerebbe quella di _accorgersi quando le istruzioni sono dipendenti le une dalle altre_ e quindi di _aspettare che l'istruzione $x$ abbia terminato tutti gli stadi prima che le altre operazioni $y$ possano caricare gli operandi_ (**stall**), causando il solito gap.

Un trucchetto adottato dai [[compilatore-ottimizzato|compilatori ottimizzati]] è quello di riordinare le istruzioni dipendenti così da "dare il tempo" all'istruzione $x$ di terminare la sua esecuzione senza che l'istruzione dipendente $y$ debba creare uno stallo nella pipeline.

##### Esempio
```asm
ADD ax, bx
MOV [v], ax
DEC cx
```
verrebbe modificato in
```asm
ADD ax, bx
DEC cx
MOV [v], ax
```

## Referenze
[^1]: basti pensare alle [[comandi-condizionali|condizioni]]
[^2]: per via della maggiore frequenza dei [[iterazione|cicli]]to alle condizioni