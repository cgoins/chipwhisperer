/* Christine Goins 10/11/18
   Testing to see whether outputs of 
   aes.c and aes_orig.c match
*/

#include <stdio.h>
#include <inttypes.h>
#include "aes.h"
#include "aes_orig.h"

uint32_t key[4] = {
	0x2b7e1516UL, 0x28aed2a6UL, 0xabf71588UL, 0x09cf4f3cUL
};

uint32_t pt[4] = {
	0xa66530f9, 0xc310ee11, 0xd0eb3c0a, 0xef7280f3
};

uint32_t ct_exp[4] = {
	0x011812a9, 0xd99f06d1, 0xc58640f3, 0x26b54ef1
};

uint32_t ct[4];

main() {
	FILE *fp;
	
	fp = fopen("test.txt", "w");

	// print key, plaintext, expected cipher (all defined above)	
	int i;
	for (i = 0; i <4; i++) 
		fprintf(fp, "Key: %32" PRIx32 "UL\n", key[i]); 
	for (i = 0; i <4; i++) 
		fprintf(fp, "Plaintext: %32" PRIx32 "\n", pt[i]);
	for (i = 0; i <4; i++) 
		fprintf(fp, "Expected ciphertext: %32" PRIx32 "\n", ct_exp[i]);

	// original function

	
	GALOIS_AES128_blockencrypt_orig(pt, key, ct);
	
	for (i = 0; i <4; i++) 
		fprintf(fp, "Ciphertext from original: %32" PRIx32 "\n", ct[i]);	

	// modified function
	GALOIS_AES128_setkey(key);

	GALOIS_AES128_blockencrypt(pt);	

	for (i = 0; i <4; i++) 
		fprintf(fp, "Ciphertext from modified: %32" PRIx32 "\n", pt[i]);	
}
