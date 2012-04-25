/* gmp-entries.h: header private to gmp-plugin.c.
   C macros as IDL for libgmp.

   Copyright(C) 2012 John Tobey, see ../LICENCE

   TO DO:

   MAYBE TO DO:
      mpz_inits
      mpz_clears
      mpz_import - what would it do?
      mpz_export - what would it do?
      mpq_inits
      mpq_clears
      mpf_inits
      mpf_clears
      mpz_out_str
      mpz_inp_str
      mpz_out_raw
      mpz_inp_raw
      mpq_out_str
      mpq_inp_str
      mpf_out_str
      mpf_inp_str
      gmp_randinit - obsolete

   NOT TO DO:
      mpz_get_str - use toString method
      mpz_fits_uint_p
      mpz_fits_sint_p
      mpz_fits_ushort_p
      mpz_fits_sshort_p
      mpz_array_init
      mpq_get_str - use toString method
      mpf_fits_uint_p
      mpf_fits_sint_p
      mpf_fits_ushort_p
      mpf_fits_sshort_p
      mpn* - probably not
      gmp_*printf - possibly with libffi
      gmp_*scanf - possibly with libffi
      BSD compatibility functions - probably not
      mp_set_memory_functions - C-specific
      mp_get_memory_functions - C-specific

   DONE: every remaining function and macro in the GMP v5.0.4 manual.
*/

#ifndef ENTRY
# define ENTRY(__nargs, __nret, __string, __id)
#endif

#ifndef ENTRY1R1
# define ENTRY0R1(__name, __string, __id, __r0) ENTRY (0, 1, __string, __id)
# define ENTRY1R0(__name, __string, __id, __t0) ENTRY (1, 0, __string, __id)
# define ENTRY1R1(__name, __string, __id, __r0, __t0) \
    ENTRY (1, 1, __string, __id)
# define ENTRY1R2(__name, __string, __id, __r0, __r1, __t0) \
    ENTRY (1, 2, __string, __id)
# define ENTRY2R0(__name, __string, __id, __t0, __t1) \
    ENTRY (2, 0, __string, __id)
# define ENTRY2R1(__name, __string, __id, __r0, __t0, __t1) \
    ENTRY (2, 1, __string, __id)
# define ENTRY3R0(__name, __string, __id, __t0, __t1, __t2) \
    ENTRY (3, 0, __string, __id)
# define ENTRY3R1(__name, __string, __id, __r0, __t0, __t1, __t2) \
    ENTRY (3, 1, __string, __id)
# define ENTRY3R2(__name, __string, __id, __r0, __r1, __t0, __t1, __t2) \
    ENTRY (3, 2, __string, __id)
# define ENTRY4R0(__name, __string, __id, __t0, __t1, __t2, __t3) \
    ENTRY (4, 0, __string, __id)
# define ENTRY4R1(__name, __string, __id, __r0, __t0, __t1, __t2, __t3) \
    ENTRY (4, 1, __string, __id)
# define ENTRY5R0(__name, __string, __id, __t0, __t1, __t2, __t3, __t4) \
    ENTRY (5, 0, __string, __id)
#endif

// http://gmplib.org/manual/Integer-Functions.html

