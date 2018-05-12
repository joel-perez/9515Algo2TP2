#include <iostream>
#include "Archivo.h"

using namespace std;

Archivo::Archivo() {

}

char Archivo::obtenerSeparadorDirectorio() {
	//return SEPARADOR_DIRECTORIO;
	return '/';
}

string Archivo::obtenerRutaEjecutable() {
	/*
	 //	Windows:

	 int bytes = GetModuleFileName(NULL, pBuf, len);
	 if (bytes == 0)
	 return -1;
	 else
	 return bytes;
	 //	Linux:

	 char szTmp[32];
	 sprintf(szTmp, "/proc/%d/exe", getpid());
	 int bytes = MIN(readlink(szTmp, pBuf, len), len - 1);
	 if (bytes >= 0)
	 pBuf[bytes] = '\0';
	 return bytes;
	 */

	/*
	 This is from the cplusplus forum

	 On windows:

	 #include <string>
	 #include <windows.h>

	 std::string getexepath()
	 {
	 char result[ MAX_PATH ];
	 return std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
	 }
	 On Linux:

	 #include <string>
	 #include <limits.h>
	 #include <unistd.h>

	 std::string getexepath()
	 {
	 char result[ PATH_MAX ];
	 ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
	 return std::string( result, (count > 0) ? count : 0 );
	 }
	 On HP-UX:

	 #include <string>
	 #include <limits.h>
	 #define _PSTAT64
	 #include <sys/pstat.h>
	 #include <sys/types.h>
	 #include <unistd.h>

	 std::string getexepath()
	 {
	 char result[ PATH_MAX ];
	 struct pst_status ps;

	 if (pstat_getproc( &ps, sizeof( ps ), 0, getpid() ) < 0)
	 return std::string();

	 if (pstat_getpathname( result, PATH_MAX, &ps.pst_fid_text ) < 0)
	 return std::string();

	 return std::string( result );
	 }
	 */
	return "";
}
