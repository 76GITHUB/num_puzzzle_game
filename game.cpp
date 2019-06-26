#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

int main() {
		srand((unsigned int)time(NULL));
        int puzzle[25] = {};
        for (int i = 0; i < 24; i++) {
			puzzle[i] = i + 1;
		}
        puzzle[24] = INT_MAX;
		int star = 24;

		int tmp, id1, id2;  //���þ˰������� ���� �����ش�
		for (int i = 0; i < 100; i++) {
			id1 = rand() % 24;
			id2 = rand() % 24;

			tmp = puzzle[id1];
			puzzle[id1] = puzzle[id2];
			puzzle[id2] = tmp;
		}
		while(1){

		cout << "���ڸ� ������� ��ġ�ϸ� ������ �����ϴ�" << endl;
		cout << endl;		
		
		for (int i = 0; i < 5; i++) { //ȭ�鿡 ������ ǥ��
			for (int j = 0; j < 5; j++) {
				if (puzzle[i * 5 + j] == INT_MAX)
					cout << "*"<<"\t";
				else
					cout << puzzle[i * 5 + j] << "\t";
			}
			cout << endl;
		}
	
		bool win = true;
		for (int i = 0; i < 24; i++) { //������ ����θ��߾������� üũ
			if (puzzle[i] != i + 1)
				win = false;
		}
		if (win == true) {
			cout << endl;
			cout << "������ Ŭ����!" << endl;
			break;
		}
		    cout << "w:�� s:�� a:�� d:�� q:��������" << endl;
			char input = _getch();
			if (input == 'q' || input == 'Q') //q��Q�Է½� ��������
				break;

				switch (input)
				{
				case 'w':
				case 'W':
					if (star > 4) {
						puzzle[star] = puzzle[star - 5];
						puzzle[star - 5] = INT_MAX;
						star -= 5;
						system("cls");
					}
					else
						system("cls");
					break;
				case 's':
				case 'S':
					if ( star <20) {
						puzzle[star] = puzzle[star + 5];
						puzzle[star + 5] = INT_MAX;
						star += 5;
						system("cls");
					}
					else
						system("cls");

					break;
				case 'a':
				case 'A':
					if (star%5 !=0 ) {
						puzzle[star] = puzzle[star -1];
						puzzle[star -1] = INT_MAX;
						star -= 1;
						system("cls");
					}
					else
						system("cls");

					break;
				case 'd':
				case 'D':
					if (star % 5 != 4) {
						puzzle[star] = puzzle[star +1];
						puzzle[star + 1] = INT_MAX;
						star += 1;
						system("cls");
					}
					else
						system("cls");
					break;		
				}
			}
		cout << endl;
		cout << endl;
}