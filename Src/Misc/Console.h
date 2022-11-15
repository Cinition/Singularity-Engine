#pragma once

#include <cstdarg>
#include <cstdio>
#include "String.h"

namespace Singularity
{
    void static Log( const char* _string ) { printf( _string); }
    void static Log( const char* _string, va_list _vars ) { vprintf( _string, _vars); }
}
