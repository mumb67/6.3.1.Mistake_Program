#include <iostream>

class SmartArray {
public:
	int* arr_;
	int count_newnum = 0;
	int count_num = 0;

	explicit SmartArray(int count_num_) {
		arr_ = new int[count_num_];
		count_num = count_num_;
	}

	void outputSmartArray() {
		std::cout << "Array: " << std::endl;
		for (int i = 0; i < count_num; i++) {
			std::cout << arr_[i] << "\n";
		}
		std::cout << "\n";
	}

	void add_element(int newnum_) {
		if (count_newnum < count_num) {
			arr_[count_newnum] = newnum_;
			count_newnum++;
		}
		else { std::cout << "Overflow! Number '" << newnum_ << "' doesn't added." << "\n\n"; }
	}

	void get_element(int i_elem) {
		if (i_elem < count_num) {
			std::cout << i_elem << " ";
			std::cout << "Element = " << arr_[i_elem] << ";" << std::endl;
			//return arr_[i_elem];
		}
		else { std::cout << i_elem << " Element " << "doesn't exist." << std::endl; }
		
	}

	~SmartArray() {
		delete[]arr_;
	}
};


int main()
{
	try {
		SmartArray arr1(5);

		arr1.add_element(1);
		arr1.add_element(4);
		arr1.add_element(155);
		arr1.add_element(14);
		arr1.add_element(15);
		arr1.add_element(6795);

		arr1.outputSmartArray();

		arr1.get_element(0);
		arr1.get_element(1);
		arr1.get_element(2);
		arr1.get_element(3);
		arr1.get_element(4);
		arr1.get_element(5);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	} 
}
