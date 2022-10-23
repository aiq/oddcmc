#ifndef NUKLEAR_NKSTRINGBUFFER_H
#define NUKLEAR_NKSTRINGBUFFER_H

#include "clingo/lang/mem.h"
#include "raylib-nuklear.h"

struct nkStringBuffer
{
   char* mem;
   int len;
   int max;
};
typedef struct nkStringBuffer nkStringBuffer;

#define static_string_buffer_c_( Name, Max )                                   \
static char Name##CharArray[Max];                                              \
static nkStringBuffer Name = { .mem=Name##CharArray, .len=0, .max=(Max) }

#define string_buffer_c_( Max )                                                \
(                                                                              \
   (nkStringBuffer){ .mem=(char[]){ [(Max)-1]=0 }, .len=0, .max=(Max),  }      \
)

static inline nk_flags edit_string_nk( struct nk_context* ctx,
                                       nk_flags flags,
                                       nkStringBuffer buf[static 1],
                                       nk_plugin_filter filter )
{
   return nk_edit_string( ctx, flags, buf->mem, &(buf->len), buf->max, filter );
}

#endif