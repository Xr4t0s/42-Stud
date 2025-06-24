#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	// Initialisation MLX
	mlx = mlx_init();
	if (!mlx)
	{
		fprintf(stderr, "❌ mlx_init() a échoué (problème de DISPLAY/X11 ?)\n");
		return (1);
	}

	// Création fenêtre (pas nécessaire pour charger une image mais utile pour afficher si ça marche)
	win = mlx_new_window(mlx, 300, 300, "Test XPM");
	if (!win)
	{
		fprintf(stderr, "❌ mlx_new_window() a échoué\n");
		return (1);
	}

	// Chargement de l’image
	img = mlx_xpm_file_to_image(mlx, "./test.xpm", &img_width, &img_height);
	if (!img)
	{
		fprintf(stderr, "❌ mlx_xpm_file_to_image() a échoué\n");
		fprintf(stderr, "   → Chemin invalide ? Mauvais DISPLAY ? .xpm corrompu ?\n");
		return (1);
	}
	else
	{
		printf("✅ Image chargée avec succès : %d x %d\n", img_width, img_height);
	}

	// Affichage image dans fenêtre
	mlx_put_image_to_window(mlx, win, img, 50, 50);

	// Boucle MLX
	mlx_loop(mlx);
	return (0);
}

