/*
    This file is part of the ChipWhisperer Example Targets
    Copyright (C) 2012-2017 NewAE Technology Inc.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "hal.h"
#include <stdint.h>
#include <stdlib.h>

#include "simpleserial.h"

uint8_t get_key(uint8_t* k)
{
	// Load key here
	return 0x00;
}

uint8_t get_pt(uint8_t* pt)
{
	/**********************************
	* Start user-specific code here. */
	//trigger_high();

	asm volatile (
	"ldr r0,=0x01000000"       "\n\t"
	"ldr r2, =0x48000018\n\t"
	"mov r1, #0x1000\n\t"
	"ldr r3, =0x10000000\n\t"
	"str r1,[r2]\n\t"
	"ldr r4, =0x89a002\n\t"
	"ldr r5, =0xb32acc\n\t"
	"ldr r6, =0x89a002\n\t"
	"ldr r7, =0x89aa02\n\t"
	"ldr r8, =0x89a0a2\n\t"
	"ldr r9, =0x89b002\n\t"
	"ldr r10, =0x8ca002\n\t"
	"ldr r11, =0x09a002\n\t"
	"ldr r12, =0xa9a002\n\t"
	::
	);

	/*	
	asm volatile(
	"mul r0,r1" "\n\t"
	"mul r0,r2" "\n\t"
	"mul r0,r3" "\n\t"
	"mul r0,r4" "\n\t"
	"mul r0,r5" "\n\t"
	"mul r0,r6" "\n\t"
	"mul r0,r7" "\n\t"
	"mul r0,r8" "\n\t"          
	"mul r0,r9" "\n\t"
	"mul r0,r10" "\n\t"
	"mul r0,r11" "\n\t"
	"mul r0,r12" "\n\t"
	"mul r1,r2" "\n\t"
	"mul r1,r3" "\n\t"
	"mul r1,r4" "\n\t"
	"mul r1,r5" "\n\t"
	"mul r1,r6" "\n\t"
	"mul r1,r7" "\n\t"          
	"mul r1,r8" "\n\t"
	"mul r1,r9" "\n\t"
	::
	);
	*/

	/*
	asm volatile(
	"add r0,r1" "\n\t"
	"add r0,r2" "\n\t"
	"add r0,r3" "\n\t"
	"add r0,r4" "\n\t"
	"add r0,r5" "\n\t"
	"add r0,r6" "\n\t"
	"add r0,r7" "\n\t"
	"add r0,r8" "\n\t"
	"add r0,r9" "\n\t"
	"add r0,r10" "\n\t"
	"add r0,r11" "\n\t"
	"add r0,r12" "\n\t"
	"add r1,r2" "\n\t"
	"add r1,r3" "\n\t"
	"add r1,r4" "\n\t"
	"add r1,r5" "\n\t"
	"add r1,r6" "\n\t"
	"add r1,r7" "\n\t"
	"add r1,r8" "\n\t"
	"add r1,r9" "\n\t"
	::
	);
	*/

	//trigger_low();
	
	asm volatile (
	"str r3,[r2]\n\t"
	::
	);

	/* End user-specific code here. *
	********************************/
	simpleserial_put('r', 16, pt);
	return 0x00;
}

uint8_t reset(uint8_t* x)
{
	// Reset key here if needed
	return 0x00;
}

int main(void)
{
    platform_init();
	init_uart();	
	trigger_setup();
	
 	/* Uncomment this to get a HELLO message for debug */
	/*
	putch('h');
	putch('e');
	putch('l');
	putch('l');
	putch('o');
	putch('\n');
	*/
		
	simpleserial_init();		
	simpleserial_addcmd('k', 16, get_key);
	simpleserial_addcmd('p', 16, get_pt);
	simpleserial_addcmd('x', 0, reset);
	while(1)
		simpleserial_get();
}
