### the directory name
set(directory source/QC)

### list all filenames of the directory here
set(sources_list
MzCalibration.cpp
)   

### add path to the filenames
set(sources)
foreach(i ${sources_list})
	list(APPEND sources ${directory}/${i})
endforeach(i)

### pass source file list to the upper instance
set(OpenMS_sources ${OpenMS_sources} ${sources})

### source group definition
source_group("Source Files\\QC" FILES ${sources})
