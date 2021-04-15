#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	Contact		Contact[8];
public:
	Phonebook();
	~Phonebook();
	void		PrintPrompt(void);
	void		AddContact(void);
	void		SearchContact(void);
};

#endif