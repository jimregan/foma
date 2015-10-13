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

static int 
is_escaped(char c)
{
    switch (c) {
    case '[':
    case ']':
    case '}':
    case '{':
    case '^':
    case '$':
    case '/':
    case '\\':
    case '@':
    case '<':
    case '>':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

