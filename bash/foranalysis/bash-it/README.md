#bash-it-analysis

##install of the bash-it

* you can find the github page [clickhere](https://github.com/revans/bash-it)
* clone the source code `git clone http://github.com/revans/bash-it.git ~/.bash_it`
* **./install.sh**
* make options following prompt

##the process of the install script

* all those process can be understood by analysing `install.sh`
* first step: backup the origin ` bash_profile` to`~/.bash_profile.bak`
* copy `/bash_it/template/bash_profile.template.bash` to replace the origin `~/.bash_profile`
* prompt with options to user
* create enabled directory under `aliases` `plugins` `completion` and make symbliclink to `available`bash scripts
* analysing the new bash_profile to master the inner process

###summary
1. install.sh:replace origin bashprofile;make symlink to available plugins;prompt for user options
2. bash\_profile:export envornment variables;execute bash\_it.sh
3. ~/.bash\_it/bash\_it.sh;source lib/\*.bash custom/\*.bash etc. and load option bash file in `enabled` directory

	**NOTE:** `/lib/*.bash` provide a army of shell script functions used in other shell file, so souce those scripts in the wake of sourcing that lib shell files
