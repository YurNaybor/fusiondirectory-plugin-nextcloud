#!/bin/bash
#
# Build a debian package for the plugin.
#
# Note that we currently build one package for the implementation in fusiondirectory as well as the ldap schema as opposed to the "official" way of a seperate package for the schema.

WORKDIR=./work
FD_HOME=usr/share/fusiondirectory
DEB=fusiondirectory-plugin-nextcloud.deb

rm -rf $WORKDIR $DEB

mkdir -p $WORKDIR/$FD_HOME/plugins
mkdir -p $WORKDIR/$FD_HOME/locale/plugins/nextcloud
mkdir -p $WORKDIR/etc/ldap/schema/fusiondirectory

cp -r src/admin $WORKDIR/$FD_HOME/plugins/
cp -r src/html $WORKDIR/$FD_HOME/
cp -r src/locale $WORKDIR/$FD_HOME/locale/plugins/nextcloud/
cp -r src/personal $WORKDIR/$FD_HOME/plugins/

cp src/contrib/openldap/nextcloud.schema $WORKDIR/etc/ldap/schema/fusiondirectory/

cp -r src/DEBIAN $WORKDIR/

chown -R root:root $WORKDIR

dpkg-deb --build $WORKDIR $DEB
