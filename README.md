IDT to konsolowa gra utworzona w 100% w C++ która jest formą projektu.
Tworzenie gry to czas miesiąca (łącznie około 8godzin) ponieważ nie był priorytetem.

Fabuła:
Jesteś podróżnikiem Joelem który usłyszał o możliwośći zdobycia części ziemi Aelorin w zamian za 
zabicie paru potworów.

OPEN-SOURCE
WYKORZYSTANO CHAT GPT TO WIELU RZECZY (30-40% projektu)

OPIS FUNKCJI I KLAS

klasa potworek (obrazek niżej) zawiera podstawowe informacje prywatne (tylko dla niego) oraz 
publiczne po których użyciu możemy dostać jakiś zwrot w konsoli. Pare z tych intów itp. nie jest
użytych ale wiele się przydało w tworzeniu.

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/8fcd4b53-f2ce-4673-9f4b-485e752c6254)


Najrpościej mówiąc: Kod bierze Obrażenia X i odejmuje od obiektu Y z uwzględnieniem pancerza

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/00ffe544-9beb-448d-a243-d7ee668dd2cc)

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/ce06b2a7-a93e-4197-8f2a-a5daee57f241)

FIGHT

OBR1 
Jedno z najważniejszych miejsc w kodzie to fight, jest to funkcja która bierze gracza i wroga
oraz wypisuje, dodatkowo jest system PKT akcji które pozwalają na m.in. Strong attack bądź heal

OBR2
Jest tu użyty switch który odnotowuje wybór gracza od 1-4 przez CIN oraz wybiera daną akcje
jeżeli gracz wybierze akcje powyżej 4 (5+) to zaatakuje podstawowym atakiem (1)

OBR3
Później kolej wroga gdzie Ifami jest zrobiony system co zrobi, attack heal lub strong attack.

Jeżeli wróg umrze to wtedy zapisywane jest HP oraz Coiny gracza i lecimy dalej.

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/e4cff222-b969-4fa7-83c9-0a5c41aa6f06)

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/686932c9-02dc-4efb-abe1-1c9ff8d4be41)

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/5863b99c-fa60-4b54-8edd-0c4698b776e7)


SHOP
Gracz wybiera co chce kupić za pomocą zebranych coinów, po czym zwiększają mu się statystyki.

![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/7dad09ad-d271-4899-8475-926511142fe7)



MAIN
W Main jest wywoływanie funkcji oraz tworzenie wrogów lub odpalenie sklepu.
Po walce jest odpalany sklep i następna walka i tak pare razy


![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/7648cec9-8267-46a3-8c31-b638a1442b9f)
![obraz](https://github.com/Alaniczek/infinite-dungeon-travel----PcConsoleEdition/assets/146478174/147d2af5-d79e-4994-9b71-18b9626118e4)


I to tyle z gry, jeżeli są jakieś pomysły jak rozwinąć grę to można napisać
