# Copyright (C) 2026 Ben Zignego
# Copyright (C) 2026 Josiah VanderZee
# Copyright (C) 2026 Valliamai Arunachalam

import sys
import os
from os.path import basename

Import("env")

platform = env.PioPlatform()

def dfu_upload(source, target, env):
    firmware_path = source[0]


    genpkg = "nrfutil nrf5sdk-tools pkg generate " \
                + f"--application {firmware_path} " \
                + "--hw-version 52 " \
                + "--sd-req 0x123 " \
                + "--application-version-string \"0.1.0\" " \
                + "firmware.zip"

    dfupkg = "nrfutil device program " \
                + "--traits nordicDfu " \
                + "--firmware firmware.zip" \

    print(genpkg)
    os.system(genpkg)
    print(dfupkg)
    os.system(dfupkg)

    print("Uploading done.")

env.Replace(PROGNAME="firmware", UPLOADCMD=dfu_upload)
