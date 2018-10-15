/* This AES-128 comes from Galois and is synthesized from Haskell */

#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

#ifndef AES_CONST_VAR
//#define AES_CONST_VAR static const
#define AES_CONST_VAR
#endif

/*
void GALOIS_AES128_setkey(uint8_t *key);
void GALOIS_AES128_blockencrypt(uint8_t* pt, uint8_t* key, uint8_t *ct);
*/

void GALOIS_AES128_setkey(uint32_t *key);
void GALOIS_AES128_blockencrypt_orig(uint32_t* pt, uint32_t* key, uint32_t *ct);
//void GALOIS_AES128_blockencrypt(uint32_t* pt);

#endif //_AES_H_
