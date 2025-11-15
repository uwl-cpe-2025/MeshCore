#!/bin/sh

BUILD_DIR=.pio/build/uwl_capstone

nrfutil nrf5sdk-tools pkg generate --application "${BUILD_DIR}/firmware.hex" --hw-version 52 --sd-req 0x123 --application-version-string "0.1.0" .pio/build/uwl_capstone/firmware.zip

nrfutil device program --traits nordicDfu --firmware "${BUILD_DIR}/firmware.zip"
