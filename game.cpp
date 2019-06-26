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

		int tmp, id1, id2;  //셔플알고리즘으로 값을 섞어준다
		for (int i = 0; i < 100; i++) {
			id1 = rand() % 24;
			id2 = rand() % 24;

			tmp = puzzle[id1];
			puzzle[id1] = puzzle[id2];
			puzzle[id2] = tmp;
		}
		while(1){

		cout << "숫자를 순서대로 배치하면 게임이 끝납니다" << endl;
		cout << endl;		
		
		for (int i = 0; i < 5; i++) { //화면에 퍼즐을 표시
			for (int j = 0; j < 5; j++) {
				if (puzzle[i * 5 + j] == INT_MAX)
					cout << "*"<<"\t";
				else
					cout << puzzle[i * 5 + j] << "\t";
			}
			cout << endl;
		}
	
		bool win = true;
		for (int i = 0; i < 24; i++) { //퍼즐이 제대로맞추어졌는지 체크
			if (puzzle[i] != i + 1)
				win = false;
		}
		if (win == true) {
			cout << endl;
			cout << "퍼즐을 클리어!" << endl;
			break;
		}
		    cout << "w:상 s:하 a:좌 d:우 q:게임종료" << endl;
			char input = _getch();
			if (input == 'q' || input == 'Q') //q나Q입력시 게임종료
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