#if ENTRY_FIRST
(__LINE__ + 2)
#endif
ENTRY1R1 (mpz_init, "mpz", np_mpz, new_mpz, new_mpz)
ENTRY1R0 (mpz_init, "mpz_init", np_mpz_init, uninit_mpz)
#if NPGMP_PORTING
// mpz_inits: unimplemented.
#endif
ENTRY2R0 (mpz_init2, "mpz_init2", np_mpz_init2, uninit_mpz, mp_bitcnt_t)
#if NPGMP_PORTING
// mpz_clear: called automatically.  Dummy version:
ENTRY1R0 (mpz_init, "mpz_clear", np_mpz_clear, uninit_mpz)
// mpz_clears: unimplemented.
#endif
ENTRY2R0 (mpz_realloc2, "mpz_realloc2", np_mpz_realloc2, mpz_ptr, mp_bitcnt_t)
ENTRY2R0 (mpz_set, "mpz_set", np_mpz_set, mpz_ptr, mpz_ptr)
ENTRY2R0 (mpz_set_ui, "mpz_set_ui", np_mpz_set_ui, mpz_ptr, ulong)
ENTRY2R0 (mpz_set_si, "mpz_set_si", np_mpz_set_si, mpz_ptr, long)
ENTRY2R0 (mpz_set_d, "mpz_set_d", np_mpz_set_d, mpz_ptr, double)
#if NPGMP_MPQ
ENTRY2R0 (mpz_set_q, "mpz_set_q", np_mpz_set_q, mpz_ptr, mpq_ptr)
#endif
#if NPGMP_MPF
ENTRY2R0 (mpz_set_f, "mpz_set_f", np_mpz_set_f, mpz_ptr, mpf_ptr)
#endif
ENTRY3R1 (mpz_set_str, "mpz_set_str", np_mpz_set_str, int, mpz_ptr, stringz, int_0_or_2_to_62)
ENTRY2R0 (mpz_swap, "mpz_swap", np_mpz_swap, mpz_ptr, mpz_ptr)
ENTRY2R0 (mpz_init_set, "mpz_init_set", np_mpz_init_set, uninit_mpz, mpz_ptr)
ENTRY2R0 (mpz_init_set_ui, "mpz_init_set_ui", np_mpz_init_set_ui, uninit_mpz, ulong)
ENTRY2R0 (mpz_init_set_si, "mpz_init_set_si", np_mpz_init_set_si, uninit_mpz, long)
ENTRY2R0 (mpz_init_set_d, "mpz_init_set_d", np_mpz_init_set_d, uninit_mpz, double)
ENTRY3R1 (mpz_init_set_str, "mpz_init_set_str", np_mpz_init_set_str, int, uninit_mpz, stringz, int_0_or_2_to_62)
ENTRY1R1 (mpz_get_ui, "mpz_get_ui", np_mpz_get_ui, ulong, mpz_ptr)
ENTRY1R1 (mpz_get_si, "mpz_get_si", np_mpz_get_si, long, mpz_ptr)
ENTRY1R1 (mpz_get_d, "mpz_get_d", np_mpz_get_d, double, mpz_ptr)
// Usage: var a = mpz_get_d_2exp(z), d = a[0], exp = a[1];
ENTRY1R2 (x_mpz_get_d_2exp, "mpz_get_d_2exp", np_mpz_get_d_2exp, double, long, mpz_ptr)
// mpz_get_str: C-specific; use integers' toString method instead.
ENTRY3R0 (mpz_add, "mpz_add", np_mpz_add, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_add_ui, "mpz_add_ui", np_mpz_add_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_sub, "mpz_sub", np_mpz_sub, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_sub_ui, "mpz_sub_ui", np_mpz_sub_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_ui_sub, "mpz_ui_sub", np_mpz_ui_sub, mpz_ptr, ulong, mpz_ptr)
ENTRY3R0 (mpz_mul, "mpz_mul", np_mpz_mul, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_mul_si, "mpz_mul_si", np_mpz_mul_si, mpz_ptr, mpz_ptr, long)
ENTRY3R0 (mpz_mul_ui, "mpz_mul_ui", np_mpz_mul_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_addmul, "mpz_addmul", np_mpz_addmul, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_addmul_ui, "mpz_addmul_ui", np_mpz_addmul_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_submul, "mpz_submul", np_mpz_submul, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_submul_ui, "mpz_submul_ui", np_mpz_submul_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_mul_2exp, "mpz_mul_2exp", np_mpz_mul_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY2R0 (mpz_neg, "mpz_neg", np_mpz_neg, mpz_ptr, mpz_ptr)
ENTRY2R0 (mpz_abs, "mpz_abs", np_mpz_abs, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_cdiv_q, "mpz_cdiv_q", np_mpz_cdiv_q, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_cdiv_r, "mpz_cdiv_r", np_mpz_cdiv_r, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY4R0 (mpz_cdiv_qr, "mpz_cdiv_qr", np_mpz_cdiv_qr, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R1 (mpz_cdiv_q_ui, "mpz_cdiv_q_ui", np_mpz_cdiv_q_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY3R1 (mpz_cdiv_r_ui, "mpz_cdiv_r_ui", np_mpz_cdiv_r_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY4R1 (mpz_cdiv_qr_ui, "mpz_cdiv_qr_ui", np_mpz_cdiv_qr_ui, ulong, mpz_ptr, mpz_ptr, mpz_ptr, ulong)
ENTRY2R1 (mpz_cdiv_ui, "mpz_cdiv_ui", np_mpz_cdiv_ui, ulong, mpz_ptr, ulong)
ENTRY3R0 (mpz_cdiv_q_2exp, "mpz_cdiv_q_2exp", np_mpz_cdiv_q_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_cdiv_r_2exp, "mpz_cdiv_r_2exp", np_mpz_cdiv_r_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_fdiv_q, "mpz_fdiv_q", np_mpz_fdiv_q, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_fdiv_r, "mpz_fdiv_r", np_mpz_fdiv_r, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY4R0 (mpz_fdiv_qr, "mpz_fdiv_qr", np_mpz_fdiv_qr, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R1 (mpz_fdiv_q_ui, "mpz_fdiv_q_ui", np_mpz_fdiv_q_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY3R1 (mpz_fdiv_r_ui, "mpz_fdiv_r_ui", np_mpz_fdiv_r_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY4R1 (mpz_fdiv_qr_ui, "mpz_fdiv_qr_ui", np_mpz_fdiv_qr_ui, ulong, mpz_ptr, mpz_ptr, mpz_ptr, ulong)
ENTRY2R1 (mpz_fdiv_ui, "mpz_fdiv_ui", np_mpz_fdiv_ui, ulong, mpz_ptr, ulong)
ENTRY3R0 (mpz_fdiv_q_2exp, "mpz_fdiv_q_2exp", np_mpz_fdiv_q_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_fdiv_r_2exp, "mpz_fdiv_r_2exp", np_mpz_fdiv_r_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_tdiv_q, "mpz_tdiv_q", np_mpz_tdiv_q, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_tdiv_r, "mpz_tdiv_r", np_mpz_tdiv_r, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY4R0 (mpz_tdiv_qr, "mpz_tdiv_qr", np_mpz_tdiv_qr, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R1 (mpz_tdiv_q_ui, "mpz_tdiv_q_ui", np_mpz_tdiv_q_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY3R1 (mpz_tdiv_r_ui, "mpz_tdiv_r_ui", np_mpz_tdiv_r_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY4R1 (mpz_tdiv_qr_ui, "mpz_tdiv_qr_ui", np_mpz_tdiv_qr_ui, ulong, mpz_ptr, mpz_ptr, mpz_ptr, ulong)
ENTRY2R1 (mpz_tdiv_ui, "mpz_tdiv_ui", np_mpz_tdiv_ui, ulong, mpz_ptr, ulong)
ENTRY3R0 (mpz_tdiv_q_2exp, "mpz_tdiv_q_2exp", np_mpz_tdiv_q_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_tdiv_r_2exp, "mpz_tdiv_r_2exp", np_mpz_tdiv_r_2exp, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_mod, "mpz_mod", np_mpz_mod, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_mod_ui, "mpz_mod_ui", np_mpz_mod_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_divexact, "mpz_divexact", np_mpz_divexact, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_divexact_ui, "mpz_divexact_ui", np_mpz_divexact_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY2R1 (mpz_divisible_p, "mpz_divisible_p", np_mpz_divisible_p, bool, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_divisible_ui_p, "mpz_divisible_ui_p", np_mpz_divisible_ui_p, bool, mpz_ptr, ulong)
ENTRY2R1 (mpz_divisible_2exp_p, "mpz_divisible_2exp_p", np_mpz_divisible_2exp_p, bool, mpz_ptr, mp_bitcnt_t)
ENTRY3R1 (mpz_congruent_p, "mpz_congruent_p", np_mpz_congruent_p, bool, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R1 (mpz_congruent_ui_p, "mpz_congruent_ui_p", np_mpz_congruent_ui_p, bool, mpz_ptr, ulong, ulong)
ENTRY3R1 (mpz_congruent_2exp_p, "mpz_congruent_2exp_p", np_mpz_congruent_2exp_p, bool, mpz_ptr, mpz_ptr, mp_bitcnt_t)
ENTRY4R0 (mpz_powm, "mpz_powm", np_mpz_powm, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY4R0 (mpz_powm_ui, "mpz_powm_ui", np_mpz_powm_ui, mpz_ptr, mpz_ptr, ulong, mpz_ptr)
ENTRY4R0 (mpz_powm_sec, "mpz_powm_sec", np_mpz_powm_sec, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_pow_ui, "mpz_pow_ui", np_mpz_pow_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_ui_pow_ui, "mpz_ui_pow_ui", np_mpz_ui_pow_ui, mpz_ptr, ulong, ulong)
ENTRY3R1 (mpz_root, "mpz_root", np_mpz_root, bool, mpz_ptr, mpz_ptr, ulong)
ENTRY4R0 (mpz_rootrem, "mpz_rootrem", np_mpz_rootrem, mpz_ptr, mpz_ptr, mpz_ptr, ulong)
ENTRY2R0 (mpz_sqrt, "mpz_sqrt", np_mpz_sqrt, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_sqrtrem, "mpz_sqrtrem", np_mpz_sqrtrem, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY1R1 (mpz_perfect_power_p, "mpz_perfect_power_p", np_mpz_perfect_power_p, bool, mpz_ptr)
ENTRY1R1 (mpz_perfect_square_p, "mpz_perfect_square_p", np_mpz_perfect_square_p, bool, mpz_ptr)
ENTRY2R1 (mpz_probab_prime_p, "mpz_probab_prime_p", np_mpz_probab_prime_p, int, mpz_ptr, int)
ENTRY2R0 (mpz_nextprime, "mpz_nextprime", np_mpz_nextprime, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_gcd, "mpz_gcd", np_mpz_gcd, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R1 (mpz_gcd_ui, "mpz_gcd_ui", np_mpz_gcd_ui, ulong, mpz_ptr, mpz_ptr, ulong)
ENTRY5R0 (mpz_gcdext, "mpz_gcdext", np_mpz_gcdext, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_lcm, "mpz_lcm", np_mpz_lcm, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_lcm_ui, "mpz_lcm_ui", np_mpz_lcm_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R1 (mpz_invert, "mpz_invert", np_mpz_invert, int, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_jacobi, "mpz_jacobi", np_mpz_jacobi, int, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_legendre, "mpz_legendre", np_mpz_legendre, int, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_kronecker, "mpz_kronecker", np_mpz_kronecker, int, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_kronecker_si, "mpz_kronecker_si", np_mpz_kronecker_si, int, mpz_ptr, long)
ENTRY2R1 (mpz_kronecker_ui, "mpz_kronecker_ui", np_mpz_kronecker_ui, int, mpz_ptr, ulong)
ENTRY2R1 (mpz_si_kronecker, "mpz_si_kronecker", np_mpz_si_kronecker, int, long, mpz_ptr)
ENTRY2R1 (mpz_ui_kronecker, "mpz_ui_kronecker", np_mpz_ui_kronecker, int, ulong, mpz_ptr)
ENTRY3R1 (mpz_remove, "mpz_remove", np_mpz_remove, mp_bitcnt_t, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY2R0 (mpz_fac_ui, "mpz_fac_ui", np_mpz_fac_ui, mpz_ptr, ulong)
ENTRY3R0 (mpz_bin_ui, "mpz_bin_ui", np_mpz_bin_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY3R0 (mpz_bin_uiui, "mpz_bin_uiui", np_mpz_bin_uiui, mpz_ptr, ulong, ulong)
ENTRY2R0 (mpz_fib_ui, "mpz_fib_ui", np_mpz_fib_ui, mpz_ptr, ulong)
ENTRY3R0 (mpz_fib2_ui, "mpz_fib2_ui", np_mpz_fib2_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY2R0 (mpz_lucnum_ui, "mpz_lucnum_ui", np_mpz_lucnum_ui, mpz_ptr, ulong)
ENTRY3R0 (mpz_lucnum2_ui, "mpz_lucnum2_ui", np_mpz_lucnum2_ui, mpz_ptr, mpz_ptr, ulong)
ENTRY2R1 (mpz_cmp, "mpz_cmp", np_mpz_cmp, int, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_cmp_d, "mpz_cmp_d", np_mpz_cmp_d, int, mpz_ptr, double)
ENTRY2R1 (mpz_cmp_si, "mpz_cmp_si", np_mpz_cmp_si, int, mpz_ptr, long)
ENTRY2R1 (mpz_cmp_ui, "mpz_cmp_ui", np_mpz_cmp_ui, int, mpz_ptr, ulong)
ENTRY2R1 (mpz_cmpabs, "mpz_cmpabs", np_mpz_cmpabs, int, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_cmpabs_d, "mpz_cmpabs_d", np_mpz_cmpabs_d, int, mpz_ptr, double)
ENTRY2R1 (mpz_cmpabs_ui, "mpz_cmpabs_ui", np_mpz_cmpabs_ui, int, mpz_ptr, ulong)
ENTRY1R1 (mpz_sgn, "mpz_sgn", np_mpz_sgn, int, mpz_ptr)
ENTRY3R0 (mpz_and, "mpz_and", np_mpz_and, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_ior, "mpz_ior", np_mpz_ior, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY3R0 (mpz_xor, "mpz_xor", np_mpz_xor, mpz_ptr, mpz_ptr, mpz_ptr)
ENTRY2R0 (mpz_com, "mpz_com", np_mpz_com, mpz_ptr, mpz_ptr)
ENTRY1R1 (mpz_popcount, "mpz_popcount", np_mpz_popcount, mp_bitcnt_t, mpz_ptr)
ENTRY2R1 (mpz_hamdist, "mpz_hamdist", np_mpz_hamdist, mp_bitcnt_t, mpz_ptr, mpz_ptr)
ENTRY2R1 (mpz_scan0, "mpz_scan0", np_mpz_scan0, mp_bitcnt_t, mpz_ptr, mp_bitcnt_t)
ENTRY2R1 (mpz_scan1, "mpz_scan1", np_mpz_scan1, mp_bitcnt_t, mpz_ptr, mp_bitcnt_t)
ENTRY2R0 (mpz_setbit, "mpz_setbit", np_mpz_setbit, mpz_ptr, mp_bitcnt_t)
ENTRY2R0 (mpz_clrbit, "mpz_clrbit", np_mpz_clrbit, mpz_ptr, mp_bitcnt_t)
ENTRY2R0 (mpz_combit, "mpz_combit", np_mpz_combit, mpz_ptr, mp_bitcnt_t)
ENTRY2R1 (mpz_tstbit, "mpz_tstbit", np_mpz_tstbit, int, mpz_ptr, mp_bitcnt_t)
// mpz_out_str, mpz_inp_str, mpz_out_raw, mpz_inp_raw: not relevant to plugin.
#if NPGMP_RAND
ENTRY3R0 (mpz_urandomb, "mpz_urandomb", np_mpz_urandomb, mpz_ptr, x_gmp_randstate_ptr, mp_bitcnt_t)
ENTRY3R0 (mpz_urandomm, "mpz_urandomm", np_mpz_urandomm, mpz_ptr, x_gmp_randstate_ptr, mpz_ptr)
ENTRY3R0 (mpz_rrandomb, "mpz_rrandomb", np_mpz_rrandomb, mpz_ptr, x_gmp_randstate_ptr, mp_bitcnt_t)
ENTRY2R0 (mpz_random, "mpz_random", np_mpz_random, mpz_ptr, mp_size_t)
ENTRY2R0 (mpz_random2, "mpz_random2", np_mpz_random2, mpz_ptr, mp_size_t)
#endif  /* NPGMP_RAND */
// mpz_import, mpz_export: tricky to implmement with NPAPI.
ENTRY1R1 (mpz_fits_ulong_p, "mpz_fits_ulong_p", np_mpz_fits_ulong_p, bool, mpz_ptr)
ENTRY1R1 (mpz_fits_slong_p, "mpz_fits_slong_p", np_mpz_fits_slong_p, bool, mpz_ptr)
#if NPGMP_PORTING
// mpz_fits_uint_p, mpz_fits_sint_p, mpz_fits_ushort_p, mpz_fits_sshort_p:
// C-specific; let us avoid gratuitous, non-portable exposure of C type sizes.
#endif
ENTRY1R1 (mpz_odd_p, "mpz_odd_p", np_mpz_odd_p, bool, mpz_ptr)
ENTRY1R1 (mpz_even_p, "mpz_even_p", np_mpz_even_p, bool, mpz_ptr)
ENTRY2R1 (mpz_sizeinbase, "mpz_sizeinbase", np_mpz_sizeinbase, size_t, mpz_ptr, int_2_to_62)
// mpz_array_init: tricky and unsuitable.
ENTRY2R0 (_mpz_realloc, "_mpz_realloc", np__mpz_realloc, mpz_ptr, mp_size_t)
ENTRY2R1 (mpz_getlimbn, "mpz_getlimbn", np_mpz_getlimbn, mp_limb_t, mpz_ptr, mp_size_t)
ENTRY1R1 (mpz_size, "mpz_size", np_mpz_size, size_t, mpz_ptr)

#if NPGMP_MPQ
ENTRY1R0 (mpq_canonicalize, "mpq_canonicalize", np_mpq_canonicalize, mpq_ptr)
ENTRY1R1 (mpq_init, "mpq", np_mpq, new_mpq, new_mpq)
ENTRY1R0 (mpq_init, "mpq_init", np_mpq_init, uninit_mpq)
#if NPGMP_PORTING
// mpq_inits: unimplemented.
// mpq_clear: called automatically.  Dummy version:
ENTRY1R0 (mpq_init, "mpq_clear", np_mpq_clear, uninit_mpq)
// mpq_clears: unimplemented.
#endif
ENTRY2R0 (mpq_set, "mpq_set", np_mpq_set, mpq_ptr, mpq_ptr)
ENTRY2R0 (mpq_set_z, "mpq_set_z", np_mpq_set_z, mpq_ptr, mpz_ptr)
ENTRY3R0 (mpq_set_ui, "mpq_set_ui", np_mpq_set_ui, mpq_ptr, ulong, ulong)
ENTRY3R0 (mpq_set_si, "mpq_set_si", np_mpq_set_si, mpq_ptr, long, long)
ENTRY3R1 (mpq_set_str, "mpq_set_str", np_mpq_set_str, int, mpq_ptr, stringz, int_0_or_2_to_62)
ENTRY2R0 (mpq_swap, "mpq_swap", np_mpq_swap, mpq_ptr, mpq_ptr)
ENTRY1R1 (mpq_get_d, "mpq_get_d", np_mpq_get_d, double, mpq_ptr)
ENTRY2R0 (mpq_set_d, "mpq_set_d", np_mpq_set_d, mpq_ptr, double)
#if NPGMP_MPF
ENTRY2R0 (mpq_set_f, "mpq_set_f", np_mpq_set_f, mpq_ptr, mpf_ptr)
#endif
// mpq_get_str: C-specific; use numbers' toString method instead.
ENTRY3R0 (mpq_add, "mpq_add", np_mpq_add, mpq_ptr, mpq_ptr, mpq_ptr)
ENTRY3R0 (mpq_sub, "mpq_sub", np_mpq_sub, mpq_ptr, mpq_ptr, mpq_ptr)
ENTRY3R0 (mpq_mul, "mpq_mul", np_mpq_mul, mpq_ptr, mpq_ptr, mpq_ptr)
ENTRY3R0 (mpq_mul_2exp, "mpq_mul_2exp", np_mpq_mul_2exp, mpq_ptr, mpq_ptr, mp_bitcnt_t)
ENTRY3R0 (mpq_div, "mpq_div", np_mpq_div, mpq_ptr, mpq_ptr, mpq_ptr)
ENTRY3R0 (mpq_div_2exp, "mpq_div_2exp", np_mpq_div_2exp, mpq_ptr, mpq_ptr, mp_bitcnt_t)
ENTRY2R0 (mpq_neg, "mpq_neg", np_mpq_neg, mpq_ptr, mpq_ptr)
ENTRY2R0 (mpq_abs, "mpq_abs", np_mpq_abs, mpq_ptr, mpq_ptr)
ENTRY2R0 (mpq_inv, "mpq_inv", np_mpq_inv, mpq_ptr, mpq_ptr)
ENTRY2R1 (mpq_cmp, "mpq_cmp", np_mpq_cmp, int, mpq_ptr, mpq_ptr)
ENTRY3R1 (mpq_cmp_si, "mpq_cmp_si", np_mpq_cmp_si, int, mpq_ptr, long, long)
ENTRY3R1 (mpq_cmp_ui, "mpq_cmp_ui", np_mpq_cmp_ui, int, mpq_ptr, ulong, ulong)
ENTRY1R1 (mpq_sgn, "mpq_sgn", np_mpq_sgn, int, mpq_ptr)
ENTRY2R1 (mpq_equal, "mpq_equal", np_mpq_equal, int, mpq_ptr, mpq_ptr)
ENTRY2R1 (x_mpq_numref, "mpq_numref", np_mpq_numref, new_mpzref, new_mpzref, mpq_ptr)
ENTRY2R1 (x_mpq_denref, "mpq_denref", np_mpq_denref, new_mpzref, new_mpzref, mpq_ptr)
ENTRY2R0 (mpq_get_num, "mpq_get_num", np_mpq_get_num, mpz_ptr, mpq_ptr)
ENTRY2R0 (mpq_get_den, "mpq_get_den", np_mpq_get_den, mpz_ptr, mpq_ptr)
ENTRY2R0 (mpq_set_num, "mpq_set_num", np_mpq_set_num, mpq_ptr, mpz_ptr)
ENTRY2R0 (mpq_set_den, "mpq_set_den", np_mpq_set_den, mpq_ptr, mpz_ptr)
// mpq_out_str, mpq_inp_str: not relevant to plugin.
#endif  /* NPGMP_MPQ */

#if NPGMP_MPF
ENTRY1R0 (x_mpf_set_default_prec, "mpf_set_default_prec", np_mpf_set_default_prec, mp_bitcnt_t)
ENTRY0R1 (x_mpf_get_default_prec, "mpf_get_default_prec", np_mpf_get_default_prec, mp_bitcnt_t)
ENTRY1R1 (x_mpf_init, "mpf", np_mpf, new_mpf, new_mpf)
ENTRY1R0 (x_mpf_init, "mpf_init", np_mpf_init, defprec_mpf)
ENTRY2R0 (mpf_init2, "mpf_init2", np_mpf_init2, uninit_mpf, mp_bitcnt_t)
#if NPGMP_PORTING
// mpf_inits: unimplemented.
// mpf_clear: called automatically.  Dummy version:
ENTRY1R0 (x_mpf_clear, "mpf_clear", np_mpf_clear, uninit_mpf)
// mpf_clears: unimplemented.
#endif
ENTRY1R1 (mpf_get_prec, "mpf_get_prec", np_mpf_get_prec, mp_bitcnt_t, mpf_ptr)
ENTRY2R0 (x_mpf_set_prec, "mpf_set_prec", np_mpf_set_prec, mpf_ptr, mp_bitcnt_t)
ENTRY2R0 (x_mpf_set_prec_raw, "mpf_set_prec_raw", np_mpf_set_prec_raw, mpf_ptr, mp_bitcnt_t)
ENTRY2R0 (mpf_set, "mpf_set", np_mpf_set, mpf_ptr, mpf_ptr)
ENTRY2R0 (mpf_set_ui, "mpf_set_ui", np_mpf_set_ui, mpf_ptr, ulong)
ENTRY2R0 (mpf_set_si, "mpf_set_si", np_mpf_set_si, mpf_ptr, long)
ENTRY2R0 (mpf_set_d, "mpf_set_d", np_mpf_set_d, mpf_ptr, double)
ENTRY2R0 (mpf_set_z, "mpf_set_z", np_mpf_set_z, mpf_ptr, mpz_ptr)
#if NPGMP_MPQ
ENTRY2R0 (mpf_set_q, "mpf_set_q", np_mpf_set_q, mpf_ptr, mpq_ptr)
#endif
ENTRY3R1 (mpf_set_str, "mpf_set_str", np_mpf_set_str, int, mpf_ptr, stringz, int_abs_2_to_62)
ENTRY2R0 (mpf_swap, "mpf_swap", np_mpf_swap, mpf_ptr, mpf_ptr)
ENTRY2R0 (mpf_set, "mpf_init_set", np_mpf_init_set, defprec_mpf, mpf_ptr)
ENTRY2R0 (mpf_set_ui, "mpf_init_set_ui", np_mpf_init_set_ui, defprec_mpf, ulong)
ENTRY2R0 (mpf_set_si, "mpf_init_set_si", np_mpf_init_set_si, defprec_mpf, long)
ENTRY2R0 (mpf_set_d, "mpf_init_set_d", np_mpf_init_set_d, defprec_mpf, double)
ENTRY3R1 (mpf_set_str, "mpf_init_set_str", np_mpf_init_set_str, int, defprec_mpf, stringz, int_abs_2_to_62)
ENTRY1R1 (mpf_get_d, "mpf_get_d", np_mpf_get_d, double, mpf_ptr)
// Usage: var a = mpf_get_d_2exp(x), d = a[0], exp = a[1];
ENTRY1R2 (x_mpf_get_d_2exp, "mpf_get_d_2exp", np_mpf_get_d_2exp, double, long, mpf_ptr)
ENTRY1R1 (mpf_get_si, "mpf_get_si", np_mpf_get_si, long, mpf_ptr)
ENTRY1R1 (mpf_get_ui, "mpf_get_ui", np_mpf_get_ui, ulong, mpf_ptr)
// Usage: var a = mpf_get_str(base,n_digits,x), fraction = a[0], exp = a[1];
ENTRY3R2 (x_mpf_get_str, "mpf_get_str", np_mpf_get_str, stringz, mp_exp_t, int, size_t, mpf_ptr)
ENTRY3R0 (mpf_add, "mpf_add", np_mpf_add, mpf_ptr, mpf_ptr, mpf_ptr)
ENTRY3R0 (mpf_add_ui, "mpf_add_ui", np_mpf_add_ui, mpf_ptr, mpf_ptr, ulong)
ENTRY3R0 (mpf_sub, "mpf_sub", np_mpf_sub, mpf_ptr, mpf_ptr, mpf_ptr)
ENTRY3R0 (mpf_ui_sub, "mpf_ui_sub", np_mpf_ui_sub, mpf_ptr, ulong, mpf_ptr)
ENTRY3R0 (mpf_sub_ui, "mpf_sub_ui", np_mpf_sub_ui, mpf_ptr, mpf_ptr, ulong)
ENTRY3R0 (mpf_mul, "mpf_mul", np_mpf_mul, mpf_ptr, mpf_ptr, mpf_ptr)
ENTRY3R0 (mpf_mul_ui, "mpf_mul_ui", np_mpf_mul_ui, mpf_ptr, mpf_ptr, ulong)
ENTRY3R0 (mpf_div, "mpf_div", np_mpf_div, mpf_ptr, mpf_ptr, mpf_ptr)
ENTRY3R0 (mpf_ui_div, "mpf_ui_div", np_mpf_ui_div, mpf_ptr, ulong, mpf_ptr)
ENTRY3R0 (mpf_div_ui, "mpf_div_ui", np_mpf_div_ui, mpf_ptr, mpf_ptr, ulong)
ENTRY2R0 (mpf_sqrt, "mpf_sqrt", np_mpf_sqrt, mpf_ptr, mpf_ptr)
ENTRY2R0 (mpf_sqrt_ui, "mpf_sqrt_ui", np_mpf_sqrt_ui, mpf_ptr, ulong)
ENTRY3R0 (mpf_pow_ui, "mpf_pow_ui", np_mpf_pow_ui, mpf_ptr, mpf_ptr, ulong)
ENTRY2R0 (mpf_neg, "mpf_neg", np_mpf_neg, mpf_ptr, mpf_ptr)
ENTRY2R0 (mpf_abs, "mpf_abs", np_mpf_abs, mpf_ptr, mpf_ptr)
ENTRY3R0 (mpf_mul_2exp, "mpf_mul_2exp", np_mpf_mul_2exp, mpf_ptr, mpf_ptr, mp_bitcnt_t)
ENTRY3R0 (mpf_div_2exp, "mpf_div_2exp", np_mpf_div_2exp, mpf_ptr, mpf_ptr, mp_bitcnt_t)
ENTRY2R1 (mpf_cmp, "mpf_cmp", np_mpf_cmp, int, mpf_ptr, mpf_ptr)
ENTRY2R1 (mpf_cmp_d, "mpf_cmp_d", np_mpf_cmp_d, int, mpf_ptr, double)
ENTRY2R1 (mpf_cmp_ui, "mpf_cmp_ui", np_mpf_cmp_ui, int, mpf_ptr, ulong)
ENTRY2R1 (mpf_cmp_si, "mpf_cmp_si", np_mpf_cmp_si, int, mpf_ptr, long)
ENTRY3R1 (mpf_eq, "mpf_eq", np_mpf_eq, int, mpf_ptr, mpf_ptr, mp_bitcnt_t)
ENTRY3R0 (mpf_reldiff, "mpf_reldiff", np_mpf_reldiff, mpf_ptr, mpf_ptr, mpf_ptr)
ENTRY1R1 (mpf_sgn, "mpf_sgn", np_mpf_sgn, int, mpf_ptr)
// mpf_out_str, mpf_inp_str: not relevant to plugin.
ENTRY2R0 (mpf_ceil, "mpf_ceil", np_mpf_ceil, mpf_ptr, mpf_ptr)
ENTRY2R0 (mpf_floor, "mpf_floor", np_mpf_floor, mpf_ptr, mpf_ptr)
ENTRY2R0 (mpf_trunc, "mpf_trunc", np_mpf_trunc, mpf_ptr, mpf_ptr)
ENTRY1R1 (mpf_integer_p, "mpf_integer_p", np_mpf_integer_p, bool, mpf_ptr)
ENTRY1R1 (mpf_fits_ulong_p, "mpf_fits_ulong_p", np_mpf_fits_ulong_p, bool, mpf_ptr)
ENTRY1R1 (mpf_fits_slong_p, "mpf_fits_slong_p", np_mpf_fits_slong_p, bool, mpf_ptr)
// mpf_fits_uint_p, mpf_fits_sint_p, mpf_fits_ushort_p, mpf_fits_sshort_p:
// C-specific; let us avoid gratuitous, non-portable exposure of C type sizes.
#if NPGMP_RAND
ENTRY3R0 (mpf_urandomb, "mpf_urandomb", np_mpf_urandomb, mpf_ptr, x_gmp_randstate_ptr, mp_bitcnt_t)
ENTRY3R0 (mpf_random2, "mpf_random2", np_mpf_random2, mpf_ptr, mp_size_t, mp_exp_t)
#endif  /* NPGMP_RAND */
#endif  /* NPGMP_MPF */

// mpn functions: unimplemented, not very suitable for plugins.

#if NPGMP_RAND
ENTRY1R1 (gmp_randinit_default, "randstate", np_randstate, new_rand, new_rand)
ENTRY1R0 (gmp_randinit_default, "gmp_randinit_default", np_gmp_randinit_default, uninit_rand)
ENTRY1R0 (gmp_randinit_mt, "gmp_randinit_mt", np_gmp_randinit_mt, uninit_rand)
ENTRY4R0 (gmp_randinit_lc_2exp, "gmp_randinit_lc_2exp", np_gmp_randinit_lc_2exp, uninit_rand, mpz_ptr, ulong, mp_bitcnt_t)
// Usage: rs=gmp_randinit_lc_2exp_size(size); returns undefined if unsuccessful.
ENTRY2R1 (x_randinit_lc_2exp_size, "gmp_randinit_lc_2exp_size", np_gmp_randinit_lc_2exp_size, int, uninit_rand, mp_bitcnt_t)
ENTRY2R0 (gmp_randinit_set, "gmp_randinit_set", np_gmp_randinit_set, uninit_rand, x_gmp_randstate_ptr)
// gmp_randinit: obsolete and variadic.
// gmp_randclear: called automatically.  Dummy version:
ENTRY1R0 (gmp_randinit_default, "gmp_randclear", np_gmp_randclear, uninit_rand)
ENTRY2R0 (gmp_randseed, "gmp_randseed", np_gmp_randseed, x_gmp_randstate_ptr, mpz_ptr)
ENTRY2R0 (gmp_randseed_ui, "gmp_randseed_ui", np_gmp_randseed_ui, x_gmp_randstate_ptr, ulong)
ENTRY2R1 (gmp_urandomb_ui, "gmp_urandomb_ui", np_gmp_urandomb_ui, ulong, x_gmp_randstate_ptr, ulong)
ENTRY2R1 (gmp_urandomm_ui, "gmp_urandomm_ui", np_gmp_urandomm_ui, ulong, x_gmp_randstate_ptr, ulong)
#endif  /* NPGMP_RAND */

// gmp_printf, gmp_scanf, and friends: something similar would be nice.
// mp_set_memory_functions, mp_get_memory_functions: not relevant to plugin.

#undef ENTRY
#undef ENTRY0R1
#undef ENTRY1R0
#undef ENTRY1R1
#undef ENTRY1R2
#undef ENTRY2R0
#undef ENTRY2R1
#undef ENTRY3R0
#undef ENTRY3R1
#undef ENTRY3R2
#undef ENTRY4R0
#undef ENTRY4R1
#undef ENTRY5R0
#undef ENTRY_FIRST
