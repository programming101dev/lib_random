#include <p101_env/env.h>
#include <p101_error/error.h>
#include <p101_random/p101_stdlib.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;
    unsigned short     seed[3] = {1, 2, 3};
    unsigned char      bytes[16];
    unsigned short    *old_seed;
    uint32_t           random_value;

    err = p101_error_create(false);
    if(err == NULL)
    {
        return EXIT_FAILURE;
    }
    env = p101_env_create(err, NULL);
    if(env == NULL)
    {
        p101_error_destroy(err);
        return EXIT_FAILURE;
    }

    /* P101_TEST_CASE(p101_arc4random) */
    random_value = p101_arc4random(env);
    (void)random_value;
    /* P101_TEST_CASE(p101_arc4random_buf) */
    p101_arc4random_buf(env, bytes, sizeof(bytes));
    /* P101_TEST_CASE(p101_arc4random_uniform) */
    if(p101_arc4random_uniform(env, 1) != 0)
    {
        return EXIT_FAILURE;
    }

    /* P101_TEST_CASE(p101_seed48) */
    old_seed = p101_seed48(env, seed);
    if(old_seed == NULL)
    {
        return EXIT_FAILURE;
    }
    /* P101_TEST_CASE(p101_srand48) */
    p101_srand48(env, 1234L);
    /* P101_TEST_CASE(p101_srandom) */
    p101_srandom(env, 1234U);

    p101_env_destroy(env);
    p101_error_destroy(err);
    return EXIT_SUCCESS;
}
