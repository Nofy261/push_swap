#include "push_swap.h"

//verifier le nombre d argument 
// si c'est 1 ou moins = erreur 
int verif_argc(int argc)
{
	if (argc <= 1)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
//creer une fonction qui parcourt un tableau de tableau 
int	check_sign(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		while(argv[j][i])
		{
			if((argv[j][0] == '-' || argv[j][0] == '+') && (argv[j][i + 1] == ft_isdigit))
				return (1);//on return un booleen pour dire vrai // le return n'arrete-t'il pas la fonction??? 
			else if((argv[j][0] == '-' || argv[j][0] == '+') && (argv[j][i + 1] != ft_isdigit))
				return (0);
			else if (argv[j][0] == 32 && (argv[j][i + 1] == 32 || argv[j][i + 1] == '\0'))
			{
				write (1, "Error\n", 6);
				return (0);
			}
			i++;//on va checker les autres chiffres/caractere?
		}
		j++;
	}
	if (i == 0)
		return (1);
	return(0);//??
}

//boucle qui parcourt argc
//fonction qui stocke argv
//split sur les espaces
//creer un tableau de tableau et stocke la valeur de retour de ft_split
function()
{
	int	i;

	i = 1;
	while (argc[i])
	{
		tableau = ft_split(argc);
	}



}

