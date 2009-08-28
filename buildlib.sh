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
		echo "	@mkdir -p \`dirname \$@\`" >> $make_include_file
		echo "	\$(CXX) \$< -c \$(CXX_FLAGS) \$(INCLUDE_FLAGS) \$(DEFINE_FLAGS) -o \$@" >> $make_include_file
	done 
	
}


# Call make with the given target
# arg 1 : make target
# args : maya version(s) to make 
function _callMake () {
	local target=${1:?"Need make target"}
	shift
	
	if [[ $# == 0 ]]; then
		echo "Please provide the maya version (s) you want to build"
		exit 2
	fi
	
	# PARSE ARGUMENTS
	###################
	# parse the versions from the possible additional args
	local maya_versions=(8.5 2008 2009)
	local compilers=( 	  g++402 g++412 g++412 	)
	if [[ ${#maya_versions[*]} != ${#compilers[*]} ]]; then
		echo "ASSERTION FAILED: Each maya version needs the corresponding cxx compiler entry"
		exit 2
	fi
	
	local args=( )
	local version_compiler=( )
	for arg in $@
	do
		local count=0
		local found=0
		for version in ${maya_versions[@]}; do
			if [[ $arg == $version ]]; then
				found=1
				vl=${#version_compiler[*]}
				version_compiler[$vl]=$version
				version_compiler[(($vl+1))]=${compilers[$count]}$'\n'	# newline to make reading easier
			fi # end if arg is version 
			count=$(( $count + 1 ))
		done # for each version
		
		# otherwise put it into args
		if [[ $found == 0 ]]; then
			args[${#args[*]}]=$arg
		fi
	done # for each arg
	
	# CALL MAKE
	############
	echo "${version_compiler[@]}" |
	while read version cxx
	do 
		# marks the end of the array data
		if [[ $version == "" ]]; then break; fi
		make ${args[@]} MAYA_VERSION=$version CXX=$cxx $target || ( echo "Failed to make $target" && exit $? )
	done
}

# call make with the appropriate options to build BPT
# args maya version number, i.e. 8.5 2008 2009 
function build () {
	_callMake "build" $@	
}

# allows to call functions directly 
if [[ $1 == "call" ]]; then
	funcname=${2:?"You need to set a function to call as second argument"}
	shift;shift 
	
	$funcname $@
fi
