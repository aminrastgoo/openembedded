# SHR conf file

# We need to override some machine stuff as well; include the machine-
# specific file here (if it exists).
#include conf/distro/include/shr-${MACHINE}.conf

# Nail down some SRCREV's for the kernels.  There is a real potential problem
# here, in that git hashes are hashes, not incrementing version numbers.  Thus
# we need to have something else in the kernel version string that gets bumped
# with each change.  So if you change one of these, go to the kernel recipe
# and bump the OEV value up as well.
SRCREV_pn-linux-eten = "df9715883efa3e6a88866813168fabb1c16b0b7a"
SRCREV_pn-linux-openmoko-shr-devel = "2d158aae9d8d36f575504f59884ed8e80802efe2"

# FSO stuff
SRCREV_pn-dbus-hlid = "39e804f28808247df2573788cb99897d4d765e69"
SRCREV_pn-frameworkd = "e96a204768744130859ab091162ec5c976854d49"
SRCREV_pn-frameworkd-config-shr = "${AUTOREV}"
SRCREV_pn-frameworkd-config-shr_FSO_REV = "e96a204768744130859ab091162ec5c976854d49"
SRCREV_pn-frameworkd-config-shr_SHR_REV = "${AUTOREV}"
SRCREV_pn-fsod = "${AUTOREV}"
SRCREV_pn-fsodeviced = "${AUTOREV}"
SRCREV_pn-fsonetworkd = "${AUTOREV}"
SRCREV_pn-fsousaged = "3c3e1b862cdde806cef8f502dfe79f1d48f1c5d7"
SRCREV_pn-fsoraw = "${AUTOREV}"
SRCREV_pn-fso-abyss = "ff68be1581069ca494a559e85f6299246888d3b5"
SRCREV_pn-fso-apm = "${AUTOREV}"
SRCREV_pn-fso-term = "${AUTOREV}"
SRCREV_pn-fso-gsm0710muxd = "abcbcd7cc532a8834906de3fc24c8f8fe7643cd4"
SRCREV_pn-fso-gpsd = "78fe48dffb923175bde9f0aabc3500a9264a57e0"
SRCREV_pn-fso-monitord = "${AUTOREV}"
SRCREV_pn-fso-sounds = "3a4767ec01988bd0fd8f72f0c35d6d36e5fbc815"
SRCREV_pn-fso-specs = "${AUTOREV}"
SRCREV_pn-fso-term = "${AUTOREV}"
SRCREV_pn-gsmd2 = "${AUTOREV}"
SRCREV_pn-illume-theme-freesmartphone = "${AUTOREV}"
SRCREV_pn-libascenario = "${AUTOREV}"
SRCREV_pn-libfsobasics = "3c3e1b862cdde806cef8f502dfe79f1d48f1c5d7"
SRCREV_pn-libfsoframework = "3c3e1b862cdde806cef8f502dfe79f1d48f1c5d7"
SRCREV_pn-libfsotransport = "3c3e1b862cdde806cef8f502dfe79f1d48f1c5d7"
SRCREV_pn-libframeworkd-glib = "680276e4cddabeb1edd088ddd421f363dd106a50"
SRCREV_pn-libfso-glib = "9d292508739452b55b80ec40ec57405a5de2159f"
SRCREV_pn-libgsm0710 = "3bb80ba6cc9f86ed3996f88bfa2986cc572489d6"
SRCREV_pn-libgsm0710mux = "8e3e7533b286d8086bce8fa09bce23bb9f18bb98"
SRCREV_pn-mickeydbus = "6d7f51b5189a00a07d9b88100a565f46fcb62644"
SRCREV_pn-mickeyterm = "6d7f51b5189a00a07d9b88100a565f46fcb62644"
SRCREV_pn-misc-vapi = "${AUTOREV}"
SRCREV_pn-python-pytrc = "f15ff7c58946a2fd6ba767628b2fe5d6f46ff9bb"
SRCREV_pn-vala-dbus-binding-tool-native = "6071da6ad645e1200eb2aee88d254ada348d361b"
SRCREV_pn-vala = "${AUTOREV}"
SRCREV_pn-zhone = "${AUTOREV}"


# SHR stuff
SHRREV = "c3d97171723d8e824cb5acf58b711aa78b3b82d9"

