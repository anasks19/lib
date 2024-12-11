#include "utils.hpp"

int main( void ) {

IMateriaSource* src = new MateriaSource();

src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");
AMateria* tmp;

tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
//me->unequip(1);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);

delete bob;
delete me;
delete src;
//delete tmp;
return 0;

}