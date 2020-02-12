/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:17:58 by ljonas            #+#    #+#             */
/*   Updated: 2019/12/05 14:18:05 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> /*forbbiden*/

typedef struct	s_ttpos
{
	int	x[4];
	int	y[4];
	int	num;
	char	simb;
	int	cord[2];
}		t_ttpos;

typedef struct	s_mas
{
	char	sq[15][15];
}		t_mas;

int		ft_checkttrmn(char **ttrmn);
int		ft_check1(char **ttrmn);
int		ft_check2(char **ttrmn);
int		ft_check3(char **ttrmn);
int		ft_gettrmn(char **ttrmn, t_list *head, int fd);
t_ttpos		*ft_newpos(char **ttrmn, char a);
void		ft_lstaddbackpos(t_list *head, t_ttpos *pos);
void		ft_printfsq(t_mas *mas, int s);
void 		ft_sq(t_mas *mas, int a);
void		ft_placettrm(t_list *head, int q);
int		ft_fullttrm(t_mas *mas, t_ttpos *tmppos, int s);
void		ft_clearch(t_mas *mas, char a);
int		ft_fullsq(t_mas *mas, t_list *head, int q, int s);
void		ft_search(int s, t_ttpos *tmppos);
int		ft_reshotka(t_mas *mas, t_ttpos *pos, int s);
void		ft_headfree(t_list *head);
int		ft_sqrt(int q);
int		ft_neighbours(char **ttrmn);
void		ft_clearallmas(t_mas *mas, t_list *head);
void		ft_sqinit(t_mas *mas);
void		ft_addttrmn(t_list *head, char **ttrmn, int q);
char		**ft_cleartt(char **ttrmn);
void		ft_checkposx(t_ttpos *pos);
void		ft_checkposy(t_ttpos *pos);

#endif
