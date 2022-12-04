/*Състаавете алгоритъм и програма(може да използвате псевдокод) за сортиране
чрез вмъкване,
като мястото на вмъкване се търси дихотомично.
Съставете опорна схема(масивът и какво се прави с него), означете имената на
променливите, които ползвате.
(примерен код)
*/
#include<iostream>
using namespace std;
int main() {
	cout << "Please enter the size of array: " << endl;
	int n;
	cin >> n;
	int* arr = new int[n];
	cout << "please fill the array: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int flag = 0;
	int iBeg = 0;
	int iEnd = 0;
	int iMid = 0;
	int number = 0;
	for (int i = 1; i < n; i++) {//
		number = arr[i];
		if (number >= arr[i - 1]) {
			continue;
		}
		else if (i == 1 && arr[i] < arr[i - 1]) {
			flag = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = flag;
			i--;
		}
		else {
			iBeg = 0;
			iEnd = i - 1;
			iMid = (iBeg + iEnd) / 2;
			while (iBeg != iMid && iEnd != iMid) {
				if (number > arr[iMid]) {
					iBeg = iMid;
					iMid = (iBeg + iEnd) / 2;
				}
				else if (number < arr[iMid]) {
					iEnd = iMid;
					iMid = (iBeg + iEnd) / 2;
				}
				else if (number == arr[iMid]) {
					break;
				}
			}
			flag = arr[i];
			for (int j = i; j > iBeg; j--) {
				arr[j] = arr[j - 1];
			}
			if (number > arr[iMid]) {
				arr[iMid + 1] = flag;
			}
			else
			{
				arr[iMid] = flag;
			}
		}
	}
	cout << "Ordered array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	return 0;
}
