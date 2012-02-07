SConscript('unbuffered_system/SConscript', variant_dir='build_unbuffered_system')
Program('runner_unbuffered_system', Glob('*.c'), LIBS='unbuffered_system', LIBPATH='build_unbuffered_system')
SConscript('buffered_stdio/SConscript', variant_dir='build_buffered_stdio')
Program('runner_buffered_stdio', Glob('*.c'), LIBS='buffered_stdio', LIBPATH='build_buffered_stdio')
