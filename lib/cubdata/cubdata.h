/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:27 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/13 11:58:27 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBDATA_H
# define CUBDATA_H

typedef struct s_cubdata	t_cubdata;
/*
Returns a pointer to a cubdata structure made from FILENAME.
*/
t_cubdata	*cubdata_extract(char *filename);
void		cubdata_print(t_cubdata *cubdata);
void		cubdata_free(t_cubdata *cubdata);

#endif