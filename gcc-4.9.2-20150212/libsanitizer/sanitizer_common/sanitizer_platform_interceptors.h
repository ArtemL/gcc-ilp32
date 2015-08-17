//===-- sanitizer_platform_interceptors.h -----------------------*- C++ -*-===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines macro telling whether sanitizer tools can/should intercept
// given library functions on a given platform.
//
//===----------------------------------------------------------------------===//
#ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
#define SANITIZER_PLATFORM_INTERCEPTORS_H

#include "sanitizer_internal_defs.h"

#if !SANITIZER_WINDOWS
# define SI_NOT_WINDOWS 1
# include "sanitizer_platform_limits_posix.h"
#else
# define SI_NOT_WINDOWS 0
#endif

#if SANITIZER_LINUX && !SANITIZER_ANDROID
# define SI_LINUX_NOT_ANDROID 1
#else
# define SI_LINUX_NOT_ANDROID 0
#endif

#if SANITIZER_LINUX
# define SI_LINUX 1
#else
# define SI_LINUX 0
#endif

#if SANITIZER_MAC
# define SI_MAC 1
#else
# define SI_MAC 0
#endif

#if SANITIZER_IOS
# define SI_IOS 1
#else
# define SI_IOS 0
#endif

# define SANITIZER_INTERCEPT_STRCMP 1
# define SANITIZER_INTERCEPT_TEXTDOMAIN SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_STRCASECMP SI_NOT_WINDOWS

# define SANITIZER_INTERCEPT_READ   SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PREAD  SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_WRITE  SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PWRITE SI_NOT_WINDOWS

#define SANITIZER_INTERCEPT_PREAD64 SI_LINUX_NOT_ANDROID
#define SANITIZER_INTERCEPT_PWRITE64 SI_LINUX_NOT_ANDROID

#define SANITIZER_INTERCEPT_READV SI_NOT_WINDOWS
#define SANITIZER_INTERCEPT_WRITEV SI_NOT_WINDOWS

#define SANITIZER_INTERCEPT_PREADV SI_LINUX_NOT_ANDROID
#define SANITIZER_INTERCEPT_PWRITEV SI_LINUX_NOT_ANDROID
#define SANITIZER_INTERCEPT_PREADV64 SI_LINUX_NOT_ANDROID
#define SANITIZER_INTERCEPT_PWRITEV64 SI_LINUX_NOT_ANDROID

# define SANITIZER_INTERCEPT_PRCTL   SI_LINUX

# define SANITIZER_INTERCEPT_LOCALTIME_AND_FRIENDS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_STRPTIME SI_NOT_WINDOWS

# define SANITIZER_INTERCEPT_SCANF SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_ISOC99_SCANF SI_LINUX

# define SANITIZER_INTERCEPT_FREXP 1
# define SANITIZER_INTERCEPT_FREXPF_FREXPL SI_NOT_WINDOWS

# define SANITIZER_INTERCEPT_GETPWNAM_AND_FRIENDS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETPWNAM_R_AND_FRIENDS \
    SI_MAC || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_CLOCK_GETTIME SI_LINUX
# define SANITIZER_INTERCEPT_GETITIMER SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_TIME SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GLOB SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_WAIT SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_INET SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PTHREAD_GETSCHEDPARAM SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETADDRINFO SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETNAMEINFO SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETSOCKNAME SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETHOSTBYNAME SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETHOSTBYNAME_R SI_LINUX
# define SANITIZER_INTERCEPT_GETSOCKOPT SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_ACCEPT SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_ACCEPT4 SI_LINUX
# define SANITIZER_INTERCEPT_MODF SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_RECVMSG SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETPEERNAME SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_IOCTL SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_INET_ATON SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_SYSINFO SI_LINUX
# define SANITIZER_INTERCEPT_READDIR SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_READDIR64 SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_PTRACE SI_LINUX_NOT_ANDROID && \
  (defined(__i386) || defined (__x86_64))  // NOLINT
# define SANITIZER_INTERCEPT_SETLOCALE SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GETCWD SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_GET_CURRENT_DIR_NAME SI_LINUX
# define SANITIZER_INTERCEPT_STRTOIMAX SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_MBSTOWCS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_MBSNRTOWCS SI_MAC || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_WCSTOMBS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_WCSNRTOMBS SI_MAC || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_TCGETATTR SI_LINUX
# define SANITIZER_INTERCEPT_REALPATH SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_CANONICALIZE_FILE_NAME SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_CONFSTR SI_MAC || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SCHED_GETAFFINITY SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_STRERROR SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_STRERROR_R SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_XPG_STRERROR_R SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SCANDIR SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SCANDIR64 SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_GETGROUPS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_POLL SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PPOLL SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_WORDEXP SI_MAC || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SIGWAIT SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_SIGWAITINFO SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SIGTIMEDWAIT SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SIGSETOPS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_SIGPENDING SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_SIGPROCMASK SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_BACKTRACE SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_GETMNTENT SI_LINUX
# define SANITIZER_INTERCEPT_GETMNTENT_R SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_STATFS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_STATFS64 \
    (SI_MAC && !SI_IOS) || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_STATVFS SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_STATVFS64 SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_INITGROUPS SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_ETHER SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_ETHER_R SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_SHMCTL \
    (SI_LINUX_NOT_ANDROID && SANITIZER_WORDSIZE == 64)
# define SANITIZER_INTERCEPT_RANDOM_R SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_PTHREAD_ATTR_GET SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PTHREAD_ATTR_GETINHERITSCHED \
  SI_MAC || SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_PTHREAD_ATTR_GETAFFINITY_NP SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_TMPNAM SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_TMPNAM_R SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_TEMPNAM SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_SINCOS SI_LINUX
# define SANITIZER_INTERCEPT_REMQUO SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_LGAMMA SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_LGAMMA_R SI_LINUX
# define SANITIZER_INTERCEPT_DRAND48_R SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_ICONV SI_LINUX_NOT_ANDROID
# define SANITIZER_INTERCEPT_TIMES SI_NOT_WINDOWS

// FIXME: getline seems to be available on OSX 10.7
# define SANITIZER_INTERCEPT_GETLINE SI_LINUX_NOT_ANDROID

# define SANITIZER_INTERCEPT__EXIT SI_LINUX

# define SANITIZER_INTERCEPT_PHTREAD_MUTEX SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PTHREAD_COND SI_NOT_WINDOWS
# define SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP SI_LINUX_NOT_ANDROID

#endif  // #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
