#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class phonebook
{
private:
	int			num;
	contact		contact[8];
public:
	void		PrintWelcome(void);
	void		PrintPrompt(void);
	void		AddContact(void);
	void		SearchContact(void);
	void		PrintExit(void);
	void		PrintError(void);
};

#endif