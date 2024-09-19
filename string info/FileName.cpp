#include <iostream>
#include <string>

using namespace std;

class IOutput {
public:
	virtual void Show() = 0;
};

class IMath {
public:
	virtual int Max() = 0;
	virtual int Min() = 0;
	virtual float Avg() = 0;
};

class ISort {
public:
	virtual void SortAsc() = 0;
	virtual void SortDesc() = 0;
	virtual void Show() = 0;
};

class Array : public ISort, public IOutput, public IMath {
	int* elements;
	int size;
public:
	~Array() {
		delete[] elements;
	}
	void SortAsc() override{
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
	void SortDesc()override {
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
	void Show() override {
		for (int j = 0; j < size; j++) {
			cout << elements[j] << " ";
		}
	}
	int Max()override {
		int maxn = 0;
		for (int i = 0; i < size; i++) {
			if (elements[i] > maxn) { maxn = elements[i]; }
			else { continue; }
		}
		return maxn;
	}
	int Min()override {
		int minn = elements[0];
		for (int i = 0; i < size; i++) {
			if (elements[i] < minn) { minn = elements[i]; }
			else { continue; }
		}
		return minn;
	}
	float Avg()override {
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