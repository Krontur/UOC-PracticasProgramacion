##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCCongress
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019
ProjectPath            :=C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019/UOCCongress
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=krono
Date                   :=16/04/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/winbuilds/bin/g++.exe
SharedObjectLinkerName :=C:/winbuilds/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCCongress.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/winbuilds/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./test/include $(IncludeSwitch)../UOCOrganization/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UOCOrganization 
ArLibs                 :=  "UOCOrganization" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/winbuilds/bin/ar.exe rcu
CXX      := C:/winbuilds/bin/g++.exe
CC       := C:/winbuilds/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/winbuilds/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix): test/src/utils.c $(IntermediateDirectory)/test_src_utils.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019/UOCCongress/test/src/utils.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_utils.c$(DependSuffix): test/src/utils.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_utils.c$(DependSuffix) -MM test/src/utils.c

$(IntermediateDirectory)/test_src_utils.c$(PreprocessSuffix): test/src/utils.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_utils.c$(PreprocessSuffix) test/src/utils.c

$(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix): test/src/test_pr2.c $(IntermediateDirectory)/test_src_test_pr2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019/UOCCongress/test/src/test_pr2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr2.c$(DependSuffix): test/src/test_pr2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr2.c$(DependSuffix) -MM test/src/test_pr2.c

$(IntermediateDirectory)/test_src_test_pr2.c$(PreprocessSuffix): test/src/test_pr2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr2.c$(PreprocessSuffix) test/src/test_pr2.c

$(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix): test/src/test_suit.c $(IntermediateDirectory)/test_src_test_suit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019/UOCCongress/test/src/test_suit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_suit.c$(DependSuffix): test/src/test_suit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_suit.c$(DependSuffix) -MM test/src/test_suit.c

$(IntermediateDirectory)/test_src_test_suit.c$(PreprocessSuffix): test/src/test_suit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_suit.c$(PreprocessSuffix) test/src/test_suit.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019/UOCCongress/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix): test/src/test_pr1.c $(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/krono/Dropbox/MiUOC/2do.SemestreUOC/PracticasDeProgramacion/WorkspacePRs/UOCCongress2019/UOCCongress/test/src/test_pr1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix): test/src/test_pr1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix) -MM test/src/test_pr1.c

$(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix): test/src/test_pr1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix) test/src/test_pr1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


