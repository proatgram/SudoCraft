bin_PROGRAMS = sudocraft
include_HEADERS = $(top_srcdir)/include/* $(top_srcdir)/deps/libnoise/include/noise/*.h $(top_srcdir)/deps/libnoise/include/noise/module/*.h $(top_srcdir)/deps/libnoise/include/noise/model/*.h
sudocraft_CPPFLAGS = "-I$(top_srcdir)/include" "-I$(top_srcdir)/deps/libnoise/include" "-std=c++17"
sudocraft_SOURCES = src/Game.cpp src/Inventory.cpp src/Character.cpp src/Craft.cpp src/Item.cpp src/Weapon.cpp src/Tool.cpp
dist_doc_DATA = README.md
