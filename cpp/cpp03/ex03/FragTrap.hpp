#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap( void );
	FragTrap( const FragTrap& other);
	FragTrap& operator=( const FragTrap& other );
	FragTrap( const std::string& name );
	~FragTrap( void );

	/* Member functions */
	void	highFiveGuys( void );
};

#endif /* FRAGTRA_HPP */
