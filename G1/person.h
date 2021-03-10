#define FILENAME "file_pessoas"

tupedef struct Person {
	char nome[200];
	int age;
}Person;

int new_person (char* name, int age);

int person_change_age (char* name, int age);

int person_change_age_v2 (int pos, int age);

int new_person_v2 (char* name, int age);
