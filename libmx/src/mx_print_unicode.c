#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char bytes[4];
    int size = 0;

    if (c < 0x80) {
        bytes[0] = (c & 0x7F) | 0x00;
        size = 1;
    }
    else if (c < 0x0800) {
        bytes[0] = ((c >> 6) & 0x1F) | 0xC0;
        bytes[1] = (c & 0x3F) | 0x80;
        size = 2;
    }
    else if (c < 0x010000) {
        bytes[0] = ((c >> 12) & 0x0F) | 0xE0;
        bytes[1] = ((c >> 6) & 0x3F) | 0x80;
        bytes[2] = (c & 0x3F) | 0x80;
        size = 3;
    }
    else {
        bytes[0] = ((c >> 18) & 0x07) | 0xF0;
        bytes[1] = ((c >> 12) & 0x3F) | 0x80;
        bytes[2] = ((c >> 6) & 0x3F) | 0x80;
        bytes[3] = (c & 0x3F) | 0x80;
        size = 4;
    }

    write(1, bytes, size);
}
