/*
 * dfu-programmer
 *
 * $Id$
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include <stdint.h>
#include "arguments.h"
#include "dfu-device.h"

int32_t execute_command( dfu_device_t *device,
                         struct programmer_arguments *args );
int32_t execute_launch( dfu_device_t *device,
                               struct programmer_arguments *args );
int32_t execute_erase( dfu_device_t *device,
                              struct programmer_arguments *args );
int32_t execute_flash( dfu_device_t *device,
                              struct programmer_arguments *args );

#endif
