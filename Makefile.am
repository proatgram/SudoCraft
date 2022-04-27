bin_PROGRAMS = sudocraft
noinst_LIBRARIES = libnoise.a

libnoise_a_SOURCES = deps/libnoise/src/module/abs.cpp\
deps/libnoise/src/module/add.cpp\
deps/libnoise/src/module/billow.cpp\
deps/libnoise/src/module/blend.cpp\
deps/libnoise/src/module/cache.cpp\
deps/libnoise/src/module/checkerboard.cpp\
deps/libnoise/src/module/clamp.cpp\
deps/libnoise/src/module/const.cpp\
deps/libnoise/src/module/curve.cpp\
deps/libnoise/src/module/cylinders.cpp\
deps/libnoise/src/module/displace.cpp\
deps/libnoise/src/module/exponent.cpp\
deps/libnoise/src/module/invert.cpp\
deps/libnoise/src/module/max.cpp\
deps/libnoise/src/module/min.cpp\
deps/libnoise/src/module/modulebase.cpp\
deps/libnoise/src/module/multiply.cpp\
deps/libnoise/src/module/perlin.cpp\
deps/libnoise/src/module/power.cpp\
deps/libnoise/src/module/ridgedmulti.cpp\
deps/libnoise/src/module/rotatepoint.cpp\
deps/libnoise/src/module/scalebias.cpp\
deps/libnoise/src/module/scalepoint.cpp\
deps/libnoise/src/module/select.cpp\
deps/libnoise/src/module/spheres.cpp\
deps/libnoise/src/module/terrace.cpp\
deps/libnoise/src/module/translatepoint.cpp\
deps/libnoise/src/module/turbulence.cpp\
deps/libnoise/src/module/voronoi.cpp\
deps/libnoise/src/latlon.cpp\
deps/libnoise/src/noisegen.cpp\
deps/libnoise/src/model/sphere.cpp\
deps/libnoise/src/model/plane.cpp\
deps/libnoise/src/model/line.cpp\
deps/libnoise/src/model/cylinder.cpp
libnoise_a_CPPFLAGS = "-I$(top_srcdir)/deps/libnoise/include/noise" "-I$(top_srcdir)/deps/libnoise/include/noise/module"

include_HEADERS = $(top_srcdir)/include/* $(top_srcdir)/deps/libnoise/include/noise/*.h $(top_srcdir)/deps/libnoise/include/noise/module/*.h $(top_srcdir)/deps/libnoise/include/noise/model/*.h
sudocraft_CPPFLAGS = "-I$(top_srcdir)/include" "-I$(top_srcdir)/deps/libnoise/include" "-I$(top_srcdir)/deps/libnoise/include/noise" "-std=c++17" "-I$(top_srcdir)/deps/libnoise/include/noise/module"
sudocraft_SOURCES = src/Game.cpp src/Inventory.cpp src/Character.cpp src/Craft.cpp src/Item.cpp src/Weapon.cpp src/Tool.cpp src/WorldGen.cpp src/World.cpp src/Blocks.cpp src/GameUI.cpp src/Utils.cpp
sudocraft_LDADD = libnoise.a
dist_doc_DATA = README.md
