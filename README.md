# System do inteligentnego sterowania oświetleniem w domu



## Wymagania projektowe

### Wymagania funkcjonalne:
* Możliwość zdalnego sterowania oświetleniem (bezprzewodowo)
* Możliwość wykrywania użytkownika i zapalania oświetlenia z wykorzystaniem czujnika
* Możliwość automatycznego zapalania oświetlenia po zmierzchu z wykorzystaniem czujnika
* Możliwość zapalania i gaszenia oświetlenia za pomocą sekwencji dźwiękowej z wykorzystaniem czujnika (opcjonalnie)

### Wymagania niefunkcjonalne:
* Arduino
* Moduł do komunikacji bezprzewodowej Bluetooth
* Czujnik światła
* Diody led (symulacja oświetlenia w domu)
* Czujnik dźwięku (opcjonalnie)
* Płytka prototypowa lub drukowana łącząca wszystkie moduły
* Arduino IDE lub inne środowisko kompatybilne z systemami operacyjnymi Windows lub Linux
* Spis potrzebnych komponentów:

| Komponent | Ilość | PIN |
| :--- | :---: | :--- |
| Arduino | 1 | 
| Moduł Bluetooth | 1 | Digital |
| Płytka stykowa 830 | 1 |
| Dioda LED | 3 | Digital |
| Opornik 220Ω | 3 |
| Opornik 1kΩ | 1 |
| Opornik 2kΩ | 1 |
| Opornik 10kΩ | 2 |
| Czujka PIR | 1 | Digital |
| Fotorezystor | 1 | Analog |
| Opcjonalnie: |
| Czujnik dźwięku | 1 | Analog |



## Schemat projektu
https://github.com/Jankele/remote_light/blob/master/README.md
### Prototype v0.2 - LED working
![schemat projektu Fritzing](https://github.com/Jankele/remote_light/blob/master/src/schemat.png?raw=true)

Log:
Sprawdzone działanie diód - Projekt z Arduino IDE
