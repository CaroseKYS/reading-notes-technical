#include <iostream>
#include <string>

int main(void){
	std::string str1("Heavy rains are pushing water levels beyond the limit.");
	std::string str2, str3;
	int k;
	
	str2 = "Sluice gates at Three Gorges Dam opened to discharge water.";
	
	str3 = str1 + str2;
	
	k = str3.find("Heavy");
	
	str3.erase(k, sizeof("Heavy") - 1);
	str3.insert(k, "Strong");
	str3.find
	
	std::cout << str3 << std::endl;
	
	return 0;
}
