## BCM2835
The info for all hardware stuff is below. Also, most of this also works for BCM2835 and up. Specifically, this board is for raspberry pi 1. Please note, you may have to change some of the memory locations defined for the code to work on hardware. This was tested on QEMU, which is highly inaccurate. Other ARM stuff is also up for change to make it work on real hardware. Early versions of the raspberry pi do not seem to have much support nowadays.

## Resources
- Framebuffer: [https://elinux.org/RPi_Framebuffer](https://elinux.org/RPi_Framebuffer)
- Resolution Info: [https://en.wikipedia.org/wiki/VideoCore#Table_of_SoCs_adopting_VideoCore_SIP_blocks](https://en.wikipedia.org/wiki/VideoCore#Table_of_SoCs_adopting_VideoCore_SIP_blocks)
- Kernel Start Address: [https://www.raspberrypi.com/documentation/computers/legacy_config_txt.html#kernel_address](https://www.raspberrypi.com/documentation/computers/legacy_config_txt.html#kernel_address)
- BCM2835 Specs: [https://www.raspberrypi.com/documentation/computers/processors.html#bcm2835](https://www.raspberrypi.com/documentation/computers/processors.html#bcm2835)
- ARMv7 A53 Instruction Ref: [https://developer.arm.com/documentation/ddi0406/c/Application-Level-Architecture/Instruction-Details/Alphabetical-list-of-instructions/ADC--immediate-](https://developer.arm.com/documentation/ddi0406/c/Application-Level-Architecture/Instruction-Details/Alphabetical-list-of-instructions/ADC--immediate-)
- ARM GNU Toolchain: [https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
