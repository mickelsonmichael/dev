# Git Branches, Merges, and Remotes

With **Kevin Skoglund**  
*Started:* January 15, 2020  
*Completed:* January 21, 2020  
*Next Course:* [Git Intermediate Techniques](https://www.linkedin.com/learning/git-intermediate-techniques)

- [Git Branches, Merges, and Remotes](#git-branches-merges-and-remotes)
  - [1. Navigate the Commit Tree](#1-navigate-the-commit-tree)
    - [`git log`](#git-log)
  - [2. Branching](#2-branching)
    - [Switch Branches](#switch-branches)
    - [Compare Branches](#compare-branches)
    - [Rename Branches](#rename-branches)
    - [Delete Branches](#delete-branches)
    - [Configure Command Prompt](#configure-command-prompt)
  - [3. Reset Branches](#3-reset-branches)
    - [Soft Reset](#soft-reset)
    - [Mixed Reset](#mixed-reset)
    - [Hard Reset](#hard-reset)
  - [4. Merge Branches](#4-merge-branches)
    - [Merge Conflicts](#merge-conflicts)
    - [Strategies to Reduce Merge Conflicts](#strategies-to-reduce-merge-conflicts)
  - [5. Stash Changes](#5-stash-changes)
  - [6. Set Up a Remote](#6-set-up-a-remote)
    - [Creating Remote Branches](#creating-remote-branches)
    - [Clone a Remote Repository](#clone-a-remote-repository)
    - [Tracking Remote Branch](#tracking-remote-branch)
  - [7. Collaborate with a Remote](#7-collaborate-with-a-remote)
    - [Check Out Remote Branches](#check-out-remote-branches)
    - [Delete a Remote Branch](#delete-a-remote-branch)
  - [Conclusion](#conclusion)

## 1. Navigate the Commit Tree

**Tree-ish** is used to reference both trees and the point when a tree has been applied. A tree-ish is a directory, commit, or reference

- SHA-1 Hash
  - 40 character string identifying a commit
  - To find a commit, you should use a minimum of 4 characters
  - Ideally between 8-10 characters to find a commit
- HEAD pointer reference
  - Tracks the location of where the current checkins will go
  - .git/HEAD
  - .git/refs/heads/master
- Branch Reference
- Tag reference
- Ancestry

You can refer to the parent of any commit by adding the caret `^` symbol. It will tell Git that you want to access the parent of the specified commit. You can use either the commit SHA, HEAD, or branch name. These carets may stack multiple times, so `HEAD^^` will go to the parent of the parent.

To go back a certain number of children, you can use the tilde `~` to go back any number of commits like `HEAD~4` to go back four commits from the HEAD. Generally, developers use this format instead of the carets after 3 or more parents.

`git ls-tree <treeish>` will list the contents of a tree-ish object. This is simlar to typing `ls -a` or `dir` into a terminal window. For example, `git ls-tree HEAD` will open up the "listing" for the HEAD; some items will be listed as "tree" while others will be "blobs." A blob (binary large object) is a file and not a tree. Running this command on HEAD or any other changeset will display the file structure of the project at the time of the commit. You can look to a deeper branch of the tree by adding the name of the directory to the ls-tree command like `git ls-tree HEAD directory/`. It's important to remember the forward slash after the directory name, otherwise the command will perform pattern matching and just show the items that match that name on the top level.

### `git log`

You can specify the number of commits to show when using `git log` by adding a `-n` to the command, where `n` is the number of commits to show. `git log -3` would show the last three commits.

`git log` also accepts dates with the `--since=2020-01-02` and `--before=2020-01-03` or `--until=2020-01-03` to narrow the commits by a time frame. Relative dates, like `2.weeks` or `"3 days ago"` will do a smart detection of the specified date based on the current date time.

`git log --author="name"` will return commits only made by a particular author.

`git log --grep="regex"` can be used to search *all* the metadata for commits to find a particular phrase.

`git log <SHA1>..<SHA2>` will return all the commits *after* `<SHA1>` and up to (and including) `<SHA2>`.

`git log <file>` limits the list of changes to only commits that affected the specified file.

`git log -p` where `-p` stands for "patch." Patch is the same thing as a changeset. This option will show all the commits in the log *and* their changes.

`git log --stat` will show the statistics about the changes made, including number of files changed, insertions, and deletions.

`git log --format=<format>` modifes the format of the git log. The default value is `medium`, but you can also select several other options

- oneline
- short
- medium (*default*)
- full
- fuller
- email
- raw

`git log --oneline` is an alternative to using `--format=oneline`, but will also truncate the SHA key to make the result a little more readable.

To view the branch path, you can use `git log --graph`. You can combine a large number of the options to make a very helpful result with `git log --graph --all --oneline --decorate`.

## 2. Branching

Branches are cheap, and make it easy to try new ideas. The cost of making a branch is very very low, and very fast. Creating a new branch is much faster than creating a series of changesets and attempting to undo them if you change your mind later.

When you create a branch, there will still only be one working directory. It's not like making a duplicate of the files; it's only swapping out the changes in the branch. Git will make these changes *very* fast and automatically when switching between branches.

When switching branches, the HEAD pointer will move between the last commits of the two branches. Initially, after creating a new branch, it will still be pointing to the same branch as the parent branch, but once a new commit is made the HEAD will move fully into the child branch.

To create a branch, you simply need to use `git branch <name>`. Branch names should not contain spaces, and you will need to switch branches before you can begin working.

Within the .git/HEAD file, you will find a reference to a branch. These branch references are located in .git/refs/heads folder, and the .git/HEAD file will reference the filename that matches the branch name. For example, if HEAD is on the master branch, then .git/HEAD will contain "ref: .git/refs/heads/master." The files themselves will contain a SHA key for the latest commit.

You may also view the branches and HEADs more easily using the `git log` command.

### Switch Branches

The command `git checkout <branch>` will checkout the specified branch. The HEAD pointer will now point at the new branch, and all commits will go onto that branch instead.

If you want to create a branch and check it out immediately, you can use the `git checkout -b <branch>` command where `<branch>` is the name of the new branch.

When you use a `git checkout` command you tell Git to retrieve the current version of the branch from the repository.  If you attempt to checkout while you have uncommitted changes, Git will tell you that you have to either remove the changes, or commit them before you can proceed.

- You cannot switch if you have unsaved changes in the working directory
- You *can* switch if the changes can be applied without conflict
- You *can* switch if files are not being tracked

If you have a conflict you can

- Commit the changes to the current branch
- Remove the changes (`git checkout -- <file>`)
- Stash the changes

### Compare Branches

`gif diff` can be used to compare any two tree-ish, including two files or two branches. To compare the "master" branch to the "feature" branch, you could use `git diff master..feature`. Flipping the order of the branches will show you the reverse of the changes. What is an insertion in one order will become a deletion in the other order. Typically, you want to put the older branch first.

With the `git branch --merged` command will show you all the other branches that are reachable from the current commit. `git branch --no-merged` will show the opposite, show branches that are not fully included in the current branch.

### Rename Branches

To rename a branch, you can utilize the `-m` option of the `git branch` command. The `-m` stands for move, because you are "moving" one branch to a new "location." To rename a feature branch that is currently checked out, you can use `git branch -m new_name`. To rename a feature branch that is *not* currently checked out, you can use `git branch -m old_name new_name`.

### Delete Branches

If you have the branch to be deleted currently checked out, you will need to change to another branch. Then you can use `git branch -d <branch>` to delete a branch (`-d` is for delete). Git has several checks to make sure you don't do this accidentally.

1. You must not be in the branch you want to delete
2. If your branch is not fully merged, you must use the `-D` option

If you are going to delete a branch, always use the lowercase `-d` just in case, that way you will get the warning from Git about your unmerged changes.

### Configure Command Prompt

Git prompt will give additional information about the currently checked out page. This comes pre-installed with Git Bash by default. You can find it inside the Git repository by searching for "git-prompt."

## 3. Reset Branches

> Reset changes the files in the staging index and/or working directory to the state they had when a specified commit was made

This will move the HEAD pointer to a specific commit and update the files to match that version.

### Soft Reset

- Moves HEAD pointer
- Does not change staging index
- Does not change working directory
- `git reset --soft <tree-ish>` (a commit, branch, or tag)
  
This is used to return to an old state but leave code changes staged, which can be used to amend one or more commits. Similar to `git commit --amend`. When you do a reset, the old commits will be unreachable. **You should only do resets when you are working in a private repository or have not pushed changes to a group repository.**

This type of reset is most useful for backing up changes and combining them into a single commit.  

### Mixed Reset

- Moves HEAD pointer
- Changes the staging index to match the repository
  - Staged changes will be replaced
- Does not change working directory
- `git reset --mixed <tree-ish>`
- The default reset setting

Allows us to return to an old state while leaving the working directory alone. This is useful for reorganizing commits. 

### Hard Reset

- Moves HEAD pointer
- Changes staging index to match repository
- Changes working directory to match repository
- Rollbacks all changes to the specific point
- `git reset --hard <tree-ish>`

This is useful for going back to a previous version. All the commits will be undone.

Commits which are abandoned will eventually be cleaned up by Git. You will be able to reset back to them in the short term, but they may disappear.

## 4. Merge Branches

When doing a `git merge`, you should be on the branch you want to receive the changes **into**. Performing a `git merge feature` will bring the changes from "feature" into the "master" branch. **Always run merges with a clean working directory** to make things more simple; either stash your changes or commit them.

There are two version of merging, fast-forward and true merge. 

When you merge a branch and the history of the branch passes over the HEAD of the current branch, you perform a fast-forwards instead. In other words, if the branch was created from the HEAD of the original branch, then no true merge needs to happen, Git can simply bring the master branch up to the HEAD of the new branch.

![fast-forward gif](https://i.stack.imgur.com/Wne9D.gif)

A "real" commit will require a commit in order to merge the changes. This occurs when the feature branch cannot be fast-forwarded; when the master branch has changesets that the feature branch does not.

### Merge Conflicts

A conflict occurs when there are two changes to the same line or set of lines in two commits. When this happens, you will still be on the branch, but you will be in an unmerged state. You will be able to view the conflicts inside each of the files with conflicts; Git will insert some merging code, with both version visible in the file with the conflict. Simply remove one of the versions within the conflict markers and stage those changes to fix the merge issue(s).

```plaintext
<<<<<<<
    This is one version
======
    This is another version
>>>>>>>
```

You can abort a merge with `get merge --abort` to back up, and undo all the changes that are pending. You will be able to make modifications and try the merge again. `git reset --hard` will also let you undo this merge.

Git will continue to alert you when you have pending conflicts. Once they are all resolved, you will need to commit the changes in order to fully complete the merge.

Additionally, you can use `git mergetool` which will help you with the merge conflict. However, the instructor does not use this method and instead manually resolves them or uses a GUI.

### Strategies to Reduce Merge Conflicts

- Keep lines short
- Keep commits small and focused
- Beware edits to whitespace
- Merge *often*
- Track changes to master

## 5. Stash Changes

- `git stash save [-u] <name>`
- `git stash show [-p] <id>`
- `git stash pop <id>`
- `git stash apply <id>`
- `git stash drop <id>`
- `git stash clear`

The stash is not part of the repository, staging index, or working directory. It is a fourth area, separate from the rest. You can store things in the stash by using `git stash save <name>`; this will remove all the changes in your working directory into the stash. That will allow you to checkout new branches.

By default, stash **doesn't include untracked files.** This is because there isn't a conflict with the file, you aren't stopped from switching branches. To include any untracked files you should use the `-u` option or `--untracked`.

To view everything in the stash, use `git stash list`. You can view a stash using `git stash show <stashId>`. The stash ID will usually be something like `stash@{n}` where `n` is the ID number of the stash. Include the `-p` option to the show command and you will view the actual changes.

Changes in the stash are **independent** of the changes in your branch.

Utilize `git stash pop <stashId>` to remove a single stash and apply it to the working directory. If you have only one, you don't need to specify a stash ID, otherwise pop will remove the first item. `pop` will apply it immediately to the working directory **and** remove it from the stash.

With `git stash apply <stashId>`, you will apply the changes to the working directory **without** deleting it from the stash. This will let you apply the same stash to multiple branches. If there is only one item in the stash, you don't need to specify a stash ID.

It's possible for a stash to result in conflicts. If this happens, you will need to resolve any merge conflicts that come up. This is uncommon because of the transient nature of the stash, but not impossible.

If you want to clear the stash, you should use `git stash drop <id>` to drop a particular stash item or `git stash clear` to clear them all.

## 6. Set Up a Remote

Local Git repositories do not require an internet connection. Remote servers allow for easier collaboration, since there is a centralized location designated as the "main" branch. Keep in mind that in reality, there is no difference between the remote repository and any other repository.

Generally, you will create a copy of the remote branch named `origin/branch`. This will attempt to stay as similar to the remote server as possible. You will need to push and fetch changes from the remote server into your `origin` branch.

Once you set up a remote repository on either GitHub, Bitbucket, or Azure, use the provided commands to create a new remote branch.

To list the current remotes, use `git remote`. Then add one using `git remote add <name> <url>`; in general, the name of the main remote branch should be called "origin." The URL will be specific to your account, so it will need to be modified to be shared.

When using `git remote`, adding the `-v` option will give additional options.

Typically you will only have one remote and it will be called "origin," but it's not unheard of to have multiple.

`git remote rm <name>` will remove the remote with the given name. This is an uncommon scenario, you usually stick with a remote once you've got it.

### Creating Remote Branches

You can have local branches that only you see and only you work with, and you push branches on a branch-by-branch basis. You can also have remote branches that everyone can share.

To push a local branch to the remote repository, you can use `git push <remote> <local>`. When first creating a branch, it's recommended to use the `-u` option, which will tell Git to track the branch. This command may ask you to provide credentials in order to access the remote branch, there are a number of different ways to solve this problem (if you're using MFA then the user/password option won't work).

When you create a remote branch, a new folder is created inside of `.git/refs/remotes/<name>`, and inside that folder are each of the branches associated with that remote, all containing the SHA for the tip of the branch.

### Clone a Remote Repository

When you want to pull down a version of the repository and you already have a folder and Git set up on your machine, you can simply add a new remote. There should be a convenient URL for you to enter in while creating a remote using the `git remote add <url>`.

However, if you don't already have a git directory, then you can use the `git clone <ul> <name?>` command to initialize and pull down all in one step. If you do not specify a name, then Git will create the name based on the naming of the .git file you are cloning. For example, if cloning <https://github.com/mickelsonmichael/Notes.git>, then Git would create a directory called "Notes." By default, when you clone, only the master branch is brought down.

### Tracking Remote Branch

You can have a branch that "tracks" another; keeps it regularly in sync by pulling from the main branch frequently, so they don't diverge too often, reducing the number of merge conflicts.

Tracking is really common with remote branches, and saves a lot of trouble. Your master branch will track the origin/master branch, so you will want to sync it up frequently to prevent the number of issues you run into. Without tracking, you will need to specify the remote branch every time you want to interact with it. In a tracking branch, this will be automatic.

When using the `-u` option in a push or pull, the branch will automatically be tracked. If you forget, you will need to use `git branch -u <upstream> <branch>`, where the u is equivalent to `--set-upstream-to=<upstream>`. For example, you would write `git branch -u origin/master master`.

If needed you can use `git branch --unset-upstream <branch>` to untrack a branch.

Tracking will be automatic when cloning.

## 7. Collaborate with a Remote

The `origin/master` branches are "tracking branches" and *not* the actual remote branch. The information is offline, allowing for local work without an internet connection.

Use `git push <alias> <branch>` to push all the information from the local branch to the tracking branch. If you have tracking enabled for the current branch, you can simply use `git push` to automatically push to the tracking branch.

To synchronize the origin/master with the remote server, you can use `git fetch <origin>`. This will bring down any new changesets from the remote server into the local tracking branch. Fetch *does not change the local branch*, and therefore does not impact any incomplete work. It doesn't actually merge anything into the existing branches. For this reason, you should fetch often

- Fetch before you work (at the start of the day)
- Fetch before you push
- Fetch before you go offline
  - Before you go on a vacation or trip
  - Allows you to work offline
- Fetch often
  - No harm in doing it
  - Not destructive
  - Just do it frequently

When you fetch, the changes are in your tracking branch, so you will need to merge them into your local branch. *You will only be merging with the local tracking branch, so you will always want to **fetch first***. Simply use the `git merge <trackingBranch>` command.

The two-step process should be `git fetch` then `git merge`. But there is a shortcut called `git pull`, which will do the fetch then merge them in. You should use this with caution as a beginner. The instructor says he uses both interchangeably, depending on what kind of situation he is in; if he wants to merge later, he uses the `fetch`, but if he wants to do them at once right now, he'll use `pull`.

### Check Out Remote Branches

With the command `git branch <name> <tracking>` you can specify a tracking branch to point to. If you want to create and checkout at the same time you can use `git checkout -b <name> <tracking>`.

If you attempt to push your changes to the remote branch while there are untracked changes in the remote repository, Git will not let you. You will need to fetch those changes first, so that Git knows where in the timeline your changes will go.

### Delete a Remote Branch

You can remove a remote branch at any time, but it is most useful when a feature branch is complete and merged. 

If you use `git push <origin> :<branch>`, it will delete the remote repository. The colon in front of the branch name lets Git know that you intend to delete the branch. This will only delete the remote branch, your local branch will be unchanged. This syntax is because you normally are doing something like `git push origin master:master`, which tells Git you want to push one branch to another; by omitting the first operator you are saying "push nothing to the branch."

Now however, you can use `git push origin --delete branch`. They do the same thing, but this one is in a slightly more readable format than the original.

## Conclusion

You can add aliases to get using `git config --global alias.<keys> "<replaced>"`. So you could create one like `git config --global alias.logg "log --graph --decorate --online --all"` to allow you to simply type `git logg` and get the entire result.

Beginners should learn the real commands well before using the aliases.

You can create SSH keys fro remote login. This is out of the scope of the project, but can be helpful. See the [GitHub Help Pages](https://help.github.com/en/articles/set-up-git) section about connecting over SSH. SSH keys can be used to login to other servers as well, without needing to type another password.

There are many IDEs and GUIs that integrate with Git.

You can continue learning with [Git Intermediate Techniques](https://www.linkedin.com/learning/git-intermediate-techniques) which will teach some of the more advanced features of Git.
