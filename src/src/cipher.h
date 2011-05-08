/* cipher.h
 *	Copyright (C) 1998, 2002, 2003 Free Software Foundation, Inc.
 *
 * This file is part of Libgcrypt.
 *
 * Libgcrypt is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser general Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * Libgcrypt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifndef G10_CIPHER_H
#define G10_CIPHER_H

#include <gcrypt.h>

#define DBG_CIPHER _gcry_get_debug_flag( 1 )

#include "../cipher/random.h"

#define PUBKEY_FLAG_NO_BLINDING (1 << 0)

/*-- rmd160.c --*/
void _gcry_rmd160_hash_buffer (void *outbuf,
                               const void *buffer, size_t length);
/*-- sha1.c --*/
void _gcry_sha1_hash_buffer (void *outbuf,
                             const void *buffer, size_t length);

/*-- dsa.c --*/
void _gcry_register_pk_dsa_progress (gcry_handler_progress_t cbc, void *cb_data);
gcry_err_code_t _gcry_dsa_generate2 (int algo, unsigned int nbits,
                                     unsigned int qbits,
                                     unsigned long dummy,
                                     gcry_mpi_t *skey,
                                     gcry_mpi_t **retfactors);

/*-- elgamal.c --*/
void _gcry_register_pk_elg_progress (gcry_handler_progress_t cb,
                                     void *cb_data);
gcry_err_code_t _gcry_elg_generate_using_x (int algo, unsigned int nbits,
                                            gcry_mpi_t x, 
                                            gcry_mpi_t *skey,
                                            gcry_mpi_t **retfactors);

/*-- ecc.c --*/
void _gcry_register_pk_ecc_progress (gcry_handler_progress_t cbc,
                                     void *cb_data);
gcry_err_code_t _gcry_ecc_generate (int algo, unsigned int nbits,
                                    const char *curve,
                                    gcry_mpi_t *skey, gcry_mpi_t **retfactors);
gcry_err_code_t _gcry_ecc_get_param (const char *name, gcry_mpi_t *pkey);


/*-- primegen.c --*/
void _gcry_register_primegen_progress (gcry_handler_progress_t cb,
                                       void *cb_data);

/*-- pubkey.c --*/
const char * _gcry_pk_aliased_algo_name (int algorithm);

/* Declarations for the cipher specifications.  */
extern gcry_cipher_spec_t _gcry_cipher_spec_blowfish;
extern gcry_cipher_spec_t _gcry_cipher_spec_des;
extern gcry_cipher_spec_t _gcry_cipher_spec_tripledes;
extern gcry_cipher_spec_t _gcry_cipher_spec_arcfour;
extern gcry_cipher_spec_t _gcry_cipher_spec_cast5;
extern gcry_cipher_spec_t _gcry_cipher_spec_aes;
extern gcry_cipher_spec_t _gcry_cipher_spec_aes192;
extern gcry_cipher_spec_t _gcry_cipher_spec_aes256;
extern gcry_cipher_spec_t _gcry_cipher_spec_twofish;
extern gcry_cipher_spec_t _gcry_cipher_spec_twofish128;
extern gcry_cipher_spec_t _gcry_cipher_spec_serpent128;
extern gcry_cipher_spec_t _gcry_cipher_spec_serpent192;
extern gcry_cipher_spec_t _gcry_cipher_spec_serpent256;
extern gcry_cipher_spec_t _gcry_cipher_spec_rfc2268_40;
extern gcry_cipher_spec_t _gcry_cipher_spec_seed;
extern gcry_cipher_spec_t _gcry_cipher_spec_camellia128;
extern gcry_cipher_spec_t _gcry_cipher_spec_camellia192;
extern gcry_cipher_spec_t _gcry_cipher_spec_camellia256;

/* Declarations for the digest specifications.  */
extern gcry_md_spec_t _gcry_digest_spec_crc32;
extern gcry_md_spec_t _gcry_digest_spec_crc32_rfc1510;
extern gcry_md_spec_t _gcry_digest_spec_crc24_rfc2440;
extern gcry_md_spec_t _gcry_digest_spec_md4;
extern gcry_md_spec_t _gcry_digest_spec_md5;
extern gcry_md_spec_t _gcry_digest_spec_rmd160;
extern gcry_md_spec_t _gcry_digest_spec_sha1;
extern gcry_md_spec_t _gcry_digest_spec_sha224;
extern gcry_md_spec_t _gcry_digest_spec_sha256;
extern gcry_md_spec_t _gcry_digest_spec_sha512;
extern gcry_md_spec_t _gcry_digest_spec_sha384;
extern gcry_md_spec_t _gcry_digest_spec_tiger;
extern gcry_md_spec_t _gcry_digest_spec_whirlpool;

/* Declarations for the pubkey cipher specifications.  */
extern gcry_pk_spec_t _gcry_pubkey_spec_rsa;
extern gcry_pk_spec_t _gcry_pubkey_spec_elg;
extern gcry_pk_spec_t _gcry_pubkey_spec_dsa;
extern gcry_pk_spec_t _gcry_pubkey_spec_ecdsa;

#endif /*G10_CIPHER_H*/
