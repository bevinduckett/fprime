module Va416x0 {

    @ Constant defining the number of APIO pins used as discretes (REU+CHIC use 66 pins on Apio devices)
    constant NUM_APIO_DISCRETES = 66

    @ Constant defining the high watermark number of discretes on any one board
    constant MAX_NUM_DISCRETES = 73 # REU has the high watermark

    # This enumeration contains important comments used by the ground channel
    # dictionary generation script (cmake/scripts/build_ground_dictionaries.py)
    # The card names heading each discrete section are used to generated card-specific
    # dictionaries.  The comment behind each discrete is used to assign that discrete
    # to the appropriate ground dictionaries.  Please maintain this format when adding
    # new discretes.
    @ Discretes List for ATC, REU, and PBC per Rev. B Schematics (includes Moonfall & Skyfall discretes)
    enum DiscreteName : U8 {   # Board, Direction, Location
        # ATC
        XS_SWD_ENA_VOTE  # ATC, OUTPUT, GPIO
        XS_HK_INH_VOTE  # ATC, OUTPUT, GPIO
        TEST_PWR_OFF_WARN # ATC, INPUT, GPIO
        TEST_UC_SPARE1  # ATC, INPUT, GPIO
        TEST_UC_SPARE2  # ATC, INPUT, GPIO

        # REU
        BOOT_PROG_XS_IN1  # REU, INPUT, APIO
        BOOT_PROG_XS_IN2  # REU, INPUT, APIO
        BOOT_PROG_XS_IN3  # REU, INPUT, APIO
        VOTE_OUT1_XREU_HK  # REU, OUTPUT, APIO
        VOTE_OUT2_XREU_SWD  # REU, OUTPUT, APIO
        VOTE_OUT3_ATC1_HK  # REU, OUTPUT, APIO
        VOTE_OUT4_ATC1_SWD  # REU, OUTPUT, APIO
        VOTE_OUT5_ATC2_HK  # REU, OUTPUT, APIO
        VOTE_OUT6_ATC2_SWD  # REU, OUTPUT, APIO
        VOTE_OUT7_ATC3_HK  # REU, OUTPUT, APIO
        VOTE_OUT8_ATC3_SWD  # REU, OUTPUT, APIO
        VOTE_OUT9_ATC4_HK  # REU, OUTPUT, APIO
        VOTE_OUT10_ATC4_SWD  # REU, OUTPUT, APIO
        TEST_PWR_OFF_ADV_NOTICE  # REU, INPUT, GPIO
        TEST_PBC_UV  # REU, INPUT, APIO
        TEST_MRAM_ZZ  # REU, OUTPUT, GPIO
        TEST_MRAM_WP0  # REU, OUTPUT, APIO
        TEST_MRAM_WP1  # REU, OUTPUT, APIO
        IOE1_DISC_1 # REU, INPUT, APIO
        IOE1_DISC_2 # REU, INPUT, APIO
        IOE1_DISC_3 # REU, INPUT, APIO
        IOE1_DISC_4 # REU, INPUT, APIO
        IOE1_DISC_5 # REU, INPUT, APIO
        IOE1_DISC_6 # REU, INPUT, APIO
        IOE1_DISC_7 # REU, INPUT, APIO
        IOE1_DISC_8 # REU, INPUT, APIO
        IOE1_DISC_9 # REU, OUTPUT, APIO
        IOE1_DISC_10 # REU, OUTPUT, APIO
        IOE1_DISC_11 # REU, OUTPUT, APIO
        IOE1_DISC_12 # REU, OUTPUT, APIO
        IOE1_DISC_13 # REU, INPUT, APIO
        IOE1_DISC_14 # REU, INPUT, APIO
        IOE1_DISC_15 # REU, INPUT, APIO
        IOE1_DISC_16 # REU, INPUT, APIO
        IOE2_DISC_1 # REU, INPUT, APIO
        IOE2_DISC_2 # REU, INPUT, APIO
        IOE2_DISC_3 # REU, INPUT, APIO
        IOE2_DISC_4 # REU, INPUT, APIO
        IOE2_DISC_5 # REU, INPUT, APIO
        IOE2_DISC_6 # REU, INPUT, APIO
        IOE2_DISC_7 # REU, INPUT, APIO
        IOE2_DISC_8 # REU, INPUT, APIO
        IOE2_DISC_9 # REU, OUTPUT, APIO
        IOE2_DISC_10 # REU, OUTPUT, APIO
        IOE2_DISC_11 # REU, OUTPUT, APIO
        IOE2_DISC_12 # REU, OUTPUT, APIO
        IOE2_DISC_13 # REU, INPUT, APIO
        EN_CUT_3V3_2 # REU, OUTPUT, APIO
        EN_CUT_3V3_1 # REU, OUTPUT, APIO
        PFA_RSB_CMD_INH # REU, OUTPUT, APIO
        IOE3_DISC_1 # REU, INPUT, APIO
        IOE3_DISC_2 # REU, INPUT, APIO
        IOE3_DISC_3 # REU, INPUT, APIO
        IOE3_DISC_4 # REU, INPUT, APIO
        IOE3_DISC_5 # REU, INPUT, APIO
        IOE3_DISC_6 # REU, INPUT, APIO
        IOE3_DISC_7 # REU, INPUT, APIO
        IOE3_DISC_8 # REU, INPUT, APIO
        IOE3_DISC_9 # REU, OUTPUT, APIO
        IOE3_DISC_10 # REU, OUTPUT, APIO
        IOE3_DISC_11 # REU, OUTPUT, APIO
        IOE3_DISC_12 # REU, OUTPUT, APIO
        IOE3_DISC_13 # REU, INPUT, APIO
        IOE3_DISC_14 # REU, INPUT, APIO
        IOE3_DISC_15 # REU, INPUT, APIO
        IOE3_DISC_16 # REU, INPUT, APIO

        #PBC
        MCU_BW_STAT_A1  # PBC, INPUT, GPIO
        MCU_BW_STAT_A2  # PBC, INPUT, GPIO
        MCU_BW_STAT_B1  # PBC, INPUT, GPIO
        MCU_BW_STAT_B2  # PBC, INPUT, GPIO
        MCU_UV_TRIPn  # PBC, INPUT, GPIO
        PBC_HK_INH_X_OUT  # PBC, OUTPUT, GPIO
        PBC_HK_INH_Y_OUT  # PBC, OUTPUT, GPIO
        PBC_X_SWD_OEn_OUTn  # PBC, OUTPUT, GPIO 
        PBC_Y_SWD_OEn_OUTn  # PBC, OUTPUT, GPIO
        IGNORE_CRC  # PBC, OUTPUT, APIO
        CHIC_INH_1  # PBC, OUTPUT, GPIO
        CHIC_INH_2  # PBC, OUTPUT, GPIO
        MCU_BLIS_UMB_BDIS_OVRD  # PBC, OUTPUT, GPIO
        MCU_BLIS_LOW_V_BDIS_OVRD  # PBC, OUTPUT, GPIO
        MCU_BW_RELEASE  # PBC, OUTPUT, GPIO
        MCU_PYRO_CMD_X  # PBC, OUTPUT, GPIO
        MCU_PYRO_CMD_Y  # PBC, OUTPUT, GPIO
        MCU_PYRO_CMD_Z  # PBC, OUTPUT, GPIO
        PBC_SELF_SWD_IN_OEn  # PBC, OUTPUT, GPIO
        TEST_HPCC_PRE_PWR_OFF  # PBC, INPUT, GPIO
        DEADFACE_ENn        # PBC, OUTPUT, APIO
        ABIS_EN             # PBC, OUTPUT, APIO
        PROT_SW_INH1_B1_PBC # PBC, OUTPUT, APIO
        PROT_SW_INH2_B1_PBC # PBC, OUTPUT, APIO
        PROT_SW_INH1_B2_PBC # PBC, OUTPUT, APIO
        PROT_SW_INH2_B2_PBC # PBC, OUTPUT, APIO

        BOOT_PROG_IN1  # ATC/PBC, INPUT, GPIO/APIO
        BOOT_PROG_IN2  # ATC/PBC, INPUT, GPIO/APIO
        BOOT_PROG_IN3  # ATC/PBC, INPUT, GPIO/APIO
        TEST_BOOT_PROG_OUT1  # ATC/REU/PBC, OUTPUT, GPIO
        TEST_BOOT_PROG_OUT2  # ATC/REU/PBC, OUTPUT, GPIO
        TEST_BOOT_PROG_OUT3  # ATC/REU/PBC, OUTPUT, GPIO
        TEST_WARM_RSTn  # ATC/REU/PBC, OUTPUT, GPIO
        TEST_FRAM_ZZ  # ATC/REU/PBC/PDH/PDP/JELI, OUTPUT, GPIO
        TEST_SPARE_IO_1  # REU/PBC, INPUT, APIO
        TEST_SPARE_IO_2  # REU/PBC, INPUT, APIO

        # JELI
        # PDH
        # PDP
        # REC
        LED_INDICATOR # JELI/PDH/PDP/REC, OUTPUT, GPIO
        BOOT_BANKSEL # JELI/PDH/PDP/REC, INPUT, APIO

        NUM_TOTAL_DISCRETES
    }
}