# How to git your way around

## Create your local repository (just for yourself!)

```
mkdir myrepo
cd myrepo
git init
git branch -m main
```

The last command renames the current branch as `main`.
Do the following
```
ls
git log
ls -a
```

## Add files

We create a new file. Then we _stage_ it using  `git add` and then we _commit_ it using `git commit`

```
touch CHANGELOG
git add CHANGELOG
git status
git commit -m "add changelog"
git status
git log
```

Add more files from a subdirectory

```
mkdir docs
touch docs/modeling.tex
git add docs/modeling.tex
git commit -m "add starting modeling doc"
git log -–pretty=oneline
```

## Make changes to an existing file

```
echo "Added documentation for the forward model" >> CHANGELOG
git status
git diff CHANGELOG
git commit -m "Update change log"
```

## Clone a local repo

```
git clone myrepo myrepo2
```

Commit some changes in `myrepo` and use `git pull` to fetch those changes in `myrepo2`. 

## Clone an existing repo from Github

Read-only public repository: use `https`
```
git clone https://github.com/uvilla-teaching/cse380.git
```

Passwordless Read/write access (both public and private repositories): use `ssh`
```
git clone git@github.com:uvilla-teaching/cse380.git
```

Show
```
git remote -v
```

Make a change on the remote repo and then pull
```
git pull
```


Show how to set-up keys. To verify things are good to go
```
ssh -T git@github.com
```

## Sending changes back to GitHub

Step 1: Create an empty repo on GitHub called `myrepo`

Step 2: Set the remote repo
```
git remote -v
git remote add origin git@github.com:uvilla-teaching/myrepo.git
git push --set-upstream origin main
```

## Branching
Create a new branch and move to that branch. Note the `-b` option to create a branch that before did not exist
```
git checkout -b testing
git status
echo "Making more changes" >> CHANGELOG
git add CHANGELOG
git commit -m "Make some new work in testing branch"
```

Optional if you want to push the branch on GitHub
```
git push -u origin testing
```

Go back to the main branch
```
git checkout main
cat CHANGELOG
git merge testing
cat CHANGELOG
```

Push the merge to GitHub:
```
git push
```

## Extra

### Creating and resolving a conflict

1. Create a new branch `dev`, modify `CHANGELOG`, and commit
2. Go back to `main`, also modify `CHANGELOG`, and commit
3. Type `git merge dev`, show and resolve the conflict

### Ignore some files
Create a `.gitignore` file to tell git to avoid tracking some files. Point out that GitHub has several default `.gitignore` for the programming language you are using.

 ### Create a tag
To tag a specific version of the repo
```
git tag -a v0.1 -m "my first version"
```
Note: by default git push will not push tags. You need:
```
git push origin --tags
```

 ### Pull requests

 Show in GitHub :)
