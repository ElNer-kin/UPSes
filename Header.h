#ifndef HEADER_H
#define HEADER_H
#include <string>

using namespace std;

enum class ColorUPS : int //Цвет корпуса ИБП
{
	Black = 0,
	Grey = 1,
	White = 2,
};

enum class Working : int //Текущее состояние ИБП(работает = 1 / сломан = 0)
{
	Work = 1,
	Broke = 0,
};

class UPS { //Создание родителського класса ИБП
protected:
	string name;
	string model;
	ColorUPS Color;

	
public:
	short output_power; //Выходное напряжение
	short number_of_batteries; //Число АКБ
	Working is_working;
};

class Line_interactive : public UPS // Создание дочернего класса линейно-интерактивных ИБП
{
protected:
	bool sinusoidal_output_voltage; // Тип Л-И ИБП: с аппроксимированной синусоидой или полностью синусоидальным выходным напряжением
};
class Standby : public UPS //Создание дочернего класса резервных ИБП
{
protected:
	short age; //Срок работы ИБП(если больше 3 лет => аккумуляторы износились ввиду частых скачков напряжения и их пора менять; 
};
class Online : public UPS
{
public:
	bool switch_now; //Текущее состояние переключателя(автономная работа / работа от сети = 1)}; //Создание дочернего класса Онлайн ИБП
};

class UPS {}; //Создание родительского класса ИБП

class Line_interactive : public UPS {}; // Создание дочернего класса линейно-интерактивных ИБП

class Standby : public UPS {}; //Создание дочернего класса резервных ИБП

class Online : public UPS {}; //Создание дочернего класса Онлайн ИБП

#endif