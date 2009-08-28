
# VARIABLE DEFINITION
######################
.PHONY = default clean dep depends build release .checkargs .module
.DEFAULT_GOAL = default

# default for m2008 and m2009
maya_versions ?= 8.5 2008 2009
B_TMP_PATH ?= builddata
# separate subfolder for BPT in case the folder is used by others
BPT_TMP_PATH = $(B_TMP_PATH)/BPT
CXX ?= 
CXX_FLAGS ?= -fPIC -g
VPATH ?= $(shell find . -type d -not -wholename "*/.*" )
OBJS ?= # defined by file from 'depends' rule

PLATFORM ?= $(shell uname -m)
ifeq ($(PLATFORM),x86_64)
PLATFORM = x64
else 
PLATFORM = x32
endif

BUILDLIB ?= ./buildlib.sh

MAYA_BASE = $(MAYA_VERSION)$(PLATFORM)
SDK_PATH = $(B_MAYA_SDK)/$(MAYA_BASE)
INCLUDE_FLAGS = -I. -I./include -I$(SDK_PATH)/include
LINK_FLAGS = -L$(SDK_PATH)/lib -lFoundation -lOpenMaya -lOpenMayaAnim -lOpenMayaUI
DEFINE_FLAGS ?= -DLINUX -DREQUIRE_IOSTREAM -D_BOOL

# fully qualified path to catch all our output
COMPILE_PATH = $(BPT_TMP_PATH)/_obj_/$(MAYA_BASE)
OUTPUT_PATH = $(BPT_TMP_PATH)/$(MAYA_BASE)
LIB_PATH = $(OUTPUT_PATH)/plug-ins/ByronsPolyTools.so


FILECOUNT = $(shell find . -type f -name "*.h" -or -name "*.cpp" | wc -l )
DEPFILE_BASE = .depends_$(MAYA_BASE)
DEPFILE = $(DEPFILE_BASE)_$(FILECOUNT)
 

# RULES 
#######


# redirect rule
dep : depends
depends : .checkargs $(DEPFILE)


# DEPENDENCY GENERATION
$(DEPFILE):
# delete old depfiles that might exist as the filecount has changed
	-rm $(DEPFILE_BASE)* &>/dev/null
	$(BUILDLIB) call makeDepends $(CXX) $@ $(COMPILE_PATH) $(INCLUDE_FLAGS) $(DEFINE_FLAGS)
	

default:
	@echo "make clean|build(8.5|2008|2009)|release(8.5|2008|2009)"
	false


.checkargs:
ifndef B_MAYA_SDK
	@echo "B_MAYA_SDK needs to point to a path containing the maya sdks, i.e. 2008x64 or 2008x32"
	false
endif
ifndef B_TMP_PATH
	@echo "B_TMP_PATH needs to point to the directory for the temporary build data"
	false
endif
ifndef MAYA_VERSION
	@echo "MAYA_VERSION needs to be the maya version you want to process"
	false
endif 
ifndef CXX
	@echo "CXX needs to be set to match the compiler requirements for maya$(MAYA_VERSION)"
	false
endif


# include dependency file
include $(DEPFILE)

# BUILD
#########
# Rule on how to build the binary
build : .checkargs .module 

.module : $(LIB_PATH)
# make a fully functional module by copying scripts
	@ln -sf $$(cd scripts; echo $$PWD) $(OUTPUT_PATH)
	@if [[ -d icons ]];then ln -sf $$(cd icons; echo $$PWD) $(OUTPUT_PATH); fi
	
	
$(LIB_PATH) : $(OBJS) 
	mkdir -p `dirname $@`
	$(CXX) -shared -o $@ $(OBJS) $(LINK_FLAGS) -O2 -Wall -g3 -O2 $(EXT_LIBS)


	
# release 
release : build  


clean:
	-rm $(DEPFILE_BASE)*
	-rm -Rf $(BPT_TMP_PATH)
