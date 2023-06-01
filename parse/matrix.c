/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/03/21 09:17:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**add_chr(char **mat, char c)
{
	char	**mat2;
	int		i;
	char	*s;

	i = 0;
	while (mat[i])
		i++;
	mat2 = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (mat[++i])
		mat2[i] = mat[i];
	s = malloc(2);
	s[0] = c;
	s[1] = 0;
	mat2[i] = s;
	i++;
	mat2[i] = 0;
	free(mat);
	return (mat2);
}

char	**add_wrd(char **mat, char *s)
{
	char	**mat2;
	int		i;

	i = 0;
	while (mat[i])
		i++;
	mat2 = malloc(sizeof(char **) * (i + 2));
	i = -1;
	while (mat[++i])
		mat2[i] = mat[i];
	mat2[i] = s;
	i++;
	mat2[i] = 0;
	free(mat);
	return (mat2);
}

char	*fnd_wrd(char *s, int *i)
{	
	int		k;
	int		j;
	char	*s2;

	j = 0;
	k = *i;
	while (s[k] && s[k] != ' ' && s[k] != '|' && s[k] != '<' && s[k] != '>' && s[k] != '"' && s[k] != '\'')
	{
		j++;
		k++;
	}
	s2 = malloc(j + 1);
	j = 0;
	while (s[*i] && s[*i] != ' ' && s[*i] != '|' && s[*i] != '<' && s[*i] != '>' && s[k] != '"' && s[k] != '\'')
	{
		s2[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	s2[j] = 0;
	*i = *i - 1;
	return (s2);
}

char	*fnd_qts(char *s, int *i)
{	
	int		k;
	int		j;
	char	*s2;
	char	c;

	j = 1;
	k = *i;
	c = s[k];
	k++;
	while (s[k] && s[k] != c)
	{
		j++;
		k++;
	}
	s2 = malloc(j + 2);
	j = 1;
	*i = *i + 1;
	s2[0] = c;
	while (s[*i] && s[*i] != c)
	{
		s2[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	s2[j] = c;
	s2[j + 1] = 0;
	return (s2);
}

char	**create_matrix(char	*s)
{
	int		i;
	char	**mat;
	char	*wrd;

	i = -1;
	mat = malloc(sizeof(char *) * 1);
	mat[0] = 0; //CREO UNA MATRICE VUOTa
	while (s[++i]) //CONTROLLO CARATTERE PER CARATTERE LA STRINGA
	{
		if (s[i] == ' ') // SE TROVO UNO SPAZIO VADO AVANTI
			continue ;
		else if (s[i] == '<' || s[i] == '>' || s[i] == '|') // SE TROVO UN SIMBOLO CHIAVE LO AGGIUNGO ALLA MATRICE
			mat = add_chr(mat, s[i]);	//CREA UNA MATRICE NUOVA CON UNO SPAZIO IN PIU RICOPIA LA STRINGA VECCHIA E AGGIUNGE LA NUOVA STRINGA CON IL CARATTERE
		else if (s[i] == '\'' || s[i] == '"')	//SE INVECE TROVO UN QUOTE MI CERCO TUTTA LA STRINGA
		{
			wrd = fnd_qts(s, &i); //TROVATA LA STRINGA LA COPIO. l'INDICE I E' SPOSTATO FINO ALLA FINE DELLA STRINGA QUOTATA QUINDI CONTINUO DA LI
			mat = add_wrd(mat, wrd); // FUNZIONE CHE CREA UNA MATRICE NUOVA CON UNO SPAZIO IN PIU RICOPIA LA STRINGA VECCHIA E AGGIUNGE LA PAROLA
		}
		else //NON E UN CARATTERE SPECIALE NE UN QUOTE VUOL DIRE CHE E UNA PAROLA
		{
			wrd = fnd_wrd(s, &i); //LA TROVO E LA COPIO OVVIAMENTE SPOSTO L INDICE I DI CONSEGUENZA
			mat = add_wrd(mat, wrd); // STESSA FUNZIONE DI PRIMA PER AGGIUNGERE PAROLA aLLA MATRICE 
		}
	}
	return (mat);
}

// SE NOTI PASSO SEMPRE &I COSI POSSO CAMBIARE LA I NELLA FUNZIONE PRINCIPALE UNA VOLTA ELABORATA LA PORZIONE DI TESTO