#include <iostream>
#include <string>

using namespace std;

class IOutput {
	string info;
public:
	void Show() {
		cout << info;
	}
	void Show(string i) {
		cout << i;
	}
};

class IMath {
	int arr[6]{ 1, 2, 4, 5, 3, 6 };
public:
	int Max() {
		int maxn = 0;
		for (int i = 0; i < 6; i++) {
			if (arr[i] > maxn) { maxn = arr[i]; }
			else { continue; }
		}
		return maxn;
	}
	int Min() {
		int minn = arr[0];
		for (int i = 0; i < 6; i++) {
			if (arr[i] < minn) { minn = arr[i]; }
			else { continue; }
		}
		return minn;
	}
	float Avg() {
		float sum;
		for (int i = 0; i < 6; i++) {
			sum += arr[i];
		}
		return sum /= 6;
	}
};

class ISort {
	int arr[6]{6, 1, 5, 3 , 4 , 0};
public:
	void SortAsc() {
		for (int i = 0; i < 6 - 1; ++i) {
			for (int j = 0; j < 6 - i - 1; ++j) {
				if (arr[j] > arr[j + 1]) {
					int a = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = a;
				}
			}
		}
	}
	void SortDesc() {
		for (int i = 0; i < 6 - 1; ++i) {
			for (int j = 0; j < 6 - i - 1; ++j) {
				if (arr[j] < arr[j + 1]) {
					int a = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = a;
				}
			}
		}
	}
	void Show() {
		for (int i = 0; i < 6; i++) {
			cout << arr[i];
		}
	}
};

class Array {
	int* elements;
	int size;
public:
	~Array() {
		delete[] elements;
	}
	void SortAsc() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (elements[j] > elements[j + 1]) {
					int a = elements[j];
					elements[j] = elements[j + 1];
					elements[j + 1] = a;
				}
			}
		}
	}
	void SortDesc() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (elements[j] < elements[j + 1]) {
					int a = elements[j];
					elements[j] = elements[j + 1];
					elements[j + 1] = a;
				}
			}
		}
	}
	void Init(int s) {
		size = s;
		elements = new int[s];
		for (int i = 0; i < s; i++) {
			elements[i] = i * 3 + 2;
		}
	}
	void Show() {
		for (int j = 0; j < size; j++) {
			cout << elements[j] << " ";
		}
	}
	int Max() {
		int maxn = 0;
		for (int i = 0; i < size; i++) {
			if (elements[i] > maxn) { maxn = elements[i]; }
			else { continue; }
		}
		return maxn;
	}
	int Min() {
		int minn = elements[0];
		for (int i = 0; i < size; i++) {
			if (elements[i] < minn) { minn = elements[i]; }
			else { continue; }
		}
		return minn;
	}
	float Avg() {
		float sum;
		for (int i = 0; i < size; i++) {
			sum += elements[i];
		}
		return sum /= size;
	}
};



int main() {
	Array arr;
	arr.Init(10);
	arr.Show();

	arr.SortAsc();
	arr.Show();
	arr.SortDesc();
	arr.Show();

	arr.Max();
	arr.Min();
}