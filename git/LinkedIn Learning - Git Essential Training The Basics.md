# Git Essential Training: The Basics

*Completed:* January 14, 2020

## 1. What is Git

### History Behind Git

**Source Code Control System (SCCS)** wasn't the first source control, but it was the first to gain major popularity. It was developed by AT&T in 1972 and gained it's popularity because it came free with Unix. Universities taught using it because it was free, then the new developers took that knowledge out into the workplace with them.

It keeps the original document, but instead of saving a second document, it just saves a "snapshot" of what the changes were. This is a more efficient way to store changes over time, but in order to get the latest version of something, all the changes must be applied to that original document.

**Revision Control System (RCS)** emerged and became more popular because it was cross platform, unlike SCCS. It was also faster because it used a smarter storage method, keeping only the most recent file, meaning history to rollback changes; the main benefit of this comes from the fact that you usually work with the latest version, not the original, so not having to do any conversions to start working is a big bonus.

Both only allowed you to work with an individual file at a time, and didn't let you track multiple files at a time.

**Concurrent Versions System (CVS)** introduced the concept of a repository. Multiple users can work together on the same document at the same time, and update their files based on other users.

**Apache Subversion (SVN)** was faster than CVS and also allowed for saving of non-text files. It also tracked changes to a directory as a whole, taking a snapshot of the directory and not the files. You talked about files in context of the directory version, including tracking names and moves. You could also submit changes to multiple files at a time, instead of individually.

SVN stayed the most popular until Git came out, but **BitKeeper SCM** came out briefly after. It was closed source and proprietary, but had an important feature: distributed version control. The "community" version was free and used for source code of Linux kernel from 2002 to 2005, which was topical because of the closed source nature. In 2005, BitKeeper ended their free version, forcing the birth of Git.

**Git** was born in April 2005 when BitKeeper stopped being free. It was created by Linus Torvalds (creator of Linux) because he didn't like the other source control systems available. It is open source, free, cross platform, faster, and has better safeguards to prevent corruption. The distributed source control methodology is extremely powerful, and has lead to an explosion in users of Git.

### Distributed Version Control

Central repositories require developers to pull down a copy of the file, make their changes, then submit those changes back to the main repository; the dev is responsible for getting the latest changes and keeping them up to date.

Distributed version control allows different users to maintain their own repository, and changes are stored as sets, and changes are tracked. Instead of worrying about what version of file you have, you are worried about which *changeset* you have applied.

There is no single master repository, every user has their own copy and a list of changesets. This means changesets can be inserted and removed freely. No one changeset is "right" or "wrong" and are instead just different changesets. It is only convention that causes most projects to have a central repository; there doesn't *have* to be a central one, and all repositories are equal. There is nothing special about repositories that are considered the "central" repository in Git.

Distributed systems mean you don't have to be connected to the internet, you don't need to communicate with the central server, and you can keep working even if the "central" repository is corrupted or down.

There is also the concept of "forking" which allows a new copy of the project to be made and then merged back into the original repository, which improves the collaboration of projects.

## 2. Install Git

### Install Git on Mac

Modern version of Mac comes with a version of Git pre-installed, but you may be better of installing a new independent version instead, giving you more control. You can utilize either the git installer or Homebrew.

