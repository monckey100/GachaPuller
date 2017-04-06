#include <iostream> 
#include <time.h>
#include <algorithm>    // std::fill_n
#include <math.h>
#include <string>
using namespace std;
int main() {
	int test1, sample;
	int tests;
	float test2;
	char win = 'y';
	const int max_int = 150000000;
	string purchased = "";
	int* results = new int[max_int];
	srand(time(NULL));
	sample = 1;
	cout << "Good rolls:";
	cin >> test1;
	cout << "Do you know the successful win percent?(Y/N)\n";
	cin >> win;
	if (win == 'Y' || win == 'y') {
		cout << "win percent? (number only)\n";
		cin >> test2;
		test2 = abs(test2);
		test2 = 100 / test2;
	}
	else {
		cout << "How many cards are there?\n";
		cin >> test2;
	}
	cout << "how much does each pull remove bad cards? ";
	int badpulls;
	int oldtest2 = (int)test2;
	cin >> badpulls;
	//100 / 10000 = 1%
	/*
	int count = 0;
	num = abs(num);
	num = num - int(num);
	cout << "\nnum:" << num;
	while (num != 0) {
	num = num * 10;
	cout << "\nnum:" << num << " " << int(num);
	count = count + 1;
	num = num - int(num);

	}
	cout << "\nnum:" << num;
	cout << count;
	*/
	while (sample != 0) {
		cout << "Roll  attempts: ";
		cin >> sample;
		cout << "how many tests?";
		cin >> tests;
		for (int b = 1; b <= tests; b++) {
			cout << "running test " << b << "!\n";
			for (int i = 0; i<sample; i++) {
				int val = rand() % (int)test2 + 1;
				results[val]++;
				test2 -= badpulls;
				//cout << "cards:" << (int)test2 << "\n";
				if (test2 <= test1) {
					for (int y = 1; y <= test1; y++)
						results[y]++;
					break;
				}
			}
			test2 = (float)oldtest2;
		}
		for (int i = 1; i <= test2; i++) {
			if (i > test1)
				break;
			//if(results[i]!=0){
			cout << "R" << i << ":" << results[i] << " ";
			printf("%0.2f %%\n", ((float)results[i] / ((float)sample*(float)tests)) * 100);
			// }
		}
		cout << "------------\n";
		cout << "end of testing!\n";
		cout << "Good rolls: " << test1 << "\nTotal rolls:" << test2 << "\n";
		cout << "Roll attempts: " << sample << "\n";
		cout << "Tests:" << tests << "\n";
		cout << "------------\n";
		if (sample >= 40)
			purchased = "super computer";
		else if (sample >= 20)
			purchased = "a really bad car";
		else if (sample >= 15)
			purchased = "a bro dog";
		else if (sample >= 10)
			purchased = "a mean cat";
		else if (sample >= 7)
			purchased = "really nice ferret";
		else if (sample >= 3)
			purchased = "AAA game";
		else if (sample >= 2)
			purchased = "2+ FF games";
		else 
			purchased = "gourmet meal (27.96)";
		cout << "With " << sample << " roll attempts, You could have bought a " << purchased << " instead!\n(Assuming you spent 6 summon tickets per summon, $" << 27.96 * sample << ")\n";
		fill_n(results, (int)test2, 0);
	}
	return 0;
}