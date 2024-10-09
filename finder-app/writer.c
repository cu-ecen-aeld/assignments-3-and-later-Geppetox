#include <stdio.h>
#include <stdbool.h>
#include <syslog.h>

int file_exists(const char *filename)
{
        FILE *fp = fopen(filename, "r");

        if(fp != NULL){
                fclose(fp);
                return 1;
        }
        return 0;
}

int main(int argc, char* argv[])
{
	openlog("Writer.C", 0, LOG_USER);

	if(argc > 3){
		printf("ERROR: Too many arguments!\n");

		//Log an error
                char logError[100];
                snprintf(logError, 100, "ERROR: Too many arguments!");
                syslog(LOG_ERR, "%s", logError);        
		return 1;
	} else if (argc < 3){
		printf("ERROR: Too few arguments!\n");

		//Log an error
                char logError[100];
                snprintf(logError, 100, "ERROR: Too few arguments!");
                syslog(LOG_ERR, "%s", logError);        
		return 1;
	}

	FILE *tempFile = fopen(argv[1], "a");
	fprintf(tempFile, "%s" ,argv[2]);
	fprintf(tempFile, "%s" , "\n");
	fclose(tempFile);

	//Log what we write
	char log1[100];
	snprintf(log1, 100, "Writing %s to %s\n", argv[2], argv[1]);
	syslog(LOG_DEBUG, "%s", log1);

        if(file_exists(argv[1]) == 0){
		printf("ERROR: Could not create file!");

		//Log an error
		char logError[100];
		snprintf(logError, 100, "ERROR: Could not write %s to %s\n", argv[2], argv[1]);
		syslog(LOG_ERR, "%s", logError);	
		return 1;
	}

	closelog();
	return 0;
}

