#include<stdio.h>
int main(){
    //Simple leaky bucket algorithm
    int storage=0, no_of_ip,op_rate,buck_size,ip_size,size_left;
    printf("Enter the no of inputs :");
    scanf("%d" ,&no_of_ip);
    printf("Enter the Bucket size :");
    scanf("%d" ,&buck_size);
    size_left=buck_size;
    printf("Enter the output rate:");
    scanf("%d" ,&op_rate);
    while(no_of_ip!=0){
        printf("\nEnter the input size :");
        scanf("%d" ,&ip_size);
        if(ip_size<=size_left){
            storage+=ip_size;
        }
        else{
            printf("\nPacket loss %d",ip_size);
        }
        printf("\nBuffer size %d out of %d" ,storage,buck_size);
        printf("\nSending %d from storage = %d\nStorage now = %d" ,op_rate,storage,(storage-op_rate));
        storage-=op_rate;
        size_left=buck_size-storage;
        no_of_ip--;
    }
    return 0;
}