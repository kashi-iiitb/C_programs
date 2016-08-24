#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define MAX_ROWS 6 
//typedef struct Address address;

struct Address
{
  int id;
  int set;
  char name[MAX_SIZE];
  char email[MAX_SIZE];
};

struct Database
{
  struct Address entries[MAX_ROWS];
};

struct Connection
{
  FILE *file;
  struct Database *db;
};

int Address_print(struct Address *addr)
{
  printf("%d %s %s\n",addr->id,addr->name,addr->email);
}

int die(char *message)
{
  if(errno)
	perror(message);
  else
	printf("ERROR:%s\n",message);
}

Database_load(struct Connection *conn)
{
  int rc = fread(conn->db,sizeof(struct Database),1,conn->file);
  if(rc!=1)
	die("Failed to load Database!");
}

struct Connection * Database_open(const char *filename,char mode)
{
  int i=0;
  struct Connection *conn = malloc(sizeof(struct Connection));
  if(!conn)
	die("Memory error!");
  conn->db = malloc(sizeof(struct Database));
  if(!conn->db)
	die("Memory error!");

  if(mode == 'c')
  	conn->file = fopen(filename,"w");
  else
  {
  	conn->file = fopen(filename,"r+");
  	if(conn->file)
		Database_load(conn);
  }
  if(!conn->file)
  	die("Failed to open the file");
  return conn;
  //rc = 
}

void Database_create(struct Connection *conn)
{
  int i=0;
  for(i=0; i<MAX_ROWS; i++)
  {
	struct Address addr = {.id = i, .set=0};
	conn->db->entries[i] = addr;
  }
}

void Database_write(struct Connection *conn)
{
  rewind(conn->file);
  int rc=0;
  rc = fwrite(conn->db,sizeof(struct Database),1,conn->file);
  if(rc != 1)
	die("Database write failed!");
  rc = fflush(conn->file);
  if(rc == -1)
	die("Can't flush database!");

}

void Database_set(struct Connection *conn, int id,const char* name,const char* email)
{
  struct Address *addr = &conn->db->entries[id];
  addr->set = 1;
  addr->id = id;
  int l=0;
  char *res = strncpy(addr->name, name,MAX_SIZE);
  l = strlen(addr->name);
  addr->name[l]='\0';
  if(!res)
	die("Name copy failed!");
  res = strncpy(addr->email, email,MAX_SIZE);
  l = strlen(addr->email);
  addr->email[l]='\0';
  if(!res)
	die("Email copy failed!");
}

void Database_get(struct Connection *conn,int id)
{
  struct Address *addr = &conn->db->entries[id];
  if(addr->set)
	Address_print(addr);
  else
	die("ID not set!");
}

void Database_delete(struct Connection *conn,int id)
{
  conn->db->entries[id].set = 0;
}

void Database_list(struct Connection *conn)
{
  int i=0;
  struct Address *addr;
  struct Database *db = conn->db;
  for(i=0; i<MAX_ROWS; i++)
  {
	addr = &db->entries[i];
	if(addr->set)
		Address_print(addr);
  }
}

void find(struct Connection *conn,char *name)
{
  int i=0;
  //struct Address *addr;
  //struct Database *db = conn->db;
  for(i=0; i<MAX_ROWS; i++)
  {
	if(conn->db->entries[i].set==1)
	if(!strcmp(conn->db->entries[i].name,name))
	{
		printf("Record found!\n");
		Address_print(&conn->db->entries[i]);
		break;
	}
	/*addr = &db->entries[i];
	if(addr->set)
		Address_print(addr);*/
  }
	if(i==MAX_ROWS)
		printf("Record not found!\n");
}

Database_close(struct Connection *conn)
{
  fclose(conn->file);
  free(conn->db);
  free(conn);
}			
int main(int argc, char *argv[])
{
  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename,action);
  int id=0;
  if(argc > 3)
	id = atoi(argv[3]);
  if(id >= MAX_ROWS)
	die("Database is full, can't accept more records\n");

  switch(action)
  {
	case 'c':
			Database_create(conn);	
			Database_write(conn);	
			break;
	case 'g':
			if(argc!=4)
				die("Need an id to get");
			Database_get(conn,id);
			break;
	case 's':
			if(argc!=6)
				die("Need an id,name,email to set");
			Database_set(conn,id,argv[4],argv[5]);
			Database_write(conn);
			break;
	case 'd':
			if(argc!=4)
				die("Need an id to delete");
			Database_delete(conn,id);
			Database_write(conn);
			
			break;
	case 'l':
			Database_list(conn);
			break;
	case 'f':
			if(argc!=5)
				die("Need a name to find");
			find(conn,argv[4]);
			break;

	default:
			printf("Enter proper choice!!");
			die("Enter proper choice");
//			break;
  }
  Database_close(conn);
return 0;
}
