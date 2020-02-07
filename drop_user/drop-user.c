#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  char *user = "snap_daemon";
  struct passwd *pwd = getpwnam(user);

  if (pwd == NULL) {
    printf("Could not find %s in pwd database.\n", user);
    exit(1);
  }
  if (setgroups(0, NULL) < 0) {
    printf("Failed to drop from groups.\n");
    exit(1);
  }

  if (setgid(pwd->pw_gid) < 0) {
    printf("Failed to set group id to %d.\n", pwd->pw_gid);
    exit(1);
  }

  if (setuid(pwd->pw_uid) < 0) {
    printf("Failed to set user id to %d.\n", pwd->pw_uid);
    exit(1);
  }

  printf("Running %s.\n", argv[1]);
  execve(argv[1], argv + 2, envp);
}
