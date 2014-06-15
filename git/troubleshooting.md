Git Troubleshootings
===================

## Trouble list

1. Ownnership problems
2. 

## 1.Ownnership problems

when encounted prompt like:

`fatal : could not open '.git/COMMIT_EDITMSG':Permission denied.`

or:

`error: Unable to append to .git/logs/refs/remotes/origin/master: ????`
`error: Cannot update the ref 'refs/remotes/origin/master'.`

**Troubleshooting**:

* [senerio-1](http://stackoverflow.com/questions/12139239/could-not-open-git-commit-editmsg)
* [senerio-2](http://stackoverflow.com/questions/2642836/git-error-unable-to-append-to-git-logs-refs-remotes-origin-master-permission)

change ownnership will solve these problems:

```
sudo chown -R univfei .git/
sudo chgrp -R univfei .git/
```

NOTE:

-R : recursive


## 2.

