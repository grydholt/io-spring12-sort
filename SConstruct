SConscript('unbuffered_system/SConscript', variant_dir='build_unbuffered_system')
Program('runner_unbuffered_system', Glob('*.c'), LIBS='unbuffered_system', LIBPATH='build_unbuffered_system')

SConscript('buffered_stdio/SConscript', variant_dir='build_buffered_stdio')
Program('runner_buffered_stdio', Glob('*.c'), LIBS='buffered_stdio', LIBPATH='build_buffered_stdio')

SConscript('buffered_system/SConscript', variant_dir='build_buffered_system')
Program('runner_buffered_system', Glob('*.c'), LIBS='buffered_system', LIBPATH='build_buffered_system')

SConscript('mmap/SConscript', variant_dir='build_mmap')
Program('runner_mmap', Glob('*.c'), LIBS='mmap', LIBPATH='build_mmap')
