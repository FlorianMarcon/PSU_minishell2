/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <sys/types.h>
#include <dirent.h>
#include "binary.h"

int	main()
{
	DIR *dir = opendir("./");
	hm_binary_list_all_file(dir);
	closedir(dir);
	return (0);
}
