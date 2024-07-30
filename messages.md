# SendRec


## AskBet:[owned]
Pytanie do gracza ile ma wynosić jego zakład (0 < bet <= owned)
    
Poodebranu:
- Odzyskanie owned
- Zapytanie gracza o wartość bet
- Wysłanie odpowiedzi "AskBetResp:[bet]"

Typy:
- owned -> int

## AskMove:[numberOfMoves];{[MoveName];[MoveName],...}
Pytanie do gracza o następną akcje. numberOfMoves jest liczbą wszystkich
    możliwych ruchów. W klamrowych nawiasach znajdują się nazwy możliwych akcji.
    Odpowiedzią jest liczba move (0 <= move < numberOfMoves)
    
Poodebranu:
- Odzyskanie numberOfMoves
- Odzyskanie nazw wszystkich dostępnych ruchów (sufix wiadomości)
- Zapytanie gracza ruch który chce wykonać. [move] jest indeksem tego ruchu (od 0)
- Wysłanie odpowiedzi "AskMoveResp:[move]"

Typy:
- numberOfMoves -> int
- MoveName -> string

## AskBridgeCall:[lastCallNumber];[lastCallSuite];[canDouble];[canReDouble]
Pytanie o następną zagrywkę podczas licytacji w brydżu. Gdy lastCallNumber = 0 to nie było wcześniejszych odzywek. lastCallSuite jest enumem (clubs = 0, diamonds = 1, hearts = 2, spades = 4, noTrump = 8). canDouble i canReDouble są flagami czy gracz może skontrować/rekontrować. nextCallType jest enumem(normalCall = 0, passCall = 1, doubleCall = 2, reDoubleCall = 4)

Poodebraniu:
- Odzyskanie lastCallNumber, lastCallSuite, canDouble, canReDouble
- Zapytanie gracza o kolejną zagrykę zgodnie z zadsadami brydża(wikipedia)
- "AskBridgeCallResp:[nextCallNumber];[nextCallSuite];[nextCallType]"

Typy:
- lastCallNumber -> int
- lastCallSuite -> enum
- canDouble -> char ('1' gdy prawda, '0' gdy fałsz)
- canReDouble -> char ('1' gdy prawda, '0' gdy fałsz)

## AskCardToPlay:[numberOfCards];{[cardIndex];[cardIndex],...}
Pytanie do gracza o następną kartę do zagrana z ręki. Wszystkie poprawne karty są wysłane w liście na końcu wiadomości

Poodebraniu:
- Odzyskanie numberOfCards
- Stworzenie tablicy cardIndex z Sufixu
- Otrzymanie od gracza dokładnie jednej karty do zagrania
- Odesłanie jej indeksu w "AskCardToPlayResp:[chosenCardIndex]"

Typy:
- numberOfCards -> int
- cardIndex -> size_t

# Send

## ActionDrawCard:[handIndex];[cardIndex];[cardName]
Gracz o danym indexie dobiera kartę identyfikowaną od teraz przez cardIndex. Obrazek na karcie
będzie identyfikowaną cardName

Poodebranu:
- Odzyskanie handIndex, cardIndex, cardName
- Przetłymaczenie cardName na ścieżkę do karty 
- Dodanie dodanie card do kolekcji umożliwiającej dostęp do tego obiektu poprzez cardIndex i wyświetlanie jej w ręce odpowiedniego gracza


Typy:
- handIndex -> int
- cardIndex -> size_t
- cardName -> string ( w postaci "playingCard_[cardSuite]_[2-10/jack/queen/king/ace]" lub "playingCard_reverse" (serializacja w PlayingCard.cpp))

## ActionChangeCard:[cardIndex];[newCardName]
Obrazek na karcie identyfikowanej przez cardIndex zmienia się powstały z newCardName

Poodebranu:
- Odzyskanie handIndex, newCardName
- Przetłymaczenie cardName na ścieżkę do karty
- Zamiana obrazka na odpowiedniej karcie

Typy:
- cardIndex -> size_t
- newCardName -> string ( w postaci "playingCard_[cardSuite]_[2-10/jack/queen/king/ace]" lub "playingCard_reverse" (serializacja w PlayingCard.cpp))

## ActionRemoveCard:[cardIndex]
Usuwa kartę identyfikowaną przez cardIndex

Poodebranu:
- Odzyskanie cardIndex
- Usunięcie karty identyfikowanej przez cardIndex

Typy:
- cardIndex -> size_t

## ActionClearHand:[handIndex]
Usuwa wszystkie karty danego gracza

Poodebranu:
- Odzyskanie handIndex
- Wyczyszczenie ręki danego gracza

Typy:
- handIndex -> int

## ActionNewHand:[handIndex, newHandIndex]
Tworzy nową rękę identyfikowaną teraz z newHandIndex

Poodebranu:
- Odzyskanie handIndex, newHandIndex
- Stworzenie nowej ręki (ma być wyświetlana na prawo od ręki identyfikowanej przez handIndex)

Typy:
- handIndex -> int
- newHandIndex -> int

## ActionRemoveHand:[handIndex]
Usuwa rękę identyfikowaną z handIndex

Poodebranu:
- Odzyskanie handIndex
- Wyczyszczenie odpowiedniej ręki
- Usunięcie odpowiedniej ręki

Typy:
- handIndex -> int

## ActionBridgeCall:[callNumber];[callSuite];[callType];[playerIndex]
Zapisuje przebieg licytacji. Odzywki są identyfikowane tak jak w "AskBridgeCall"

Poodebraniu:
- Odzyskanie callNumber, callSuite, callType, playerIndex
- Wywołanie odpowiedniej funkcji

Typy:
- callNumber -> int
- callSuite -> enum
- callType -> enum
- playerIndex -> int

## ActionBridgeAuctionEnd:[contractNumber];[contractSuite];[playingPlayerIndex]
Wiadomość kto wygrał licytacje i będzie grał w rozgrywce. contractSuite jest tym samym enumem co callSuite

Poodebraniu:
- Odzyskanie contractNumber, contractSuite, playingPlayerIndex
- Dodanie tego do jakiegoś pola na ekranie

Typy:
- contractNumber -> int
- contractSuite -> enum
- playingPlayerIndex -> int

## PrintMessage:[message]
Wypisuje message na polu widocznym dla gracza

Poodebranu:
- Odzyskanie message
- Wypisanie message na jakimś polu tekstowym widocznym dla gracza

Typy:
- message -> string
