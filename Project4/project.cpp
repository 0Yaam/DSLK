#include <iostream>
#include <iomanip>

#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#include "thuvien.h"
#include "menu.h"


void ChayChuongTrinh();
int main()
{
	 ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int soMenu = 13, menu;
	List l;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(l, menu);
		system("pause");

	} while (menu >= 0);
}