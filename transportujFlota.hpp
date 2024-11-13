#pragma once

#include "Stocznia.hpp"

// Funkcja transportujFlota
unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0) {
        return 0; // Jeœli iloœæ towaru wynosi 0, zwracamy 0 bez tworzenia statków
    }

    Stocznia     stocznia;               // Fabryka statków
    unsigned int przetransportowane = 0; // Licznik przetransportowanego towaru
    unsigned int liczbaZaglowcow    = 0; // Licznik ¿aglowców

    while (przetransportowane < towar) {
        Statek*      statek = stocznia();            // Tworzymy losowy statek
        unsigned int ilosc  = statek->transportuj(); // Transportujemy towar przy u¿yciu statku
        przetransportowane += ilosc; // Dodajemy iloœæ przetransportowanego towaru do sumy

        // Sprawdzamy, czy stworzony statek jest ¿aglowcem
        if (dynamic_cast< Zaglowiec* >(statek)) {
            liczbaZaglowcow++; // Je¿eli to ¿aglowiec, zwiêkszamy licznik ¿aglowców
        }

        delete statek; // Usuwamy dynamicznie utworzony statek
    }

    return liczbaZaglowcow; // Zwracamy liczbê ¿aglowców
}