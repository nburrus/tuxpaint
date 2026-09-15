# Source-built MINGW64 dependencies; opt out with WIN32_SOURCE_BUILD=0.
WIN32_SOURCE_PREFIX ?= /usr/local
WIN32_SOURCE_LIBDIR := -L/usr/local/lib
WIN32_SOURCE_BUILD ?= $(if $(and $(filter windows,$(OS)),$(filter /mingw64,$(MINGW_DIR)),$(wildcard $(WIN32_SOURCE_PREFIX)/share/tuxpaint-source-build/imagequant.json)),1,0)
ifeq ($(WIN32_SOURCE_BUILD),1)
  SOURCE_NATIVE := $(shell cygpath -m '$(WIN32_SOURCE_PREFIX)')
  export PATH := $(WIN32_SOURCE_PREFIX)/bin:/mingw64/bin:/usr/bin:$(PATH)
  export PKG_CONFIG_PATH :=
  export PKG_CONFIG_LIBDIR := $(SOURCE_NATIVE)/lib/pkgconfig
  PKG_CONFIG := /mingw64/bin/pkg-config
  override WIN32_SOURCE_LIBDIR := -L$(SOURCE_NATIVE)/lib
  override CPPFLAGS += -I$(SOURCE_NATIVE)/include -DTUXPAINT_SOURCE_RUNTIME
  override OPTFLAGS := -Os
  override LDFLAGS := -L$(SOURCE_NATIVE)/lib -static-libgcc
  override PANGO_LIB := -lpango-1.0 -lpangoft2-1.0
endif
