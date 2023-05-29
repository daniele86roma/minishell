/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:36:23 by adi-fort          #+#    #+#             */
/*   Updated: 2023/05/24 12:01:39 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


/*devo implementare cd con:

-path relativi (cd ..)
-path assoluti (passando il path tra parentesi)

-devo cambiare le variabili env PWD e OLDPWD
-devo muovermi nella nuova cartella indicata dall´argomento

LA FUNZIONE DOVRA ESSERE IN GRADO DI GESTIRE:

- cd .. (deve funzionare anche ../../../../..)
- cd + path corretto
- cd + path scorretto / nessun path

QUANDO CD VA A BUON FINE:

-una funzione che trova OLDPWD nella lista envp e ritorna la stringa con OLDPWD
-una funzione che sostituisce OLDPWD con PWD
-una funzione che trova PWD nella lista envp e ritorna la stringa con PWD
-una funzione che scriva su PWD il nuovo PATH
*/

char	*find_oldpwd(t_pipex *pipex)
{
	int	i;
	
	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp("OLDPWD", pipex->envp[i], 6) == 0)
			break;
		i++;
	}
	return (pipex->envp[i]);
}

char	*find_pwd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp[i])
	{
		if (strncmp("PWD", pipex->envp[i], 3) == 0)
			break ;
		i++;
	}
	return (pipex->envp[i]);
}

void	overwrite_envp(t_pipex *pipex)
{	
	find_pwd() = find_oldpwd();
	find_oldpwd() = //argomento di cd;
}

void	ft_cd(void)
{
	if (cd + argomenti != 2)
	{
		write(2, "cd: too many arguments\n", 23);
		return ;
	}
	if (cd + non path)//ovvero una parola che non corrisponde a una cartella)
	{
		write(2, "cd: No such file or directory\n", 30);
		return ;
	}
	overwrite_envp(t_pipex *pipex);
	chdir(//argomento di cd)
}
