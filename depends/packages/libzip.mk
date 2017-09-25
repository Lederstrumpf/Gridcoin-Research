package=libzip
$(package)_version=1.3.0
$(package)_download_path=https://nih.at/$(package)/
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=a919350f683ca6194df0a856698b477da9e06416665b883fe4fc23c0e46e6398
$(package)_dependencies=zlib

define $(package)_config_cmds
  ./configure --prefix=$(host_prefix) --with-zlib=$(host_prefix) --with-pic --enable-static --enable-shared=no
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef

define $(package)_postprocess_cmds
  cp $($(package)_staging_dir)$(host_prefix)/lib/libzip/include/zipconf.h $($(package)_staging_dir)$(host_prefix)/include/zipconf.h
endef
