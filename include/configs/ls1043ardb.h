/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2015 Freescale Semiconductor
 * Copyright 2022 NXP
 */

#ifndef __LS1043ARDB_H__
#define __LS1043ARDB_H__

#include "ls1043a_common.h"

/* Physical Memory Map */

#ifndef CONFIG_SPL
#define CONFIG_MEM_INIT_VALUE           0xdeadbeef
#endif

/*
 * NOR Flash Definitions
 */
#define CONFIG_SYS_NOR_CSPR_EXT		(0x0)
#define CONFIG_SYS_NOR_AMASK		IFC_AMASK(128*1024*1024)
#define CONFIG_SYS_NOR_CSPR					\
	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS)		| \
	CSPR_PORT_SIZE_16					| \
	CSPR_MSEL_NOR						| \
	CSPR_V)

/* NOR Flash Timing Params */
#define CONFIG_SYS_NOR_CSOR		(CSOR_NOR_ADM_SHIFT(4) | \
					CSOR_NOR_TRHZ_80)
#define CONFIG_SYS_NOR_FTIM0		(FTIM0_NOR_TACSE(0x1) | \
					FTIM0_NOR_TEADC(0x1) | \
					FTIM0_NOR_TAVDS(0x0) | \
					FTIM0_NOR_TEAHC(0xc))
#define CONFIG_SYS_NOR_FTIM1		(FTIM1_NOR_TACO(0x1c) | \
					FTIM1_NOR_TRAD_NOR(0xb) | \
					FTIM1_NOR_TSEQRAD_NOR(0x9))
#define CONFIG_SYS_NOR_FTIM2		(FTIM2_NOR_TCS(0x1) | \
					FTIM2_NOR_TCH(0x4) | \
					FTIM2_NOR_TWPH(0x8) | \
					FTIM2_NOR_TWP(0x10))
#define CONFIG_SYS_NOR_FTIM3		0
#define CONFIG_SYS_IFC_CCR		0x01000000

#define CONFIG_SYS_FLASH_BANKS_LIST	{ CONFIG_SYS_FLASH_BASE_PHYS }

#define CONFIG_SYS_WRITE_SWAPPED_DATA

/*
 * NAND Flash Definitions
 */

#define CONFIG_SYS_NAND_BASE		0x7e800000
#define CONFIG_SYS_NAND_BASE_PHYS	CONFIG_SYS_NAND_BASE

#define CONFIG_SYS_NAND_CSPR_EXT	(0x0)
#define CONFIG_SYS_NAND_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_NAND_BASE_PHYS) \
				| CSPR_PORT_SIZE_8	\
				| CSPR_MSEL_NAND	\
				| CSPR_V)
#define CONFIG_SYS_NAND_AMASK	IFC_AMASK(64*1024)
#define CONFIG_SYS_NAND_CSOR	(CSOR_NAND_ECC_ENC_EN	/* ECC on encode */ \
				| CSOR_NAND_ECC_DEC_EN	/* ECC on decode */ \
				| CSOR_NAND_ECC_MODE_4	/* 4-bit ECC */ \
				| CSOR_NAND_RAL_3	/* RAL = 3 Bytes */ \
				| CSOR_NAND_PGS_2K	/* Page Size = 2K */ \
				| CSOR_NAND_SPRZ_64	/* Spare size = 64 */ \
				| CSOR_NAND_PB(64))	/* 64 Pages Per Block */

#define CONFIG_SYS_NAND_FTIM0		(FTIM0_NAND_TCCST(0x7) | \
					FTIM0_NAND_TWP(0x18)   | \
					FTIM0_NAND_TWCHT(0x7) | \
					FTIM0_NAND_TWH(0xa))
#define CONFIG_SYS_NAND_FTIM1		(FTIM1_NAND_TADLE(0x32) | \
					FTIM1_NAND_TWBE(0x39)  | \
					FTIM1_NAND_TRR(0xe)   | \
					FTIM1_NAND_TRP(0x18))
#define CONFIG_SYS_NAND_FTIM2		(FTIM2_NAND_TRAD(0xf) | \
					FTIM2_NAND_TREH(0xa) | \
					FTIM2_NAND_TWHRE(0x1e))
#define CONFIG_SYS_NAND_FTIM3		0x0

#define CONFIG_SYS_NAND_BASE_LIST	{ CONFIG_SYS_NAND_BASE }
#define CONFIG_MTD_NAND_VERIFY_WRITE

