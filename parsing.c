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
int	check_sign(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while(argv[j][i])
		{
			if(argv[j][0] == '-' || argv[j][0] == '+')
			{
				if(!ft_isdigit(argv[j][i + 1]))
					return (1);
			}
			if (argv[j][0] == 32 && (argv[j][1] == 32 || argv[j][1] == '\0'))
				return (0);
			i++;//on va checker les autres chiffres/caractere?
		}
	}
	if (i == 0)
		return (1);
	j++;
	return(0);
}

//boucle qui parcourt argc
//fonction qui stocke argv
//split sur les espaces
//creer un tableau de tableau et stocke la valeur de retour de ft_split
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	char **tableau;
	t_list *list_a;
	t_list *list_b;

	list_a = NULL;
	list_b = NULL;
	if (verif_argc(argc) == 1 || check_sign(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argv)
	{
		tableau = ft_split(argv[i], ' ');
		
	}



}

