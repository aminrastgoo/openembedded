DESCRIPTION = "TI Local Power Manager (LPM)"
HOMEPAGE = "http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/lpm"
SECTION = "devel"

# TODO : Hardcoded path to evm3530 - need to fix when adding omap24xx/dm6446 (other lpm targets)

require ti-paths.inc
require ti-staging.inc

PROVIDES = "ti-lpm-module"
PROVIDES += "ti-lpm-utils"

# This package builds a kernel module, use kernel PR as base and append a local version
PR = "${MACHINE_KERNEL_PR}"
PR_append = "c"

S = "${WORKDIR}/local_power_manager_linux_${PV}"

SRC_URI = "http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/lpm/${PV}/exports/local_power_manager_linux_${PV}.tar.gz;name=lpmtarball"

DEPENDS = "ti-dsplink ti-xdctools"
DEPENDS += "virtual/kernel"

# SOC_FAMILY configuration

LPMDSPPOWERSOC_omap3  = "omap3530"
LPMDSPPOWERSOC_dm6446 = "dm6446"
LPMDSPPOWERSOC       ?= "<UNDEFINED_LPMDSPPOWERSOC>"

XDC_PLATFORM_dm6446   = "ti.platforms.evmDM6446"
XDC_PLATFORM_omap3    = "ti.platforms.evm3530"
XDC_PLATFORM         ?= "<UNDEFINED_XDC_PLATFORM>"

do_configure () {

    # Generate a config.bld for XDC

    cat > ${S}/config.bld <<EOF

/* Generated by ti-local-power-manager.inc OE recipe */

var Build = xdc.useModule('xdc.bld.BuildEnvironment');

var GCArmv5T = xdc.useModule('gnu.targets.arm.GCArmv5T');
GCArmv5T.LONGNAME = "bin/${TARGET_PREFIX}gcc";
GCArmv5T.rootDir = "${TOOLCHAIN_PATH}";
GCArmv5T.ccOpts.prefix += " -Wall -fno-strict-aliasing ";
GCArmv5T.lnkOpts.suffix = GCArmv5T.lnkOpts.suffix.replace("-lstdc++", "");
GCArmv5T.lnkOpts.suffix += " -lpthread ";
GCArmv5T.platform = null;
GCArmv5T.platforms = [
    "${XDC_PLATFORM}"
];

/* remove profiles we don't use */
delete GCArmv5T.profiles["coverage"];
delete GCArmv5T.profiles["profile"];

Build.targets.\$add(GCArmv5T);
EOF

}

do_prepsources () {

    # Prepare the tree for rebuiling - generate makefiles and clean
    XDCPATH=${S} ${XDC_INSTALL_DIR}/xdc .make -PR .
    XDCPATH=${S} ${XDC_INSTALL_DIR}/xdc clean -PR .
}

addtask prepsources after do_configure before do_compile

do_compile () {

    # Build the LPM kernel module
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    cd ${S}/packages/ti/bios/power/modules/${LPMDSPPOWERSOC}/lpm
    make \
      DSPLINK_REPO="${LINK_INSTALL_DIR}" \
      LINUXKERNEL_INSTALL_DIR="${STAGING_KERNEL_DIR}" \
      MVTOOL_PREFIX="${TARGET_PREFIX}" \
      clean default

    # Build the user space library
    # TODO

    # Build the utilities (lpmON/OFF)
    cd ${S}
    XDCPATH=${S} ${XDC_INSTALL_DIR}/xdc -PR .
}

KERNEL_VERSION = "${@base_read_file('${STAGING_KERNEL_DIR}/kernel-abiversion')}"

do_install () {

    # Install the kernel module 
    install -d ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/dsp
    install -m 0755 ${S}/packages/ti/bios/power/modules/${LPMDSPPOWERSOC}/lpm/*.ko ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/dsp

    # Install the Utilities
    install -d ${D}/${installdir}/ti-lpm-utils
    install -m 0755 ${S}/packages/ti/bios/power/utils/bin/$(echo ${XDC_PLATFORM} | sed s:\\.:_:g)/linux/release/* ${D}/${installdir}/ti-lpm-utils

    # Install/Stage the Source Tree 
    install -d ${D}${LPM_INSTALL_DIR_RECIPE}
    cp -pPrf ${S}/* ${D}${LPM_INSTALL_DIR_RECIPE}
}

PACKAGES += "ti-lpm-module"
FILES_ti-lpm-module = "/lib/modules/${KERNEL_VERSION}/kernel/drivers/dsp/*lpm*ko"
RDEPENDS_ti-lpm-module += "ti-dsplink-module"
RDEPENDS_ti-lpm-module += "update-modules"

pkg_postinst_ti-lpm-module_append () {
        if [ -n "$D" ]; then
                exit 1
        fi
        depmod -a
        update-modules || true
}

pkg_postrm_ti-lpm-module_append () {
        update-modules || true
}

PACKAGES += "ti-lpm-utils"
RDEPENDS_ti-lpm-utils += "ti-lpm-module"
FILES_ti-lpm-utils = "${installdir}/ti-lpm-utils/*"
INSANE_SKIP_ti-lpm-utils = True