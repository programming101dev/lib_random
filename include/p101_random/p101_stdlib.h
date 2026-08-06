#ifndef LIBP101_RANDOM_P101_STDLIB_H
#define LIBP101_RANDOM_P101_STDLIB_H

/*
 * Copyright 2026 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBP101_RANDOM_SHARED_DECLARATIONS
    #define LIBP101_RANDOM_SHARED_DECLARATIONS
    #include <inttypes.h>
    #include <p101_env/env.h>
    #include <p101_error/attributes.h>
    #include <stddef.h>
#endif    // LIBP101_RANDOM_SHARED_DECLARATIONS

#ifdef __cplusplus
extern "C"
{
#endif

    uint32_t        p101_arc4random(const struct p101_env *env);
    void            p101_arc4random_buf(const struct p101_env *env, void *buf, size_t nbytes);
    uint32_t        p101_arc4random_uniform(const struct p101_env *env, uint32_t upper_bound);
    char           *p101_initstate(const struct p101_env *env, struct p101_error *err, unsigned seed, char *state, size_t size);
    unsigned short *p101_seed48(const struct p101_env *env, unsigned short seed16v[3]);
    char           *p101_setstate(const struct p101_env *env, struct p101_error *err, char *state);
    void            p101_srand48(const struct p101_env *env, long seedval);
    void            p101_srandom(const struct p101_env *env, unsigned seed);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_RANDOM_P101_STDLIB_H
