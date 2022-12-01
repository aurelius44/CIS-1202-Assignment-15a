// Mark Middleton
// CIS 1202 501
// December 1, 2022

#include<iostream>

using namespace std;

char character(char start, int offset);

class invalidCharacterException {

};

class invalidRangeException {

};

class caseConversionException {

};

char character(char start, int offset) {
	
	int value = int(start);
	int i = value + offset;

	try {
		if (value < 65 || (value > 90 && value < 97) || value > 122) {
			
			throw invalidCharacterException();
		}
		else if (i < 65 || (i > 90 && i < 97) || i > 122) {
			
			throw invalidRangeException();
		}
		else if ((i >= 65 && i <= 90 && value >= 95 && value <= 122) || (i >= 95 && value <= 122 && value >= 65 && value <= 90)) {
			
			throw caseConversionException();
		}
	}

	catch (invalidCharacterException e1) {
		
		cout << "Invalid Character Exception" << endl;
		
		return ' ';
	}
	catch (invalidRangeException e2) {

		cout << "Invalid Range Exception" << endl;

		return ' ';
	}
	catch (caseConversionException e3) {
		
		cout << "Invalid letter casing" << endl;

		return ' ';
	}

	return char(i);
}

int main() {

	cout << character('a', 1) << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32) << endl;
}