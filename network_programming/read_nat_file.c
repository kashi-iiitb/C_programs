#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define NAT_TABLE_SIZE 3

struct nat_entry{
    struct in_addr input_addr;
    struct in_addr output_addr;
};

struct nat_entry nat_table[NAT_TABLE_SIZE];

//write a function - takes private IP address as argument
//and return public IP which will be used while sending the packet out
struct in_addr *nat_map(struct in_addr *pri_addr){
    for(int i=0; i<NAT_TABLE_SIZE; i++){
        if(nat_table[i].input_addr.s_addr == pri_addr->s_addr)
            return &nat_table[i].output_addr;        
    }
    return NULL;
}

int main(){
    char in[16], out[16];
    struct in_addr i_addr, o_addr;

    FILE *fp = fopen("nat.txt","r");
    if(!fp){
        printf("Error opening the input file.\n");
        return -1;
    }
    int i=0;
    while(fscanf(fp,"%s -> %s", in, out) != EOF){
        //printf("in address = %s\tout address = %s\n", in, out);
        inet_pton(AF_INET, in, &i_addr);
        inet_pton(AF_INET, out, &o_addr);
        nat_table[i].input_addr = i_addr;
        nat_table[i].output_addr = o_addr;
        i++;
    }
    for(int j=0; j<NAT_TABLE_SIZE; j++){
        printf("private address=%x\tpublic address=%x\n",
                nat_table[j].input_addr.s_addr, nat_table[j].output_addr.s_addr);
    }
    printf("Searching the NAT table\n");
    char *t_addr[3] = {"192.168.0.1", "10.1.1.1", "192.168.0.3"};
    struct in_addr *pub_addr = NULL, priv_addr;
    char pub_addr_str[16];

    for (int i=0; i<3; i++){
        inet_pton(AF_INET, t_addr[i], &priv_addr);
        pub_addr = nat_map(&priv_addr);
        if(pub_addr){        
            printf("private address = %s\t public address = %s\n",
                    t_addr[i], inet_ntop(AF_INET, pub_addr, pub_addr_str,
                    sizeof(pub_addr_str)));
        } else{
            printf("private address = %s is not present in nat table\n",
                    t_addr[i]);
        }
    }
}