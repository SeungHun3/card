#include<iostream>
#include<time.h>
void Draw(int* A);
using namespace std;

int main()
{

	int A[52] = {};
	int Rand1[52] = {};
	int Rand2[52] = {};
	int split[52] = {};
	int player[10] = {};
	int Ai[10] = {};

	

	srand(unsigned int(time(NULL)));

	for (int i = 0; i < 52; ++i)
	{
		A[i] = i;
	}
	for (int i = 0; i < 52; ++i)
	{
		Rand1[i] = rand()% 52;
		Rand2[i] = rand() % 52;
		int temp;
		temp = Rand1[i];
		A[Rand1[i]] = A[Rand2[i]];
		A[Rand2[i]] = temp;
		

	}
	// 섞였다
	// 숫자 분배

	
	
	//플레이어,  AI 카드 3장씩분배


	cout << "Player" << "   " << "AI" << endl;
	int playersum = 0;
	int AiSum = 0;
	for (int i = 0; i < 3; ++i)
	{
		player[i] = A[i * 2];
		Ai[i] = A[(i * 2) + 1];

		Draw(&player[i]);
		Draw(&Ai[i]);

		for (int i = 0; i < 6; ++i)
		{

			split[i] = (A[i] % 13) + 1;
			if (split[i] > 10)
			{
				split[i] = 10;
			}
		}
		

		playersum = playersum + player[i];
		AiSum = AiSum + Ai[i];
		if (AiSum >= 22 ||(AiSum > 21&& playersum>21))
		{
			cout << "Ai 패배" << endl;
			break;
		}
		else if (playersum > 21)
		{
			cout << "Player 패배" << endl;
			break;
		}
	
	}

		

		

	return 0;
	
}

void Draw(int *A)
{

	
		int Type = *A / 13;
		int Number = *A % 13;

		switch (Type)
		{
		case 0:
			cout << "★";
			break;
		case 1:
			cout << "○";
			break;
		case 2:
			cout << "◆";
			break;
		case 3:
			cout << "▲";
			break;
		}

		switch (Number)
		{
		case 12:
			cout << "K" << " ";
			break;
		case 11:
			cout << "Q" << " ";
			break;
		case 10:
			cout << "J" << " ";
			break;
		case 0:
			cout << "A" << " ";
			break;
		default:
			cout << Number + 1 << " ";
			break;
		}

	
}