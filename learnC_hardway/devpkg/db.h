#ifndef _db_h
#define _db_h

#define DB_FILE "/home/kashi/git/C/learnC_hardway/devpkg/.devpkg/db"
#define DB_DIR "/home/kashi/git/C/learnC_hardway/devpkg/.devpkg"


int DB_init();
int DB_list();
int DB_update(const char *url);
int DB_find(const char *url);

#endif
