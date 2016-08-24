-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

Format: 1.0
Source: linux-meta
Binary: linux-source, linux-crashdump, linux-image-hwe-generic-trusty, linux-hwe-generic-trusty, linux-image-hwe-virtual-trusty, linux-hwe-virtual-trusty, linux-tools-lts-quantal, linux-headers-generic-lts-quantal, linux-image-generic-lts-quantal, linux-generic-lts-quantal, linux-generic-lts-quantal-eol-upgrade, linux-signed-image-generic-lts-quantal, linux-signed-generic-lts-quantal, linux-signed-generic-lts-quantal-eol-upgrade, linux-tools-lts-raring, linux-headers-generic-lts-raring, linux-image-generic-lts-raring, linux-generic-lts-raring, linux-generic-lts-raring-eol-upgrade, linux-signed-image-generic-lts-raring, linux-signed-generic-lts-raring, linux-signed-generic-lts-raring-eol-upgrade, linux-tools-lts-saucy, linux-headers-generic-lts-saucy, linux-image-generic-lts-saucy, linux-tools-generic-lts-saucy, linux-generic-lts-saucy, linux-generic-lts-saucy-eol-upgrade, linux-headers-generic-lpae-lts-saucy, linux-image-generic-lpae-lts-saucy,
 linux-tools-generic-lpae-lts-saucy, linux-generic-lpae-lts-saucy, linux-generic-lpae-lts-saucy-eol-upgrade, linux-signed-image-generic-lts-saucy, linux-signed-generic-lts-saucy, linux-signed-generic-lts-saucy-eol-upgrade, linux-tools-lts-trusty, linux-headers-generic-lts-trusty, linux-image-generic-lts-trusty, linux-tools-generic-lts-trusty, linux-generic-lts-trusty, linux-headers-generic-lpae-lts-trusty, linux-image-generic-lpae-lts-trusty, linux-tools-generic-lpae-lts-trusty, linux-generic-lpae-lts-trusty, linux-signed-image-generic-lts-trusty, linux-signed-generic-lts-trusty, linux-headers-generic, linux-image-generic, linux-tools-generic, linux-cloud-tools-generic, linux-generic, linux-headers-generic-lpae, linux-image-generic-lpae, linux-tools-generic-lpae, linux-generic-lpae, linux-headers-generic-pae, linux-image-generic-pae, linux-generic-pae, linux-headers-highbank, linux-image-highbank, linux-highbank, hv-kvp-daemon-init, linux-headers-lowlatency,
 linux-image-lowlatency, linux-tools-lowlatency, linux-cloud-tools-lowlatency, linux-lowlatency, linux-headers-lowlatency-pae, linux-image-lowlatency-pae, linux-lowlatency-pae, linux-headers-omap, linux-image-omap, linux-omap, linux-headers-powerpc-e500, linux-image-powerpc-e500, linux-tools-powerpc-e500, linux-powerpc-e500, linux-headers-powerpc-e500mc, linux-image-powerpc-e500mc, linux-tools-powerpc-e500mc, linux-powerpc-e500mc, linux-headers-powerpc-smp, linux-image-powerpc-smp, linux-tools-powerpc-smp, linux-powerpc-smp, linux-headers-powerpc64-emb, linux-image-powerpc64-emb, linux-tools-powerpc64-emb, linux-powerpc64-emb, linux-headers-powerpc64-smp, linux-image-powerpc64-smp, linux-tools-powerpc64-smp, linux-powerpc64-smp, linux-headers-server, linux-image-server, linux-server, linux-signed-image-generic, linux-signed-generic, linux-headers-virtual, linux-image-virtual, linux-tools-virtual, linux-cloud-tools-virtual, linux-virtual,
 linux-image-extra-virtual
