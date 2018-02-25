//
// Created by sz on 25.02.18.
//

#ifndef DFU_PROGRAMMER_LIB_IMPLEMENTATION_H
#define DFU_PROGRAMMER_LIB_IMPLEMENTATION_H

#if HAVE_CONFIG_H
# include "config.h"
#endif
#include <stdio.h>
#include <string.h>
#ifdef HAVE_LIBUSB_1_0
#include <libusb.h>
#else
#include <usb.h>
#endif

#include "config.h"
#include "dfu-device.h"
#include "dfu.h"
#include "atmel.h"
#include "arguments.h"
#include "commands.h"

extern int debug;
#ifdef HAVE_LIBUSB_1_0
extern libusb_context *usbcontext;
#endif


void erase();
void flash();
void launch();


#endif //DFU_PROGRAMMER_LIB_IMPLEMENTATION_H
