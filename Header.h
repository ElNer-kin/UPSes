#ifndef HEADER_H
#define HEADER_H
#include <string>

using namespace std;

class UPS {}; //�������� ������������� ������ ���

class Line_interactive : public UPS {}; // �������� ��������� ������ �������-������������� ���

class Standby : public UPS {}; //�������� ��������� ������ ��������� ���

class Online : public UPS {}; //�������� ��������� ������ ������ ���

#endif