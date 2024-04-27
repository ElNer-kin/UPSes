#ifndef HEADER_H
#define HEADER_H
#include <string>

using namespace std;

class UPS {}; //Создание родительского класса ИБП

class Line_interactive : public UPS {}; // Создание дочернего класса линейно-интерактивных ИБП

class Standby : public UPS {}; //Создание дочернего класса резервных ИБП

class Online : public UPS {}; //Создание дочернего класса Онлайн ИБП

#endif