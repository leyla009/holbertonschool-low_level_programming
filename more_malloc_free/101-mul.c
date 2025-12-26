#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int trouver_longueur(char *str);
char *creer_tableau_x(int size);
char *ignorer_zero_initiaux(char *str);
void obtenir_produit(char *produit, char *mult, int digit, int zeroes);
void ajouter_nombres(char *produit_final, char *produit_suiv, int taille_suiv);

/**
 * trouver_longueur - Trouve la longueur d'une chaîne.
 * @str: la chaîne à mesurer
 *
 * Return: la longueur de la chaîne
 */
int trouver_longueur(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * creer_tableau_x - Crée un tableau de caractères initial'x'.
 * @size: taille du tableau
 *
 * Return: pointeur vers le tableau
 */
char *creer_tableau_x(int size)
{
	char *tab;
	int i;

	tab = malloc(sizeof(char) * size);
	if (tab == NULL)
		exit(98);

	for (i = 0; i < size - 1; i++)
		tab[i] = 'x';
	tab[i] = '\0';

	return (tab);
}

/**
 * ignorer_zero_initiaux - Avance dans la chaîne jusqu'au premier
 *  chiffre non nul
 * @str: chaîne de chiffres
 *
 * Return: pointeur sur le premier chiffre non nul
 */
char *ignorer_zero_initiaux(char *str)
{
	while (*str && *str == '0')
		str++;
	return (str);
}

/**
 * obtenir_chiffre - Convertit un caractère en chiffre
 * @c: caractère à convertir
 *
 * Return: chiffre correspondant
 */
int obtenir_chiffre(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}
	return (digit);
}

/**
 * obtenir_produit - Multiplie une chaîne de nombres par un chiffre
 * @produit: buffer pour le résultat
 * @mult: chaîne de nombres
 * @digit: chiffre unique
 * @zeroes: nombre de zéros initiaux
 */
void obtenir_produit(char *produit, char *mult, int digit, int zeroes)
{
	int len_mult, num, retenue = 0;

	len_mult = trouver_longueur(mult) - 1;
	mult += len_mult;

	while (*produit)
	{
		*produit = 'x';
		produit++;
	}
	produit--;

	while (zeroes--)
	{
		*produit = '0';
		produit--;
	}

	for (; len_mult >= 0; len_mult--, mult--, produit--)
	{
		if (*mult < '0' || *mult > '9')
		{
			printf("Error\n");
			exit(98);
		}
		num = (*mult - '0') * digit + retenue;
		*produit = (num % 10) + '0';
		retenue = num / 10;
	}

	if (retenue)
		*produit = (retenue % 10) + '0';
}

/**
 * ajouter_nombres - Additionne deux tableaux représentant des nombres
 * @produit_final: résultat cumulatif
 * @produit_suiv: prochain produit à ajouter
 * @taille_suiv: taille du prochain produit
 */
void ajouter_nombres(char *produit_final, char *produit_suiv, int taille_suiv)
{
	int num, retenue = 0;

	while (*(produit_final + 1))
		produit_final++;
	while (*(produit_suiv + 1))
		produit_suiv++;

	for (; *produit_final != 'x'; produit_final--)
	{
		num = (*produit_final - '0') + (*produit_suiv - '0') + retenue;
		*produit_final = (num % 10) + '0';
		retenue = num / 10;
		produit_suiv--;
		taille_suiv--;
	}

	for (; taille_suiv >= 0 && *produit_suiv != 'x'; taille_suiv--)
	{
		num = (*produit_suiv - '0') + retenue;
		*produit_final = (num % 10) + '0';
		retenue = num / 10;
		produit_final--;
		produit_suiv--;
	}

	if (retenue)
		*produit_final = (retenue % 10) + '0';
}

/**
 * main - Multiplie deux nombres positifs
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 *
 * Return: toujours 0
 */
int main(int argc, char *argv[])
{
	char *produit_final, *produit_suiv;
	int size, index, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = ignorer_zero_initiaux(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = ignorer_zero_initiaux(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = trouver_longueur(argv[1]) + trouver_longueur(argv[2]);
	produit_final = creer_tableau_x(size + 1);
	produit_suiv = creer_tableau_x(size + 1);

	for (index = trouver_longueur(argv[2]) - 1; index >= 0; index--)
	{
		digit = obtenir_chiffre(*(argv[2] + index));
		obtenir_produit(produit_suiv, argv[1], digit, zeroes++);
		ajouter_nombres(produit_final, produit_suiv, size - 1);
	}

	for (index = 0; produit_final[index]; index++)
	{
		if (produit_final[index] != 'x')
			putchar(produit_final[index]);
	}
	putchar('\n');

	free(produit_suiv);
	free(produit_final);

	return (0);
}
