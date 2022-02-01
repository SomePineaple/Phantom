//
// Created by somepineaple on 1/31/22.
//

#include "XUtils.h"

#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>

XDeviceInfo* XUtils::findDeviceInfo(Display *display, char *name, bool only_extended) {
    XDeviceInfo	*devices;
    XDeviceInfo *found = nullptr;
    int		loop;
    int		num_devices;
    int		len = (int) strlen(name);
    bool	is_id = true;
    XID		id = (XID)-1;

    for(loop=0; loop<len; loop++) {
        if (!isdigit(name[loop])) {
            is_id = false;
            break;
        }
    }

    if (is_id) {
        id = atoi(name);
    }

    devices = XListInputDevices(display, &num_devices);

    for(loop=0; loop<num_devices; loop++) {
        if ((!only_extended || (devices[loop].use >= IsXExtensionDevice)) &&
            ((!is_id && strcmp(devices[loop].name, name) == 0) ||
             (is_id && devices[loop].id == id))) {
            if (found) {
                fprintf(stderr,
                        "Warning: There are multiple devices named '%s'.\n"
                        "To ensure the correct one is selected, please use "
                        "the device ID instead.\n\n", name);
                return nullptr;
            } else {
                found = &devices[loop];
            }
        }
    }
    return found;
}
