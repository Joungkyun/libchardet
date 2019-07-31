/*
 * sample code with libchardet
 * author: JoungKyun.Kim <http://oops.org>
 */

#include <chardet.h>
//#include "../src/chardet.h"

#ifdef CHARDET_BINARY_SAFE
    #define detect_handledata_str(x,y,z) detect_handledata_r(x, y, strlen(y), z)
#else
    #define detect_handledata_str(x,y,z) detect_handledata(x, y, z)
#endif

int main (int argc, char ** argv) {
	Detect * d;
	DetectObj *obj;
	int i, ret = 0;

	char *str[] = {
		"안녕",
		"안녕하세요",
		"안녕하세요 정말?",
		"그래 이정도면 판단 될까?",
		"좀더 길게 적어 볼까 얼마나 길게 해야!",
		"그래 그래 좀 더 길게 적어 보자 더 길게 적어 보야야 겠지...",
		"12345 abcde"
	};

	char *expect[] = {
		"ECU-KR",
		"ECU-KR",
		"ECU-KR",
		"ECU-KR",
		"ECU-KR",
		"ECU-KR",
		"ASCII"
	};

	short arrayNum;
	arrayNum = sizeof (str) / sizeof (str[0]);

	if ( (d = detect_init ()) == NULL ) {
		fprintf (stderr, "chardet handle initialize failed\n");
		return CHARDET_MEM_ALLOCATED_FAIL;
	}

	for ( i=0; i<arrayNum; i++ ) {
		detect_reset (&d);

		obj = detect_obj_init ();
		if ( obj == NULL ) {
			fprintf (stderr, "On attemped \"%s\", memory allocation failed\n", str[i]);
			continue;
		}

		if ( detect_handledata_str (&d, str[i], &obj) == CHARDET_OUT_OF_MEMORY )
		{
			fprintf (stderr, "On handle processing, occured out of memory\n");
			return CHARDET_OUT_OF_MEMORY;
		}

		if ( argc > 1 )
			printf ("#1 %s : %s : %f : %d\n", str[i], obj->encoding, obj->confidence, obj->bom);
		else {
			if ( strcmp(obj->encoding, expect[i]) != 0 || obj->confidence < 0.6 )
				ret = 1;
		}
		detect_obj_free (&obj);

		if ( ret > 0 )
			break;
	}

	detect_destroy (&d);

	return ret;
}
