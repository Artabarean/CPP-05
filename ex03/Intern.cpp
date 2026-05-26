#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern&)
{
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern&)
{
    return (*this);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    if (formName == "shrubbery creation")
    {
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return (new ShrubberyCreationForm(target));
    }
    else if (formName == "robotomy request")
    {
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return (new RobotomyRequestForm(target));
    }
    else if (formName == "presidential pardon")
    {
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return (new PresidentialPardonForm(target));
    }
    else
    {
        std::cout << "Intern couldn't create form: " << formName << std::endl;
        return (nullptr);
    }
}
