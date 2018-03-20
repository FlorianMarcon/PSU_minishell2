/*
** EPITECH PROJECT, 2017
** generate_hash_map
** File description:
** generate_hash_map
*/

#include <criterion/criterion.h>
#include "hash_map.h"

hash_map_t	*generate_hash_map(int size)
{
	hash_map_t *hm;

	if (size <= 0 || (hm = malloc(sizeof(*hm))) == NULL)
		return (NULL);
	hm->hash_map = malloc(sizeof(*(hm->hash_map)) * (size + 1));
	if (hm->hash_map == NULL) {
		free(hm);
		return (NULL);
	}
	hm->size = size;
	return (hm);
}
