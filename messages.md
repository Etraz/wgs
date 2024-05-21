# SendRec


## "AskBet:[owned]"
Pytanie do gracza ile ma wynosić jego zakład (0 < bet <= owned)
    
Poodebranu:
- Odzyskanie owned
- Wywołanie funkcji getPlayersBet(int owned) która zwraca bet
- Wysłanie odpowiedzi "AskBetResp:[bet]"

Typy:
- owned -> int

## "AskMove:[numberOfMoves];{[MoveName];[MoveName],...}"
Pytanie do gracza o następną akcje. numberOfMoves jest liczbą wszystkich
    możliwych ruchów. W klamrowych nawiasach znajdują się nazwy możliwych akcji.
    Odpowiedzią jest liczba move (0 <= move < numberOfMoves)
    
Poodebranu:
- Odzyskanie numberOfMoves
- Stworzenie Tablicy z sufixu wiadomości
- Wywłanie funkcji getPlayersMove(String[]) która zwraca index wybranego elementu.
- Wysłanie odpowiedzi "AskMoveResp:[move]"

Typy:
- numberOfMoves -> int
- MoveName -> string

## "AskBridgeCall:[lastCallNumber];[lastCallSuite];[lastCallPlayer]
Pytanie o następną zagrywkę podczas licytacji w brydżu. Gdy lastCallNumber = 0 to nie było wcześniejszych odzywek. Gdy 0 < lastCallNumber < 8 to poprzednia zagrywka jest normalna. Gdy 7 < lastCallNumber < 15 to poprzednia zagrywka była skontrowana. Gdy 14 < lastCallNumber < 22 to ostania zagrywka była zrekontrowana. lastCallSuite jest enumem (0 empty, 1 clubs, 2 diamonds, 4 hearts, 8 spades, 16 NT). 

Poodebraniu:
- Odzyskanie lastCallNumber, lastCallSuite, lastCallPlayer
- Wywołanie funkcji dostającej kolejną zagrykę od gracza zgodnie z zadsadami brydża(wikipedia)
- "AskBridgeCallResp:[newCallNumber];[newCallSuite]"

Typy:
- lastCallNumber -> int
- lastCallSuite -> enum
- lastCallPlayer -> int

## "AskCardToPlay:[numberOfCards];{[cardIndex];[cardIndex],...}"
Pytanie do gracza o następną kartę do zagrana z ręki. Wszystkie poprawne karty są wysłane w liście na końcu wiadomości

Poodebraniu:
- Odzyskanie numberOfCards
- Stworzenie tablicy cardIndex z Sufixu
- Otrzymanie od gracza dokładnie jednej karty do zagrania
- Odesłanie jej indeksu w "AskCardToPlayResp:[chosenCardIndex]"

Typy:
- numberOfCards -> int
- numberOfCards -> int

# Send

## "ActionDrawCard:[handIndex];[cardIndex];[cardName]"
Gracz o danym indexie dobiera kartę identyfikowaną od teraz przez cardIndex. Obrazek na karcie
będzie identyfikowaną cardName

Poodebranu:
- Odzyskanie handIndex, cardIndex, cardName
- Stworzenie obiektu card poprzez użycie CardParser::parse(String cardName)
- Dodanie dodanie card do kolekcji umożliwiającej dostęp do tego obiektu poprzez cardIndex i wyświetlanie jej w ręce odpowiedniego gracza


Typy:
- handIndex -> int
- cardIndex -> int
- cardName -> string

## "ActionChangeCard:[cardIndex];[newCardName]"
Obrazek na karcie identyfikowanej przez cardIndex zmienia się powstały z newCardName

Poodebranu:
- Odzyskanie handIndex, newCardName
- Stworzenie obiektu newCard poprzez użycie CardParser::parse(String cardName)
- Podmiana Kolekcja[cardIndex] na newCard

Typy:
- cardIndex -> int
- newCardName -> string

## "ActionRemoveCard:[cardIndex]"
Usuwa kartę identyfikowaną przez cardIndex

Poodebranu:
- Odzyskanie cardIndex
- Usunięcie karty identyfikowanej przez cardIndex

Typy:
- cardIndex -> int

## "ActionClearHand:[handIndex]"
Usuwa wszystkie karty danego gracza

Poodebranu:
- Odzyskanie handIndex
- Wyczyszczenie ręki danego gracza

Typy:
- handIndex -> int

## "ActionNewHand:[handIndex, newHandIndex]"
Tworzy nową rękę identyfikowaną teraz z newHandIndex

Poodebranu:
- Odzyskanie handIndex, newHandIndex
- Stworzenie nowej ręki(ma być wyświetlana na prawo od ręki identyfikowanej przez handIndex)

Typy:
- handIndex -> int
- newHandIndex -> int

## "ActionRemoveHand:[handIndex]"
Usuwa rękę identyfikowaną z handIndex

Poodebranu:
- Odzyskanie handIndex
- Wyczyszczenie odpowiedniej ręki
- Usunięcie odpowiedniej ręki

Typy:
- handIndex -> int

## "ActionBridgeCall:[callNumber];[callSuite];[playerIndex]"
Zapisuje przebieg licytacji. Odzywki są identyfikowane tak jak w "AskBridgeCall" z tym, że callNumber = 0 oznacza pas

Poodebraniu:
- Odzyskanie callNumber, callSuite, playerIndex
- Wywołanie odpowiedniej funkcji

Typy:
- callNumber -> int
- callSuite -> enum
- playerIndex -> int

## "PrintMessage:[message]"
Wypisuje message na polu widocznym dla gracza

Poodebranu:
- Odzyskanie message
- Wypisanie message na jakimś polu tekstowym widocznym dla gracza

Typy:
- message -> string
