/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:20:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/03 11:01:00 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

# include "builtin.h"
# include "types.h"
# include "cmd.h"
# include "env.h"
# include "exe_utils.h"
# include "libft.h"
# include "mt.h"
# include "parse.h"
# include <readline/history.h>
# include <readline/readline.h>

// Verde
# define SUCCESS "\033[1;32m✅ Success: Function finished well!\n\033[0m"
// Rojo
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m"
// Amarillo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"

// Definiciones de colores ANSI como macros para Readline
# define BLACK_RL "\001\033[0;30m\002"
# define RED_RL "\001\033[0;31m\002"
# define GREEN_RL "\001\033[0;32m\002"
# define YELLOW_RL "\001\033[0;33m\002"
# define BLUE_RL "\001\033[0;34m\002"
# define PURPLE_RL "\001\033[0;35m\002"
# define CYAN_RL "\001\033[0;36m\002"
# define WHITE_RL "\001\033[0;37m\002"
# define RESET_RL "\001\033[0m\002"

# define BOLD_BLACK_RL    "\001\033[1;30m\002"
# define BOLD_RED_RL      "\001\033[1;31m\002"
# define BOLD_GREEN_RL    "\001\033[1;32m\002"
# define BOLD_YELLOW_RL   "\001\033[1;33m\002"
# define BOLD_BLUE_RL     "\001\033[1;34m\002"
# define BOLD_MAGENTA_RL  "\001\033[1;35m\002"
# define BOLD_CYAN_RL     "\001\033[1;36m\002"
# define BOLD_WHITE_RL    "\001\033[1;37m\002"

# define ORANGE_RL        "\001\033[38;5;208m\002"
# define WINE_RL          "\001\033[38;5;88m\002"
# define LIME_RL          "\001\033[38;5;190m\002"
# define TURQUOISE_RL     "\001\033[38;5;38m\002"
# define LIGHT_PINK_RL    "\001\033[38;5;13m\002"
# define DARK_GRAY_RL     "\001\033[38;5;235m\002"
# define LIGHT_RED_RL     "\001\033[38;5;203m\002"
# define LIGHT_BLUE_RL    "\001\033[38;5;75m\002"

# define BRIGHT_BLUE_RL   "\001\033[38;5;27m\002"
# define BRIGHT_GREEN_RL  "\001\033[38;5;46m\002"
# define BRIGHT_YELLOW_RL  "\001\033[38;5;226m\002"
# define BRIGHT_CYAN_RL   "\001\033[38;5;51m\002"
# define BRIGHT_WHITE_RL  "\001\033[38;5;231m\002"

#endif