
# VARIABLE DEFINITION
######################
.PHONY = default clean dep depends .buildcommon .releasecommon .checkargs
.DEFAULT_GOAL = default

# default for m2008 and m2009
maya_versions ?= 8.5 2008 2009
B_TMP_PATH ?= builddata
CXX ?= g++412
VPATH ?= $(shell find . -type d -not -wholename "*/.*" )

PLATFORM ?= $(shell uname -m)
ifeq ($(PLATFORM),x86_64)
PLATFORM = x64
else 
PLATFORM = x32
endif

BUILDLIB ?= ./buildlib.sh

MAYA_BASE ?= $(MAYA_VERSION)$(PLATFORM)
INCLUDE_FLAGS ?= -I. -I./include -I$(B_MAYA_SDK)/$(MAYA_BASE)/include
LINK_FLAGS ?= -L$(B_MAYA_SDK)/$(MAYA_BASE)/lib
DEFINE_FLAGS ?= -DLINUX


FILECOUNT = $(shell find . -type f -name "*.h" -or -name "*.cpp" | wc -l )
DEPFILE_BASE = .depends_
DEPFILE := $(DEPFILE_BASE)$(FILECOUNT)
 



# include dependency file
include $(DEPFILE)


# RULES 
#######


# redirect rule
dep : depends
depends : $(DEPFILE)


# DEPENDENCY GENERATION
$(DEPFILE): .checkargs
# delete old depfiles that might exist as the filecount has changed
	-rm $(DEPFILE_BASE)* &>/dev/null
	$(BUILDLIB) call makeDepends $(CXX) $@ $(B_TMP_PATH)/$(MAYA_BASE) $(INCLUDE_FLAGS) $(DEFINE_FLAGS)
	

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

# BUILD COMMON
# Rule on how to build the binary
.buildcommon : 


# .releasecommon 
.releasecommon : 





clean:
	-rm $(DEPFILE_BASE)*

# @$(CXX) -shared -o $@ $(OBJS) $(ADOBJS) $(LINKFLAGS) -O2 -Wall -g3 -O2 $(EXT_LIBS) >>$(ROOTPATH)/log/error.$(PROJECTNAME).log 2>>$(ROOTPATH)/log/error.$(PROJECTNAME).log
# @strip $(BINTARGETPATH)/release/$(LIB) 2>>$(ROOTPATH)/log/error.$(PROJECTNAME).log
