require xorg-lib-common.inc
DESCRIPTION = "Session management library"
PRIORITY = "optional"
DEPENDS += " libice xproto xtrans"
PE = "1"
PR = "${INC_PR}.0"

SRC_URI[archive.md5sum] = "a254771550c01db372e88d1a1dc2e13a"
SRC_URI[archive.sha256sum] = "e290614797bd626c1b92bac8f83e8954b99bd66e6ecdaa1e935e176df099eba8"

BBCLASSEXTEND = "native"

XORG_PN = "libSM"
