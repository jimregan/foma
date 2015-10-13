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

#include "fomalib.h"

/* http://tools.ietf.org/html/rfc3629 */
#define UTF8_MAX_LEN 4

typedef struct {
    char *buf;
    int length;
    int bytes;
    int start;
    int end;
} rbuf;

rbuf* buf_alloc (int length)
{
    rbuf *buf = xxcalloc(1, sizeof(rbuf));
    buf->length = length + 1;
    buf->bytes = (length * UTF8_MAX_LEN) + 1;
    buf->start = 0;
    buf->end = 0;
    buf->buf = xxcalloc(buf->bytes, 1);
}

void buf_free (rbuf buf)
{
    if(buf) {
        if(buf->buf) {
            xxfree(buf->buf);
        }
        xxfree(buf);
    }
}
