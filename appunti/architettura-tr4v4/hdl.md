---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 30-09-2023 20:13:23
links:
  - "[[lecture-28092023130653|Lecture 28092023130653]]"
---
# HDL
---
## Definizione
> L'**HDL** (_Hardware Description Language_) è un linguaggio standard per la descrizione di un [[circuiti-combinatori|circuito combinatorio]].

## Funzionamento
### Bus multi-bit
Per realizzare alcune componenti sono necessarie tante connessioni, e per evitare di scrivere grandi quantità di pin è possibile sfruttare i _bus multi-bit_, in poche parole [[array|array]] di bit.
Questi possono essere sia di tipo `IN` che di tipo `OUT`, e ad essi
- si può accedere _singolarmente_ --> `a[0]`
- si può accedere a _range_ --> `a[0..7]`

```hdl
CHIP Add16 {
	IN a[16], b[16];
	OUT out[16];

	PARTS:
	// TODO
}
```

## Referenze
- [documentazione](https://virtuale.unibo.it/pluginfile.php/1695567/mod_resource/content/1/Hardware_Description_Language.pdf)