[https://git-scm.com/download/mac](https://git-scm.com/download/mac) for the .dmg file.

With Homebrew you can just type `brew install git`

### Install Git on Windows

You can get the software from [https://git-scm.com/download/win](http://git-scm.com/downloads/win), save the file then, then launch the installer.

Use `git --version` to verify the installation was successful.

### Install Git on Linux

A list of installation instructions is available at [https://git-scm.com/download/linux](http://git-scm.com/downloads/linux), and your command will vary depending on which flavor of Linux you have available.

You can type `which git` to determine where Git is installed and `git --version` to verify which version you are in.

### Basic Git Configuration

There are three places that git stores configuration information

- System
  - `Program Files\Git\etc\gitconfig` or `/etc/gitconfig`
- User
  - `~/.gitconfig` or `$HOME\.gitconfig` (which is likely your User folder)
- Project
  - `project_name/.git/config`

You can set a config option by typing `git config`, which will define it for the Project by default. You can additionally add `--system` or `--global` to define the setting either system or globally respectively.

To start off, you can set your username by typing `git config --global user.name "Mike Mickelson"` and the email by using `git config --global user.email`, which will tell Git that all changesets you check in will be associated with those. Use `git.config` to list the current settings or `git config [setting name]` to view the current value for the specified name.

You may also directly edit the config files.

To update the editor you want to use, type `git config --global core.editor "editor"`. You can even specify executable files as well. [Check out this StackOverflow question](https://stackoverflow.com/questions/30024353/how-to-use-visual-studio-code-as-default-editor-for-git) for instructions on how to set Visual Studio code as your default editor.

#### Specify the Color

Using the `git config --global color.ui true` will enable color-coding for git command lines. This should be set by default, but you may want to do it anyway to be certain.

### Git auto-completion

Auto-complete should be pre-installed in Windows, but will have to be manually installed for Mac and Linux. The script is separate from Git and can be viewed on [https://github.com/git/git](https://github.com/git/git), looking inside the `contrib/completion` files (or search for completion). The files inside will contain instructions on how to enable auto-completion for your shell.

### Git help

You can type `git help` to get a list of possible commands and some additional advice on using the help menu. In Bash environments you can use the `man git-<command>` command to view the help for a particular command.

## 3. Getting Started

### Initialize a repository

A Git directory can be initialized by navigating to the root of the directory and typing `git init`, which will create a .git directory (hidden by default). This directory will store additional information about your git environment for this particular repository.

### Where Git files are stored

The .git directory inside of your repository contains all the files Git uses to track your changesets, and will not need to be manually modified by you (except perhaps the config file). If you delete this directory, git would be removed from the project and would have no tracking information regarding this project. This makes it very easy to uninstall git from a project, but also very easy to accidentally delete what it knows.

### Your first commit

Use the command `git add .` to add *all* changes within the current directory. This doesn't track the changes permanently, you must use `git commit` to lock those changes in. Add the `-m` argument and a string message to add a comment to your commit. You would repeat this process a lot, and may add in additional flair and options, but this will be the baseline.

### Write a commit message

There are some best practices for writing commit messages

- Start with a short, one-line summary (<50 characters)
- Blank line followed by a more complete description if needed
- Keep each line to less than 72 characters (to account for different devices and environments)
- Write them in presence tense, and not past tense
  - "Fix for a bug" or "fixes a bug" but not "fixed a bug"
  - The message is meant to label the changes
- Bullet points are asterisks or hyphens
- Can add "tracking numbers" from bugs or support requests
- Can develop shorthand for your organization
- **Be clear and descriptive**

### View the Commit Log

From inside your project, type the command `git log`, which will display all the commits in descending order (newest first).

Each commit is given a unique ID, has an author, and a date. See below for some additional options

- `-n` limits the number of commits to display
- `--since={date}` in the format yyyy-mm-dd
- `--until={date}` in the format yyyy-mm-dd
- `--author={author}` can be used with *any* part of the name
  - `git log --author="mik"` will locate "Mike Mickelson" and "Dees Smiks"
- `--grep={string}` will return any commit that has the provided string in it
  - Globally search for regular expressions (GREP)
  - e.g. `git log --grep="bug fix"`

## Git Concepts and Architecture

### The three trees

Other source control methods use the "two tree" layout. There is a repository and a working copy, two directory trees. When you want to move files between the repository and working directly by checking out the files, then committing the changes.

Git uses a three tree architecture with the repository, working copy, and the staging index. The staging index is accessed when you perform the `git add` command. The index then pushes its change up to the repository once `git commit` is called. It's possible to directly commit to the repository and skip the staging index, which we will look at later.

It's also possible to pull changes down into the staging index and then into the working directory, but usually the changes are just pulled directly down into the working directory.

### Git Workflow

Starting with changes in the working directory, you specify `get add` to move the changes up to the staging index, then use `get commit` to move them up to the repository.

### Hash values (SHA-1)

Changesets are labelled using hash values (checksum) which is generated by feeding data into a mathematical algorithm. The same data put into the algorithm will always return the same hash, which supports data integrity. The label is fundamentally tied to those changes.

Git uses the SHA-1 hash algorithm which results in a 40-character hexadecimal string (0-9, a-f). Git takes the entire changeset, runs them through the algorithm, and generates the forty character algorithm.

Additionally, Git uses the metadata of the commit, which means the author, parent, and message are also taken into account when generating the hash. Because it also includes the SHA value of the parent, there is a direct link between the changesets, meaning the history is fundamentally built in to the changeset hash.

### The HEAD Pointer

The HEAD points to the tip of the current branch in the repository as it was last checked out. Wherever the HEAD is positioned is the place where new commits will be added.

Generally, this is the last commit that you made. This commit is also the parent of the *next* commit you make. It is also the last changeset in any new branches created.

Git will track the HEAD for you, but you can manually update it if you need.

## 5. Make Changes to Files

### Add Files

The command `git status` will display the current branch and any changes you have in the working tree (not the staging index) and any commits in the staging index. It will list any "un-tracked files" or files that are not in the git repository and that git is not recording changes for; you have to use `git add` to move it into the staging tree, then `git commit` to add them to the repository.

You can chain multiple files into the `git add` command like `git add file.txt file2.txt`.

### Edit Files

When using `git status` with pending changes, git will report there there are "Changes not staged for commit" and display the files that have been modified, or "Changes to be committed."

### View Changes with `diff`

The command `git diff` will allow you to view all the changes for the current repository at the given time. You can also specify two changesets to compare by using `git diff changeset1 changeset2`.

By default, it compares the *working directory* to the *repository*.

### View Only Staged Changes

If you want to compare the staged changes to the repository, then you can use the command `git diff --stage`. It will *not* show the un-staged changes. You can alternatively do `git diff --cache`, which was the original option before `--cache` was added as an alias.

### Delete files

When a file that is in the remote repository is deleted in your local directory (or moved), then Git will register the file as deleted. That deletion will need to be added to the staging directory and then committed to the repository in order for that deletion to cascade to the remote repository.

Additionally, you can tell Git to remove a file by using `git rm <file>`, which will delete the file from your filesystem. This utilizes a Unix command and so it has been *permanently* removed (it cannot be restored). The command will also automatically add the changes to the staging directory. This automatic staging is a bit more dangerous but more convenient than manually moving or deleting.

### Move and Rename Files

You can rename files by using the File Explorer, which will initially show that the original name is deleted while the new name is added. Once they have been staged, if the two "files" are more than 50% similar, then Git will consider them the same file, and the staged status will show the rename instead.

To Git and the operating system, moving the file and renaming the file are the same thing; the file is the same in a move but the path is different. Thus you can utilize `git mv <file> <newloc>` to both move *and* rename a file. This will automatically move/rename the file and then stage the changes.

## 6. Use Git with a Real Project

### The Explore California Website

The course utilizes an example project with existing files and folder that is not yet being tracked with Git. Find the Exercise Files in the [Course Notes](https://www.linkedin.com/learning/git-essential-training-the-basics/initialize-git).

### Initialize Git

Git can be added to any project, new or existing easily just by using the `git init` command. The command will also search the parent directories for the nearest git instance.

When you first initialize Git with an existing set of files, you will need to check in these initial "changes." You must push something to the repository before you can track their changes.

It's very common to use *Initial Commit* as your first commit message.

Git will track projects separately, so changing your directory will change the Git project, making swapping effortless.

### View file edits

When viewing the `diff` for a file, it is paginated, so you can press the `space` key or `F` key to navigate to the next page, and the `B` key to navigate **b**ackwards. Each change in prefixed with the line `@@ originalLineNumber,originalNumberOfLines newLineNumber,newNumberOfLines @@`.

If you want to disable line wrapping, you can enter the type "-S" then press `Enter`. You can exit the diff by typing `Q`.

You may also use `git diff --color-words` to show only the *words* that are different in a diff comparison instead of the entire line.

### Stage and commit shortcut

Instead of using `git add .` then `git commit`, you can utilize `git commit -a` or `git commit --all` which will stage and commit *all* changes for *tracked* files with one command. **If you have added files then you will need to manually stage those changes**, the `-a` option will not add un-tracked changes.

To combine both the -a and -m options, use `git commit -am`.

### View a Commit

The command `git show` can be used to view a particular commit. You must specify an identifier for the commit. You do not need to type the entire identifier, only enough that Git is able to narrow it down to one changeset.

Example: `git show fb74d33f8` will show the diff for the changeset with an identifier starting with "fb74d33f8."

### Compare Commits

Use the command `git diff` to also compare two non-consecutive or historical changesets. `git diff {id}...{id2}`. You can do this with branches and labels as well, and refer to the HEAD branch with the name HEAD instead (e.g. `git diff 0000...HEAD`).

### Multiline Commit Messages

If you want to do a more thorough editing of your commit message, simply omit the "-m" when committing the changes. Your configured text editor (Vim by default) will be opened and you will be able to write multiple lines.

When viewing the `git status`, add the `--one-line` option to view only the first line of all the commit messages.

### Making Atomic Commits

An atomic commit is a very small commit that only affects a single aspect. Committing atomically makes it easier to understand, work with, find bugs, and collaborate with others. Team members can grab commits selectively instead of one big one.

You can stage all the changes in a directory by using `git add directory/`, replacing the `directory` text with the name of your directory.

## 7. Undo Changes

### Undo Working Directory Changes

Git can be used to restore accidental deletions easily because it is tracking the changes you've made and what the original file looked like. Inside the `git status` command you will find the hint on how to undo a particular change. Use `git checkout -- file.txt`. The "--" tells the checkout command to stay in the current branch and check out the repository version of the file selected.

### Unstage Files

**Tip:** You can add all the files with a certain name using wildcard characters like `git add tours*`, which will add all files that start with "tours" and everything in directories that start with "tours."

To undo a change, utilize the `git reset HEAD file.txt` to unstage the file, which can then be modified locally again without entering the repository. You can see this command recommended in the `git status` command results.

### Amend Commits

Because the unique ID of a commit references its parent commit ID, if you were to change anything in the parent (thus changing the ID), you would break the chain of commits. This is intended behavior; Git does not want you to change history. However, you can easily amend the *last* commit, since nothing currently depends on it.

The command `git commit --amend` will amend the current changes to last changeset, thus changing the SHA value. You can also modify the commit message using the `--amend` command as well.

### Retrieve Old Versions

Git by convention does not let you easily change a previous commit. This is for data integrity reasons. You should instead create a new commit to fix any mistakes.

You can retrieve old versions of files by using the `git checkout` command. For example, you can revert a file to a certain commit using `git checkout {SHA} -- file.txt`. This will stage a change to revert the page to the previous version and move that change into your working directory; you can then modify the file again freely, staging and unstaging changes as you go.

### Revert a Commit

If you don't want to edit the file, and instead want to revert to a previous version as is, you can utilize the `git revert <SHA>` to revert the changes made by the entered SHA. These changes will be automatically committed once you enter a commit message. This is not the same as going back to a particular point in time, but instead like undoing a particular changeset.

### Remove Untracked Files

When a file is added to a repository that you don't want to be tracked you can use `git clean` with one of the following options. This will remove the un-tracked files completely from the project.

- `-f` forces the command
- `-n` shows what the command *would* do if ran
- `-i` runs the command in interactive

This is a destructive process; the files are no longer located in the trash or on the hard drive. This is useful when there is a large amount of files in your repository that you want to remove.

## 8. Ignore Files

### Use .gitignore files

You can ignore particular files, like log files or junk files, using the ".gitignore" file in the root of the project.

You can do any of the following

- File name
- Pattern matching (regular expressions)
  - e.g. ignoring all .txt files with *.txt
- Negative Expressions
  - If *.php ignores all PHP files, you can use !index.php to exclude the index file from this ignoring
- Ignore files in a directory with a trailing slash
- Comments are valid with a "#"
- Blank lines are skipped

#### Example .gitignore

```plaintext
# Ignore one file
access.log

# Ignore a directory
logs/
Content/videos

# Ignore files only in a directory
logs/*.txt
logs/*.txt.[0-9]

# Ignore all files of one type
*.php
*.zip
*.gz

# Include a certain ignored file
!index.php
!logs/config.txt
```

### Ideas on What to Ignore

- Compiled source code
- Packages and compressed files
- Logs
- Databases
- Operating system generated files
- User-uploaded assets (images, PDFs, videos)

You can find a selection of .gitignore template at [github.com/github/gitignore](https://github.com/github/gitignore). Download one of these files and place it in the root of your Git repository. You can find the [Visual Studio .gitignore file here](https://github.com/github/gitignore/blob/master/VisualStudio.gitignore).

### Globally Ignore Files

If you want to ignore files in *all* repositories and projects, you can set the `core.excludesfile` config option to point to any file you'd like. This is considered a User configuration, so it's best to put this in your user directory.

### Ignore Tracked Files

Files that are already being tracked are not ignored by the .gitignore. If you add an already tracked file to the .gitignore, then Git will *continue* to track the changes because Git was already tracking the file before it was added to the ignore list.

To remove a file that is already being tracked, you have to use `git rm --cached file.txt`, which will stage a removal of the selected file that will need to be committed. The file will still exist in the main repository, but future changes will not be tracked.

If you need to begin tracking again, you will need to remove it from the .gitignore file.

### Track Empty Directories

Git ignores directories that have no files within it. If you need to have an empty directory in the repository, you can add a .gitkeep file. You can add any file to this directory, but the convention is to put a `.` file and name it ".gitkeep."

If you're on a Unix machine, you can simply just `touch` a file, which will create the .gitkeep if it does not exist. For example `touch temp/.gitkeep`.
