#!/usr/bin/env bash

#colorecho.sh: a method features printing colorful characters


NORMAL=$(tput sgr0)
GREEN=$(tput setaf 2; tput bold)
YELLOW=$(tput setaf 3)
RED=$(tput setaf 1)
		 
function red() {
	echo -e "$RED$*$NORMAL"
}
 
function green() {
	echo -e "$GREEN$*$NORMAL"
}
 
function yellow() {
	echo -e "$YELLOW$*$NORMAL"
}
 
# To print success
green "Task has been completed"
 
# To print error
red "The configuration file does not exist"
 
# To print warning
yellow "You have to use higher version."

