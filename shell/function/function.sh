#!/bin/sh
# A simple script with a function...

add_a_user(){
	USER=$1
	PASSWORD=$2
	shift; shift;
	#Having shifted twice, the reset is now comments...
	COMMENTS=$@
	echo "Adding user $USER..."
	echo useradd -c "COMMENTS" $USER
	echo passwd $USER $PASSWORD
	echo "Added user $USER ($COMMENTS) with pass $PASSWORD"
}

###
# Main body of script starts here
###
echo "Start of script..."
add_a_user bob letmein Bob Holness the presenter
echo "End of script..."
