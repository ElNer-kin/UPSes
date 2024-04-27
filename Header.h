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
};

class Line_interactive : public UPS // �������� ��������� ������ �������-������������� ���
{
protected:
	bool sinusoidal_output_voltage; // ��� �-� ���: � ������������������ ���������� ��� ��������� �������������� �������� �����������
};
class Standby : public UPS //�������� ��������� ������ ��������� ���
{
protected:
	short age; //���� ������ ���(���� ������ 3 ��� => ������������ ���������� ����� ������ ������� ���������� � �� ���� ������; 
};
class Online : public UPS
{
public:
	bool switch_now; //������� ��������� �������������(���������� ������ / ������ �� ���� = 1)}; //�������� ��������� ������ ������ ���
};

class UPS {}; //�������� ������������� ������ ���

class Line_interactive : public UPS {}; // �������� ��������� ������ �������-������������� ���

class Standby : public UPS {}; //�������� ��������� ������ ��������� ���

class Online : public UPS {}; //�������� ��������� ������ ������ ���

#endif