from libcpp cimport bool
from Types cimport *
from String cimport *

cdef extern from "<OpenMS/SYSTEM/BuildInfo.h>" namespace "OpenMS::Internal":

    cdef cppclass OpenMSOSInfo:

        OpenMSOSInfo() nogil except +
        OpenMSOSInfo(OpenMSOSInfo) nogil except + # wrap-ignore

    cdef cppclass OpenMSBuildInfo:

        OpenMSBuildInfo() nogil except +
        OpenMSBuildInfo(OpenMSBuildInfo) nogil except + # wrap-ignore


cdef extern from "<OpenMS/SYSTEM/BuildInfo.h>" namespace "OpenMS::Internal::OpenMSOSInfo":

    OpenMSOSInfo getOpenMSOSInfo()  # wrap-attach:OpenMSOSInfo

    String getOSAsString() # wrap-attach:OpenMSOSInfo

    String getArchAsString() # wrap-attach:OpenMSOSInfo

    String getOSVersionAsString() # wrap-attach:OpenMSOSInfo

    String getBinaryArchitecture() # wrap-attach:OpenMSOSInfo


cdef extern from "<OpenMS/SYSTEM/BuildInfo.h>" namespace "OpenMS::Internal::OpenMSBuildInfo":

    bool isOpenMPEnabled() # wrap-attach:OpenMSBuildInfo

    String getBuildType() # wrap-attach:OpenMSBuildInfo

    Size getOpenMPMaxNumThreads() # wrap-attach:OpenMSBuildInfo
