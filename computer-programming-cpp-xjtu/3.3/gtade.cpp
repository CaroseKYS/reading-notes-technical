#include <iostream>

int main(void){
	int old_grade;
	float new_grade;
	
	std::cout << "Enter your grade: ";
	std::cin  >> old_grade;
	
	switch(old_grade / 5){
		case 12:
			new_grade = 2.0f;
			break;
		case 13:
			new_grade = 2.5f;
			break;
		case 14:
			new_grade = 3.0f;
			break;
		case 15:
			new_grade = 3.5f;
			break;
		case 16:
			new_grade = 4.0f;
			break;
		case 17:
			new_grade = 4.5f;
			break;
		case 18:
			new_grade = 5.0f;
			break;
		case 19:
			new_grade = 5.5f;
			break;
		case 20:
			new_grade = 6.0f;
			break;
		default:
			new_grade = 1.0f;
	}
	
	std::cout << "Your new grade is: " << new_grade << std::endl; 
}
