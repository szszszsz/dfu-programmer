//
// Created by sz on 25.02.18.
//
#include "lib_implementation.h"

#include "commands.h"

int debug;
#ifdef HAVE_LIBUSB_1_0
libusb_context *usbcontext;
#endif

dfu_device_t dfu_device;
#ifdef HAVE_LIBUSB_1_0
  struct libusb_device *device = NULL;
#else
  struct usb_device *device = NULL;
#endif

int init_device(const uint32_t vendor,
                 const uint32_t product,
                 const uint32_t bus_number,
                 const uint32_t device_address,
                 dfu_device_t *dfu_device,
                 const dfu_bool initial_abort,
                 const dfu_bool honor_interfaceclass){
  device = dfu_device_init( vendor, product,
                            bus_number, device_address,
                            dfu_device,
                            initial_abort,
                            honor_interfaceclass);
  return device != NULL;
}

int init_short_usbaddr(const uint32_t bus_number,
               const uint32_t device_address){
  return init_device(
      0x20a0, 0x4108, bus_number, device_address, &dfu_device,
      0, 0
  );
}

int init_short(){
  return init_device(0x2FF1, 0x03eb, 0, 0, &dfu_device, 0, 0);
}

int close_device(){
  int rv;
#ifdef HAVE_LIBUSB_1_0
  rv = libusb_release_interface( dfu_device.handle, dfu_device.interface );
#else
  rv = usb_release_interface( dfu_device.handle, dfu_device.interface );
#endif

  if( NULL != dfu_device.handle ) {
#ifdef HAVE_LIBUSB_1_0
    libusb_close(dfu_device.handle);
#else
    if( 0 != usb_close(dfu_device.handle) ) {
            fprintf( stderr, "%s: failed to close the handle.\n", progname );
            retval = DEVICE_ACCESS_ERROR;
        }
#endif


#ifdef HAVE_LIBUSB_1_0
    libusb_exit(usbcontext);
#endif

  }

  return rv;
}

void erase(){
  return;
}

void flash(){
  return;
}

struct programmer_arguments args;

char *argv[] = {"name\0", "at32uc3a3256s\0","launch\0"};

void init_args(){
  parse_arguments(&args, 3, argv);
}

void init_usb(){
#ifdef HAVE_LIBUSB_1_0
  if (libusb_init(&usbcontext)) {
    fprintf( stderr, "%s: can't init libusb.\n", "lib" );
    return; // DEVICE_ACCESS_ERROR;
  }
#else
  usb_init();
#endif
}

void launch(){
  init_args();
  init_usb();

  if(!init_short()){
    printf("error\n");
    close_device();
    return;
  }

  execute_launch(&dfu_device, &args);

  close_device();
  return;
}