# Lustre and BeeGFS

Create a 5MB file `bigfile.test` on `$WORK` and check how Lustre striped it

```
cdw
dd if=/dev/zero of=./bigfile.test bs=4k iflag=fullblock,count_bytes count=5M
lfs getstripe bigfile.test
```


Do the same on `SCRATCH` which uses BeeGFS
```
cds
dd if=/dev/zero of=./bigfile.test bs=4k iflag=fullblock,count_bytes count=5M
beegfs-ctl --getentryinfo bigfile.test
```
