#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error Meh....
#endif

GO(swr_alloc_set_opts2, iFppiipiiip)
GO(swr_init, iFp)
GO(swr_free, vFp)
GO(swr_get_out_samples, iFpi)
GO(swr_convert, iFppipi)
