#include<stdio.h>
int main(){
   /** int incoming, outgoing,buck_size,n,store=0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d" ,&buck_size,&outgoing,&n);
    while(n!=0)
    {
        printf("Enter the incoming packet size :");
        scanf("%d" ,&incoming);
        printf("Incoming packet size %d\n" ,incoming);
        if(incoming <=(buck_size-store)){
            store +=incoming;
            printf("Bucket buffer size %d out of %d\n", store,buck_size);
        }
        else{
            printf("Dropped %d no of packets\n", incoming-(buck_size-store));
            printf("Bucket buffer size %d out of %d\n" ,store,buck_size);
            store=buck_size;
        }
        store=store-outgoing;
        printf("After outgoing %d packets left out of %d in buffer\n" ,store,buck_size);
        n--;
    }*/

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