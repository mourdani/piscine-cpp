#include <iostream>
#include <limits>
#include <cstdlib>
#include <algorithm> // Ajout de l'en-tête <algorithm> pour utiliser la fonction std::all_of
#include <cctype> // Ajout de l'en-tête <cctype> pour utiliser les fonctions de la famille is*

int main(int argc, char* argv[])
{
    int i = 0;
    float f = 0.0f;
    double d = 0.0; 
    // On vérifie que le nombre de paramètres est correct
    if (argc != 2)
    {
        std::cerr << "Erreur : un seul paramètre est attendu." << std::endl;
        return EXIT_FAILURE;
    }

    // On récupère le paramètre passé en ligne de commande
    const std::string param = argv[1];

    // On vérifie si c'est un littéral de type char
    if ((param.size() == 3 && param[0] == '\'' && param[2] == '\'') || param.size() == 1)
    {        std::cout << "shiit\n";

// On extrait le caractère
char c;
if (param.size() == 3)
{
    c = param[1];
}
else
{
    c = param[0];
}

// On vérifie si le caractère est affichable
if (std::isprint(c))
{
    std::cout << "char: " << c << std::endl;
}
else
{
    std::cout << "char: Non displayable" << std::endl;
}
    }
    // On vérifie si c'est un littéral de type int
    else if (std::all_of(param.begin(), param.end(), ::isdigit) ||
             (param[0] == '-' && std::all_of(param.begin() + 1, param.end(), ::isdigit)))
    {
        // On convertit le paramètre en int
        const int i = std::stoi(param);

        // On vérifie si la conversion a réussi et si la valeur est dans les limites du type int
        if (i == std::stoi(param) && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
        {
            std::cout << "int: " << i << std::endl;
        }
        else
        {
            std::cout << "int: impossible" << std::endl;
        }
    }
    // On vérifie si c'est un littéral de type float
   else if (param.find('f') != std::string::npos)
    {
        // On convertit le paramètre en float
        const float f = std::stof(param);

        // On vérifie si la conversion a réussi et si la valeur est dans les limites du type float
        if (f == std::stof(param) && f >= -std::numeric_limits<float>::infinity() && f <= std::numeric_limits<float>::infinity())
        {
            std::cout << "float: " << f << "f" << std::endl;
        }
        else
        {
            std::cout << "float: impossible" << std::endl;
        }
    }
    // On vérifie si c'est un littéral de type double
   else
    {
        // On convertit le paramètre en double
        const double d = std::stod(param);

        // On vérifie si la conversion a réussi et si la valeur est dans les limites du type double
        if (d == std::stod(param) && d >= -std::numeric_limits<double>::infinity() && d <= std::numeric_limits<double>::infinity())
        {
            std::cout << "double: " << d << std::endl;
        }
        else
        {
            std::cout << "double: impossible" << std::endl;
        }
    }
     //On convertit le littéral dans les autres types de données
    std::cout << "char: " << param << std::endl;
    if (std::all_of(param.begin(), param.end(), ::isdigit))
    {
        std::cout << "int: " << std::stoi(param) << std::endl;
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }
    if (std::all_of(param.begin(), param.end() - 1, ::isdigit) && param.back() == 'f')
    {
        std::cout << "float: " << std::stof(param) << "f" << std::endl;
    }
    else   
    {
        std::cout << "float: impossible" << std::endl;
    }

    return EXIT_SUCCESS;
}

