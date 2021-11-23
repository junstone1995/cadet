/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:54:56 by namhkim           #+#    #+#             */
/*   Updated: 2021/11/22 16:40:40 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	g_fd;
int	g_ret;
int	g_type;

int	is_cub_file(char const *conf_path)
{
	int	ret;
	int	len;

	ret = 1;
	len = ft_strlen(conf_path);
	if (len >= 4)
		ret = ft_strncmp(conf_path + len - 4, ".cub", 4);
	if (ret == 0)
		return (1);
	else
		return (0);
}

int	is_blank_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_map_component(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("012NSEW ", line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_type(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (C_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (C_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (C_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (C_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (C_EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (C_S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (C_F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C_C);
	else if (check_map_component(line))
		return (C_MAP);
	return (-1);
}

int	parse_config(t_game *game, t_config *config, char const *conf_path)
{
	int		cmd;
	char	*line;

	cmd = operate(conf_path);
	if (cmd == 23 || cmd == 24)
		return (exit_error(game, EXIT_FAILURE, "ERROR\nNOT .CUB EXTENSION\n"));
	g_ret = get_next_line(g_fd, &line);
	while (g_ret > 0)
	{
		g_type = check_type(line);
		if (is_blank_line(line) && !(config->map))
		{
			free(line);
			g_ret = get_next_line(g_fd, &line);
			continue ;
		}
		else if (is_blank_line(line) && config->map && g_ret)
			return (exit_error(game, EXIT_FAILURE, "blank line in the map"));
		if (!parse_by_type(g_ret, config, g_type, line))
			return (0);
		g_ret = get_next_line(g_fd, &line);
	}
	parseandclose(g_ret, config, g_type, line);
	return (1);
}
