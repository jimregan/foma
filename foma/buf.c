/*   Foma: a finite-state toolkit and library.                                 */
/*   Copyright © 2008-2015 Mans Hulden                                         */

/*   This file is part of foma.                                                */

/*   Licensed under the Apache License, Version 2.0 (the "License");           */
/*   you may not use this file except in compliance with the License.          */
/*   You may obtain a copy of the License at                                   */

/*      http://www.apache.org/licenses/LICENSE-2.0                             */

/*   Unless required by applicable law or agreed to in writing, software       */
/*   distributed under the License is distributed on an "AS IS" BASIS,         */
/*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  */
/*   See the License for the specific language governing permissions and       */
/*   limitations under the License.                                            */

//#include "fomalib.h"
#include <stdlib.h>
#include <stdio.h>

/* http://tools.ietf.org/html/rfc3629 */
#define UTF8_MAX_LEN 4

#define xxcalloc calloc
#define xxfree free

typedef struct {
    unsigned int length;
    unsigned int bytes;
    unsigned int start;
    unsigned int end;
    unsigned int cpos;
    unsigned int lpos;
    char *buf;
} rbuf;

rbuf* buf_alloc (unsigned int length)
{
    rbuf *buf = (rbuf *) xxcalloc(1, sizeof(rbuf));
    buf->length = length + 1;
    buf->bytes = (length * UTF8_MAX_LEN) + 1;
    buf->start = 0;
    buf->end = 0;
    buf->cpos = 0;
    buf->lpos = 0;
    buf->buf = (char *) xxcalloc(buf->bytes, sizeof(char));
}

void buf_free (rbuf* buf)
{
    if(buf) {
        if(buf->buf) {
            xxfree(buf->buf);
            buf->buf = NULL;
        }
        xxfree(buf);
        buf = NULL;
    }
}

char* buf_last (rbuf* buf)
{
    if(buf->lpos != 0) {
         return (buf->buf + (buf->lpos - 1));
    } else {
         return (buf->buf + (buf->bytes - 1));
    }
}

/* blech */
void buf_set_pos (rbuf* buf, unsigned int pos)
{
     buf->cpos = pos;
}

unsigned int buf_get_pos (rbuf* buf)
{
     return buf->cpos;
}

unsigned int buf_diff_prev (rbuf* buf, unsigned int pos)
{
     if(pos <= buf->cpos) {
         return (buf->cpos - pos);
     } else {
         return (buf->cpos + buf->bytes - pos);
     }
}

int buf_empty (rbuf* buf)
{
     return (buf->cpos == buf->lpos) ? 1 : 0;
}

int buf_has_space (rbuf* buf)
{
    return ((buf->end + 1) % buf->bytes - buf->start - 1);
}

int main (int argc, char** argv)
{
    rbuf* test = buf_alloc(10);
    printf("Has space: %d\n", buf_has_space(test));
    printf("Is empty: %d\n", buf_empty(test));
}
