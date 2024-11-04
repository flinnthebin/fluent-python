#include "messages.h"
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

messagetype messages = messagetype::error;

auto main() -> int {
	auto framebuf_fd = open("/dev/fb0", O_RDWR);
	if (framebuf_fd == -1) {
		MSG(messagetype::error, "Error opening framebuffer.");
		return -1;
	}

	struct fb_var_screeninfo vinfo;
	if (ioctl(framebuf_fd, FBIOGET_VSCREENINFO, &vinfo)) {
		MSG(messagetype::error, "Error reading screen info.");
		close(framebuf_fd);
		return -1;
	}

	struct fb_fix_screeninfo finfo;
	if (ioctl(framebuf_fd, FBIOGET_FSCREENINFO, &finfo)) {
		MSG(messagetype::error, "Error reading fixed screen info.");
		close(framebuf_fd);
		return -1;
	}

	auto screensize = size_t{finfo.smem_len};
	auto framebuf_ptr = static_cast<unsigned char*>(mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, framebuf_fd, 0));
	if (framebuf_ptr == MAP_FAILED) {
		MSG(messagetype::error, "Error mapping framebuffer device to memory");
		close(framebuf_fd);
		return -1;
	}

	for (auto y = 0; y < vinfo.yres; ++y) {
		for (auto x = 0; x < vinfo.xres; ++x) {
			auto location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) + (y + vinfo.yoffset) * finfo.line_length;
			if (vinfo.bits_per_pixel == 32) {
				*(framebuf_ptr + location)     = x * 255 / vinfo.xres; // blue
				*(framebuf_ptr + location + 1) = y * 255 / vinfo.yres; // green
				*(framebuf_ptr + location + 2) = 0;                    // red
				*(framebuf_ptr + location + 3) = 0;                    // no transparency
			}
		}
	}

	munmap(framebuf_ptr, screensize);
	close(framebuf_fd);
	return 0;
}
