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
#green "Task has been completed"
 
# To print error
#red "The configuration file does not exist"
 
# To print warning
#yellow "You have to use higher version."

# ==============================================================================
# Draw Show
# ==============================================================================

function namegreen() {
	green ' ________       .__   ___                               __                       '
	green '|    ____|      |__\ |   |                             |  |                      '
	green '|   |     _____  __  |   |     __    _  _ ____  _______|  | ___  ______  __    _.'
	green '|   |___./ __  \|  | |   |    |  |  | |/ "    |/       |   "   |/      \|  |  | |'
	green '|   ____| (__) ||  | |   |    |  |  | |   __  | ___   /|   ___ |   __   |  |  | |'
	green '|   |   |   ___||  | |   |____|  |__| |  |  | |  /   /_|  |  | |  (__)  |  |__| |'
	green '|   |   \  \___ |  | |        |       |  |  | | /      |  |  | |        |       |'
	green '|___|    \_____/|__| \___,____|\____,_|__|  \_|/______/|__|  |_|\______/ \____,_|'
}

function namered() {
	red ' ________       .__   ___                               __                       '
	red '|    ____|      |__\ |   |                             |  |                      '
	red '|   |     _###_  __  |   |     __    _  _ ____  _______|  | ___  ______  __    _.'
	red '|   |___./ ___ \|  | |   |    |  |  | |/ "    |/       |   "   |/      \|  |  | |'
	red '|    ___| (@ @)||  | |   |    |  |  | |   __  | ___   /|   ___ |   __   |  |  | |'
	red '|   |   |   ___||  | |   |____|  |__| |  |  | |  /   /_|  |  | |  ((()  |  |__| |'
	red '|   |   \  \___ |  | |        |       |  |  | | /      |  |  | |        |       |'
	red '|___|    \_____/|__| \___ ____|\____$_|__|  \_|/______/|__|  |_|\______/ \____$_|'
}

function nameyellow() {
	yellow ' ________       .__                                    __                       '
	yellow '|    ____|      |__\ $$$$$                            |  |                      '
	yellow '|   |     _###_  __  $   $    __    _  _ ____  _______|  | ___  ______  __    _.'
	yellow '|   |___./ ___ \|  | $   $   |  |  | |/ "    |/       |   "   |/      \|  |  | |'
	yellow '|    ___| (@ @)||  | $   $   |  |  | |   __  |____   /|   ___ |   __   |  |  | |'
	yellow '|   |   |   ___||  | $   $$$$|  |__| |  |  | |  /   /_|  |  | |  (__)  |  |__| |'
	yellow '|   |   \  \___ |  | $      $|       |  |  | | /      |  |  | |        |       |'
	yellow '|___|    \_____/|__| $$$$$$$$ \____#_|__|  \_|/______/|__|  |_|\______/ \____$_|'
}

# ==============================================================================
# Logic
# ==============================================================================

case $1 in
	"green"|"g")
		namegreen
		;;
	"red"|"r")
		namered
		;;
	"yellow"|"y")
		nameyellow
		;;
	*)
		namegreen
		;;
esac

		
