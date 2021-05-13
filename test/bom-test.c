/*
 * sample code with libchardet
 * author: JoungKyun.Kim <http://oops.org>
 */
#include <chardet.h>
//#include "../src/chardet.h"
#include <stdlib.h>
#include <sys/stat.h>

#ifdef CHARDET_BINARY_SAFE
	#define detect_api(x,y) detect_r(x, strlen(x), y)
#else
	#define detect_api(x,y) detect(x, y)
#endif

int main (int argc, char **argv) {
	DetectObj *obj;
	FILE      *fp;
	struct     stat sb;
	char      *buf;
	char      *buf1;
	size_t     n, i, bom, ret = 0;
	char      *f[2] = { "utf-8-bom.txt", "utf-8.txt" };

	for ( i=0; i<2; i++ ) {
		if ( stat (f[i], &sb) != 0 ) {
			fprintf (stderr, "file %s not found.", f[i]);
			continue;
		}

		buf = malloc (sizeof (char) * (sb.st_size + 4));
		memset (buf, 0, sb.st_size + 4);


		fp = fopen (f[i], "r");
		n = fread (buf, sizeof (char), sb.st_size, fp);
		fclose (fp);

		obj = detect_obj_init ();
		if ( obj == NULL ) {
			fprintf (stderr, "On attemped detector, memory allocation failed\n");
			return CHARDET_OUT_OF_MEMORY;
		}

		if ( detect_api (buf, &obj) == CHARDET_OUT_OF_MEMORY )
		{
			fprintf (stderr, "On handle processing, occured out of memory\n");
			return CHARDET_OUT_OF_MEMORY;
		}

		if ( buf[n-1] == '\n' ) {
			memset (buf + n - 1, 0, 1);
			n--;
		}

		if ( obj->bom == 1 ) {
			memmove (buf, buf + 4, n - 4);
			memset (buf + n - 4, 0, 1);
		}

		if ( argc > 1 ) {
			printf ("## Charset: %s, Confidence: %f, BOM: %d => %s\n", obj->encoding, obj->confidence, obj->bom, buf);
		} else {
			bom = i ? 0 : 1;
			if ( strcmp (obj->encoding, "UTF-8") != 0 && obj->confidence < 0.6 && bom != obj->bom ) {
				ret = 1;
			}
		}

		free (buf);
		detect_obj_free (&obj);

		if ( ret != 0 )
			return 1;
	}
	return 0;
}
