# Step 1:

Let's see my current images

```
docker images
```

Let's build the image for step 1

```
docker build -t step1 .
docker images
```

Note: it's a dot! It tells docker to look in the current directory for a file called `Dockerfile`

Now we can run the container

```
docker run -it step1 /bin/bash
```

I can now do a few things from inside this container.

```
cat /etc/rocky-release
cat /proc/cpuinfo
whoami
touch newfile
```

Outside the container:

```
docker ps
docker ps -a
```