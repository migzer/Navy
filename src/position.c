/*
** position.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:07:28 2017 miguel joubert
** Last update Sun Feb 19 20:55:55 2017 Joubert Miguel
*/

#include "../include/my.h"

int	verify_length(char *buff)
{
  int	i;
  int	j;
  char	*stock;

  if (buff[28] != ':') return (1);
  if (buff[0] < '2' || *buff > '5') return (1);
  if ((stock = malloc(sizeof(char) * 6)) == NULL) return (1);
  j = i = 0;
  *stock = *buff;
  while (buff[i])
    if (buff[i++] == '\n')
      stock[++j] = buff[i];
  stock[++j] = 0;
  i = 0;
  j = 1;
  while (stock[i])
    {
      while (stock[j])
	if (stock[i] == stock[j++] || (stock[i] >= '5' && stock[i] <= '2'))
	  return (1);
      i++;
      j = i + 1;
    }
  return (0);
}

char	**is_touched(char **map, t_vector C)
{
  t_touch	T;

  T.k = T.j = T.i = 0;
  if ((T.dest = malloc(sizeof(char *) * 15)) == NULL)
    return (NULL);
  while (T.i != C.y)
    T.dest[T.j++] = my_strdup(map[T.i++]);
  if ((T.dest[T.j] = malloc(sizeof(char) * 22)) == NULL)
    return (NULL);
  while (map[T.i][T.k])
    {
      if (T.k == C.x)
	{
	  if (map[T.i][T.k] == '.')
	    return (NULL);
	  T.dest[T.j][T.k++] = 'x';
	}
      T.dest[T.j][T.k] = map[T.i][T.k], T.k++;
    }
  T.dest[T.j][T.k] = 0;
  while (map[++T.i])
    T.dest[++T.j] = my_strdup(map[T.i]);
  T.dest[T.j + 1] = NULL;
  return (T.dest);
}

char	**my_position_init(char **map, t_vector C, char c)
{
  char  **dest;
  int   i;
  int   j;
  int   k;

  k = j = i = 0;
  if ((dest = malloc(sizeof(char *) * 20)) == NULL) return (NULL);
  while (i != C.y)
    {
      dest[j] = my_strdup(map[i]);
      j++, i++;
    }
  if ((dest[j] = malloc(sizeof(char) * 22)) == NULL) return (NULL);
  while (map[i][k])
    {
      if (k == C.x) dest[j][k++] = c;
      dest[j][k] = map[i][k];
      k++;
    }
  dest[j][k] = 0;
  while (map[++i])
    dest[++j] = my_strdup(map[i]);
  dest[j + 1] = NULL;
  *dest[0] = ' ';
  return (dest);
}

char	**my_position(char *buff)
{
  char  **all_cases;
  char  **map;
  int   i;
  int   time;

  i = 0;
  time = -1;
  all_cases = ret_all_cases(buff);
  map = my_init_map();
  while (++time != 2)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 50);
  time = -1;
  while (++time != 3)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 51);
  time = -1;
  while (++time != 4)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 52);
  time = -1;
  while (++time != 5)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 53);
  return (map);
}
