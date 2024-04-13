#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
  // Open the file
  FILE *fp = fopen("test_delete_ip_port.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read a line from the file
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    // Parse the IP address and port number
    char *ip_address = strtok(line, ":");
    char *port_number = strtok(NULL, ":");

    // Convert the IP address and port number to integers
    unsigned int ip_address_int = inet_addr(ip_address);
    int port_number_int = atoi(port_number);

    // Print the IP address and port number
    printf("%x:%d\n", ip_address_int, port_number_int);
  }

  // Close the file
  fclose(fp);

  return 0;
}