#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
	: Form(ref), target(ref.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	if (this == &ref)
		return (*this);
	Form::operator=(ref);
	return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	
	std::ofstream ofs(target + "_shrubbery");

	ofs <<"                                              .       "<< std::endl;
	ofs <<"                                   .         ;        "<< std::endl;  
	ofs <<"      .              .              ;%     ;;         "<< std::endl;
	ofs <<"        ,           ,                :;%  %;          "<< std::endl;
	ofs <<"         :         ;                   :;%;'     .,   "<< std::endl;
	ofs <<",.        %;     %;            ;        %;'    ,;     "<< std::endl;
	ofs <<"  ;       ;%;  %%;        ,     %;    ;%;    ,%'      "<< std::endl;     
	ofs <<"   %;       %;%;      ,  ;       %;  ;%;   ,%;'       "<< std::endl;
	ofs <<"    ;%;      %;        ;%;        % ;%;  ,%;'         "<< std::endl;
	ofs <<"     `%;.     ;%;     %;'         `;%%;.%;'           "<< std::endl;
	ofs <<"      `:;%.    ;%%. %@;        %; ;@%;%'              "<< std::endl;    
	ofs <<"         `:%;.  :;bd%;          %;@%;'                "<< std::endl;            
	ofs <<"           `@%:.  :;%.         ;@@%;'                 "<< std::endl;    
	ofs <<"             `@%.  `;@%.      ;@@%;                   "<< std::endl;
	ofs <<"               `@%%. `@%%    ;@@%;                    "<< std::endl;
	ofs <<"                 ;@%. :@%%  %@@%;                     "<< std::endl;
	ofs <<"                   %@bd%%%bd%%:;                      "<< std::endl;    
	ofs <<"                     #@%%%%%:;;                       "<< std::endl;
	ofs <<"                     %@@%%%::;                        "<< std::endl;
	ofs <<"                     %@@@%(o);  . '                   "<< std::endl;    
	ofs <<"                     %@@@o%;:(.,'                     "<< std::endl;    
	ofs <<"                 `.. %@@@o%::;                        "<< std::endl;
	ofs <<"                    `)@@@o%::;                        "<< std::endl;
	ofs <<"                     %@@(o)::;                        "<< std::endl;
	ofs <<"                    .%@@@@%::;                        "<< std::endl;
	ofs <<"                    ;%@@@@%::;.                       "<< std::endl;
	ofs <<"                   ;%@@@@%%:;;;.                      "<< std::endl;
	ofs <<"               ...;%@@@@@%%:;;;;,..                   "<< std::endl;
}