/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexspi_nor_boot.h"
__attribute__((section(".boot_hdr_ivt")))
/************************************* 
 *  IVT Data 
 *************************************/
const ivt image_vector_table = {
  IVT_HEADER,                         /* IVT Header */
  IMAGE_ENTRY_ADDRESS,                /* Image Entry Function */
  IVT_RSVD,                           /* Reserved = 0 */
  0x00000000,                         /* Address where DCD information is stored */
  (uint32_t)BOOT_DATA_ADDRESS,        /* Address where BOOT Data Structure is stored */
  (uint32_t)&image_vector_table,      /* Pointer to IVT Self (absolute address */
  (uint32_t)CSF_ADDRESS,              /* Address where CSF file is stored */
  IVT_RSVD                            /* Reserved = 0 */
};

__attribute__((section(".boot_hdr_boot_data")))
/************************************* 
 *  Boot Data 
 *************************************/
const BOOT_DATA_T boot_data = {
  0x60000000,                 /* boot start location */
  FLASH_SIZE,                 /* size */
  PLUGIN_FLAG,                /* Plugin flag*/
  0xFFFFFFFF  		      /* empty - extra data word */
};




