#ifndef MATRIX_H
#define MATRIX_H

#ifdef __STDC__
        #define PREDEF_STANDARD_C89
        #ifdef __STDC_VERSION__
                #if __STDC_VERSION__ >= 199901L
                        #define PREDEF_STANDARD_C99
                        #if __STDC_VERSION__ >= 201112L
                                #define PREDEF_STANDARD_C11
                        #endif
                #endif
        #endif
#endif

#ifdef _MSC_VER
        #define __INLINE __forceinline
#else
        #define __INLINE inline __attribute((always_inline))
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define __EXTERN_INLINE extern __INLINE
#else
        #undef __INLINE

        #define __INLINE
        #define __EXTERN_INLINE
#endif

void matrix_get_blocks_count(size_t *size);
void matrix_set_blocks_count(size_t size);
void matrix_get_block_size(size_t *size);
void matrix_set_block_size(size_t size);
void matrix_init(double *S);
void matrix_printf(double *S);
void matrix_triangular_init(double *S);
void matrix_triangular_printf(double *S);

#endif
