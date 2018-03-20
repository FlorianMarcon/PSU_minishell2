/*
** EPITECH PROJECT, 2017
** put_binary_in_hm
** File description:
** put_binary_in_hm
*/

#include "binary.h"
#include "hash_map.h"

void	put_binary_in_hm(hash_map_t *hm, char *path, char *cmd)
{
	binary_t *bin = malloc(sizeof(*bin));

	if (bin == NULL)
		return;
	if ((bin->cmd = my_strdup(cmd)) == NULL) {
		free(bin);
		return;
	} else if ((bin->path = my_strcat(path, cmd)) == NULL) {
		free(bin->cmd);
		free(bin);
		return;
	} else {
		hm_add_object(hm, cmd, bin);
	}
}
