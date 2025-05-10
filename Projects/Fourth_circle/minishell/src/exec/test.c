// int execute_commands(t_data *data)
// {
//     t_cmd   *tmp;
//     pid_t   pid;
//     char    *joined = NULL;
//     int     fd[2];
//     int     status_code;
//     int     i;

//     // First pass: Create all pipes
//     tmp = data->cmd;
//     while (tmp)
//     {
//         if (tmp->pipe && (tmp->type != R_APPEND && tmp->type != R_OUT))
//         {
//             if (!tmp->exec)
//             {
//                 tmp = tmp->next;
//                 continue;
//             }
//             if (pipe(fd) == -1)
//                 return (perror("pipe"), 1);
//             tmp->output_fd = fd[1];
//             if (tmp->next && tmp->next->input_fd == -1)
//                 tmp->next->input_fd = fd[0];
//         }
//         tmp = tmp->next;
//     }

//     // Second pass: Execute commands
//     tmp = data->cmd;
//     while (tmp)
//     {
//         if (!tmp->exec)
//         {
//             tmp = tmp->next;
//             continue;
//         }
        
//         // Handle builtins in parent process
//         if (is_builtin(tmp->bin[0]) == 1)
//         {
//             // Close pipe FDs before executing builtin
//             if (tmp->input_fd > 2)
//                 close(tmp->input_fd);
//             if (tmp->output_fd > 2)
//                 close(tmp->output_fd);
//             data->envp = exec_env_builtin(tmp->bin, data->envp);
//             tmp = tmp->next;
//             continue;
//         }

//         pid = fork();
//         if (pid == -1)
//             return (perror("fork"), 1);
//         else if (pid == 0)
//         {
//             // Child process: Set up redirections
//             if (tmp->input_fd != -1 && tmp->input_fd != STDIN_FILENO)
//             {
//                 dup2(tmp->input_fd, STDIN_FILENO);
//                 close(tmp->input_fd);
//             }
//             if (tmp->output_fd != -1 && tmp->output_fd != STDOUT_FILENO)
//             {
//                 dup2(tmp->output_fd, STDOUT_FILENO);
//                 close(tmp->output_fd);
//             }

//             // Close all pipe FDs that aren't needed
//             t_cmd *close_tmp = data->cmd;
//             while (close_tmp)
//             {
//                 if (close_tmp->input_fd > 2 && close_tmp->input_fd != tmp->input_fd)
//                     close(close_tmp->input_fd);
//                 if (close_tmp->output_fd > 2 && close_tmp->output_fd != tmp->output_fd)
//                     close(close_tmp->output_fd);
//                 close_tmp = close_tmp->next;
//             }

//             // Execute command
//             i = 0;
//             while (tmp->bin[i] && !tmp->bin[i][0])
//                 i++;
//             joined = find_path(data->envp, tmp->bin[i]);
//             if (is_builtin(tmp->bin[0]))
//             {
//                 free(joined);
//                 if (is_builtin(tmp->bin[0]) == 1)
//                     data->envp = exec_env_builtin(tmp->bin, data->envp);
//                 else if (is_builtin(tmp->bin[0]) == 2)
//                     exec_void_builtin(tmp->bin, data->envp);
//                 exit(0);
//             }
//             else
//             {
//                 execve(joined, &tmp->bin[i], data->envp);
//                 free(joined);
//                 perror("Command not found");
//                 exit(127);
//             }
//         }
//         else
//         {
//             // Parent process: Close pipe FDs that aren't needed anymore
//             free(joined);
// 			if (tmp->input_fd != -1 && tmp->input_fd != STDIN_FILENO)
// 				close(tmp->input_fd);
// 			if (tmp->output_fd != -1 && tmp->output_fd != STDOUT_FILENO)
// 				close(tmp->output_fd);
//         }
//         tmp = tmp->next;
//     }

//     // Wait for all child processes
//     tmp = data->cmd;
//     while (tmp)
//     {
//         if (tmp->exec && !is_builtin(tmp->bin[0]))
//         {
//             wait(&status_code);
//             status_code = status_code % 127;
//         }
//         tmp = tmp->next;
//     }
//     return (status_code);
// }
