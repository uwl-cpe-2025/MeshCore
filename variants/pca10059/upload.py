import sys
import os
from os.path import basename
Import("env")

platform = env.PioPlatform()

def dfu_upload(source, target, env):
    firmware_path = str(source[0])
    firmware_name = basename(firmware_path)


    genpkg = "".join(["nrfutil nrf5sdk-tools pkg generate --application ", firmware_path, "  --hw-version 52 --sd-req 0x123 --application-version-string \"0.1.0\" firmware.zip"])
    dfupkg = "nrfutil device program --traits nordicDfu --firmware firmware.zip"
    print( genpkg )
    os.system( genpkg )
    os.system( dfupkg )

    print("Uploading done.")


# Custom upload command and program name
env.Replace(PROGNAME="firmware", UPLOADCMD=dfu_upload)