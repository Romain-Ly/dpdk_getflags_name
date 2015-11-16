
#include "getflags_name.h"


/* print binary from hex */
void 
print_binary(uint32_t n){
  int count = 0;
  while (n) {
    if (n & 1)
      printf("1");
    else
      printf("0");
    n >>= 1;
    
    count++;
    if ((count%8)==0){
      printf(" ");
    }
  }
  printf("\n");
}

/************* txq flags *****************/
/* eth config tx flags */
const char *
get_eth_txq_flags(uint32_t mask){
  switch(mask){
  case ETH_TXQ_FLAGS_NOMULTSEGS: return "ETH_TXQ_FLAGS_NOMULTSEGS";/*0x0001 < nb_segs=1 for all mbufs */
  case ETH_TXQ_FLAGS_NOREFCOUNT: return "ETH_TXQ_FLAGS_NOREFCOUNT";/*0x0002 < refcnt can be ignored */
  case ETH_TXQ_FLAGS_NOMULTMEMP: return "ETH_TXQ_FLAGS_NOMULTMEMP";/*0x0004 < all bufs come from same mempool */
  case ETH_TXQ_FLAGS_NOVLANOFFL: return "ETH_TXQ_FLAGS_NOVLANOFF";/*0x0100 < disable VLAN offload */
  case ETH_TXQ_FLAGS_NOXSUMSCTP: return "ETH_TXQ_FLAGS_NOXSUMSCTP";/*0x0200 < disable SCTP checksum offload */
  case ETH_TXQ_FLAGS_NOXSUMUDP : return "ETH_TXQ_FLAGS_NOXSUMUDP";/*0x0400 < disable UDP checksum offload */
  case ETH_TXQ_FLAGS_NOXSUMTCP : return "ETH_TXQ_FLAGS_NOXSUMTC";/*0x0800 < disable TCP checksum offload */
  case ETH_TXQ_FLAGS_NOOFFLOADS: return "ETH_TXQ_FLAGS_NOOFFLOADS";/*(ETH_TXQ_FLAGS_NOVLANOFFL | ETH_TXQ_FLAGS_NOXSUMSCTP | ETH_TXQ_FLAGS_NOXSUMUDP  | ETH_TXQ_FLAGS_NOXSUMTCP) */
  case ETH_TXQ_FLAGS_NOXSUMS  :  return "ETH_TXQ_FLAGS_NOXSUMS";/*(ETH_TXQ_FLAGS_NOXSUMSCTP | ETH_TXQ_FLAGS_NOXSUMUDP | ETH_TXQ_FLAGS_NOXSUMTCP) */
  default: return NULL;
  }
}

/* create a mask and get flagname if bit is set 
 */
void 
get_txq_flags_mask(uint32_t mask){

 uint32_t bitmask = 0;
 uint16_t count = 1;

 for ( int i = 0 ; i < 32 ; i++) {
   bitmask = 1 << i;
   
   /*printf("bitmask : "); 
    *   print_binary(bitmask); 
    *   print_binary(mask&bitmask); 
    */
   
   const char* text ;
   text = get_eth_txq_flags(mask & bitmask);
   if (text !=NULL){
     printf("%s ",text);
     count ++;
     printf("\n");
   }

  
 }
}

/************* tx offload flags *****************/
/* eth config tx offload flags */
const char *
get_eth_tx_offload_flags(uint32_t flags){
  switch(flags){
  case DEV_TX_OFFLOAD_VLAN_INSERT: return "DEV_TX_OFFLOAD_VLAN_INSERT"; /*  0x00000001 */
  case DEV_TX_OFFLOAD_IPV4_CKSUM: return "DEV_TX_OFFLOAD_IPV4_CKSUM"; /*  0x00000002*/
  case DEV_TX_OFFLOAD_UDP_CKSUM: return "DEV_TX_OFFLOAD_UDP_CKSUM"; /*   0x00000004*/
  case DEV_TX_OFFLOAD_TCP_CKSUM: return "DEV_TX_OFFLOAD_TCP_CKSUM"; /* 0x00000008*/
  case DEV_TX_OFFLOAD_SCTP_CKSUM: return "DEV_TX_OFFLOAD_SCTP_CKSUM"; /* 0x00000010*/
  case DEV_TX_OFFLOAD_TCP_TSO: return "DEV_TX_OFFLOAD_TCP_TSO";   /* 0x00000020*/
  case DEV_TX_OFFLOAD_UDP_TSO: return "DEV_TX_OFFLOAD_UDP_TSO";    /*0x00000040*/
  case DEV_TX_OFFLOAD_OUTER_IPV4_CKSUM: return "DEV_TX_OFFLOAD_OUTER_IPV4_CKSUM"; /*0x00000080 */
  default: return NULL;
  }
}

/* create a mask and get flagname if bit is set 
 */
void 
get_tx_offload_flags_mask(uint32_t flags){

 uint32_t bitmask = 0;
 uint16_t count = 1;

 for ( int i = 0 ; i < 32 ; i++) {
   bitmask = 1 << i;
   
   const char* text = NULL;
   text = get_eth_tx_offload_flags(flags & bitmask);
   if (text !=NULL){
     printf("%s ",text);
     count ++;
     printf("\n");
     
   }
 }//endfor
}


/************* rx offload flags *****************/
/* eth config tx offload flags */

