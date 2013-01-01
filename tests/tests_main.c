#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "tests.h"

int pipefd[2];
int len; // shared declaration ensures sizeof matches

int passed = 0;
int tested = 0;

pid_t kidpid;

void wait_attach ( void )
{
  printf("PID %d ready for attach\n", getpid());
  fflush(stdout);
  while(1); // increment instruction pointer to continue
}

void send_message ( char * message )
{
  len = strlen(message);
  close(pipefd[0]);
  write(pipefd[1], &len, sizeof(len));
  write(pipefd[1], message, len);
  close(pipefd[1]);
}

char * recv_message ( void )
{
  char * message;
  if ( read ( pipefd[0], &len, sizeof(len) ) == sizeof(len) )
  {
    int i = 0, bytes_read;
    message = malloc((sizeof*message)*(len+1));
    while ( 0 < (bytes_read = read ( pipefd[0], message+i, len-i )) )
    {
      i += bytes_read;
    }
    message[i] = '\0';

    if ( len != i )
    {
      printf("read %d bytes while expecting %d\n", i, len);
    }
  }

  return message;
}

void test_succeeded ( void )
{
  // send_message ( "Succeeded." );
}

void test_failed ( char * message )
{
  send_message ( message );
  exit(1);
}

int execute_test ( char * test_name, void(*test_func)(void) )
{
  if ( 0 != pipe(pipefd) )
  {
    fprintf(stderr, "Failed to open pipe for %s\n", test_name);
    exit(1);
  }

  kidpid = fork();

  if ( 0 == kidpid )
  {
    (*test_func)();
    return 0;
  }
  else
  {
    char * message = NULL;
    int kid_status;

    tested ++;

    waitpid(kidpid, &kid_status, 0);

    if ( WIFEXITED ( kid_status ) && WEXITSTATUS ( kid_status ) != 0 )
    {
      printf("Test %s (%d): ", test_name, kidpid);

      if ( WIFEXITED ( kid_status ) )
      {
        char * message = recv_message ( );
        printf("'%s'\n", message);
        free ( message );
        printf("  exited with status %d\n", WEXITSTATUS ( kid_status ) );
      }
    }
    else if ( WIFSIGNALED ( kid_status ) )
    {
      printf("Test %s (%d): ", test_name, kidpid);
      printf("terminated by signal %d"
#ifdef WCOREDUMP
          WCOREDUMP ( kid_status ) ? "; core dumped" : "; no core"
#endif // WCOREDUMP
          "\n", WTERMSIG ( kid_status ) );
    }
    else
    {
      passed ++;
    }

    return 1;
  }
}

int main ( void )
{
  printf ( "Parent PID: %d\n", getpid() );
  do_tests ();

  if ( kidpid ) 
  {
    printf("%d/%d assertions held (%0.2f%%)\n", passed, tested, passed*(100./tested));

    if ( passed < tested ) return 1;
  }
}

