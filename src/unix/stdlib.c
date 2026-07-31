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

#include "p101_random/random.h"
#include <p101_env/wrapper.h>
#include <stdlib.h>
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
