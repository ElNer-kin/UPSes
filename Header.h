#ifndef HEADER_H
#define HEADER_H
#include <string>

using namespace std;


enum class ColorUPS : int //Öâåò êîðïóñà ÈÁÏ
{
	Black = 0,
	Grey = 1,
	White = 2,
};

enum class Working : int //Òåêóùåå ñîñòîÿíèå ÈÁÏ(ðàáîòàåò = 1 / ñëîìàí = 0)
{
	Work = 1,
	Broke = 0,
};


class UPS { //Ñîçäàíèå ðîäèòåëüñêîãî êëàññà ÈÁÏ
protected:
	string name;
	string model;
	ColorUPS Color;


public:
	short output_power; //Âûõîäíîå íàïðÿæåíèå
	short number_of_batteries; //×èñëî ÀÊÁ
	Working is_working;

	virtual ColorUPS look_at() const { return Color; } //Ôóíêöèÿ ïîçâîëÿåò óçíàòü öâåò
	int GetBatteries() const { return number_of_batteries; } //Ôóíêöèÿ ïîçâîëÿåò óçíàòü ÷èñëî ÀÊÁ ó ÈÁÏ
	virtual void Punch_it() {} //Ïèíàåì ÈÁÏ íîãîé


};
class Line_interactive : public UPS // Ñîçäàíèå äî÷åðíåãî êëàññà ëèíåéíî-èíòåðàêòèâíûõ ÈÁÏ
{
protected:
	bool sinusoidal_output_voltage; // Òèï Ë-È ÈÁÏ: ñ àïïðîêñèìèðîâàííîé ñèíóñîèäîé èëè ïîëíîñòüþ ñèíóñîèäàëüíûì âûõîäíûì íàïðÿæåíèåì
public:
	Line_interactive() : UPS() { Color = ColorUPS::Grey; }
	ColorUPS look_at() const { return ColorUPS::Grey; }

	void Punch_it()
	{
		cout << "It's a good UPS, it's still can working!";
	}
};

class Standby : public UPS //Ñîçäàíèå äî÷åðíåãî êëàññà ðåçåðâíûõ ÈÁÏ
{
protected:
	short age; //Ñðîê ðàáîòû ÈÁÏ(åñëè áîëüøå 3 ëåò => àêêóìóëÿòîðû èçíîñèëèñü ââèäó ÷àñòûõ ñêà÷êîâ íàïðÿæåíèÿ è èõ ïîðà ìåíÿòü
public:
	Standby() : UPS() { Color = ColorUPS::White; }
	ColorUPS look_at() const { return ColorUPS::White; }

	void Punch_it()
	{
		cout << "Oh no, now it's broken!";
		is_working = Working::Broke;
	}
};

class Online : public UPS //Ñîçäàíèå äî÷åðíåãî êëàññà Îíëàéí ÈÁÏ
{
public:
	bool switch_now; //Òåêóùåå ñîñòîÿíèå ïåðåêëþ÷àòåëÿ(àâòîíîìíàÿ ðàáîòà / ðàáîòà îò ñåòè = 1)

	Online() : UPS() { Color = ColorUPS::Black; }
	ColorUPS look_at() const { return ColorUPS::Black; }

	void Punch_it()
	{
		cout << "Wow, now it's working!";
		is_working = Working::Work;
	}
};


#endif
