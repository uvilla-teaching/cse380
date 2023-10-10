# Hello Docker.

Here some simple examples on how to run Docker.

Let's start pulling a Ubuntu image

```
docker run -it ubuntu bash
```

Above we use the option `-it` to get an interactive shell in the container. Note the first time we run this command it will take some time to download the image, but the second time it will be faster.
Also, note: When running on linux, you must use `sudo`. 


Let's play around inside the container.

```
whoami
```
I am the `root` user!

```
uname -a
```
Yep, I am actually running linux!

```
make
```
Opsy... There is not much stuff installed here...

But since I am root
```
apt-get update
apt-get install build-essential
which make
```

However, what happen if I exit and rerun the command above?

Show `docker ps -a` and `docker images` in a different window.

Do you prefer a different Linux distro?

```
docker run -it fedora bash
``` 

Here, the package manager is called `yum`.
