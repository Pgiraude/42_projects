
#include "pipex.h"

int	no_heredoc(int argc, char **argv, t_data *data)
{
	data->file1 = open(argv[1], O_RDONLY);
	if (data->file1 < 0)
	{
		ft_printf("Error : cannot open %s\n", argv[1]);
		return (2);
	}
	data->file2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (3);
	}
	return (0);
}

int	open_file(int argc, char **argv, char **envp, t_data *data)
{
	if (check_arguments(argc, argv, 4) != 0)
		return (1);
	no_heredoc(argc, argv, data);
	if (get_command(argc, argv + 2, envp, data) != 0)
		return (2);
    return (0);
}