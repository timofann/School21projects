/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_message.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:01:06 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 19:01:08 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PUT_MESSAGE_H
# define FDF_PUT_MESSAGE_H

# define WAIT_MESSAGE "Wait until all data will be loaded...\
\n(this might take a while)"
# define METADATA_LOADED "Now we are ready to get the map of the model..."
# define SUCCESSFUL_PARSING "Successful reading!\
\nStart building wireframe model..."

# include <stdlib.h>
# include <unistd.h>

size_t	str_len(char *str);
void	put_message(char *str);

#endif
