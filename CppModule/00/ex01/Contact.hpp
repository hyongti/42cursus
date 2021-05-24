#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class contact
{
private:
	std::string	information[11];
	static std::string infoname[11];
public:
	void		InputInfo(void);
	void		SearchInfo(void);
	void		PreviewInfo(void);
	void		ViewInfo(void);
};

#endif