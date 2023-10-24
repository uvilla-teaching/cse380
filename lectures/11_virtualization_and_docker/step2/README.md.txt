# Build and run, but this time seeing files from host

```
docker build –t step2 .
docker run -it -v /Users/uvilla:/home/uvilla step2 /bin/bash
```

Note: `-v <host_directory>:<container_directory>` makes `<host_directory>` available from inside the container in the directory `<container_directory>`.

Other commands:

```
whoami
which git
```