#!/bin/bash
# Contains functions that aid build BPT
# Call a function from the library directly such as:
# buildlib.sh call funcname [ args ]

# create dependencies, produces $(OBJS) make variable 
# arg 1: g++ executable 
# arg 2: target file that can be included into makefile
# arg 3: object output path ( may include subdirectories )
# [ args ] additional g++ flags like includes/definesd
function makeDepends () {
	local CXX=${1:?"need g++ executable"}
	local make_include_file=${2:?"Need output file to be included in makefile"}
	local obj_out_dir=${3:?"Need object output directory"}
	
	# shift the mandatory args away
	shift;shift;shift
	
	# WRITE LIBRARY DEPENDENCIES
	# process all cpp files
	local data=()
	local dl=0
	
	echo "# Library dependencies" >> $make_include_file
	echo "OBJS = \\" >> $make_include_file
	for cfile in `find . -regex ".*/.*\.cpp\|c\|C"`
	do
		local dirname=${cfile%/*}
		local dirname=${dirname#./}
		local filename=${cfile##*/}
		local basename=${filename%.*}
		
		local ofile=$obj_out_dir/$dirname/${basename}.o
		echo "$ofile \\" >> $make_include_file
		
		# keep the data for later
		data[$dl]=$cfile
		dl=$((dl+1))
		data[$dl]=${ofile}$'\n'
		dl=$((dl+1))
	done
	
	
	# WRITE PER-OBJ DEPENDENCIES 
	###############################
	echo "${data[@]}" | 
	while read cfile ofile
	do
		if [[ $cfile == "" ]]; then break; fi
		local basename=${ofile##*/}
		
		echo >> $make_include_file
		echo "# $basename" >> $make_include_file
		echo "$ofile = " >> $make_include_file
		g++ $@ -MT $ofile -MM $cfile >> $make_include_file
		
		# put the make rule in here - it is hard to tell make a general rule considering the O files are somewhere else
		echo "	mkdir -p \`dirname \$@\`" >> $make_include_file
		echo "	\$(CXX) \$< -c \$(CXX_FLAGS) \$(INCLUDE_FLAGS) \$(DEFINE_FLAGS) -o \$@" >> $make_include_file
	done 
	
}


# allows to call functions directly 
if [[ $1 == "call" ]]; then
	funcname=${2:?"You need to set a function to call as second argument"}
	shift;shift 
	
	$funcname $@
fi
