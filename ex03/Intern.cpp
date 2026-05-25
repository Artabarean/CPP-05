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
        return (new ShrubberyCreationForm(target));
    else if (formName == "robotomy request")
        return (new RobotomyRequestForm(target));
    else if (formName == "presidential pardon")
        return (new PresidentialPardonForm(target));
    else
    {
        std::cout << "Intern couldn't create form: " << formName << std::endl;
        return (nullptr);
    }
}
