---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
  - topic/calcolo-numerico
date: 09-10-2023 19:14:31
links:
  - "[[lecture-09102023132029|Lecture 09102023132029]]"
  - "[[lecture-05102023130513|Lecture 05102023130513]]"
  - "[[lecture-16092024131302|Lecture 16092024131302]]"
  - "[[lecture-23092024132935|Lecture 23092024132935]]"
---
# Codifica floating-point
---
## Introduzione
Per rappresentare tante informazioni in maniera compatta, e quindi sia numeri grandissimi che piccolissimi, usiamo la _notazione esponenziale_. Esempi:
- $9 \times 10^{-8}$
- $2 \times 10^{33}$

Questa formattazione risulta molto efficace per i calcolatori, perché consente di memorizzare con facilità informazioni altrimenti irrappresentabili. In particolare, la tecnica che sfrutta questa notazione si chiama **virgola mobile** (o _floating-point_).

## Tecnica
Con il floating-point si va a definire _ogni_ numero nella forma
$$n = (-1)^{s} \times f \times 10^{e}$$
dove:
- $s$ è detto **segno**
- $f$ è detto frazione o **mantissa**
- $e$ è detto esponente o **caratteristica**

Per esempio, [[python|Python]] utilizza lo standard _IEEE754_, ossia 64 bit totali divisi in:
- 1 bit per il segno;
- 11 bit per la caratteristica;
- 52 bit per la mantissa.

Per cui ogni numero float in Python è rappresentato dalla formula:
$$n = (-1)^{s} \cdot 2^{e-1023} \cdot (1 + f)$$

