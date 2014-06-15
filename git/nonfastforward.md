Non-fast-forward
================

## What's Non-fast-forward
It means:

* your local repo's origin/master is not real-time;
* remote repo have updated,that you do not know until right now
* not serilazied branch figure
* remote newest commit is not the father commit of local newest commit

## Overview of workflow senerioes

1. make a commit locally
2. git push (OK / failed)
3. git pull if push failed(non-fast-forward) (OK / failed)
4. discuss if pull clashed, conclude a final commit resolution
5. git push (succeed)

## typical senerioes

1. **make a commit locally**
	- git add
	- git commit
2. **git push**

`push successfully` : no clash occured!
your local origin/master is real-time;
no new updates you don't know after your last git pull! finished!!!

`push failed` : clash happened!(non-fast-forward happened!)
your local origin/master is not real-time;
remote origin/master have updated (changed) but local origin/master unchanged;
remote origin/master not equals local master commit's fater commit!
then,you need to:

3. **git pull**

git pull = git fetch + git merge

git fetch : fetch remote (newest origin/master) update to local (success!)
git merge : merge fetched commit (origin/master) and local newes master commit;
						generate a new commit(taged commit "M");

NOTE:
git fetch succeed for sure         --
                                    |=> git pull may succeed or failed
git merge may succeed or failed    --

`pull successfully` : remote's update do not have clashes with local modifies;
											(i.e.:others don't modified the same file as you)
then you need only git push,that can succeed for sure! finished!!!

`pull failed` : remote's update have clashes with local new modifies:
								(i.e.:you and other modified the same file and can not merge)
pull failed not equals that git do nothing,git have done this although failed:
> git fetch origin/master (newest update of remote repo)
> generate taged infomations in clashed file;

so you need to:

4. **discuss the clashed file with mate staff**
5. **conclude a finnal resolution,and make a commit ,then push(succes for sure!)**


## workflow figure

```

--------------------------------------------------------------------------------
--------------
|git add     |
|git commit  |
--------------
     ||
  	 \/
    ( A )
     ||
  	 \/
--------------         -----------------------------------          ------------
|            |         |                                 |          |* discuss |
|            | failed   -------------  OK   -------------| failed   |* modify  |
|git push    | =======>|| git fetch | ====> | git merge ||========> |          |
|            |         |-------------       -------------|          |* git add |
|            |         |    ( B )                ||      |          |* git ci  |
|            |         |            git pull     ||      |          |          |
--------------         --------------------------||-------          ------------
     ||                                          ||SUCCEED               ||
     ||                                          ||                      ||
     ||                                          \/                      ||
     ||                                         ( M ) <====================
     ||                                          ||             
     ||SUCCEED                                   ||             
     ||                                          \/             
     ||                                     --------------    
     ||                                     |  git push  |        
     ||                                     --------------    
     ||                                          ||SUCCEED      
     ||                                          ||             
     \/                                          \/
--------------------------------------------------------------------------------
correspongding tig map:
|                                           |                    |
A  commit A                                 M-- Merge ci         M-- Merge ci
O  init commit                              | B commit B         | B commit B
|                                           A | commit A         A | commit A
|                                           I-- init commit      I-- init commit
|                                           |                    |
-------------------------------------------------------------------------------- ```
