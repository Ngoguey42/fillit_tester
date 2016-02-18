/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstrerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:58:11 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 13:16:02 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

#define ENTRY(NAME, STR) [NAME] = #NAME ": " STR

static const char *g_error_table[] =
{
#if defined (EPERM)

	ENTRY(EPERM, "Not owner"),
#endif
#if defined (ENOENT)

	ENTRY(ENOENT, "No such file or directory"),
#endif
#if defined (ESRCH)

	ENTRY(ESRCH, "No such process"),
#endif
#if defined (EINTR)

	ENTRY(EINTR, "Interrupted system call"),
#endif
#if defined (EIO)

	ENTRY(EIO, "I/O error"),
#endif
#if defined (ENXIO)

	ENTRY(ENXIO, "No such device or address"),
#endif
#if defined (E2BIG)

	ENTRY(E2BIG, "Arg list too long"),
#endif
#if defined (ENOEXEC)

	ENTRY(ENOEXEC, "Exec format error"),
#endif
#if defined (EBADF)

	ENTRY(EBADF, "Bad file number"),
#endif
#if defined (ECHILD)

	ENTRY(ECHILD, "No child processes"),
#endif
#if defined (EWOULDBLOCK)

	ENTRY(EWOULDBLOCK, "Operation would block"),
#elif defined (EAGAIN)

	ENTRY(EAGAIN, "No more processes"),
#endif
#if defined (ENOMEM)

	ENTRY(ENOMEM, "Not enough space"),
#endif
#if defined (EACCES)

	ENTRY(EACCES, "Permission denied"),
#endif
#if defined (EFAULT)

	ENTRY(EFAULT, "Bad address"),
#endif
#if defined (ENOTBLK)

	ENTRY(ENOTBLK, "Block device required"),
#endif
#if defined (EBUSY)

	ENTRY(EBUSY, "Device busy"),
#endif
#if defined (EEXIST)

	ENTRY(EEXIST, "File exists"),
#endif
#if defined (EXDEV)

	ENTRY(EXDEV, "Cross-device link"),
#endif
#if defined (ENODEV)

	ENTRY(ENODEV, "No such device"),
#endif
#if defined (ENOTDIR)

	ENTRY(ENOTDIR, "Not a directory"),
#endif
#if defined (EISDIR)

	ENTRY(EISDIR, "Is a directory"),
#endif
#if defined (EINVAL)

	ENTRY(EINVAL, "Invalid argument"),
#endif
#if defined (ENFILE)

	ENTRY(ENFILE, "File table overflow"),
#endif
#if defined (EMFILE)

	ENTRY(EMFILE, "Too many open files"),
#endif
#if defined (ENOTTY)

	ENTRY(ENOTTY, "Not a typewriter"),
#endif
#if defined (ETXTBSY)

	ENTRY(ETXTBSY, "Text file busy"),
#endif
#if defined (EFBIG)

	ENTRY(EFBIG, "File too large"),
#endif
#if defined (ENOSPC)

	ENTRY(ENOSPC, "No space left on device"),
#endif
#if defined (ESPIPE)

	ENTRY(ESPIPE, "Illegal seek"),
#endif
#if defined (EROFS)

	ENTRY(EROFS, "Read-only file system"),
#endif
#if defined (EMLINK)

	ENTRY(EMLINK, "Too many links"),
#endif
#if defined (EPIPE)

	ENTRY(EPIPE, "Broken pipe"),
#endif
#if defined (EDOM)

	ENTRY(EDOM, "Math argument out of domain of func"),
#endif
#if defined (ERANGE)

	ENTRY(ERANGE, "Math result not representable"),
#endif
#if defined (ENOMSG)

	ENTRY(ENOMSG, "No message of desired type"),
#endif
#if defined (EIDRM)

	ENTRY(EIDRM, "Identifier removed"),
#endif
#if defined (ECHRNG)

	ENTRY(ECHRNG, "Channel number out of range"),
#endif
#if defined (EL2NSYNC)

	ENTRY(EL2NSYNC, "Level 2 not synchronized"),
#endif
#if defined (EL3HLT)

	ENTRY(EL3HLT, "Level 3 halted"),
#endif
#if defined (EL3RST)

	ENTRY(EL3RST, "Level 3 reset"),
#endif
#if defined (ELNRNG)

	ENTRY(ELNRNG, "Link number out of range"),
#endif
#if defined (EUNATCH)

	ENTRY(EUNATCH, "Protocol driver not attached"),
#endif
#if defined (ENOCSI)

	ENTRY(ENOCSI, "No CSI structure available"),
#endif
#if defined (EL2HLT)

	ENTRY(EL2HLT, "Level 2 halted"),
#endif
#if defined (EDEADLK)

	ENTRY(EDEADLK, "Deadlock condition"),
#endif
#if defined (ENOLCK)

	ENTRY(ENOLCK, "No record locks available"),
#endif
#if defined (EBADE)

	ENTRY(EBADE, "Invalid exchange"),
#endif
#if defined (EBADR)

	ENTRY(EBADR, "Invalid request descriptor"),
#endif
#if defined (EXFULL)

	ENTRY(EXFULL, "Exchange full"),
#endif
#if defined (ENOANO)

	ENTRY(ENOANO, "No anode"),
#endif
#if defined (EBADRQC)

	ENTRY(EBADRQC, "Invalid request code"),
#endif
#if defined (EBADSLT)

	ENTRY(EBADSLT, "Invalid slot"),
#endif
#if defined (EDEADLOCK)

	ENTRY(EDEADLOCK, "File locking deadlock error"),
#endif
#if defined (EBFONT)

	ENTRY(EBFONT, "Bad font file format"),
#endif
#if defined (ENOSTR)

	ENTRY(ENOSTR, "Device not a stream"),
#endif
#if defined (ENODATA)

	ENTRY(ENODATA, "No data available"),
#endif
#if defined (ETIME)

	ENTRY(ETIME, "Timer expired"),
#endif
#if defined (ENOSR)

	ENTRY(ENOSR, "Out of streams resources"),
#endif
#if defined (ENONET)

	ENTRY(ENONET, "Machine is not on the network"),
#endif
#if defined (ENOPKG)

	ENTRY(ENOPKG, "Package not installed"),
#endif
#if defined (EREMOTE)

	ENTRY(EREMOTE, "Object is remote"),
#endif
#if defined (ENOLINK)

	ENTRY(ENOLINK, "Link has been severed"),
#endif
#if defined (EADV)

	ENTRY(EADV, "Advertise error"),
#endif
#if defined (ESRMNT)

	ENTRY(ESRMNT, "Srmount error"),
#endif
#if defined (ECOMM)

	ENTRY(ECOMM, "Communication error on send"),
#endif
#if defined (EPROTO)

	ENTRY(EPROTO, "Protocol error"),
#endif
#if defined (EMULTIHOP)

	ENTRY(EMULTIHOP, "Multihop attempted"),
#endif
#if defined (EDOTDOT)

	ENTRY(EDOTDOT, "RFS specific error"),
#endif
#if defined (EBADMSG)

	ENTRY(EBADMSG, "Not a data message"),
#endif
#if defined (ENAMETOOLONG)

	ENTRY(ENAMETOOLONG, "File name too long"),
#endif
#if defined (EOVERFLOW)

	ENTRY(EOVERFLOW, "Value too large for defined data type"),
#endif
#if defined (ENOTUNIQ)

	ENTRY(ENOTUNIQ, "Name not unique on network"),
#endif
#if defined (EBADFD)

	ENTRY(EBADFD, "File descriptor in bad state"),
#endif
#if defined (EREMCHG)

	ENTRY(EREMCHG, "Remote address changed"),
#endif
#if defined (ELIBACC)

	ENTRY(ELIBACC, "Can not access a needed shared library"),
#endif
#if defined (ELIBBAD)

	ENTRY(ELIBBAD, "Accessing a corrupted shared library"),
#endif
#if defined (ELIBSCN)

	ENTRY(ELIBSCN, ".lib section in a.out corrupted"),
#endif
#if defined (ELIBMAX)

	ENTRY(ELIBMAX, "Attempting to link in too many shared libraries"),
#endif
#if defined (ELIBEXEC)

	ENTRY(ELIBEXEC, "Cannot exec a shared library directly"),
#endif
#if defined (EILSEQ)

	ENTRY(EILSEQ, "Illegal byte sequence"),
#endif
#if defined (ENOSYS)

	ENTRY(ENOSYS, "Operation not applicable"),
#endif
#if defined (ELOOP)

	ENTRY(ELOOP, "Too many symbolic links encountered"),
#endif
#if defined (ERESTART)

	ENTRY(ERESTART, "Interrupted system call should be restarted"),
#endif
#if defined (ESTRPIPE)

	ENTRY(ESTRPIPE, "Streams pipe error"),
#endif
#if defined (ENOTEMPTY)

	ENTRY(ENOTEMPTY, "Directory not empty"),
#endif
#if defined (EUSERS)

	ENTRY(EUSERS, "Too many users"),
#endif
#if defined (ENOTSOCK)

	ENTRY(ENOTSOCK, "Socket operation on non-socket"),
#endif
#if defined (EDESTADDRREQ)

	ENTRY(EDESTADDRREQ, "Destination address required"),
#endif
#if defined (EMSGSIZE)

	ENTRY(EMSGSIZE, "Message too long"),
#endif
#if defined (EPROTOTYPE)

	ENTRY(EPROTOTYPE, "Protocol wrong type for socket"),
#endif
#if defined (ENOPROTOOPT)

	ENTRY(ENOPROTOOPT, "Protocol not available"),
#endif
#if defined (EPROTONOSUPPORT)

	ENTRY(EPROTONOSUPPORT, "Protocol not supported"),
#endif
#if defined (ESOCKTNOSUPPORT)

	ENTRY(ESOCKTNOSUPPORT, "Socket type not supported"),
#endif
#if defined (EOPNOTSUPP)

	ENTRY(EOPNOTSUPP, "Operation not supported on transport endpoint"),
#endif
#if defined (EPFNOSUPPORT)

	ENTRY(EPFNOSUPPORT, "Protocol family not supported"),
#endif
#if defined (EAFNOSUPPORT)

	ENTRY(EAFNOSUPPORT, "Address family not supported by protocol"),
#endif
#if defined (EADDRINUSE)

	ENTRY(EADDRINUSE, "Address already in use"),
#endif
#if defined (EADDRNOTAVAIL)

	ENTRY(EADDRNOTAVAIL, "Cannot assign requested address"),
#endif
#if defined (ENETDOWN)

	ENTRY(ENETDOWN, "Network is down"),
#endif
#if defined (ENETUNREACH)

	ENTRY(ENETUNREACH, "Network is unreachable"),
#endif
#if defined (ENETRESET)

	ENTRY(ENETRESET, "Network dropped connection because of reset"),
#endif
#if defined (ECONNABORTED)

	ENTRY(ECONNABORTED, "Software caused connection abort"),
#endif
#if defined (ECONNRESET)

	ENTRY(ECONNRESET, "Connection reset by peer"),
#endif
#if defined (ENOBUFS)

	ENTRY(ENOBUFS, "No buffer space available"),
#endif
#if defined (EISCONN)

	ENTRY(EISCONN, "Transport endpoint is already connected"),
#endif
#if defined (ENOTCONN)

	ENTRY(ENOTCONN, "Transport endpoint is not connected"),
#endif
#if defined (ESHUTDOWN)

	ENTRY(ESHUTDOWN, "Cannot send after transport endpoint shutdown"),
#endif
#if defined (ETOOMANYREFS)

	ENTRY(ETOOMANYREFS, "Too many references: cannot splice"),
#endif
#if defined (ETIMEDOUT)

	ENTRY(ETIMEDOUT, "Connection timed out"),
#endif
#if defined (ECONNREFUSED)

	ENTRY(ECONNREFUSED, "Connection refused"),
#endif
#if defined (EHOSTDOWN)

	ENTRY(EHOSTDOWN, "Host is down"),
#endif
#if defined (EHOSTUNREACH)

	ENTRY(EHOSTUNREACH, "No route to host"),
#endif
#if defined (EALREADY)

	ENTRY(EALREADY, "Operation already in progress"),
#endif
#if defined (EINPROGRESS)

	ENTRY(EINPROGRESS, "Operation now in progress"),
#endif
#if defined (ESTALE)

	ENTRY(ESTALE, "Stale NFS file handle"),
#endif
#if defined (EUCLEAN)

	ENTRY(EUCLEAN, "Structure needs cleaning"),
#endif
#if defined (ENOTNAM)

	ENTRY(ENOTNAM, "Not a XENIX named type file"),
#endif
#if defined (ENAVAIL)

	ENTRY(ENAVAIL, "No XENIX semaphores available"),
#endif
#if defined (EISNAM)

	ENTRY(EISNAM, "Is a named type file"),
#endif
#if defined (EREMOTEIO)

	ENTRY(EREMOTEIO, "Remote I/O error"),
#endif

};

static char g_static_assert[sizeof(g_error_table) < 2048 ? 1 : -1];

char const		*ft_strerror(int errnum)
{
	if (errnum < 0 || errnum > (int)SIZE_ARRAY(g_error_table)
		|| g_error_table[errnum] == NULL)
		return ("Unknown errno");
	else
		return (g_error_table[errnum]);
	(void)g_static_assert;
}
