#include <net-snmp/system/generic.h>
#include <sys/select.h>

#undef NPROC_SYMBOL
#undef RTHASHSIZE_SYMBOL
#undef RTHOST_SYMBOL
#undef RTNET_SYMBOL

#undef RTTABLES_SYMBOL
#define RTTABLES_SYMBOL "rt_tables"

#ifndef __GNUC__
#  undef NETSNMP_ENABLE_INLINE
#  define NETSNMP_ENABLE_INLINE 0
#endif

/* define the extra mib modules that are supported */
#define NETSNMP_INCLUDE_HOST_RESOURCES

/* the legacy symbol NOACCESS clashes with the system headers. Remove it. */
#define NETSNMP_NO_LEGACY_DEFINITIONS

#ifdef _AIX43
#define aix4
#endif

#ifdef _AIX51
#define aix5
#endif

#ifdef _AIX61
#define aix6
#endif
