# EroProject
###### *Unreal 4.16.1 project source control.*

---

### Guests:

Haaaai haaaaaaii! Ohayooooou onii-chan! ❤

This is a repository belonging to an **Unreal Engine project**.
We are developing a **visual novel game** with no planned release date yet (title is still pending too, as it is the most twisted feature to set).

We are doing our best to cope up with all the troubles any wide scope-like project like this can have, and hope to come up with an *alpha* version within a **few years**.

Unless your name appears in the collaborators list, ***KEEP YOUR HANDS THE FUCK OFF THIS SHIT*** onegaishimasu.
Nevertheless, you can still `clone` us to see if we are doing good, but **no** pull requests will be accepted... **so far!**

~~~
git clone https://github.com/DenkiManiac/EroProject
~~~

---

### Collaborators:

#### Working with the project

Add this repository as the remote `origin`, if you have not already done so:

~~~
git remote add origin https://github.com/DenkiManiac/EroProject
~~~

Make sure you `pull` this repository before making any changes. You must also `pull` before trying to `merge` branches. This is in order to avoid as many conflicts as possible. 
The `master` branch is considered the actual project only. Changes in other branches are considered testing, and will not be part of the development process until merged.

To work with branches:

~~~
git branch branch_name
git checkout branch_name

-- or --

git checkout -b branch_name
~~~

To `merge` branches with `master`:

~~~
git checkout master
git pull #highly recommended
git merge branch_name
~~~

Perform every `commit` using the Unreal Engine tool. Unreal keeps track of the files you modify, adding them automatically to the index. Simply finish committing clicking *Source Control > Submit to Source Control...*.
<br>If the method above fails, you need to `add` and `commit` changes manually (using bash). To do so:

~~~
git add .
git commit -m "commit message"
~~~

Pleas provide a descritive message for every `commit` you make, no matter the way you make it.

To keep track of the repository `status` manually:

~~~
git status
~~~

This will check differences between local and `source` repository versions, and will keep track of any modified file since last `commit`.

#### When troubles loom

Changes are associated with an user name. **Whoever that fucks it up will be spotted**. Demo daijoubu, there are solutions available before shedding your shreds to a pit. 

If you want to **temporarily switch to a different commit**, create a new `branch` from an existing `commit` and work from there:

~~~
git checkout -b branch_name commit_id

-- you can go back to the original work cheking out the master branch ---

git checkout master
~~~

Otherwise, if you want to **delete unpublished commits** (only affects to local changes), reset the commits:

~~~
# If you DON'T have work uncommited that you want to keep
git reset --hard commit_id

# Else
git stash
git reset --hard commit_id
git stash pop
~~~

Finally, if you want to **delete published commits**, you must create new commits that overwrite all the changes you have made:

~~~
# To revert the last N commits
git revert HEAD~N..HEAD

# To revert a merge commit
git revert -m 1 merge_commit_id

# Either way, you must commit afterwards
git commit -m "good explanation of what you have done"
~~~

To get a `commit` history, run:

~~~
git log
~~~

Please, **only use any of these methos if there is no alternative way to solve the problem**.

---

Either guest or collaborator:<br>
### Yoroshiku onegaishimasu! ♡♡♡
