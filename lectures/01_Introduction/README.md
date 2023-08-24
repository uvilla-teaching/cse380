# Access lonestar6

1. Use ssh to connect to lonestar6 (Replace `villa13` with your user id)


```
ssh villa13@ls6.tacc.utexas.edu
```

2. Enter your password

3. Enter your TACC Token (e.g. using DUO)

## Set up ssh-keys to avoid entering the password each time

1. If you don't have a ssh key, generate one on your machine with

```
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

2. Use `ssh-copy-id` to copy your public key on lonestar6

```
ssh-copy-id villa13@ls6.tacc.utexas.edu
``` 

3. Connect to lonestar6 (You'll still need to enter the TACC Token)

```
ssh villa13@ls6.tacc.utexas.edu
```