const char *
get_eth_rx_offload_flags(uint32_t flags){
  switch(flags){
  case DEV_RX_OFFLOAD_VLAN_STRIP: return "DEV_RX_OFFLOAD_VLAN_STRIP"; /*0x00000001*/
  case DEV_RX_OFFLOAD_IPV4_CKSUM: return "DEV_RX_OFFLOAD_IPV4_CKSUM"; /*0x00000002*/
  case DEV_RX_OFFLOAD_UDP_CKSUM: return "DEV_RX_OFFLOAD_UDP_CKSUM"; /*0x00000004*/
  case DEV_RX_OFFLOAD_TCP_CKSUM: return "DEV_RX_OFFLOAD_TCP_CKSUM"; /*0x00000008*/
  case DEV_RX_OFFLOAD_TCP_LRO: return "DEV_RX_OFFLOAD_TCP_LRO"; /*0x00000010*/
  default: return NULL;
  }
}

/* create a mask and get flagname if bit is set 
 */
void 
get_rx_offload_flags_mask(uint32_t flags){

 uint32_t bitmask = 0;
 uint16_t count = 1;

 for ( int i = 0 ; i < 32 ; i++) {
   bitmask = 1 << i;
   
   const char* text = NULL;
   text = get_eth_rx_offload_flags(flags & bitmask);
   if (text !=NULL){
     printf("%s ",text);
     count ++;
     printf("\n");
     
   }
 }//endfor
}
/************* Flow types mask (FDIR) *****************/

const char *
get_eth_fdir_types_flags(uint32_t flags){
  switch(flags){
    // case RTE_ETH_FLOW_UNKNOWN             :return "RTE_ETH_FLOW_UNKNOWN"; /* 0 */
  case RTE_ETH_FLOW_RAW                 :return "RTE_ETH_FLOW_RAW";     /* 1 */
  case RTE_ETH_FLOW_IPV4                :return "RTE_ETH_FLOW_IPV4"; /* 2 */
  case RTE_ETH_FLOW_FRAG_IPV4           :return "RTE_ETH_FLOW_FRAG_IPV4"; /*3 */
  case RTE_ETH_FLOW_NONFRAG_IPV4_TCP    :return "RTE_ETH_FLOW_NONFRAG_IPV4_TCP"; /*4*/
  case RTE_ETH_FLOW_NONFRAG_IPV4_UDP    :return "RTE_ETH_FLOW_NONFRAG_IPV4_UDP"; /*5*/
  case RTE_ETH_FLOW_NONFRAG_IPV4_SCTP   :return "RTE_ETH_FLOW_NONFRAG_IPV4_SCTP"; /*6*/
  case RTE_ETH_FLOW_NONFRAG_IPV4_OTHER  :return "RTE_ETH_FLOW_NONFRAG_IPV4_OTHER"; /*7*/
  case RTE_ETH_FLOW_IPV6                :return "RTE_ETH_FLOW_IPV6"; /*8*/
  case RTE_ETH_FLOW_FRAG_IPV6           :return "RTE_ETH_FLOW_FRAG_IPV6"; /*9*/
  case RTE_ETH_FLOW_NONFRAG_IPV6_TCP    :return "RTE_ETH_FLOW_NONFRAG_IPV6_TCP"; /*10*/
  case RTE_ETH_FLOW_NONFRAG_IPV6_UDP    :return "RTE_ETH_FLOW_NONFRAG_IPV6_UDP"; /*11*/
  case RTE_ETH_FLOW_NONFRAG_IPV6_SCTP   :return "RTE_ETH_FLOW_NONFRAG_IPV6_SCTP"; /*12*/
  case RTE_ETH_FLOW_NONFRAG_IPV6_OTHER  :return "RTE_ETH_FLOW_NONFRAG_IPV6_OTHER"; /*13*/
  case RTE_ETH_FLOW_L2_PAYLOAD          :return "RTE_ETH_FLOW_L2_PAYLOAD"; /*14*/
  case RTE_ETH_FLOW_IPV6_EX             :return "RTE_ETH_FLOW_IPV6_EX"; /*15*/
  case RTE_ETH_FLOW_IPV6_TCP_EX         :return "RTE_ETH_FLOW_IPV6_TCP_EX"; /*16*/
  case RTE_ETH_FLOW_IPV6_UDP_EX         :return "RTE_ETH_FLOW_IPV6_UDP_EX"; /*17*/
  case RTE_ETH_FLOW_MAX                 :return "RTE_ETH_FLOW_MAX"; /*18*/
  default: return NULL;
  }
}

/* /\* create a mask and get flagname if bit is set  */
/*  *\/ */
/* void  */
/* get_fdir_types_mask(uint32_t flags){ */

/*  uint32_t bitmask = 0; */
/*  uint16_t count = 1; */

/*  for ( int i = 0 ; i < 32 ; i++) { */
/*    bitmask = 1 << i; */
   
/*    const char* text = NULL; */
/*    text = get_eth_fdir_types_flags(flags & bitmask); */
/*    if (text !=NULL){ */
/*      printf("%s ",text); */
/*      count ++; */
/*      printf("\n"); */
/*    } */
/*  }//endfor */
/* } */



/**************** main **********************/
#ifdef GETFLAGS_NAME_MAIN
int main(int argc ,char __attribute__((unused)) **argv){
  /* BEGIN */
  printf("argc : %d\n",argc);
  printf("hello dpdk\n");
  printf("----------------------------\n");
  printf("txq flags \n");
  get_txq_flags_mask(1<<2|1);

  printf("\n tx offload flags \n");
  get_tx_offload_flags_mask(1<<3|1);

  printf("\n rx offload flags \n");
  get_rx_offload_flags_mask(1<<2|1);

  printf("\n fdir types mask \n");
  get_fdir_types_mask((1<<4)|(1<<1));
  return 0;
}
#endif
