/* Command structure */
#define COMMAND_MAX_LEN 50
typedef struct command_s {
	char    cmd_name[COMMAND_MAX_LEN];
	int     required_params;
	int     threaded;
	void    *(*cmd_handler)(void *);
} command_t;

/* Command handlers prototypes
 * */
void *cmd_submit_job(void *args);
void *cmd_cancel_job(void *args);
void *cmd_status_job(void *args);
void *cmd_quit(void *args);
void *cmd_version(void *args);
void *cmd_commands(void *args);
void *cmd_async_on(void *args);
void *cmd_async_off(void *args);
void *cmd_results(void *args);

/* Function prototypes
 * */
command_t *find_command(const char *cmd);
char *known_commands(void);
int parse_command(const char *cmd, int *argc, char ***argv);
