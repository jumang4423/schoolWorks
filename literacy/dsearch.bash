#! /usr/local/gnu/bin/bash
dlook="."
if [ "$1" != "" ]; then
    dlook=$1
fi

echo "Looking at " $dlook " directory."
echo "There are following subdirectories."
echo "Which directory do you want to see? (1=quit): "
dlist="quit $( ls -aF $dlook | grep / )"

select dir in $dlist; do
    if [ "$dir" = "quit" ]; then
exit
    else
cd $dlook/$dir
exec $HOME/literacy/dsearch.bash
    fi
done

#␣Put␣this␣file␣as␣$HOME/literacy/dsearch.bash,␣and␣make␣it␣executable.