Architecture: all i386 amd64 ppc64el armhf arm64 powerpc
Version: 3.13.0.92.99
Maintainer: Ubuntu Kernel Team <kernel-team@lists.ubuntu.com>
Standards-Version: 3.6.1
Vcs-Git: http://kernel.ubuntu.com/git-repos/ubuntu/ubuntu-trusty-meta.git
Build-Depends: dpkg (>= 1.13.19), debhelper (>= 5), gawk
Package-List:
 hv-kvp-daemon-init deb oldlibs optional arch=amd64
 linux-cloud-tools-generic deb kernel optional arch=amd64
 linux-cloud-tools-lowlatency deb kernel optional arch=amd64
 linux-cloud-tools-virtual deb kernel optional arch=amd64
 linux-crashdump deb devel optional arch=i386,amd64,ppc64el
 linux-generic deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-generic-lpae deb kernel optional arch=armhf
 linux-generic-lpae-lts-saucy deb kernel optional arch=armhf
 linux-generic-lpae-lts-saucy-eol-upgrade deb metapackages optional arch=armhf
 linux-generic-lpae-lts-trusty deb kernel optional arch=armhf
 linux-generic-lts-quantal deb metapackages optional arch=i386,amd64
 linux-generic-lts-quantal-eol-upgrade deb metapackages optional arch=amd64
 linux-generic-lts-raring deb metapackages optional arch=i386,amd64,armhf
 linux-generic-lts-raring-eol-upgrade deb metapackages optional arch=amd64,armhf
 linux-generic-lts-saucy deb metapackages optional arch=i386,amd64,armhf
 linux-generic-lts-saucy-eol-upgrade deb metapackages optional arch=i386,amd64,armhf
 linux-generic-lts-trusty deb metapackages optional arch=i386,amd64,armhf
 linux-generic-pae deb kernel optional arch=i386
 linux-headers-generic deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-headers-generic-lpae deb kernel optional arch=armhf
 linux-headers-generic-lpae-lts-saucy deb kernel optional arch=armhf
 linux-headers-generic-lpae-lts-trusty deb kernel optional arch=armhf
 linux-headers-generic-lts-quantal deb devel optional arch=i386,amd64
 linux-headers-generic-lts-raring deb devel optional arch=i386,amd64,armhf
 linux-headers-generic-lts-saucy deb devel optional arch=i386,amd64,armhf
 linux-headers-generic-lts-trusty deb devel optional arch=i386,amd64,armhf
 linux-headers-generic-pae deb kernel optional arch=i386
 linux-headers-highbank deb kernel optional arch=armhf
 linux-headers-lowlatency deb devel optional arch=i386,amd64
 linux-headers-lowlatency-pae deb kernel optional arch=i386
 linux-headers-omap deb kernel optional arch=armhf
 linux-headers-powerpc-e500 deb kernel optional arch=powerpc
 linux-headers-powerpc-e500mc deb kernel optional arch=powerpc
 linux-headers-powerpc-smp deb kernel optional arch=powerpc
 linux-headers-powerpc64-emb deb kernel optional arch=powerpc
 linux-headers-powerpc64-smp deb kernel optional arch=powerpc
 linux-headers-server deb kernel optional arch=amd64,i386
 linux-headers-virtual deb kernel optional arch=i386,amd64,ppc64el
 linux-highbank deb kernel optional arch=armhf
 linux-hwe-generic-trusty deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-hwe-virtual-trusty deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-image-extra-virtual deb kernel optional arch=i386,amd64
 linux-image-generic deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-image-generic-lpae deb kernel optional arch=armhf
 linux-image-generic-lpae-lts-saucy deb kernel optional arch=armhf
 linux-image-generic-lpae-lts-trusty deb kernel optional arch=armhf
 linux-image-generic-lts-quantal deb metapackages optional arch=i386,amd64
 linux-image-generic-lts-raring deb metapackages optional arch=i386,amd64,armhf
 linux-image-generic-lts-saucy deb metapackages optional arch=i386,amd64,armhf
 linux-image-generic-lts-trusty deb metapackages optional arch=i386,amd64,armhf
 linux-image-generic-pae deb kernel optional arch=i386
 linux-image-highbank deb kernel optional arch=armhf
 linux-image-hwe-generic-trusty deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-image-hwe-virtual-trusty deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-image-lowlatency deb kernel optional arch=i386,amd64
 linux-image-lowlatency-pae deb kernel optional arch=i386
 linux-image-omap deb kernel optional arch=armhf
 linux-image-powerpc-e500 deb kernel optional arch=powerpc
 linux-image-powerpc-e500mc deb kernel optional arch=powerpc
 linux-image-powerpc-smp deb kernel optional arch=powerpc
 linux-image-powerpc64-emb deb kernel optional arch=powerpc
 linux-image-powerpc64-smp deb kernel optional arch=powerpc
 linux-image-server deb kernel optional arch=amd64,i386
 linux-image-virtual deb kernel optional arch=i386,amd64,ppc64el
 linux-lowlatency deb kernel optional arch=i386,amd64
 linux-lowlatency-pae deb kernel optional arch=i386
 linux-omap deb kernel optional arch=armhf
 linux-powerpc-e500 deb kernel optional arch=powerpc
 linux-powerpc-e500mc deb kernel optional arch=powerpc
 linux-powerpc-smp deb kernel optional arch=powerpc
 linux-powerpc64-emb deb kernel optional arch=powerpc
 linux-powerpc64-smp deb kernel optional arch=powerpc
 linux-server deb kernel optional arch=amd64,i386
 linux-signed-generic deb kernel optional arch=amd64
 linux-signed-generic-lts-quantal deb metapackages optional arch=amd64
 linux-signed-generic-lts-quantal-eol-upgrade deb metapackages optional arch=amd64
 linux-signed-generic-lts-raring deb metapackages optional arch=amd64
 linux-signed-generic-lts-raring-eol-upgrade deb metapackages optional arch=amd64
 linux-signed-generic-lts-saucy deb metapackages optional arch=amd64
 linux-signed-generic-lts-saucy-eol-upgrade deb metapackages optional arch=amd64
 linux-signed-generic-lts-trusty deb metapackages optional arch=amd64
 linux-signed-image-generic deb kernel optional arch=amd64
 linux-signed-image-generic-lts-quantal deb metapackages optional arch=amd64
 linux-signed-image-generic-lts-raring deb metapackages optional arch=amd64
 linux-signed-image-generic-lts-saucy deb metapackages optional arch=amd64
 linux-signed-image-generic-lts-trusty deb metapackages optional arch=amd64
 linux-source deb devel optional arch=all
 linux-tools-generic deb kernel optional arch=i386,amd64,armhf,arm64,ppc64el
 linux-tools-generic-lpae deb kernel optional arch=armhf
 linux-tools-generic-lpae-lts-saucy deb metapackages optional arch=armhf
 linux-tools-generic-lpae-lts-trusty deb metapackages optional arch=armhf
 linux-tools-generic-lts-saucy deb metapackages optional arch=i386,amd64,armhf
 linux-tools-generic-lts-trusty deb metapackages optional arch=i386,amd64,armhf
 linux-tools-lowlatency deb kernel optional arch=i386,amd64
 linux-tools-lts-quantal deb kernel optional arch=i386,amd64
 linux-tools-lts-raring deb kernel optional arch=i386,amd64,armhf
 linux-tools-lts-saucy deb kernel optional arch=i386,amd64,armhf
 linux-tools-lts-trusty deb kernel optional arch=i386,amd64,armhf
 linux-tools-powerpc-e500 deb kernel optional arch=powerpc
 linux-tools-powerpc-e500mc deb kernel optional arch=powerpc
 linux-tools-powerpc-smp deb kernel optional arch=powerpc
 linux-tools-powerpc64-emb deb kernel optional arch=powerpc
 linux-tools-powerpc64-smp deb kernel optional arch=powerpc
 linux-tools-virtual deb kernel optional arch=i386,amd64
 linux-virtual deb kernel optional arch=i386,amd64,ppc64el
