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

int Intern::check_form(const std::string &formName)
{
    std::string form[3] = 
    {
        "shrubbery creation", 
        "presidential pardon", 
        "robotomy request"
    };
    for (int i = 0; i < FORM_COUNT; ++i)
    {
        if (formName == form[i])
            return (i);
    }
    return (FORM_COUNT);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    int form_idx;

    form_idx = check_form(formName);
    switch (form_idx)
    {
        case SHRUBBERY:
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (new ShrubberyCreationForm(target));
        }
        case PRESIDENTIAL: 
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (new PresidentialPardonForm(target));
        }
        case ROBOTOMY:
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (new RobotomyRequestForm(target));
        }
        default :
        {
            std::cout << "Intern couldn't create form: " << formName << std::endl;
            return (NULL);
        }
    }
}
