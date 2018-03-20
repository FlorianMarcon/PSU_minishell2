/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "binary.h"
#include "hash_map.h"

Test(put_binary_in_hm, test1)
{
	hash_map_t *hm = generate_hash_map(12);
	int key;
	binary_t *bin;

	cr_assert_neq(hm, NULL);
	key = hm_get_key("test", hm);
	put_binary_in_hm(hm, "../here/", "test");
	bin = (binary_t *)(hm->hash_map[key]->data);
	cr_assert_neq(bin , NULL);
	cr_assert_str_eq(bin->cmd, "test");
	cr_assert_str_eq(bin->path, "../here/test");
}

Test(analyse_file, test1_success)
{
	hash_map_t *hm = generate_hash_map(12);
	int key;
	binary_t *bin;

	cr_assert_neq(hm, NULL);
	key = hm_get_key("ls", hm);
	analyse_file(hm, "/bin/", "ls");
	bin = (binary_t *)(hm->hash_map[key]->data);
	cr_assert_neq(bin , NULL);
	cr_assert_str_eq(bin->cmd, "ls");
	cr_assert_str_eq(bin->path, "/bin/ls");
}
Test(analyse_file, test1_failure)
{
	hash_map_t *hm = generate_hash_map(12);
	int key;

	cr_assert_neq(hm, NULL);
	key = hm_get_key("no_executable", hm);
	analyse_file(hm, "./data/", "no_executable");
	cr_assert_eq((hm->hash_map[key]), NULL);
}

Test(hm_binary_list_all_file, test1)
{
	DIR *dir = opendir("/bin/");
	hash_map_t *hm = generate_hash_map(1000);
	int key;

	cr_assert_neq(dir, NULL);
	cr_assert_neq(hm, NULL);
	key = hm_get_key("ls", hm);
	hm_binary_list_all_file(hm, dir, "/bin/");
	cr_assert_neq(hm->hash_map[key], NULL);
}
