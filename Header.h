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

	virtual ColorUPS look_at() const { return Color; } //Функция позволяет узнать цвет
	int GetBatteries() const { return number_of_batteries; } //Функция позволяет узнать число АКБ у ИБП
	virtual void Punch_it() {} //Пинаем ИБП ногой


};
class Line_interactive : public UPS // Создание дочернего класса линейно-интерактивных ИБП
{
protected:
	bool sinusoidal_output_voltage; // Тип Л-И ИБП: с аппроксимированной синусоидой или полностью синусоидальным выходным напряжением
public:
	Line_interactive() : UPS() { Color = ColorUPS::Grey; }
	ColorUPS look_at() const { return ColorUPS::Grey; }

	void Punch_it()
	{
		cout << "It's a good UPS, it's still can working!";
	}
};

class Standby : public UPS //Создание дочернего класса резервных ИБП
{
protected:
	short age; //Срок работы ИБП(если больше 3 лет => аккумуляторы износились ввиду частых скачков напряжения и их пора менять
public:
	Standby() : UPS() { Color = ColorUPS::White; }
	ColorUPS look_at() const { return ColorUPS::White; }

	void Punch_it()
	{
		cout << "Oh no, now it's broken!";
		is_working = Working::Broke;
	}
};

class Online : public UPS //Создание дочернего класса Онлайн ИБП
{
public:
	bool switch_now; //Текущее состояние переключателя(автономная работа / работа от сети = 1)

	Online() : UPS() { Color = ColorUPS::Black; }
	ColorUPS look_at() const { return ColorUPS::Black; }

	void Punch_it()
	{
		cout << "Wow, now it's working!";
		is_working = Working::Work;
	}
};


#endif
