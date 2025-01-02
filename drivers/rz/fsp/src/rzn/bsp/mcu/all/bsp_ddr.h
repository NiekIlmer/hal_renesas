/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef __BSP_DDR_H__
#define __BSP_DDR_H__

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_DDR_PHY_BASE                     ((uintptr_t) 0x88000000)

#define BPS_DDR_BASE_ADDR                    (0x200000000)

#define BSP_DDR_RETENTION_1D_SIZE            (283)
#define BSP_DDR_RETENTION_2D_SIZE            (52)
#define BSP_DDR_RETENTION_CONTROLLER_SIZE    (4)

#define BSP_DDR_INIT_ENABLE                  (1)
#define BSP_DDR_INIT_DISABLE                 (0)

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
extern void bsp_ddr_init(void);

/*******************************************************************************************************************//**
 * Executes bsp_mmio_write_32
 *
 * @param[in] addr          First argument
 * @param[in] value         Second argument
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_mmio_write_32 (uintptr_t addr, uint32_t value)
{
    *(volatile uint32_t *) addr = value;
}

/*******************************************************************************************************************//**
 * Executes bsp_mmio_read_32
 *
 * @param[in] addr          First argument
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t bsp_mmio_read_32 (uintptr_t addr)
{
    return *(volatile uint32_t *) addr;
}

/*******************************************************************************************************************//**
 * Executes bsp_ddrtop_mc_apb_wr
 *
 * @param[in] addr          First argument
 * @param[in] data          Second argument
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_ddrtop_mc_apb_wr (uint32_t addr, uint32_t data)
{
    bsp_mmio_write_32(R_DDRSS_BASE + (addr << 2), data);
}

/*******************************************************************************************************************//**
 * Executes bsp_dwc_ddrphy_apb_wr
 *
 * @param[in] addr          First argument
 * @param[in] data          Second argument
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_dwc_ddrphy_apb_wr (uint32_t addr, uint32_t data)
{
    bsp_mmio_write_32(BSP_DDR_PHY_BASE + (addr << 2), data);
}

/*******************************************************************************************************************//**
 * Executes bsp_dwc_ddrphy_apb_rd
 *
 * @param[in] addr          First argument
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t bsp_dwc_ddrphy_apb_rd (uint32_t addr)
{
    return bsp_mmio_read_32(BSP_DDR_PHY_BASE + (addr << 2));
}

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if ((BSP_CLOCKS_PLL2_NORMAL != BSP_CFG_PLL2) && (1 == BSP_CFG_DDR_INIT_ENABLE))
 #error "When using DDR, please set to 'PLL2 is released from standby state'"
#endif

#endif                                 /*__BSP_DDR_H__*/
