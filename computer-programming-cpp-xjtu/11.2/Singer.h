#include "../11.1/Person.h"

class Singer: public Person{
	private:
		float appearance_fee;
	public:
		Singer();
		virtual ~Singer();
		Singer(char *, char, char *, int, int, float);
		void plaing();
};
