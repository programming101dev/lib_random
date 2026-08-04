#include "p101_random/random.h"
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
