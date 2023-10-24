```
docker build -t step3 .
docker run -it step3 /bin/bash
```


From inside the container

```
module avail

mpicc /opt/ohpc/pub/examples/mpi/hello.c 
mpirun -np 2 ./a.out
```

How to push this remotely

```
docker login
docker tag step3 uvilla/step3:2023.1
docker push uvilla/step3:2023.1
```
