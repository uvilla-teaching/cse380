# Build the container
First let's build the docker image for step3, remember to specify `--platform=linux/amd64` if using Apple Silicon.
```
docker build -t step3 .
```

# Explore the container interactively
```
docker run -it step3 /bin/bash
```

From inside the container

```
module avail

mpicc /opt/ohpc/pub/examples/mpi/hello.c 
mpirun -np 2 ./a.out
```

# Push the container to the DockerHub registry
First of all create an account of dockerhub.
Next, login, tag and push the image
```
docker login
docker tag step3 uvilla/step3:2024.1
docker push uvilla/step3:2024.1
```

To deploy the image on lonestar6, see `../hello_apptainer.md`
