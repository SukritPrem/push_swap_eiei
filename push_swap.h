#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// #include "Libft_tt/libft.h"
#include <stdlib.h>
#include "Libft/libft.h"
#include <stdio.h>

#define false 0;
#define true 1;

typedef struct s_check_error_num
{
  int number;
  int check_error;
  int i;
} t_check_error_num;

typedef struct s_list_double_char
{
  char			**content;
	struct s_list_double_char	*next;
} t_list_double_char;

typedef struct s_check_error
{
  int count_number;
} t_check_error;

typedef struct s_list_int
{
  int   num;
	struct s_list_int	*next;
} t_list_int;

typedef struct s_list_p{
  int   index;
  int   data;
  struct s_list_p  *next;
} t_list_p;

typedef struct s_main{
  struct s_list_p *head;
  struct s_list_p *current;
  struct s_list_p *end;
} t_main;

void bubblesort(int arr[], int n);
int	ft_atoi_pushswap(const char *str,int *check_error);

void  sort_3(t_main **stack_A_main);
//operation
void pb(t_main **stack_A_main,t_main **stack_B_main);
void ra(t_main **stack_A_main);
void pa(t_main **stack_A_main,t_main **stack_B_main);
void  rra(t_main **stack_A_main);
void  sa(t_main **stack_A_main);
//operation1
void  sb(t_main **stack_A_main);
void  rb(t_main **stack_B_main);
//utils
t_main  *ft_init(t_list_int *tmp_int_main);
t_list_p *init(int num);
int	len_list(t_list_p *head_main);
int	max_in_list(t_list_p *head);
void	set_index(t_main **stack_A_main);
//utils1
void	send_b_to_a(t_main **stack_B_main, t_main **stack_A_main);
int check_sort(t_main **stack_A_main);
size_t	size_list_num(t_list_int *head);
size_t	size_array(t_list_p *head);
int	*create_arr_in_list(t_main **stack_A_main, size_t num);
//utils_operation
void	utils_pb(t_main **stack_a_main, t_main **stack_b_main);
//radix_sort
void radix_sort(t_main **stack_A_main,t_main **stack_B_main);
//simple_sort
void	find_top_and_send_pb(t_main **stack_A_main, t_main **stack_B_main);
void  find_bottom_and_send_pb(t_main **stack_A_main,t_main **stack_B_main);
void  find_rb_and_send_pb(t_main **stack_A_main,t_main **stack_B_main);
void  find_top_rb_and_send_pa(t_main **stack_A_main,t_main **stack_B_main);
void  simple_sort(t_main **stack_A_main,t_main **stack_B_main);
//utils_simple_sort
void  check_sort_for_sa(t_main **stack_A_main);
void  command_rra_and_pb(t_main **stack_A_main,t_main **stack_B_main);
void  check_sort_for_sb_and_papa(t_main **stack_A_main,t_main **stack_B_main);
//check_error_char
void	check_error_char(char **argv, int argc);
void	check_arg(char **argv, int i, int j, t_check_error *check);
void	exit_error(void);
int check_it_seem(t_list_int  *list_num);
int check_sort_num(t_list_int *list_num);
//free_list
void  free_list_double_char(t_list_double_char  **list_main);
void  free_list_num(t_list_int **list_num_main);
void  free_stack(t_main **stack_A_main,t_main **stack_B_main);
//init_arg
t_list_double_char	*init_char(char **argv, int i);
int create_list_char(char **argv,int i,t_list_double_char **list_main);
t_list_double_char	*create_list_from_input(char *argv[]);
t_list_int	*init_list_num(char *content);
int	create_list(char *content, t_list_int **list_num_main);
//init_arg1
t_list_int	*create_list_num_from_list(t_list_double_char *list);
#endif
