# Projet Algo BlackJack

**Projet Algo BlackJack** est écrit en C, voici les algorithme des différentes fonctions utilisées pendant ce projet.

## Fonction ShowHand

Fonction permettant de montrer la main d'un joueur au complet

```
  DEBUT ShowHand()
      PARAM Player player
      VAR Deck current <- player.deck
  
      TANT QUE current != NULL FAIRE
          VAR INT value <- current.card.valeur
          VAR Color color <- current.card.color
  
          AFFICHER value, " de "
          
          CAS color DE
              COEUR : APPEL AFFICHER ("Coeur")
              PIQUE : APPEL AFFICHER ("Pique")
              CARREAU : APPEL AFFICHER ("Carreau")
              TREFLE : APPEL AFFICHER ("Trèfle")
          FIN CAS
  
          current <- current.next
      FIN TANT QUE
  FIN
```

## Fonction Init

Fonction permettant de créer la banque, un jour, et un jeu de carte complet

```
DEBUT init()
    PARAM Player* bank
    PARAM Player* player1
    PARAM Deck* deckP
    player1.value <- 50
    deckP <- generateDeck()
FIN
```

## Fonction HandValue

Fonction permettant de créer la banque, un jour, et un jeu de carte complet

```
DEBUT HandValue()
    PARAM Player player
    VAR INT sum <- 0
    VAR Deck current <- player.deck

    TANT QUE current != NULL FAIRE
        VAR INT value <- current.card.valeur
        sum <- sum + value
        current <- current.next
    FIN TANT QUE

    RETOURNER sum
FIN
```
## Fonction userInput

Fonction permettant de lire le choix utilisateur durant la partie
```
DEBUT userInput()
    VAR INT answer <- 0
    VAR INT i <- 0

    APPEL AFFICHER ("Quelle action voulez-vous faire ?")
    APPEL AFFICHER (" - Pour tirer une carte, rentrez 1")
    APPEL AFFICHER (" - Pour vous arrêter, rentrez 2")
    APPEL AFFICHER (" - Pour doubler, rentrez 3")
    APEL AFFICHER (" - Pour abandonner, rentrez 4")

    TANT QUE i == 0 FAIRE
        SCANF(" %d", &answer)

        SI answer == 1 FAIRE
            i <- 1
            RETOURNER HIT
        SINON SI answer == 2 FAIRE
            i <- 1
            RETOURNER STAND
        SINON SI answer == 3 FAIRE
            i <- 1
            RETOURNER DOUBLE
        SINON SI answer == 4 FAIRE
            i <- 1
            RETOURNER SURREND
        FIN SI

        SI answer NON ÉGAL À (1 OU 2 OU 3 OU 4) FAIRE
            APPEL AFFICHER ("Le format de réponse n'est pas correct, réessayez.")
        FIN SI
    FIN TANT QUE
FIN
```

*Projet réalisé en première année de cycle ingénieur à l'ESIREM.*

<img src="/logo-couleur.jpg" alt="Logo de l'ESIREM" width=200 height=75>
