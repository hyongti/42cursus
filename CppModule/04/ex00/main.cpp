#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Hyeonkim.hpp"

int		main(void)
{
	Victim		*kilee = new Peon("kilee");
	Peon		*hyeonski = new Peon("hyeonski");

	kilee->getPolymorphed();
	hyeonski->getPolymorphed();

	std::cout << *kilee;
	std::cout << *hyeonski;

	delete kilee;
	delete hyeonski;

	Sorcerer	cjang("cjang", "cadet");
	Victim		mijeong("mijeong");
	Hyeonkim	hyeonkim("hyeonkim");

	cjang.getPolymorphed(mijeong);
	
	std::cout << cjang;
	std::cout << mijeong;
	std::cout << hyeonkim;

	hyeonkim.getPolymorphed();
}