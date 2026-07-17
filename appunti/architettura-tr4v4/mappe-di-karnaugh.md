---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 02-10-2023 21:20:47
links:
  - "[[lecture-02102023130256|Lecture 02102023130256]]"
---
# Mappe di Karnaugh
---
## Introduzione
Le **mappe di Karnaugh** sono introdotte nell'[[algebra-di-boole|algebra booleana]] come alternativa al calcolo della [[forma-canonica-booleana|forma canonica]] per passare da una [[tabella-di-verita|tabella di verità]] alla costruzione del circuito che la implementa.

Infatti quest'ultima può risultare _prolissa_, perché contenente tanti mintermini che talvolta possono essere ridotti con le leggi booleane. Si dice infatti che con le mappe di Karnaugh si può trovare, se non la **forma minima** almeno la **forma minimale** dell'espressione booleana che costituisce il circuito.

## Funzionamento
La mappa di Karnaugh, alla fine, è solo _un modo diverso di rappresentare una tabella di verità_. Attraverso delle proprietà intrinseche al modello di rappresentazione della tabella di verità, chiamato [[codice-gray|codice Gray]], è possibile da questa mappa _raccogliere più mintermini in un unico e più semplificato gruppo di mintermini_.

Ci sono quindi tre passaggi per arrivare ad ottenere l'espressione finale:
1. passaggio da tabella di verità a mappa
2. raggruppamento degli 1
3. traduzione in espressione booleana

Eseguiamo le operazioni con un esempio, prendendo quindi come riferimento la tabella di verità del [[multiplexer|multiplexer]].

### Tabella di verità $\to$ mappa di Karnaugh
| A   | B   | sel | OUT |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 0   |
| 0   | 1   | 0   | 0   |
| 0   | 1   | 1   | 1   |
| 1   | 0   | 0   | 1   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 1   |
| 1   | 1   | 1   | 1   |

Per costrire la mappa di Karnaugh a partire dalla tabella di verità, valutiamo intanto quanti ingressi ci sono: 3. In questo caso, allora, dobbiamo spartire `A` e `B` da `sel`, ottenendo come righe `AB` e come colonne `sel`, in questo modo:
![[Drawing 2023-10-02 21.33.42.excalidraw|400]]

Quindi, associamo tutte le possibili combinazioni tra i 3 ingressi per ogni cella, usando per le righe (`AB`) la **codifica Gray**.
![[Drawing 2023-10-02 21.37.44.excalidraw|400]]

Ora riempiamo le celle in relazione all'output della tabella di verità.
![[Drawing 2023-10-02 21.40.37.excalidraw|400]]

### Raggruppamenti di 1
Ci sono delle regole per farlo:
- si possono raccogliere solo gruppi di 1
- si possono raccogliere solo gruppi contenenti un numero di elementi uguale a una potenza di 2
- vale l'_effetto pac-man_!

E altrettanti suggerimenti:
- meno celle singole si prendono meglio è (valgono come mintermini della forma canonica)
- evitare di comprendere nei raggruppamenti celle già raggruppate, se non strettamente necessario

In questo specifico caso, il raccoglimento migliore risulta essere:
![[Drawing 2023-10-02 21.43.47.excalidraw|400]]

### Traduzione in espressione booleana
Una volta trovati i raggruppamenti, per tradurli in forma booleana basta per ognuno di essi _considerare solo gli ingressi che non mutano per tutto il raggruppamento_, negandoli se valgono 0. Quindi, fare un [[and|AND]] tra tali ingressi e poi mettere in [[or|OR]] ogni raggruppamento (come per la forma canonica).

In questo caso otterremo
$$A \neg sel \ \ + \ \ Bsel$$
che è la **forma minima** del multiplexer.

## Referenze