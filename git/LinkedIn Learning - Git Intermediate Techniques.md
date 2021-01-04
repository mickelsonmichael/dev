# LinkedIn Learning - Git Intermediate Techniques

with Kevin Skoglund  
*Started:* January 21, 2020  
*Completed:* N/A

## 1. Branch Management

### Force Push to a Remote

You can perform a force push with `git push -f` or `git push --force`. This will ignore the remote version changes and replace them with *your* local version. This is very disruptive for anyone using the remote branch and can easily upset coworkers. Any commits the collaborators have done in their local repository are now orphaned.

You usually want to do a force push when

- Local version is better than remote
- Remote went wrong and needs repair
- Versions have diverged and merging is undesirable

### Identify Merged Branches

Using the `git branch --merged` command, you can view "branches whose [HEADs] are reachable from the specified commit." In other words, from the current commit, you could traverse your way to the HEAD of these branches. You can also specify the particular branch or commit to use for the command as a third parameter.

You can check the opposite using `git branch --no-merged`.

### Delete Local and Remote Branches

`git branch -d feature` will delete the feature branch provided that the *feature has been fully merged into the current branch*. If it has not been merged, Git will flag a warning and force you to use `git branch -D feature`; the capital D is a force command.

To delete a remote branch, you can do `git push origin :feature` or `git push --delete origin feature`. The latter is only available in Git v1.7.0+, and in Git v2.8.0+ can be truncated to `git push -d origin feature`.

### Prune Stale Branches

Pruning is to delete all stale remote-tracking branches (not the remote branches). The remote tracking branch is the local copy of the remote branch (but not the local branch itself), which you cannot actually checkout and edit.

> Stale Branch - a remote-tracking branch that no longer tracks anything because the actual branch in the remote repository has been deleted

You get a stale branch if the remote branch has been deleted. This is done automatically when you delete a remote, but it does not do this automatically for collaborators, and they will need to do it manually using `git remote prune origin`.

You can specify `--dry-run` afterwards if you want to view the results of the prune before actually carrying it out.

If you want to be able to fetch and prune at the same time, you can use `git fetch --prune` or `git fetch -p` which will prune everything, then perform the fetch. You can also set the global configuration `fetch.prune` to `true` and this will be done automatically.

To be clear, `git prune` is different from this process. That only clears orphaned records.

## 2. Tagging

A tag allows marking points in history as important, and are most often used to mark releases (e.g. v1.0, v1.1, etc.).

- Lightweight tag
  - `git tag <name> <sha>`
  - Will use the current HEAD by default if `<sha>` is omitted
- Annotated Tag
  - `git tag -a <name> -m <message> <sha>`
  - Same as lightweight, but you can also specify a message
  - `-am` is an option as well
  - If you don't put `-m`, then Git will open up an editor so you can leave a message
  - Will use the current HEAD by default if `<sha>` is omitted
  - Most common type

You can list your current tags using `git tag` or `git tag --list` or even `git tag -l`. If you want to add options to the command, the `--list` or `-l` options are required (from now on, I will refer to just the `-l` command, but both work equally). When using `-l`, you can provide a string to use as a search. This string accepts wildcard characters like `git tag -l "v2*"`, which will search for any tags that start with "v2." In general, the instructor recommends that you explicitly specify the `-l` every time you want to list a tag, which will prevent confusion and issues.

- `-l` or `--list` - list tags
- `-l <tagname>` - lists tags matching the tag names
- `-n` - list tags *and* one line of their annotations
- `-n <number>` - list tags *and* a number of lines from their annotations
- `-d` or `--delete` - permanently deletes a tag

Git push *does not* transfer tags, but fetch/pull does. In order to push them up you must be explicit. This is done in the same way you push a remote branch.

`git push <remote> <tagname>`

or

`git push <remote> --tags`

to push *all* tags at once. You can only get tags and the necessary commits by using `git fetch --tags`, but this is uncommon.

Remote tags can be deleted with `git push <remote> :<tagname>` or `git push -d <remote> <tagname>`. This does not delete the tag locally, only on the remote server.

To check out a tag, you should create a new branch by performing `git checkout -b <branchname> <tagname>`. Tags can also be checkout out like any commit. However, if you checkout a tag directly with `git checkout <tagname>` it moves the HEAD of the working directory back to the commit defined by the tag. This results in a detached head state, which is similar to being on an unnamed branch; any commits will not belong to any branch, and will eventually be garbage collected by Git. If this happens, you can save your changes in three ways

1. Create a tag on the last commit so it is still findable
2. Create a branch on the tag; you still need to checkout the branch to re-attach the head
3. Create a branch on the tag and check it out. This will reattach the HEAD

## 3. Interactive Staging

The ability to stage changes *interactively*. This opens an interface that allows you to move files in and out of areas, and even **stage portions of files**, which will help you make smaller, focused commits.

You can use the *patch* option in the interactive mode to stage only portions. Inside of Git, a "hunk" is an area where two files differ, and can be staged, skipped, or even split into smaller hunks. When viewing a file in interactive, it will go through each hunk and give you several options

- `y` - **Yes, stage the hunk**
- `n` - **No, do not stage the hunk**
- `q` - Quit
- `?` - **Help**
- `a` - All. Stage this unk and all later hunks
- `d` - Don't. Do not stage this hunk or any later hunks in the file
- `g` - Goto. Select a Hunk to go to
- `/` - Search for a hunk matching the provided regex
- `j` - Skip and go next undecided
- `J` - Skip and go next hunk
- `k` - Skip and go previous undecided
- `K` - Skip and go previous hunk
- `s` - **Split hunk into smaller hunks**
- `e` - **Manually edit the current hunk**

