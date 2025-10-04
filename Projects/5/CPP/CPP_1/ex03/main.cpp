#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon mear("hache de guerre");

	HumanA	toto("Toto", mear);
	toto.attack();
	mear.setType("rafleuz");
	toto.attack();
	HumanB	rina("Rina");
	mear.setType("hache de guerre");
	rina.attack();
	rina.setWeapon(mear);
	mear.setType("rafleuz");
	rina.attack();
	return 0;
}