<u>Attenzione</u>: si ha $2^{e-1023}$ perché $e \in [0, 2048[ \subseteq \mathbb{N}$ (dato che con 11 bit si rappresentano 2048 numeri), e in questa maniera i valori di $e$ tra $0$ e $1022$ rappresentano esponenti negativi.

<u>Attenzione</u>: si ha $f \in [0, 1[ \subseteq \mathbb{R}$, per cui $(1 + f) \in [1, 2[$.

### Generalizzazione della codifica
Definiamo l'insieme $\mathbb{F}$ come
$$\mathbb{F}(\beta, t, +L, u) = \{\{\varnothing\} \cup n = \pm \beta^{p} \cdot d_{0}. d_{1}, \cdots, d_{t} | -L \leq p \leq u\}$$
ossia come quell'insieme che dati come parametro
- $\beta$ la base;
- $t$ il numero di cifre della mantissa;
- $(L, u)$ il range della caratteristica (infatti $p$ è compreso tra $-L$ e $u$);

contiene _tutti i numeri codificabili in quella specifica codifica floating-point_. Per fare un esempio, si ha che la IEEE754 non è altro che $\mathbb{F} (2, 52, 1023, 1024)$.

<u>Nota bene</u>: $d_{0}$ è la cifra unitaria, di norma uguale a 1.

## Normalizzazione
I numeri in virgola mobile possono essere rappresentati in infiniti modi, ma come standard si dice che devono essere _normalizzati_, ovvero rispettare le seguenti leggi:
- la mantissa dev'essere della forma $0,...$
- le cifre dopo la virgola della mantissa non devono cominciare con $0$

### Esempio
Se volessimo rappresentare 53 in virgola mobile e normalizzato allora dovremmo:
1. _convertirlo in binario_: `53 --> 110101,0`
2. _normalizzarlo_: `0,110101 x 2^6`

A questo punto, a seconda del **formato** scelto (è una convenzione), si struttura la sequenza di bit che rappresenta il numero in floating-point. In questo caso usiamo il formato:
- 1 bit _segno_
- 23 bit _mantissa_
- 8 bit _esponente_ in [[complemento-a-2|complemento a 2]]

Il risultato sarà allora
> **(0) (110101 00000000000000000) (00000 110)**
> dove
> - il primo gruppo (bit) rappresenta il segno
> - il secondo gruppo la mantissa (_notare che essendo dopo la virgola gli zeri meno significativi finiscono a destra_)
> - il terzo gruppo l'esponente (in questo caso positivo)

Lo stesso discorso si fa per qualsiasi altro numero. Fare quindi attenzione alla [[conversione-binario-decimale-numero-con-la-virgola|conversione per i numeri con la virgola]].

### Formati standard
- [[binary32|BINARY32]]
- [[binary64|BINARY64]] (i `double` del [[c|C]]/[[c|C++]])

## Problemi
Seppur efficiente, questa tecnica ha dei limiti significativi. In particolare:
- **underflow** --> i numeri troppo piccoli vengono confusi con lo 0
- **overflow** --> i numeri troppo grandi (sia positivi che negativi) non si riescono a rappresentare
- **precisione finita** --> _non si riescono a rappresentare tutti i numeri_

Per essere più precisi, presa una qualunque codifica floating-point $\mathbb{F} (\beta, t, +L, u)$ e fissato un numero $x$, si ha che:
- $x \in \mathbb{F}$, oppure
- $x \notin \mathbb{F}$
[^1]

In quest'ultimo caso ($x \notin \mathbb{F}$) _non rimane che approssimare $x$_. Infatti quando un numero non è rappresentabile con una specifica codifica floating-point indichiamo la sua approssimazione con $fl(x)$, tale che
- $x \in \mathbb{F} \implies fl(x) = x$
- $x \notin \mathbb{F} \implies fl(x) \neq x$

Per "approssimare" si può intendere:
- **arrotondamento**: _arrotondare la cifra $t$-esima rispetto alla $t+1$-esima_;
- **troncamento**: _scrivere le cifre della mantissa fino alla $t$-esima, ignorando le successive $d_{t+1}, d_{t+2}, \cdots$_.

Si riassumono così le più importanti caratteristiche di una codifica floating-point $\mathbb{F}$:
- $\mathbb{F}$ è un insieme discreto[^2]
- intorno allo $0$ c'è il _vuoto_
- $\mathbb{F}$ è limitato [[estremo-superiore|superiormente]] e [[estremo-inferiore|inferiormente]] (esiste $\max$ e $\min$)

Per esempio la codifica $\mathbb{F}(10, 4, 3, 3)$ ha come $\max$ $9.9999 \times 10^{3} = 9999.9$ e come $\min$ $1.0000 \times 10^{-3} = 0.001$.

Notare la strana simmetria tra caratteristica e mantissa:
- _la caratteristica influenza minimo e massimo_ - più è alto l'esponente più il numero può essere grande o piccolo;
- _la mantissa influenza la distanza tra i numeri discreti_ (detto **gap**[^3]) - più è il numero di cifre della mantissa meno grande è la distanza tra i numeri.

In Python la codifica IEEE754 include numeri speciali, quali `inf`, `-inf` e `NaN` (Not a Number). Se al numero massimo della codifica viene sommato un numero piccolo il risultato viene approssimato al massimo; se al massimo si somma se stesso il risultato è `inf`!

<u>Nota bene</u>: il _gap_ aumenta man mano che mi allontano dallo zero, per via della caratteristica. Di conseguenza _i numeri più grandi sono più "discreti" tra di loro_, perché le cifre della mantissa, per via della caratteristica, saranno più a sinistra della virgola.

### Esempio
Prendiamo il numero $15_{10}$, e rappresentiamolo nella codifica $\mathbb{F} (2, 52, 1023, 1024)$ (la IEEE754):
Ovviamente 15 è positivo, per cui il segno sarà a 0: $$s = 0$$
Sappiamo che 15 in binario è $1111$, per cui il valore $(1 + f)$, dove $f$ è la mantissa, dovrà essere $1111$: la parte intera è l'$1$ già incluso di base nella codifica; la parte decimale sono i rimanenti tre 1. Per cui si avrà
$$f = 1110000000000000000000000000000000000000000000000000$$

A questo punto non rimane che determinare la caratteristica, ossia $e$. Per ora il numero calcolato è $(1 + f)$ ossia $$(1 + f) = 1.1110000000000000000000000000000000000000000000000000$$
Per ottenere 15 allora dobbiamo fare un _right shift_ di 3 posizioni, così da ottenere $1111.000 \cdots$. Per questo shift dobbiamo moltiplicare $(1 + f)$ con $2^{3}$, per cui il valore $e-1023$ dovrà essere uguale a 3:
$$e-1023 = 3 \iff e = 1026$$
che in binario è
$$e = 10000000010$$

Ricapitolando, $15_{10}$ in codifica IEEE754 è
$$0 \ 10000000010 \ 1110000000000000000000000000000000000000000000000000$$

<u>Nota bene</u>: ora se volessimo sapere in questa codifica qual è il numero precedente a 15 ci basta sottrarre 1 alla mantissa: $$0 \ 10000000010 \ 1101111111111111111111111111111111111111111111111111$$
Questo valore è $14.9999999999999982236431605997$. Viceversa se volessimo sapere il numero successivo a 15.

<u>Nota bene</u>: ciò significa che tutti i numeri calcolati tra $14.9999999999999982236431605997$ e $15$ (non compresi) vengono arrotondati a $15$. Questo è il **gap**.

### Esempio
Per i limiti della codifica floating-point specificati in precedenza, il seguente codice produce al posto di 0 un output a prima vista errato, quando in realtà si tratta di un accumulo di arrotondamenti ($fl(x)$) che culmina in questo:
```cpp
for (double i = -1.0; i <= 1.0; i += 0.2) {
	cout << i << endl;
}
```
Output:
```
-1.0
-0.8
-0.6
-0.4
-0.2
3.35e-20
0.2
0.4
0.6
0.8
1.0
```

Infatti `0.2` in _virgola-mobile_ (e quindi in binario) è un numero periodico, perciò ad ogni calcolo si semplificano dei risultati che portano lo 0 a non essere effettivamente 0.

Questo tipo di errore appartiene a quelli che nel gergo vengono chiamati [[errore-nel-calcolo-numerico|errori nel calcolo numerico]].

## Referenze
- [[aritmetica-floating-point|Aritmetica floating-point]]

[^1]: ovviamente l'[[regole-di-inferenza-di-em|EM]]
[^2]: per intenderci non ha la [[proprieta-di-completezza-di-r|proprietà del continuo]] di $\mathbb{R}$
[^3]: in Python questo _gap_ si sa con la funzione `spacing` della libreria `numpy`: `np.spacing(x)` dove `x` è il numero della codifica del quale si vuole sapere la distanza tra il precedente e il successore