---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 22:27:02
links:
  - "[[lecture-18102023151217|Lecture 18102023151217]]"
---
# Direct Mapped Cache
---
## Introduzione
> Il **direct mapped cache** è la più semplice politica di gestione di una [[cache|cache]]. Funziona in modo tale da garantire il _principio di località temporale e spaziale_ della cache.

## Composizione
Una _direct mapped cache_ si struttura in una tabella indicizzata da **linee** (da $0$ a $n-1$). Ogni linea può avere un valore diverso di **tag**, e per ogni associazione linea/tag si avranno **offset** valori di [[ram|RAM]].

Preso un indirizzo di RAM, esso viene scomposto rispettivamente:
- _tag_, bit più significativi che indicheranno i "giri" di cache per ogni linea
- _linea_, ogni riga della tabella di cache
- _offset_, sottotabella di ogni linea/tag contenente il blocco di celle di memoria associato all'indirizzo tag/linea/offset.

Se in cache su quella linea sarà presente quel valore di tag, allora la cache conterrà nell'offset l'indirizzo di RAM richiesto; se invece per quella linea il tag sarà diverso, allora verranno caricate dalla memoria tutte le celle nel range degli indirizzi tag/linea/\* in cache.

E' inoltre presente nella tabella di cache il campo **valid**, un singolo bit che identifica per quella linea se effettivamente i dati che ci sono dentro sono "affidabili". Per esempio all'accensione del computer per ogni linea il valid sarà a 0.

## Workflow
### Lettura
Se la [[cpu|CPU]] richiede il valore di un indirizzo di memoria alla cache, il principio di funzionamento è il seguente:
1. la cache ricava la _linea_ dall'indirizzo
2. la cache verifica che per quella linea il _valid_ sia a 1
	- se `valid=0` allora **cache-miss**
	- se `valid=1`
		- verifica il _tag_ della linea
			- se corrisponde a quello dell'indirizzo allora **cache-hit**
			- se non corrisponde a quello dell'indirizzo allora **cache-miss**

In ogni caso si finisce in questi due rami, per cui:
- **cache-hit**: la cache ha quell'indirizzo in memoria, va nell'_offset_ giusto e restituisce il suo contenuto alla CPU
- **cache-miss**: la cache non ha quell'indirizzo di memoria, quindi sovrascrive per quella _linea_ e quel _tag_ l'intero blocco di celle dalla memoria, mettendo il _valid_ a 1

### Scrittura
Per quanto riguarda invece la scrittura in cache, la questione si complica. Dobbiamo infatti fare un distinguo tra processori con _cache uniche_ e processori con _cache multiple_.

Nel primo caso si ha che semplicemente la CPU scrive e legge in cache per tutta la durata del programma: solo dopo averlo terminato la cache sovrascrive il suo contenuto in RAM.

Nel secondo caso, spesso associato al [[multiprocessori|multiprocessing]], alcuni **core** potrebbero aver bisogno di _risultati elaborati non ancora salvati in memoria da altri_, si rischierebbe così di prelevare dati non aggiornati, sbagliando. Ci sono due approcci per risolvere il problema:
- _scrittura di ogni risultato in memoria_, che renderebbe utile la cache solo in lettura
- _sistema di rounding delle cache_ per determinare quale cache ha il valore corretto da cui prelevare

## Referenze