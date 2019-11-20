# fusiondirectory-plugin-nextcloud

LDAP and Fusiondirectory extensions for managing Nextcloud users and groups


## Building the debian package

```
fakeroot ./build-deb.sh
```


## References

- [Used ldap schema extensions from the debops project](https://github.com/debops/debops/blob/master/ansible/roles/debops.slapd/files/etc/ldap/schema/debops/nextcloud.schema)
- [Fusiondirectory developer documentation](https://fusiondirectory-developer-documentation.readthedocs.io/en/1.3/pluginsystem/start.html)
- [Fusiondirectpry posifx plugin implementatin](https://gitlab.fusiondirectory.org/fusiondirectory/fd-plugins/blob/1.4-dev/posix/personal/posix/class_posixAccount.inc)
- [Images and icons from the nextcloud project](https://github.com/nextcloud/server/tree/master/core/img)
