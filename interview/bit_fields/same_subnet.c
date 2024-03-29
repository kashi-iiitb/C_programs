#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    __uint32_t address;
}addr_t;

typedef struct {
    addr_t network_id;
    addr_t subnet_mask;
}subnet_t;

void convert_to_addr_t(addr_t *addr, __uint8_t *a1,
                    __uint8_t *a2, __uint8_t *a3, __uint8_t *a4){
    __uint32_t temp_address = 0;
    temp_address |= ((__uint32_t)*a1 << 24);
    temp_address |= ((__uint32_t)*a2 << 16);
    temp_address |= ((__uint32_t)*a3 << 8);
    temp_address |= (__uint32_t)*a4;
    //addr->address = temp_address;
    memcpy(&addr->address, &temp_address, sizeof(__uint32_t));
}

void convert_to_subnet_t(subnet_t *subnet, addr_t *addr1,
                    __uint8_t *sub_mask){
    __uint32_t subnet_mask=0;
    __uint32_t network_id=0;
    for(int i=31; i>(31-*sub_mask); i--){
        subnet_mask |= 1<<i;
    }
    printf("subnet mask = %x\n", subnet_mask);
    network_id = addr1->address & subnet_mask;
    printf("network id = %x\n", network_id);
    subnet->network_id.address = network_id;
    subnet->subnet_mask.address = subnet_mask;
}
bool ip_belongs_to_subnet(addr_t *addr, subnet_t *subnet){
    if((addr->address & subnet->subnet_mask.address) == 
        subnet->network_id.address) {
            return true;
    } else {
        return false;
    }        
}
int main(){
    addr_t addr1, addr2, addr3, subnet_mask1, subnet_mask2;
    subnet_t subnet_1, subnet_2;
    __uint8_t a1=0, a2=0, a3=0, a4=0;
    __uint8_t sub_mask=0;
    sscanf("192.168.0.1/16", "%hhu.%hhu.%hhu.%hhu/%hhu", &a1, &a2, &a3, &a4, &sub_mask);
    convert_to_addr_t(&addr1, &a1, &a2, &a3, &a4);
    convert_to_subnet_t(&subnet_1, &addr1, &sub_mask);

    sscanf("192.168.10.1/16", "%hhu.%hhu.%hhu.%hhu/%hhu", &a1, &a2, &a3, &a4, &sub_mask);
    //printf("a1=%hhu a2=%hhu a3=%hhu a4=%hhu sub_mask=%hhu\n", a1, a2, a3, a4, sub_mask);
    convert_to_addr_t(&addr2, &a1, &a2, &a3, &a4);
    convert_to_subnet_t(&subnet_2, &addr2, &sub_mask);

    printf("address1 = %0x\n", addr1.address);
    printf("address2 = %0x\n", addr2.address);

    if(ip_belongs_to_subnet(&addr1, &subnet_1)){
        printf("address=%x belongs to subnet1\n", addr1.address);
    } else
        printf("address=%x doesn't belong to subnet1\n", addr1.address);
    
    if(ip_belongs_to_subnet(&addr2, &subnet_1)){
        printf("address=%x belongs to subnet1\n", addr2.address);
    } else
        printf("address=%x doesn't belong to subnet1\n", addr2.address);

    sscanf("192.167.0.1/16", "%hhu.%hhu.%hhu.%hhu/%hhu", &a1, &a2, &a3, &a4, &sub_mask);
    convert_to_addr_t(&addr3, &a1, &a2, &a3, &a4);
    
    if(ip_belongs_to_subnet(&addr3, &subnet_1)){
        printf("address=%x belongs to subnet1\n", addr3.address);
    } else
        printf("address=%x doesn't belong to subnet1\n", addr3.address);
}