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

#include "p101_random/p101_stdlib.h"
#include <p101_c/p101_string.h>
#include <p101_env/wrapper.h>
#include <stdlib.h>
#include <string.h>

char *p101_initstate(const struct p101_env *env, struct p101_error *err, unsigned seed, char *state, size_t size)
{
    char *ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, NULL);
    errno   = 0;
    ret_val = initstate(seed, state, size);

    if(ret_val == NULL)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else
        {
            P101_ERROR_RAISE_ERRNO(err, EINVAL);
        }
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

unsigned short *p101_seed48(const struct p101_env *env, unsigned short seed16v[3])    // cppcheck-suppress constParameter
{
    unsigned short *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = seed48(seed16v);

    P101_TRACE_EXIT(env);
    return ret_val;
}

char *p101_setstate(const struct p101_env *env, struct p101_error *err, char *state)
{
    char *ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, NULL);
    errno   = 0;
    ret_val = setstate(state);

    if(ret_val == NULL)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else
        {
            P101_ERROR_RAISE_ERRNO(err, EINVAL);
        }
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

void p101_srand48(const struct p101_env *env, long seedval)
{
    P101_TRACE(env);
    errno = 0;
    srand48(seedval);
    P101_TRACE_EXIT(env);
}

void p101_srandom(const struct p101_env *env, unsigned seed)
{
    P101_TRACE(env);
    errno = 0;
    srandom(seed);
    P101_TRACE_EXIT(env);
}

/*
 * Copyright 2022-2024 D'Arcy Smith.
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

#ifdef __has_include
    #if __has_include("bsd/stdlib.h")
        #include <bsd/stdlib.h>
    #endif
#endif
uint32_t p101_arc4random(const struct p101_env *env)
{
    uint32_t ret_val;

    P101_TRACE(env);
    ret_val = arc4random();

    P101_TRACE_EXIT(env);
    return ret_val;
}

void p101_arc4random_buf(const struct p101_env *env, void *buf, size_t nbytes)
{
    P101_TRACE(env);
    arc4random_buf(buf, nbytes);
    P101_TRACE_EXIT(env);
}

uint32_t p101_arc4random_uniform(const struct p101_env *env, uint32_t upper_bound)
{
    uint32_t ret_val;

    P101_TRACE(env);
    ret_val = arc4random_uniform(upper_bound);

    P101_TRACE_EXIT(env);
    return ret_val;
}
