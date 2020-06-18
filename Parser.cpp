#include <iostream>
#include <string>
using namespace std;

string id; // GLOBAL VARIABLE TO TAKE USER INPUT
int i = 0; // GLOBAL INDEX VARIABLE

/* Grammar
 * <non-zero-digit>				::= 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 * <letter>						::= A | B | C | x | y | z
 * <group>						::= <letter> | <letter> <group'>
 * <group'>						::= <letter> | ε
 * <variable-identifier>		::= <non-zero-digit> <group>
 */

void group();

void insert_pos()
{
	for (int x = 0; x < i; x++) {
		cout << " ";
	}
	cout << "^" << endl;

	for (int x = 0; x < i; x++) {
		cout << " ";
	}
	cout << "|" << endl;
}

bool match(char t)
{
	if (id[i] == t) {
		i++;
		return true;
	}
	else {
		return false;
	}
}

void non_zero_digit()
{
	if (match('1') || match('2') || match('3') || match('4') || match('5') || match('6') ||
		match('7') || match('8') || match('9')) {
		return; // do nothing
	}
	else if (id[i] == '\0') {
		return; // string end reached, do nothing
	}
	else {
		insert_pos();
		cout << "SYNTAX ERROR: expected a number, found " << id[i] << endl;
		exit(1);
	}
}

void letter()
{
	if (match('A') || match('B') || match('C') || match('x') || match('y') || match('z')) {
		return; // do nothing
	}
	else if (id[i] == '\0') {
		return; // string end reached, do nothing
	}
	else {
		insert_pos();
		cout << "SYNTAX ERROR: expected a letter (A, B, C, x, y, z), found " << id[i] << endl;
		exit(1);
	}
}

void group_epsilon()
{
	if (match('A') || match('B') || match('C') || match('x') || match('y') || match('z')) {
		group();
	}
	else {
		return; // do nothing
	}
}

void group()
{
	letter();
	group_epsilon();
}

void variable_identifier()
{
	non_zero_digit();
	if (id[i] == '\0') {
		cout << "SYNTAX ERROR: expected a letter (A, B, C, x, y, z), found NULL character" << endl;
		exit(1); // this is a common pattern, abstract it
	}
	group();
}

int main()
{
	getline(cin, id);
	variable_identifier();

}
