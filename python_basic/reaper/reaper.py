#!/usr/bin/python

import platform
import argparse

if __name__=="__main__":
    #check os
    plat=platform.system()

    parser=argparse.ArgumentParser(
        usage="%(prog)s[PortName|DeviceFilePath]",
        description="MTK RamDump Tool",
        epilog="Plz Don't call me")

    if plat=="Linux":
        parser.add_argument("-c","--connection", help="Path of USB Serial device file")
    else:
        print("What are you using?")
        sys.exit()

