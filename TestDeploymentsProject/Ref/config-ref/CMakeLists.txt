####
# config-scythe/CMakeLists.txt:
#
# Sets a list of source files for cmake to process as part of autocoding.
####

register_fprime_config(
        config-ref
    AUTOCODER_INPUTS
        "${CMAKE_CURRENT_LIST_DIR}/Discretes.fpp"
    CONFIGURATION_OVERRIDES
        "${CMAKE_CURRENT_LIST_DIR}/AcConstants.fpp"
        "${CMAKE_CURRENT_LIST_DIR}/FpConfig.fpp"
    CHOOSES_IMPLEMENTATIONS
        "${CONSOLE_IMPLEMENTATION}"
)