Checksums-Sha1:
 393615fefa3407127978c75908372295fc25d798 11021 linux-meta_3.13.0.92.99.tar.gz
Checksums-Sha256:
 559a8d08879f7e2601535c3004cd773483084472edbba061a1af86f527206fc0 11021 linux-meta_3.13.0.92.99.tar.gz
Files:
 3a95fa7a25d8c4d337bfa40b948722e7 11021 linux-meta_3.13.0.92.99.tar.gz

-----BEGIN PGP SIGNATURE-----
Version: GnuPG v2

iQIcBAEBCAAGBQJXcuAUAAoJEHqwmdxYrXhZcg8P/0dIWnboxb4bF5TGU0eZAc7F
STpB1n+ooQTtCzjV3TkqTnELlRfPBuVm8tHBb3wXM8vTt50DAYQPHsLEZKBW/L69
kkvJbslj4//9pkeSsSLL+xmn8b7lDyhPXxyB94/34oVc03nIbra711vnxSlIkqTo
cc7NHjgxmaP6rnFS1e676CNZVYWRqYBr2AENwqH1AxML7duycRI2Edd+MSaDlDLT
tLSC/4QT60NdaM9YvSA7spPsr2l5NxnjelXsUBpnREucqIftqu+pFgrCyzP4X8Z4
Iu2uGtkpG8/brWA9YGx++8g8AWDbqY6HVcmzHk9hQcxQGBM95HrwdBgsJndbjDwU
0cvGq5FHfejKZ7KrX3DVcMZYjxbp0QxP0C/hudOaCXrV8ZagWCohRg7y40+mBwWI
MxNfdP8xR1HpjgQ98bTSuLeXDtfQmiy/1UmCtV+1/ABQb3IZRIil2JlTPYnUivt9
obDZPSuVJqr49zMaPkZIbBRLqAv4Gzb4Fltqen1JfaYDizKkq6IbZ1cxkR9Kq2kh
Wb5nodgxlNsp/6nuCeLWNgNtxMcl9AaSUDgrfWTYNYqMcofTfrla1lPrccWhAawG
lTjgZZochPgs4PZ12vLV61fHPciqutvJLsrVif3akZn/1OvJRVF3n9E+OgbM2hiJ
RKWMUmbtjJN2fCYY58r6
=REYJ
-----END PGP SIGNATURE-----