#ifdef CONFIG_NAND_BOOT
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(1024 << 10)
#endif

/*
 * CPLD
 */
#define CONFIG_SYS_CPLD_BASE		0x7fb00000
#define CPLD_BASE_PHYS			CONFIG_SYS_CPLD_BASE

#define CONFIG_SYS_CPLD_CSPR_EXT	(0x0)
#define CONFIG_SYS_CPLD_CSPR		(CSPR_PHYS_ADDR(CPLD_BASE_PHYS) | \
					CSPR_PORT_SIZE_8 | \
					CSPR_MSEL_GPCM | \
					CSPR_V)
#define CONFIG_SYS_CPLD_AMASK		IFC_AMASK(64 * 1024)
#define CONFIG_SYS_CPLD_CSOR		(CSOR_NOR_ADM_SHIFT(4) | \
					CSOR_NOR_NOR_MODE_AVD_NOR | \
					CSOR_NOR_TRHZ_80)

/* CPLD Timing parameters for IFC GPCM */
#define CONFIG_SYS_CPLD_FTIM0		(FTIM0_GPCM_TACSE(0xf) | \
					FTIM0_GPCM_TEADC(0xf) | \
					FTIM0_GPCM_TEAHC(0xf))
#define CONFIG_SYS_CPLD_FTIM1		(FTIM1_GPCM_TACO(0xff) | \
					FTIM1_GPCM_TRAD(0x3f))
#define CONFIG_SYS_CPLD_FTIM2		(FTIM2_GPCM_TCS(0xf) | \
					FTIM2_GPCM_TCH(0xf) | \
					FTIM2_GPCM_TWP(0xff))
#define CONFIG_SYS_CPLD_FTIM3		0x0

/* IFC Timing Params */
#ifdef CONFIG_TFABOOT
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3

#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NAND_FTIM3
#else
#ifdef CONFIG_NAND_BOOT
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NAND_FTIM3

#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NOR_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NOR_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NOR_FTIM3
#else
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3

#define CONFIG_SYS_CSPR1_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR1		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK1		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR1		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS1_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS1_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS1_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS1_FTIM3		CONFIG_SYS_NAND_FTIM3
#endif
#endif

#define CONFIG_SYS_CSPR2_EXT		CONFIG_SYS_CPLD_CSPR_EXT
#define CONFIG_SYS_CSPR2		CONFIG_SYS_CPLD_CSPR
#define CONFIG_SYS_AMASK2		CONFIG_SYS_CPLD_AMASK
#define CONFIG_SYS_CSOR2		CONFIG_SYS_CPLD_CSOR
#define CONFIG_SYS_CS2_FTIM0		CONFIG_SYS_CPLD_FTIM0
#define CONFIG_SYS_CS2_FTIM1		CONFIG_SYS_CPLD_FTIM1
#define CONFIG_SYS_CS2_FTIM2		CONFIG_SYS_CPLD_FTIM2
#define CONFIG_SYS_CS2_FTIM3		CONFIG_SYS_CPLD_FTIM3

/*
 * Environment
 */

/* FMan */
#ifndef SPL_NO_FMAN
#define AQR105_IRQ_MASK			0x40000000

#ifdef CONFIG_SYS_DPAA_FMAN
#define RGMII_PHY1_ADDR			0x1
#define RGMII_PHY2_ADDR			0x2

#define QSGMII_PORT1_PHY_ADDR		0x4
#define QSGMII_PORT2_PHY_ADDR		0x5
#define QSGMII_PORT3_PHY_ADDR		0x6
#define QSGMII_PORT4_PHY_ADDR		0x7

/* The AQR PHY model and MDIO address differ between board revisions */
#define FM1_10GEC1_PHY_ADDR		0x1 /* AQR105 on boards up to v6.0 */
#define AQR113C_PHY_ADDR		0x8 /* AQR113C on boards v7.0 and up */
#endif
#endif

/* SATA */
#ifndef SPL_NO_SATA
#define SCSI_VEND_ID 0x1b4b
#define SCSI_DEV_ID  0x9170
#define CONFIG_SCSI_DEV_LIST {SCSI_VEND_ID, SCSI_DEV_ID}
#endif

#include <asm/fsl_secure_boot.h>

#endif /* __LS1043ARDB_H__ */
