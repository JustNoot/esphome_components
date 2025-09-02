#pragma once
#include <cstdint>

namespace esphome {
namespace tas5825m {

/*
RESET_CTRL Register, Offset = 0x01, Reset = 0x00
RESET_CTRL[7:5] - RESERVED
RESET_CTRL[4]   - RST_DIG_CORE (0: Normal, 1: Reset Full Digital Signal Path)
RESET_CTRL[3:1] - RESERVED
RESET_CTRL[0]   - RST_REG (0: Normal, 1: Reset I2C Control Port Registers)
*/
static const uint8_t TAS5825M_RESET_CTRL = 0x01;

/*
DEVICE_CTRL_1 Register, Offset = 0x02, Reset = 0x00
DEVICE_CTRL_1[7]   - RESERVED
DEVICE_CTRL_1[6:4] - FSW_SEL 0b000: 384K
                             0b010: 480K
                             0b011: 576K
                             0b100: 768K
                             0b001: Reserved
                             0b101: Reserved
                             0b110: Reserved
                             0b111: Reserved
DEVICE_CTRL_1[3]   - RESERVED
DEVICE_CTRL_1[2]   - DAMP_PBTL (0: SET DAMP TO BTL MODE, 1: SET DAMP TO PBTL MODE)
DEVICE_CTRL_1[1:0] - DAMP_MOD 0b00: BD MODE
                              0b01: 1SPW MODE
                              0b10: HYBRID MODE
                              0b11: Reserved
*/
static const uint8_t TAS5825M_DEVICE_CTRL1 = 0x02;

/*
DEVICE_CTRL_2 Register, Offset = 0x03, Reset = 0x10
DEVICE_CTRL_2[7:5] - RESERVED
DEVICE_CTRL_2[4]   - DIS_DSP (0: Normal operation, 1: Reset the DSP)
DEVICE_CTRL_2[3]   - MUTE (0: Normal volume, 1: Mute)
DEVICE_CTRL_2[2]   - RESERVED
DEVICE_CTRL_2[1:0] - CTRL_STATE 0b00: Deep Sleep
                                0b01: Sleep
                                0b10: Hiz
                                0b11: PLAY
*/
static const uint8_t TAS5825M_DEVICE_CTRL2 = 0x03;

// I2C_PAGE_AUTO_INC Register, Offset = 0x0F, Reset = 0x00
// I2C_PAGE_AUTO_INC[7:4] - RESERVED
// I2C_PAGE_AUTO_INC[3]   - PAGE_AUTOINC_REG (0: Enable Page auto increment, 1: Disable Page auto increment)
// I2C_PAGE_AUTO_INC[2:0] - RESERVED
static const uint8_t TAS5825M_I2C_PAGE_AUTO_INC = 0x0F;

/*
SIG_CH_CTRL Register, Offset = 0x28, Reset = 0x00
SIG_CH_CTRL[7:4] - SCLK_RATIO_CONFIGURE 0b0011: 32FS
                                        0b0101: 64FS
                                        0b0111: 128FS
                                        0b1001: 256FS
                                        0b1011: 512FS
SIG_CH_CTRL[3:0] - FSMODE 0b0000: Auto detection
                          0b0100: Reserved
                          0b0110: 32 KHz
                          0b1000: 44.1 KHz
                          0b1001: 48 KHz
                          0b1010: 88.2 KHz
                          0b1011: 96 KHz
                          0b1100: 176.4 KHz
                          0b1101: 192 KHz
*/
static const uint8_t TAS5825M_SIG_CH_CTRL = 0x28;

/*
CLOCK_DET_CTRL Register, Offset = 0x29, Reset = 0x00
CLOCK_DET_CTRL[7] - RESERVED
CLOCK_DET_CTRL[6] - DIS_DET_PLL (0: Regard PLL overrate detection, 1: Ignore PLL overrate detection)
CLOCK_DET_CTRL[5] - DIS_DET_SCLK_RANGE (0: Regard BCK Range detection, 1: Ignore BCK Range detection)
CLOCK_DET_CTRL[4] - DIS_DET_FS (0: Regard FS detection, 1: Ignore FS detection)
CLOCK_DET_CTRL[3] - DIS_DET_SCLK (0: Regard SCLK detection, 1: Ignore SCLK detection)
CLOCK_DET_CTRL[2] - DIS_DET_MISS (0: Regard SCLK missing detection, 1: Ignore SCLK missing detection)
CLOCK_DET_CTRL[1] - RESERVED
CLOCK_DET_CTRL[0] - RESERVED
*/
static const uint8_t TAS5825M_CLOCK_DET_CTRL = 0x29;

/*
SDOUT_SEL Register, Offset = 0x30, Reset = 0x00
SDOUT_SEL[7:1] - RESERVED
SDOUT_SEL[0]   - SDOUT_SEL (0: SDOUT is the DSP output (post-processing), 1: SDOUT is the DSP input (pre-processing))
*/
static const uint8_t TAS5825M_SDOUT_SEL = 0x30;

/*
I2S_CTRL Register, Offset = 31h, Reset = 0x00
I2S_CTRL[7:6] - RESERVED
I2S_CTRL[5]   - SCLK_INV (0: Normal SCLK mode, 1: Inverted SCLK mode)
I2S_CTRL[4:0] - RESERVED
*/
static const uint8_t TAS5825M_I2S_CTRL = 0x31;

/*
SAP_CTRL1 Register, Offset = 33h, Reset = 0x02
SAP_CTRL1[7]   - I2S_SHIFT_MSB
SAP_CTRL1[6]   - RESERVED
SAP_CTRL1[5:4] - DATA_FORMAT 0b00: I2S
                             0b01: TDM/DSP
                             0b10: RTJ
                             0b11: LTJ
SAP_CTRL1[3:2] - I2S_LRCLK_PULSE 0b01: LRCLK pulse < 8 SCLK
SAP_CTRL1[1:0] - WORD_LENGTH 0b00: 16 bits
                             0b01: 20 bits
                             0b10: 24 bits
                             0b11: 32 bits
*/
static const uint8_t TAS5825M_SAP_CTRL1 = 0x33;

/*
SAP_CTRL2 Register, Offset = 34h, Reset = 0x00
SAP_CTRL2[7:0] - I2S_SHIFT 0b000000000: offset = 0 SCLK (no offset)
                           0b000000001: offset = 1 SCLK
                           0b000000010: offset = 2 SCLKs
                           ........
                           0b111111111: offset = 512 SCLKs
*/
static const uint8_t TAS5825M_SAP_CTRL2 = 0x34;

/*
SAP_CTRL3 Register, Offset = 0x35, Reset = 0x11
SAP_CTRL3[7:6] - RESERVED
SAP_CTRL3[5:4] - LEFT_DAC_DPATH 0b00: Zero data (mute)
                                0b01: Left channel data
                                0b10: Right channel data
                                0b11: Reserved (do not set)
SAP_CTRL3[3:2] - RESERVED
SAP_CTRL3[5:4] - RIGHT_DAC_DPATH 0b00: Zero data (mute)
                                 0b01: Right channel data
                                 0b10: Left channel data
                                 0b11: Reserved (do not set)
*/
static const uint8_t TAS5825M_SAP_CTRL3 = 0x35;

/*
FS_MON Register, Offset = 0x37, Reset = 0x00
FS_MON[7:6] - RESERVED
FS_MON[5:4] - SCLK_RATIO_HIGH
FS_MON[3:0] - FS 0b0000: FS Error
                 0b0100: 16 KHz
                 0b0110: 32 KHz
                 0b1000: Reserved
                 0b1001: 48 KHz
                 0b1011: 96 KHz
                 0b1101: 192 KHz
*/
static const uint8_t TAS5825M_FS_MON = 0x37;

/*
BCK_SCLK_MON Register, Offset = 0x38, Reset = 0x00
BCK_SCLK_MON[7:0] - BCLK_SCLK_RATIO_LOW 32 FS - 512 FS
*/
static const uint8_t TAS5825M_BCK_SCLK_MON = 0x38;

/*
CLKDET_STATUS Register, Offset = 0x39, Reset = 0x00
CLKDET_STATUS[7:6] - RESERVED
CLKDET_STATUS[5:0] - DET_STATUS bit1: This bit indicates whether the SCLK is valid or not. The SCLK ratio must be stable and in the range of 32-512FS to be valid.
                                bit2: This bit indicates whether the SCLK is missing or not.
                                bit3:This bit indicates whether the PLL is locked or not. The PLL is reported as unlocked when the PLL is disabled.
                                bit4:This bit indicates whether the PLL is overrate
                                bit5:This bit indicates whether the SCLK is overrate or underrate
*/
static const uint8_t TAS5825M_CLKDET_STATUS = 0x39;

/*
DSP_PGM_MODE Register, Offset = 0x40, Reset = 0x01
DSP_PGM_MODE[7:5] - RESERVED
DSP_PGM_MODE[4:0] - MODE_SEL 0b00000: ram mode
                             0b00001: rom mode 1
                             0b00010: rom mode 2
                             0b00011: rom mode 3
*/
static const uint8_t TAS5825M_DSP_PGM_MODE = 0x40;

/*
DSP_CTRL Register, Offset = 0x46, Reset = 0x01
DSP_CTRL[7:5] - RESERVED
DSP_CTRL[4:3] - USER_DEFINED_PROCESSING_RATE 0b00: input
                                             0b01: 48k
                                             0b10: 96k
                                             0b11: 192k
DSP_CTRL[2:1] - RESERVED
DSP_CTRL[0]   - USE_DEFAULT_COEFFS (0: don't use default coefficients from ZROM, 1: use default coefficients from ZROM)
*/
static const uint8_t TAS5825M_DSP_CTRL = 0x46;

/*
DIG_VOL Register, Offset = 0x4C, Reset = 0x30
DIG_VOL[7:0] - PGA 0b00000000: +24.0 dB
                   0b00000001: +23.5 dB
                   ........
                   0b00101111: +0.5 dB
                   0b00110000: 0.0 dB
                   0b00110001: -0.5 dB
                   ........
                   0b11111110: -103 dB
                   0b11111111: Mute
*/
static const uint8_t TAS5825M_DIG_VOL = 0x4C;

/*
DIG_VOL_CTRL1 Register, Offset = 0x4E, Reset = 0x33
DIG_VOL_CTRL1[7:6] - PGA_RAMP_DOWN_SPEED 0b00: Update every 1 FS period
                                        0b01: Update every 2 FS periods
                                        0b10: Update every 4 FS periods
                                        0b11: Directly set the volume to zero (Instant mute)
DIG_VOL_CTRL1[5:4] - PGA_RAMP_DOWN_STEP 0b00: Decrement by 4 dB for each update
                                        0b01: Decrement by 2 dB for each update
                                        0b10: Decrement by 1 dB for each update
                                        0b11: Decrement by 0.5 dB for each update
DIG_VOL_CTRL1[3:2] - PGA_RAMP_UP_SPEED 0b00: Update every 1 FS period
                                       0b01: Update every 2 FS periods
                                       0b10: Update every 4 FS periods
                                       0b11: Directly restore the volume (Instant unmute)
DIG_VOL_CTRL1[1:0] - PGA_RAMP_UP_STEP 0b00: Increment by 4 dB for each update
                                      0b01: Increment by 2 dB for each update
                                      0b10: Increment by 1 dB for each update
                                      0b11: Increment by 0.5 dB for each update
*/
static const uint8_t TAS5825M_DIG_VOL_CTRL1 = 0x4E;

/*
DIG_VOL_CTRL2 Register, Offset = 0x4F, Reset = 0x30
DIG_VOL_CTRL2[7:6] - FAST_RAMP_DOWN_SPEED 0b00: Update every 1 FS period
                                          0b01: Update every 2 FS periods
                                          0b10: Update every 4 FS periods
                                          0b11: Directly set the volume to zero (Instant mute)
DIG_VOL_CTRL2[5:4] - FAST_RAMP_DOWN_STEP 0b00: Decrement by 4 dB for each update
                                         0b01: Decrement by 2 dB for each update
                                         0b10: Decrement by 1 dB for each update
                                         0b11: Decrement by 0.5 dB for each update
DIG_VOL_CTRL2[3:0] - RESERVED
*/
static const uint8_t TAS5825M_DIG_VOL_CTRL2 = 0x4F;

/*
AUTO_MUTE_CTRL Register, Offset = 0x50, Reset = 0x07
AUTO_MUTE_CTRL[7:3] - RESERVED
AUTO_MUTE_CTRL[2:0] - REG_AUTO_MUTE_CTRL bit0: 0: Disable left channel auto mute
                                               1: Enable left channel auto mute
                                         bit1: 0: Disable right channel auto mute
                                               1: Enable right channel auto mute
                                         bit2: 0: Auto mute left channel and right channel independently.
                                               1: Auto mute left and right channels only when both channels are about to be auto muted
*/
static const uint8_t TAS5825M_AUTO_MUTE_CTRL = 0x50;

/*
AUTO_MUTE_TIME Register, Offset = 0x51, Reset = 0x00
AUTO_MUTE_TIME[7]   - RESERVED
AUTO_MUTE_TIME[6:4] - AUTOMUTE_TIME_LEFT 0b000: 11.5 ms
                                         0b001: 53 ms
                                         0b010: 106.5 ms
                                         0b011: 266.5 ms
                                         0b100: 0.535 sec
                                         0b101: 1.065 sec
                                         0b110: 2.665 sec
                                         0b111: 5.33 sec
AUTO_MUTE_TIME[3]   - RESERVED
AUTO_MUTE_TIME[2:0] - AUTOMUTE_TIME_RIGHT 0b000: 11.5 ms
                                          0b001: 53 ms
                                          0b010: 106.5 ms
                                          0b011: 266.5 ms
                                          0b100: 0.535 sec
                                          0b101: 1.065 sec
                                          0b110: 2.665 sec
                                          0b111: 5.33 sec
*/
static const uint8_t TAS5825M_AUTO_MUTE_TIME = 0x51;

/*
ANA_CTRL Register, Offset = 0x53, Reset = 0x00
ANA_CTRL[7]   - RESERVED
ANA_CTRL[6:5] - CLASS_D_BANDWIDTH_CTRL 0b00: 100 kHz
                                       0b01: 80 kHz
                                       0b10: 120 kHz
                                       0b11:175 kHz
ANA_CTRL[4:1] - RESERVED
ANA_CTRL[0]   - L_R_PWM_PHASE_CTRL (0: Out of phase, 1: In phase)
*/
static const uint8_t TAS5825M_ANA_CTRL = 0x53;

/*
AGAIN Register, Offset = 0x54, Reset = 0x00
AGAIN[7:5] - RESERVED
AGAIN[4:0] - ANA_GAIN 0b00000: 0 dB (29.5V peak voltage)
                      0b00001: -0.5db
                      .....
                      0b11111: -15.5 dB
*/
static const uint8_t TAS5825M_AGAIN = 0x54;

/*
SPI_CLK Register, Offset = 0x55, Reset = 0x00
SPI_CLK[7:4] - RESERVED
SPI_CLK[3:0] - SPI_CLK_SEL 0b0000: 1.25MHz
                           0b0001: 2.5MHz
                           0b0010: 5MHz
                           0b0011: 10MHz
*/
static const uint8_t TAS5825M_SPI_CLK = 0x55;

/*
EEPROM_CTRL0 Register, Offset = 0x56, Reset = 0x00
EEPROM_CTRL0[7:6] - RESERVED
EEPROM_CTRL0[5]   - EEPROM_ADDR_24BITS_ENABLE
EEPROM_CTRL0[4:3] - SPI_CLK_RATE 0: spi clock rate = 1.25 MHz
                                 1: spi clock rate = 2.5 MHz
                                 2: spi clock rate = 5 MHz
                                 3: spi clock rate = 10 MHz
EEPROM_CTRL0[2]   - SPI_INV_POLAR (0: spi serial data change at post edge SCK, 1: spi serial data change at neg edge SCK)
EEPROM_CTRL0[1]   - SPI_MST_LSB (0: MSB first, 1: LSB first)
EEPROM_CTRL0[0]   - LOAD_EEPROM_START (0: DSP coefficients read from host, 1: DSP coefficients read from EEPROM)
*/
static const uint8_t TAS5825M_EEPROM_CTRL0 = 0x56;

/*
EEPROM_RD_CMD Register, Offset = 0x57, Reset = 0x03
EEPROM_RD_CMD[7:0] - EEPROM_RD_CMD
*/
static const uint8_t TAS5825M_EEPROM_RD_CMD = 0x57;

/*
EEPROM_ADDR_START0 Register, Offset = 0x58, Reset = 0x00
EEPROM_ADDR_START0[7:0] - EEPROM_ADDR_START_HIGH
*/
static const uint8_t TAS5825M_EEPROM_ADDR_START0 = 0x58;

/*
EEPROM_ADDR_START1 Register, Offset = 0x59, Reset = 0x00
EEPROM_ADDR_START1[7:0] - EEPROM_ADDR_START_MIDDLE
*/
static const uint8_t TAS5825M_EEPROM_ADDR_START1 = 0x59;

/*
EEPROM_ADDR_START2 Register, Offset = 0x5A, Reset = 0x00
EEPROM_ADDR_START2[7:0] - EEPROM_ADDR_START_LOW
*/
static const uint8_t TAS5825M_EEPROM_ADDR_START2 = 0x5A;

/*
EEPROM_BOOT_STATUS Register, Offset = 0x5B, Reset = 0x00
EEPROM_BOOT_STATUS[7:2] - RESERVED
EEPROM_BOOT_STATUS[1]   - LOAD_EEPROM_CRC_ERROR (0: CRC pass for EEPROM boot load, 1: CRC don't pass for EEPROM boot load)
EEPROM_BOOT_STATUS[0]   - LOAD_EEPROM_DONE
*/
static const uint8_t TAS5825M_EEPROM_BOOT_STATUS = 0x5B;

/*
BQ_WR_CTRL1 Register, Offset = 0x5C, Reset = 0x00
BQ_WR_CTRL1[7:1] - RESERVED
BQ_WR_CTRL1[0]   - BQ_WR_FIRST_COEF
*/
static const uint8_t TAS5825M_BQ_WR_CTRL1 = 0x5C;

/*
PVDD_ADC Register, Offset = 0x5E, Reset = 0x00
PVDD_ADC[7:0] - PVDD_ADC (PVDD Voltage = PVDD_ADC[7:0] / 8.428)
                         223: 26.45V
                         222: 26.34V
                         221:26.22V
                         ...
                         39: 4.63V
                         38: 4.51V
                         37: 4.39V
*/
static const uint8_t TAS5825M_PVDD_ADC = 0x5E;

/*
GPIO_CTRL Register, Offset = 0x60, Reset = 0x00
GPIO_CTRL[7:3] - RESERVED
GPIO_CTRL[2]   - GPIO2_OE (0: GPIO2 is input, 1: GPIO2 is output)
GPIO_CTRL[1]   - GPIO1_OE (0: GPIO1 is input, 1: GPIO1 is output)
GPIO_CTRL[0]   - GPIO0_OE (0: GPIO0 is input, 1: GPIO0 is output)
*/
static const uint8_t TAS5825M_GPIO_CTRL = 0x60;

/*
GPIO0_SEL Register, Offset = 0x61, Reset = 0x00
GPIO0_SEL[7:4] - RESERVED
GPIO0_SEL[3:0] - GPIO0_SEL 0b0000: off (low)
                           0b0001: Reserved
                           0b0010: GPIO output value programmed by User in Section 9.6.1.38
                           0b0011: Auto mute flag (asserted when both L and R channels are auto muted)
                           0b0100: Auto mute flag for left channel
                           0b0101: Auto mute flag for right channel
                           0b0110: Clock invalid flag (clock error or clock missing)
                           0b0111: Reserved
                           0b1000: GPIO0 as WARNZ output
                           0b1001: Serial audio interface data output (SDOUT)
                           0b1011: GPIO0 as FAULTZ output
                           0b1100: GPIO0 as SPI CLK
                           0b1101: GPIO0 as SPI_PICO
                           0b1110: Reserved
                           0b1111: Reserved
*/
static const uint8_t TAS5825M_GPIO0_SEL = 0x61;

/*
GPIO1_SEL Register, Offset = 0x62, Reset = 0x00
GPIO1_SEL[7:4] - RESERVED
GPIO1_SEL[3:0] - GPIO1_SEL 0b0000: off (low)
                           0b0001: Reserved
                           0b0010: GPIO output value programmed by User in Section 9.6.1.38
                           0b0011: Auto mute flag (asserted when both L and R channels are auto muted)
                           0b0100: Auto mute flag for left channel
                           0b0101: Auto mute flag for right channel
                           0b0110: Clock invalid flag (clock error or clock missing)
                           0b0111: Reserved
                           0b1000: GPIO1 as WARNZ output
                           0b1001: Serial audio interface data output (SDOUT)
                           0b1011: GPIO1 as FAULTZ output
                           0b1100: GPIO1 as SPI CLK
                           0b1101: GPIO1 as SPI_PICO
                           0b1110: Reserved
                           0b1111: Reserved
*/
static const uint8_t TAS5825M_GPIO1_SEL = 0x62;

/*
GPIO2_SEL Register, Offset = 0x63, Reset = 0x00
GPIO2_SEL[7:4] - RESERVED
GPIO2_SEL[3:0] - GPIO2_SEL 0b0000: off (low)
                           0b0001: Reserved
                           0b0010: GPIO output value programmed by User in Section 9.6.1.38
                           0b0011: Auto mute flag (asserted when both L and R channels are auto muted)
                           0b0100: Auto mute flag for left channel
                           0b0101: Auto mute flag for right channel
                           0b0110: Clock invalid flag (clock error or clock missing)
                           0b0111: Reserved
                           0b1000: GPIO2 as WARNZ output
                           0b1001: Serial audio interface data output (SDOUT)
                           0b1011: GPIO2 as FAULTZ output
                           0b1100: GPIO2 as SPI CLK
                           0b1101: GPIO2 as SPI_PICO
                           0b1110: Reserved
                           0b1111: Reserved
*/
static const uint8_t TAS5825M_GPIO2_SEL = 0x63;

/*
GPIO_INPUT_SEL Register, Offset = 0x64, Reset = 0x00
GPIO_INPUT_SEL[7:6] - GPIO_SPI_POCI_SEL 0b00: N/A
                                        0b01: GPIO0
                                        0b10: GPIO1
                                        0b11: GPIO2
GPIO_INPUT_SEL[5:4] - GPIO_PHASE_SYNC_SEL 0b00: N/A
                                          0b01: GPIO0
                                          0b10: GPIO1
                                          0b11: GPIO2
GPIO_INPUT_SEL[3:2] - GPIO_RESETZ_SEL 0b00: N/A
                                      0b01: GPIO0
                                      0b10: GPIO1
                                      0b11: GPIO2
GPIO_INPUT_SEL[1:0] - GPIO_MUTEZ_SEL 0b00: N/A
                                     0b01: GPIO0
                                     0b10: GPIO1
                                     0b11: GPIO2
*/
static const uint8_t TAS5825M_GPIO_INPUT_SEL = 0x64;

/*
GPIO_OUT Register, Offset = 0x65, Reset = 0x00
GPIO_OUT[7:3] - RESERVED
GPIO_OUT[2:0] - GPIO_OUT bit0: GPIO0 output
                         bit1: GPIO1 output
                         bit2: GPIO2 output
*/
static const uint8_t TAS5825M_GPIO_OUT = 0x65;

/*
GPIO_OUT_INV Register, Offset = 0x66, Reset = 0x00
GPIO_OUT_INV[7:3] - RESERVED
GPIO_OUT_INV[2:0] - GPIO_OUT_INV bit0: GPIO0 output invert
                                 bit1: GPIO1 output invert
                                 bit2: GPIO2 output invert
*/
static const uint8_t TAS5825M_GPIO_OUT_INV = 0x66;

/*
DIE_ID Register, Offset = 0x67, Reset = 0x95
DIE_ID[7:0] - DIE_ID (0b10010101)
*/
static const uint8_t TAS5825M_DIE_ID = 0x67;

/*
POWER_STATE Register, Offset = 0x68, Reset = 0x00
POWER_STATE[7:0] - STATE_RPT 0: Deep sleep
                             1: Seep
                             2: HIZ
                             3: Play
                             4-15: Reserved
*/
static const uint8_t TAS5825M_POWER_STATE = 0x68;

/*
AUTOMUTE_STATE Register, Offset = 0x69, Reset = 0x00
AUTOMUTE_STATE[7:2] - RESERVED
AUTOMUTE_STATE[1]   - ZERO_RIGHT_MON (0: Not auto muted, 1: Auto muted)
AUTOMUTE_STATE[0]   - ZERO_LEFT_MON (0: Not auto muted, 1: Auto muted)
*/
static const uint8_t TAS5825M_AUTOMUTE_STATE = 0x69;

/*
PHASE_CTRL Register, Offset = 0x6A, Reset = 0x00
PHASE_CTRL[7:4] - REDERVED
PHASE_CTRL[3:2] - RAMP_PHASE_SEL 0b00: phase 0
                                 0b01: phase 1
                                 0b10: phase 2
                                 0b11: phase 3 all of above have a 45 degree of phase shift
PHASE_CTRL[1]   - PHASE_SYNC_SEL 0: GPIO sync
                                 1: Internal sync
PHASE_CTRL[0]   - PHASE_SYNC_EN 0: Ramp phase sync disable
                                1: Ramp phase sync enable
*/
static const uint8_t TAS5825M_PHASE_CTRL = 0x6A;

/*
RAMP_SS_CTRL0 Register, Offset = 0x6B, Reset = 0x00
RAMP_SS_CTRL0[7:6] - RESERVED
RAMP_SS_CTRL0[5]   - SS_PRE_DIV_SEL
RAMP_SS_CTRL0[4]   - SS_MANUAL_MODE
RAMP_SS_CTRL0[3:2] - RESERVED
RAMP_SS_CTRL0[1]   - SS_RDM_EN
RAMP_SS_CTRL0[0]   - SS_TRI_EN
*/
static const uint8_t TAS5825M_SS_CTRL0 = 0x6B;

/*
SS_CTRL1 Register, Offset = 0x6C, Reset = 0x00
SS_CTRL1[7]   - RESERVED
SS_CTRL1[6:4] - SS_RDM_CTRL
SS_CTRL1[3:0] - SS_TRI_CTRL
*/
static const uint8_t TAS5825M_SS_CTRL1 = 0x6C;

/*
SS_CTRL2 Register, Offset = 0x6D, Reset = 0xA0
SS_CTRL2[7:0] - TM_FREQ_CTRL
*/
static const uint8_t TAS5825M_SS_CTRL2 = 0x6D;

/*
SS_CTRL3 Register, Offset = 0x6E, Reset = 0x11
SS_CTRL3[7:4] - SS_TM_DSTEP_CTRL
SS_CTRL3[7:4] - SS_TM_USTEP_CTRL
*/
static const uint8_t TAS5825M_SS_CTRL3 = 0x6E;

/*
SS_CTRL4 Register, Offset = 0x6F, Reset = 0x24
SS_CTRL4[7]   - RESERVED
SS_CTRL4[6:5] - TM_AMP_CTRL
SS_CTRL4[4:0] - SS_TM_PERIOD_BOUNDRY
*/
static const uint8_t TAS5825M_SS_CTRL4 = 0x6F;

/*
CHAN_FAULT Register, Offset = 0x70, Reset = 0x00
CHAN_FAULT[7:4] - RESERVED
CHAN_FAULT[3]   - CH1_DC_I (Left channel DC fault)
CHAN_FAULT[2]   - CH2_DC_I (Right channel DC fault)
CHAN_FAULT[1]   - CH1_OC_I (Left channel over current fault)
CHAN_FAULT[0]   - CH2_OC_I (Right channel over current fault)
*/
static const uint8_t TAS5825M_CHAN_FAULT = 0x70;

/*
GLOBAL_FAULT1 Register, Offset = 0x71, Reset = 0x00
GLOBAL_FAULT1[7]   - OTP_CRC_ERROR (Indicate OTP CRC check error)
GLOBAL_FAULT1[6]   - BQ_WR_ERROR (The recent BQ is written failed)
GLOBAL_FAULT1[5]   - LOAD_EEPROM_ERROR (0: EEPROM boot load was done successfully, 1: EEPROM boot load was done unsuccessfully)
GLOBAL_FAULT1[4:3] - RESERVED
GLOBAL_FAULT1[2]   - CLK_FAULT_I
GLOBAL_FAULT1[1]   - PVDD_OV_I
GLOBAL_FAULT1[0]   - PVDD_UV_I
*/
static const uint8_t TAS5825M_GLOBAL_FAULT1 = 0x71;

/*
GLOBAL_FAULT2 Register, Offset = 0x72, Reset = 0x00
GLOBAL_FAULT2[7:3] - RESERVED
GLOBAL_FAULT2[2]   - CBC_FAULT_CH2_I (Right channel cycle by cycle over current fault)
GLOBAL_FAULT2[1]   - CBC_FAULT_CH1_I (Left channel cycle by cycle over current fault)
GLOBAL_FAULT2[0]   - OTSD_I (Over temperature shut down fault)
*/
static const uint8_t TAS5825M_GLOBAL_FAULT2 = 0x72;

/*
WARNING Register, Offset = 0x73, Reset = 0x00
WARNING[7:6] - RESERVED
WARNING[5]   - CBCW_CH1_I (Left channel cycle by cycle over current warning)
WARNING[4]   - CBCW_CH2_I (Right channel cycle by cycle over current warning)
WARNING[3]   - OTW_LEVEL4_I (Over temperature warning level 4, 146C)
WARNING[2]   - OTW_LEVEL3_I (Over temperature warning level 3, 134C)
WARNING[1]   - OTW_LEVEL2_I (Over temperature warning level 2, 122C)
WARNING[0]   - OTW_LEVEL1_I (Over temperature warning level 1, 112C)
*/
static const uint8_t TAS5825M_WARNING = 0x73;

/*
PIN_CONTROL1 Register, Offset = 0x74, Reset = 0x00
PIN_CONTROL1[7]   - MASK_OTSD (Mask OTSD fault report)
PIN_CONTROL1[6]   - MASK_DVDD_UV (Mask DVDD UV fault report)
PIN_CONTROL1[5]   - MASK_DVDD_OV (Mask DVDD OV fault report)
PIN_CONTROL1[4]   - MASK_CLK_FAULT (Mask clock fault report)
PIN_CONTROL1[3]   - RESERVED
PIN_CONTROL1[2]   - MASK_PVDD_UV (Mask PVDD UV fault report mask PVDD OV fault report)
PIN_CONTROL1[1]   - MASK_DC (Mask DC fault report)
PIN_CONTROL1[0]   - MASK_OC (Mask OC fault report)
*/
static const uint8_t TAS5825M_PIN_CONTROL1 = 0x74;

/*
PIN_CONTROL2 Register, Offset = 0x75, Reset = 0xF8
PIN_CONTROL2[7]   - CBC_FAULT_LATCH_EN (Enable CBC fault latch by setting this bit to 1)
PIN_CONTROL2[6]   - CBC_WARN_LATCH_EN (Enable CBC warning latch by setting this bit to 1)
PIN_CONTROL2[5]   - CLKFLT_LATCH_EN (Enable clock fault latch by setting this bit to 1)
PIN_CONTROL2[4]   - OTSD_LATCH_EN (Enable OTSD fault latch by setting this bit to 1)
PIN_CONTROL2[3]   - OTW_LATCH_EN (Enable OT warning latch by setting this bit to 1)
PIN_CONTROL2[2]   - MASK_OTW (Mask OT warning report by setting this bit to 1)
PIN_CONTROL2[1]   - MASK_CBCW (Mask CBC warning report by setting this bit to 1)
PIN_CONTROL2[0]   - MASK_CBC_FAULT (Mask CBC fault report by setting this bit to 1)
*/
static const uint8_t TAS5825M_PIN_CONTROL2 = 0x75;

/*
MISC_CONTROL Register, Offset = 0x76, Reset = 0x00
MISC_CONTROL[7]   - DET_STATUS_LATCH (0: Don't latch clock detection status, 1: Latch clock detection status)
MISC_CONTROL[6:5] - RESERVED
MISC_CONTROL[4]   - OTSD_AUTO_REC_EN (OTSD auto recovery enable)
MISC_CONTROL[3:0] - RESERVED
*/
static const uint8_t TAS5825M_MISC_CONTROL = 0x76;

/*
CBC_CONTROL Register, Offset = 0x77, Reset = 0x00
CBC_CONTROL[7:3] - RESERVED
CBC_CONTROL[2]   - CBC_EN (Enable CBC function)
CBC_CONTROL[1]   - CBC_WARN_EN (Enable CBC warning)
CBC_CONTROL[0]   - CBC_FAULT_EN (Enable CBC fault)
*/
static const uint8_t TAS5825M_CBC_CONTROL = 0x77;

/*
FAULT_CLEAR Register, Offset = 0x78, Reset = 0x00
FAULT_CLEAR[7]   - ANALOG_FAULT_CLEAR
FAULT_CLEAR[6:0] - RESERVED
*/
static const uint8_t TAS5825M_FAULT_CLEAR = 0x78;

}  // namespace tas5825m
}  // namespace esphome
