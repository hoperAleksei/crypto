#include <iostream>

#define ST_MAX 65535
#define A_CODE 65
#define a_CODE 97
#define ALP_COUNT 26



using namespace std;

/*
 *
 * The program accepts as input a message of Latin letters and the offset key of each character.
 *
 */



int strlen(char *string)
{
	for (size_t i = 0; i < ST_MAX; ++i) {
		if (string[i] == '\0') return i;
	}
}


char* encrypt(char *str, int key)
{
	size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		char curCh = str[i];
		if ((curCh >= 'A') && (curCh <= 'Z'))
		{
			str[i] = (char) ((curCh - A_CODE + key) % ALP_COUNT + A_CODE);
		}
		else if ((curCh >= 'a') && (curCh <= 'z'))
		{
			str[i] = (char) ((curCh - a_CODE + key) % ALP_COUNT + a_CODE);
		}
	}
	
}

int main() {
	char *message;
	int key;
	
	size_t charCount;
	
	cout << "Encrypt: " << endl;
	
	cout << "Enter max char in message count: ";
	cin >> charCount;
	
	message = new char [++charCount];
	cout << "Enter your message: ";
	
	cin.ignore();
	cin.getline(message, charCount, '\n');
	
	cout << "Enter your key (1-26): ";
	cin >> key;
	if ((key < 1) ||(key > 26))
	{
		cout << "Invalid Data";
		return 1;
	}
	
	encrypt(message, key);
	
	cout << message << endl;
	
	cout << "Decrypt: " << endl;
	
	cout << "Enter your message: ";
	
	cin.ignore();
	cin.getline(message, charCount, '\n');
	
	cout << "Enter your key (1-26): ";
	cin >> key;
	if ((key < 1) ||(key > 26))
	{
		cout << "Invalid Data";
		return 1;
	}
	encrypt(message, -key);
	
	cout << message;
	
	return 0;
}
