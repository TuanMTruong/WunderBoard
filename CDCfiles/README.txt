/**************************************************/
// These files are used in the new 2013 fall update for the wunderboard with the new CDCbootloader
// The Makefile has been tuned for linux and the PORT variable needs to be changed if on a different OS.
// The inf file is the windows drive for the CDC bootloader. Recommend installing the driver before doing any programing.
//The BootloaderCDC.hex is the the booloader and can be loaded to a wunderboard with the Makefile "sudo make CDCbootloader" command.
// avrdude 5.11 or higher is needed for programming
// an atmel programmer is need to flash the bootloader.
