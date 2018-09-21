# Schachspiel

Ein einfaches graphisches Scachspielprogramm fuer zwei Spieler.

## Anforderungen

- Linux oder BSD basiertes System
- Gtk, Gtkmm3

## Installation

```
git clone https://github.com/mondokm/schachspiel.git
cd schachspiel
make compile
```

## UI

Das Programm hat ein graphisches UI, das wie ein Schachbrett aussieht.

![ui](docs/chess.png)

Nach einem Klick auf einer Schachfigur werden die Trittmoeglichkeiten gelb gafaerbt. Falls der Spieler ein gelbes Feld klickt, wird der frueher ausgewaehlter Figur da treten, andernfalls wird der Auswahl zurueckgenommen.

## Regeln

Der weißer Spieler fangt das Spiel an, die Spieler treten wechselweise. Die Regeln sind die Regeln von Schach, außer dass Rochade und Respawn schon nicht moeglich sind.

### Ende des Spiels

Das Spiel endet, wenn eine der Spieler seinen König verliert.