SRCREV_pn-libhito = "${AUTOREV}"
SRCREV_pn-neod = "${AUTOREV}"
SRCREV_pn-shr-settings = "4e0fbe17e4fddd18b0455ec4d007ab3f1d19918e"
SRCREV_pn-ophonekitd = "${SHRREV}"
SRCREV_pn-ophonekitd-vala = "${AUTOREV}"
SRCREV_pn-libmodulo = "${AUTOREV}"
SRCREV_pn-shr-messages = "${SHRREV}"
SRCREV_pn-shr-contacts = "${SHRREV}"
SRCREV_pn-shr-dialer = "${SHRREV}"
SRCREV_pn-libframeworkd-phonegui = "${SHRREV}"
SRCREV_pn-libframeworkd-phonegui-efl = "${SHRREV}"
SRCREV_pn-libframeworkd-phonegui-efl2 = "${AUTOREV}"
SRCREV_pn-libframeworkd-phonegui-gtk = "${AUTOREV}"
SRCREV_pn-libframeworkd-phonegui-gtk2 = "${AUTOREV}"
SRCREV_pn-opimd-utils = "${AUTOREV}"
SRCREV_pn-pyphonelog = "9da559f0242a32aa5d0b72c795f53d7d9ef8c973"
SRCREV_pn-shr-theme = "${AUTOREV}"
SRCREV_pn-shr-theme-brave = "${AUTOREV}"
SRCREV_pn-shr-theme-gtk-e17lookalike = "${AUTOREV}"
SRCREV_pn-shr-splash = "${AUTOREV}"
SRCREV_pn-shr-splash-theme-simple = "${AUTOREV}"
SRCREV_pn-shr-splash-theme-dontpanic = "${AUTOREV}"
SRCREV_pn-shr-splash-theme-handy = "${AUTOREV}"
SRCREV_pn-shr-splash-theme-niebiee = "${AUTOREV}"
SRCREV_pn-shr-installer = "${AUTOREV}"
SRCREV_pn-shr-config = "${AUTOREV}"
SRCREV_pn-alsa-scenarii-shr = "${AUTOREV}"
SRCREV_pn-libphone-utils = "${AUTOREV}"
SRCREV_pn-python-phoneutils = "${AUTOREV}"


# E17 stuff
EFL_SRCREV = "41040"
SRCREV_pn-python-elementary = "41040"
SRCREV_pn-e-wm-config-illume-shr = "${AUTOREV}"
SRCREV_pn-e-wm-sysactions-shr = "${AUTOREV}"
SRCREV_pn-e-wm-theme-illume-shr = "${AUTOREV}"
SRCREV_pn-e-wm-theme-illume-sixteen = "${AUTOREV}"
SRCREV_pn-e-wm-theme-illume-niebiee = "${AUTOREV}"
SRCREV_pn-elementary-theme-sixteen = "${AUTOREV}"
SRCREV_pn-elementary-theme-niebiee = "${AUTOREV}"
SRCREV_pn-e-wm-menu-shr = "${AUTOREV}"
SRCREV_pn-e-wm-illume-dict-pl = "${AUTOREV}"
SRCREV_pn-etk-theme-shr = "${AUTOREV}"
SRCREV_pn-libeflvala = "${AUTOREV}"

SRCREV_pn-illume-keyboard-german = "${AUTOREV}"
SRCREV_pn-illume-keyboard-arabic = "${AUTOREV}"
SRCREV_pn-illume-keyboard-browse = "${AUTOREV}"
SRCREV_pn-illume-keyboard-danish = "${AUTOREV}"
SRCREV_pn-illume-keyboard-default-alt = "${AUTOREV}"
SRCREV_pn-illume-keyboard-dutch = "${AUTOREV}"
SRCREV_pn-illume-keyboard-dvorak = "${AUTOREV}"
SRCREV_pn-illume-keyboard-french = "${AUTOREV}"
SRCREV_pn-illume-keyboard-hebrew = "${AUTOREV}"
SRCREV_pn-illume-keyboard-numeric-alt = "${AUTOREV}"
SRCREV_pn-illume-keyboard-russian-terminal = "${AUTOREV}"
SRCREV_pn-illume-keyboard-russian = "${AUTOREV}"


# Other stuff
SRCREV_pn-bt-configure = "${AUTOREV}"
SRCREV_pn-navit = "2309"
SRCREV_pn-omview = "${AUTOREV}"
SRCREV_pn-pythm = "${AUTOREV}"
SRCREV_pn-omoney = "29"
SRCREV_pn-enotes = "19"
SRCREV_pn-ebrainy = "${AUTOREV}"
SRCREV_pn-boost-signals2 = "52299"
SRCREV_pn-dbus-c++-native = "${AUTOREV}"
SRCREV_pn-dbus-c++ = "${AUTOREV}"
SRCREV_pn-openmoocow = "${AUTOREV}"
SRCREV_pn-libmokoui2 = "4695"
SRCREV_pn-intone = "${AUTOREV}"
SRCREV_pn-connman = "aac35324deb8c0b57f881338d87cb36b0979e7df"
SRCREV_pn-msn-pecan = "${AUTOREV}"
SRCREV_pn-omgps = "${AUTOREV}"
SRCREV_pn-shr-today = "${AUTOREV}"
SRCREV_pn-shr-launcher = "${AUTOREV}"
SRCREV_pn-e-tasks = "${AUTOREV}"
SRCREV_pn-mokonnect = "${AUTOREV}"
SRCREV_pn-elmdentica = "${AUTOREV}"
SRCREV_pn-vala-terminal = "${AUTOREV}"
