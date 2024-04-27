#ifndef HEADER_H
#define HEADER_H
#include <string>

using namespace std;

enum class ColorUPS : int //���� ������� ���
{
	Black = 0,
	Grey = 1,
	White = 2,
};

enum class Working : int //������� ��������� ���(�������� = 1 / ������ = 0)
{
	Work = 1,
	Broke = 0,
};


class UPS { //�������� ������������� ������ ���
protected:
	string name;
	string model;
	ColorUPS Color;


public:
	short output_power; //�������� ����������
	short number_of_batteries; //����� ���
	Working is_working;

	virtual ColorUPS look_at() const { return Color; } //������� ��������� ������ ����
	int GetBatteries() const { return number_of_batteries; } //������� ��������� ������ ����� ��� � ���
	virtual void Punch_it() {} //������ ��� �����


};
class Line_interactive : public UPS // �������� ��������� ������ �������-������������� ���
{
protected:
	bool sinusoidal_output_voltage; // ��� �-� ���: � ������������������ ���������� ��� ��������� �������������� �������� �����������
public:
	Line_interactive() : UPS() { Color = ColorUPS::Grey; }
	ColorUPS look_at() const { return ColorUPS::Grey; }

	void Punch_it()
	{
		cout << "It's a good UPS, it's still can working!";
	}
};

class Standby : public UPS //�������� ��������� ������ ��������� ���
{
protected:
	short age; //���� ������ ���(���� ������ 3 ��� => ������������ ���������� ����� ������ ������� ���������� � �� ���� ������
public:
	Standby() : UPS() { Color = ColorUPS::White; }
	ColorUPS look_at() const { return ColorUPS::White; }

	void Punch_it()
	{
		cout << "Oh no, now it's broken!";
		is_working = Working::Broke;
	}
};

class Online : public UPS //�������� ��������� ������ ������ ���
{
public:
	bool switch_now; //������� ��������� �������������(���������� ������ / ������ �� ���� = 1)

	Online() : UPS() { Color = ColorUPS::Black; }
	ColorUPS look_at() const { return ColorUPS::Black; }

	void Punch_it()
	{
		cout << "Wow, now it's working!";
		is_working = Working::Work;
	}
};


#endif