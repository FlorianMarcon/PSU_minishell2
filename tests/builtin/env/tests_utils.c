/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_shell.h"
#include "hash_map.h"

Test(print_env_variable, test1)
{
	hm_object_t sec = {"PATH", (void *)"where", NULL};
	hm_object_t obj = {"PWD", (void *)"/home", &sec};

	cr_redirect_stdout();
	print_env_variable(&obj);
	cr_assert_stdout_eq_str("PWD=/home\nPATH=where\n");
}

Test(env, test1)
{
	hash_map_t *hm = generate_hash_map(12);
	char str[] = "/home";
	char str2[] = "where";

	hm_add_object(hm, "PWD", str);
	hm_add_object(hm, "PATH", str2);
	cr_redirect_stdout();
	env(hm);
	cr_assert_stdout_eq_str("PATH=where\nPWD=/home\n");
}
