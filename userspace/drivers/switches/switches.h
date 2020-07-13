#ifndef __SWITCHES_H
#define __SWITCHES_H

#include <stdbool.h>
#include <stdint.h>

#define SWITCHES_SUCCESS 0  // value of an success
#define SWITCHES_0_MASK 0x1 // The mask for button zero
#define SWITCHES_1_MASK 0x2 // The mask for button one
#define SWITCHES_ALL_MASK 0x3
#define SWITCHES_CNT 2

// Initialize the driver
//  devFilePath: The file path to the uio dev file
//  Return: An error code on error, BUTTONS_SUCCESS otherwise
// This must be called before calling any other buttons_* functions
int32_t switches_init(char *devFilePath);

// Return the current state of the switches
uint8_t switches_read();

// Call this on exit to clean up
void switches_exit();

// Enable GPIO interrupt output
void switches_enable_interrupts();

// Disable GPIO interrupt output
void switches_disable_interrupts();

// Return whether an interrupt is pending
bool switches_interrupt_pending();

// Acknowledge a pending interrupt
void switches_ack_interrupt();

#endif /* __SWITCHES_H */