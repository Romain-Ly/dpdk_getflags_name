#include <stdio.h>

#include <rte_eal.h>
#include <rte_common.h>
#include <rte_mbuf.h>
#include <rte_ethdev.h>


void print_binary(uint32_t n);
const char *get_eth_txq_flags(uint32_t mask);
void get_txq_flags_mask(uint32_t mask);

const char *get_eth_tx_offload_flags(uint32_t flags);
void get_tx_offload_flags_mask(uint32_t flags);

const char *get_eth_rx_offload_flags(uint32_t flags);
void get_rx_offload_flags_mask(uint32_t flags);

const char* get_eth_fdir_types_flags(uint32_t flags);
void get_fdir_types_mask(uint32_t flags);
