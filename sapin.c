#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	total_width(int size) // size = nb de bloc | nombre rentré s la fonction
{
  int line = 4; // ça commence à 4lignes
  int i; //compteur de line         SUr schéma
  int nbr_star = 1; // commence à 1
  int offset = 2; //nombre d'étoile perdues entre deux blocs
  int n = 0; //nombre de bloc à créer

 
  while (n < size) // on part bloc du haut
  {
    i = 0;
    while (i < line) // chaque nouvelle ligne prend 2 étoiles supp
	    {
	      nbr_star = nbr_star + 2;
	      i++;
	    }
    line++; // on augmente d'une ligne a chaque bloc
      
    if (n % 2 == 0)
    /* permet de determiner si le nombre de bloc est pair (alors on perd 2 étoiles en plus à chaque nouveau bloc apres le bloc pair)
     */
      {
        offset = offset + 2;
      }
    nbr_star = nbr_star - offset;
  
    n++;
  }
  return (nbr_star + offset -2); // on veut le nb d'étoile de la base

}
 
void    mon_sapin(int size)	
{
  int line = 4;
  int width = total_width(size);// largeur
  int nbr_space = width / 2;
  int space = 0;
  int cpt_space;
  int offset = 2;
  int n = 0; //compteur nombre de bloc
  int i;
  int nbr_star = 1;
  int j; //compteur des étoiles

  while (n < size) // nb de bloc
    {
      if (n % 2 == 0 && n != 0) // si bloc est paire et diff de zero , nb detoile perdues
	    {
	      offset = offset + 2;
	    }
       
      i = 0;
      while(i < line)
	    {
	      /* on trouve le nb d'espaces ds le 1er bloc grace a la base du dernier bloc */
	  
	      space = nbr_space - nbr_star / 2; //car on ne compte que les espaces de gauche donc que la partie gauche du sapin

	      cpt_space = 0; // initialise
	      while (cpt_space < space)
	      {
	        my_putchar(' ');
	        cpt_space++;
	      }
	      j = 0;
	      while (j < nbr_star) // compteur pr le nb d'étoile a mettre
	      {
	        my_putchar('*');
	        j++;
	      }
	      my_putchar('\n');
	        // on verifie si on est à la derniere ligne avant le prochain bloc
	      if (i == line - 1) // car on commence a line =0 et que on en a 4 donc pr aller a line = 3 on fait -1
	      nbr_star = nbr_star - offset; // on retire le off set ( 2 ou 4 stars)
	      else
	      nbr_star = nbr_star + 2;
	      i++;
	    }
      
      line++; // chaque new bloc a une ligne de plus
      n++;
    }
}

  
 void	 tronc_sapin(int size)
 {
   int nbr_space;
   int width = size; //largeur tronc
   int height = size; //hauteur tronc
   int i = 0; // compteur hauteur
   int j = 0; // compteur largeur tronc
   int l = 0; // compteur espace

   if (size % 2 == 0) // on check si on a un bloc pair ou impair 
     {
       width = size + 1; // on fait un tronc impair pr centrer
     }
  
   nbr_space = total_width(size) / 2 - (width / 2); // largeur base moins largeur tronc/2

   while (i < height)
     {
       i++;
       l = 0;
       while (l < nbr_space) // définit au dessus
	      {
	        my_putchar(' ');
	        l++;
	      }
       j = 0;
       while(j < width) // size = width
	      {
	        my_putchar('|');
	        j++;
	      }
       my_putchar('\n');
     }
 }




  int	main(int argc, char **argv)
{
   if (argc != 2)
   {
     write(1,"ERROR.\n",7);
     return(1);
   }
   
      int size;
      size = atoi(argv[1]);
       
       mon_sapin(size);
       tronc_sapin(size);
  return 0;
}
