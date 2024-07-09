/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_API_H
#define BSP_API_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* FSP Common Includes. */
#include "fsp_common_api.h"

/* Gets MCU configuration information. */
#include "bsp_cfg.h"

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)

/* Store warning settings for 'conversion' and 'sign-conversion' to as specified on command line. */
 #pragma GCC diagnostic push

/* CMSIS-CORE currently generates 2 warnings when compiling with GCC. One in core_cmInstr.h and one in core_cm4_simd.h.
 * We are not modifying these files so we will ignore these warnings temporarily. */
 #pragma GCC diagnostic ignored "-Wconversion"
 #pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

/* Vector information for this project. This is generated by the tooling. */
#include "bsp_exceptions.h"
#include "vector_data.h"

/* CMSIS-CORE Renesas Device Files. Must come after bsp_feature.h, which is included in bsp_cfg.h. */
#include "renesas.h"
#include "system.h"

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)

/* Restore warning settings for 'conversion' and 'sign-conversion' to as specified on command line. */
 #pragma GCC diagnostic pop
#endif

#if defined(BSP_API_OVERRIDE)
 #include BSP_API_OVERRIDE
#else

/* BSP Common Includes. */
 #include "bsp_common.h"

/* BSP MCU Specific Includes. */
 #include "bsp_register_protection.h"
 #include "bsp_irq.h"
 #include "bsp_io.h"
 #include "bsp_group_irq.h"
 #include "bsp_clocks.h"
 #include "bsp_module_stop.h"
 
/* Factory MCU information. */
 #include "fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
 #include "bsp_delay.h"
 #include "bsp_mcu_api.h"
 #include "bsp_security.h"
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

fsp_err_t R_FSP_VersionGet(fsp_pack_version_t * const p_version);

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
