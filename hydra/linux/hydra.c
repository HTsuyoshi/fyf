#include <gtk/gtk.h>

#include <hydra.h>

int
main (int	argc,
	char	**argv)
{
	return g_application_run(G_APPLICATION (spawn_hydra ()), argc, argv);
}