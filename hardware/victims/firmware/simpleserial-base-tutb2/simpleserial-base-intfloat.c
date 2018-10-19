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

int a,b,c,d,e,f,g,h,i,j;
float k,l,m,n,o,p,q,r,s,t;

uint8_t get_key(uint8_t* k)
{
	// Load key here
	return 0x00;
}

uint8_t get_pt(uint8_t* pt)
{
	/**********************************
	* Start user-specific code here. */
	trigger_high();

	/*
	asm volatile (
	"ldr r0,=0x01000000"       "\n\t"
	"ldr r2, =0x48000018\n\t"
	"mov r1, #0x1000\n\t"
	"ldr r3, =0x10000000\n\t"
	"str r1,[r2]\n\t"
	::
	);
	*/	

	//16 hex bytes held in 'pt' were sent
	//from the computer. Store your response
	//back into 'pt', which will send 16 bytes
	//back to computer. Can ignore of course if
	//not needed

	a = 1+1;
	b = 10 + 10;
	c = 100 + 100;
	d = 1000 + 1000;
	e = 62 + 32;
	f = 89 + 75;
	g = 53 + 23;
	h = 83 + 91;
	i = 92 + 43;
	j = 48 + 58;

	k = 1.1 +1.1;
	l = 10.1 + 10.1;
	m = 100.1 + 100.1;
	n = 1000.1 + 1000.1;
	o = 62.63 + 32.32;
	p = 89.89 + 75.75;
	q = 53.53 + 23.23;
	r = 83.83 + 91.91;
	s = 92.92 + 43.42;
	t = 48.48 + 58.58;
	
	return a;
	return b;
	return c;
	return d;
	return e;
	return f;
	return g;
	return h;
	return i;
	return j;
	return k;
	return l;
	return m;
	return n;
	return o;
	return p;
	return q;
	return r;
	return s;
	return t;


	/*
	asm volatile(
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	"add r0,r1" "\n\t"
	::
	);
	
	asm volatile(
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"          
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"          
	"mul r0,r1" "\n\t"
	"mul r0,r1" "\n\t"
	::
	);
	*/
	/*asm volatile(
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	"nop"       "\n\t"
	::
	);*/
	trigger_low();
	
	/*
	asm volatile (
	"str r3,[r2]\n\t"
	::
	);
	*/

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
