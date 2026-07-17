---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/architettura-degli-elaboratori
date: 22-09-2023 19:56:46
links:
  - "[[lecture-21092023130150|Lecture 21092023130150]]"
---
# Clock
---
## Introduzione
Non tutte le [[istruzione|istruzioni]] hanno lo stesso _tempo d'esecuzione_, quindi si potrebbe dover aspettare del tempo prima che l'effettivo risultato di un'operazione appaia all'uscita della [[alu|ALU]]. Per sicurezza, quindi, **per qualunque istruzione si prende il risultato di un'operazione solo dopo aver aspettato un tempo prefissato.** La durata d'attesa standard viene scelta essere quella d'esecuzione dell'istruzione più complessa: in questo modo siamo assicurati che per ogni altra operazione il risultato letto all'uscita sia quello corretto.

Questo tempo prefissato d'attesa viene chiamato **periodo di clock**.
L'inverso del periodo di clock è la **frequenza di clock**, per cui vale:
$$f=\frac{1}{T}$$
![[clock.png]]

<u>Attenzione</u>: $1 \text { ciclo di clock} \neq 1 \text{ istruzione}$, infatti alcune istruzioni più complesse potrebbero richiedere più cicli (perché composte a loro volte da altre istruzioni). Infatti
$$\text{durata istruzione ISA} = n \times T$$
Se l'obiettivo è quello di aumentare la velocità del processore, a questo punto ci si chiede se convenga mantenere il suo _set di istruzioni semplice_ (e che quindi occuperebbero pochi cicli di clock), o se invece sia più conveniente creare un _set di istruzioni complesse_ (cui ognuna sarebbe composta da sottoistruzioni semplici). Questo è il dibattito tra [[cisc-e-risc|CISC e RISC]].

### Overclock
Overclockare una CPU significa spingere il proprio calcolatore al massimo aumentando la frequenza di clock, nella speranza che i risultati non comincino a essere errati.

## Referenze