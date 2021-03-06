DESCRIPTION = "XCB: an X protocol C binding"
SECTION = "x11/libs"
LICENSE = "MIT-X"
HOMEPAGE = "http://xcb.freedesktop.org"

SRC_URI = "http://xcb.freedesktop.org/dist/xcb-proto-${PV}.tar.bz2"

inherit autotools pkgconfig

INC_PR = "r2"

FILES_${PN}-dev += "${datadir}/xcb/*.xml"
ALLOW_EMPTY_${PN} = "1"

