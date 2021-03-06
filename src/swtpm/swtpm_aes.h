/*
 * swtpm_aes.h
 *
 * Author: Stefan Berger stefanb@us.ibm.com
 *
 *
 * (c) Copyright IBM Corporation 2014.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * Neither the names of the IBM Corporation nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SWTPM_AES_H_
#define _SWTPM_AES_H_

#include <libtpms/tpm_types.h>

#define TPM_AES_BLOCK_SIZE 16

typedef struct tdTPM_SYMMETRIC_KEY_DATA {
    TPM_TAG tag;
    TPM_BOOL valid;
    TPM_BOOL fill;
    unsigned char userKey[TPM_AES_BLOCK_SIZE];
} TPM_SYMMETRIC_KEY_DATA;

TPM_RESULT TPM_SymmetricKeyData_Encrypt(unsigned char **encrypt_data,
                                        uint32_t *encrypt_length,
                                        const unsigned char *decrypt_data,
                                        uint32_t decrypt_length,
                                        const TPM_SYMMETRIC_KEY_DATA
					*tpm_symmetric_key_token);

TPM_RESULT TPM_SymmetricKeyData_Decrypt(unsigned char **decrypt_data,
                                        uint32_t *decrypt_length,
                                        const unsigned char *encrypt_data,
                                        uint32_t encrypt_length,
                                        const TPM_SYMMETRIC_KEY_DATA
					*tpm_symmetric_key_token);

#endif /* _SWTPM_AES_H_ */

