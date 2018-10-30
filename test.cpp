#include <iostream>
#include "sigslot.h"

using namespace sigslot;

struct dog
{
	signal1<int> bark; 
	void beaten()
	{
		bark(100); 
	}
};

struct human : public has_slots<>
{
	void dog_bark(int vol)
	{
		std::cout<<"vol = "<<vol<<std::endl;
	} 
};

int main()
{
	dog d;
	human man;
	d.bark.connect(&man, &human::dog_bark); 

	d.beaten();

	//d.bark.disconnect(&man);
	return 0;
}