You can use the `-p` option in a number of commands to work on a file in patch mode. e.g. `git add -p file.txt`.

Git can be told to split a hunk further, but will require one or more lines between any changes in order to perform the hunk split.

## 4. Share Select Changes

### Cherry-picking Commits

You can cherry-pick a commit using `git cherry-pick <commit>` or `git cherry-pick <start>..<end>`. This allows you to selectively take on particular changesets into your branch. This is useful when you want only one commit from a series of commits to be merged into your branch, leaving all the unwanted items behind. You can cherry pick from any visible branch, including remote branches. The only limitation is that you cannot cherry-pick a merge commit.

Providing the `git cherry-pick --edit` will allow you to modify the commit message with the changeset. By default, it uses the original message.

There is no guarantee that cherry-picked commits will not have conflicts. You will need to merge these conflicts in the same way as a merge conflict, then use `git cherry-pick --continue` to finalize, or `git cherry-pick --abort` to abandon the cherry-pick.

### Diff Patches

Diff patches allow you to share changes via files, which is useful when you don't yet want to push changes to a remote repository, or when you want to share code with a collaborator that does not have access to the remote. By convention, these files should end with `.diff`.

*Note*: In Git Bash, you can use the `>` character to push the output from one command into the file listed. For example, `echo "hello" > file.txt` will put the text "hello" into the file.txt file (and create the file if it does not exist).

You can utilize the above Bash feature along with git diff to output into a new diff file. Like `git diff <sha> <sha> > for_review.diff`. This file will not have any commit history, only a set of changes.

Once you have a diff file, you can apply it to the working directory, making the changes without making the commits. Simply use `git apply <filename>.diff` and your local directory will be updated to match the commits. This is not a guaranteed process, the file may not be able to be fully applied and will fail.

*Tip:* You may be able to simply drag the file into the bash console to insert the file name and directory at the cursor.

### Formatted Patches

When doing a formatted patch, Git exports each commit in Unix mailbox format and is useful for emailing changes. This format also includes commit messages, not just diff information. A single file will be created per commit by default.

`git format-patch <commit>..<commit>` will create the files for each commit in the range. While `git format-patch <branch>` will export all commits on the current branch which are not in the specified branch. To export a single commit, you have to use the `-1` option, like `git format-patch -1 <sha>`.

The `-o` option can be used to specify the **o**utput directory and if no directory exists it will be created. But to push all the commits into a single file you can use a command like `git format-patch <sha>..<sha> --stdout > <filename>.patch`. `--stdout` stands for "standard output" and is a reference to the console, so all of the information is sent to the console, then sent into the .path file with the `>` command.

You can then use the `git am` command to apply the formatted patches to your local directory. This command will add the commits as new commits, just like when doing a cherry-pick.

## Rebasing

To rebase, you must take commits from one branch, and replay the commits at the end of another branch, which is useful to integrate recent commits without merging. This leads to cleaner, more linear project history which ensures commits apply cleanly. Large teams may actually require rebasing for feature branches before they can be merged into master. When performing a rebase, the SHA's for the commits that have been moved are changed.

Under the hood, Git undoes all the commits in the feature branch and stores them in a temporary space. It will then shift the focus back to the tip of master (or other branch), and replay the stashed commits from there.

`git rebase <branchToRebaseOnto>` or `git rebase <branchToRebaseOnto> <branchToRebase>` will both perform a rebase, where the former will use the current branch as the branch to rebase onto the provided branch.

**The Golden Rule of Rebasing**: Do not rebase a public branch. If you rebase a shared branch, their history will become immediately unstable, and getting them back into the fold will be much more difficult. When working with a public branch, use a merge instead.

You can use the `--onto` option to move a branch onto a different branch that it wasn't originally on. You will need to specify an upstream branch as your stopping point. Like `git rebase --onto <branchToRebaseOnto> <originalBranch> <branchToRebase>`, or written another way `git rebase --onto <master> <from> <to>`.

Undoing a simple rebase can be done using `git reset --hard ORIG_HEAD`, but only if the temporary variable `ORIG_HEAD` has not been changed. If that doesn't work, you can perform another rebase, and instead target the point where the rebased commits originated.

Finally, there's an **interactive rebase** that can be very powerful, and may be preferential. It gives you a chance to modify commits as they are being replayed, and allows you to determine how git handles each one. Including

- pick a commit and use it
- drop a commit and don't use it
- reword to change the message
- edit to change the contents
- squash the commits
- mixup the commits
- exec runs a command from the command line shell

Use `git rebase -i` to enter a rebase in interactive mode, and use the same parameters as the normal rebase.

Git rebase can be used to modify commits that have been made recently. By rebasing like `git rebase -i HEAD~3`, you can modify the last three commits. This is destructive, so it should not be done on public repositories.

## Squashing

Squashing means to combine changesets, and concatenate them together. Fixup means to combine changesets, but discard the messages. Squash and fixup both use the first author in the commitment series.

## Pull Rebase

By using the `-r` and `--rebase` options for `git pull`, you can choose to rebase your commits onto the incoming changesets instead. This will cut down on merge commits and clean up the history a little bit. You may also use `rebase=preserve` which will also keep the local merge commits without flattening them. Finally, you can use `--rebase=interactive` to use the interactive editor while doing the pull.
