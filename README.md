Mozilla's Universal Charset Detector C/C++ API (libchardet) Readme document
===

## License
Copyright (c) 2016 JoungKyun.Kim <http://oops.org> All rights reserved.

This program is under MPL 1.1 or LGPL 2.1

## Description
libchardet is based on Mozilla Universal Charset Detector library and, detects
the character set used to encode data.

Original code was writed by Netscape Communications Corporation, and John
Gardiner Myers &lt;jgmyers@proofpoint.com&gt; made independent Universal Detector
code from Mozilla Browser.

libchardet based on John Gardiner Myers's code that call [Encode-Detect-1.01](http://search.cpan.org/~jgmyers/Encode-Detect-1.01/)
perl module, and added C wrapping API, and library build environment with libtool

## Sample Codes

See also test directory of source code

```c
       #include <chardet.h>

       int main (void) {
            DetectObj *obj;

            if ( (obj = detect_obj_init ()) == NULL ) {
                 fprintf (stderr, "Memory Allocation failed\n");
                 return CHARDET_MEM_ALLOCATED_FAIL;
            }

            switch (detect ("안녕하세요", &obj)) {
                 case CHARDET_OUT_OF_MEMORY :
                      fprintf (stderr, "On handle processing, occured out of memory\n");
                      detect_obj_free (&obj);
                      return CHARDET_OUT_OF_MEMORY;
                 case CHARDET_NULL_OBJECT :
                      fprintf (stderr,
                                "2st argument of chardet() is must memory allocation "
                                "with detect_obj_init API\n");
                      return CHARDET_NULL_OBJECT;
            }

            printf ("encoding: %s, confidence: %f\n", obj->encoding, obj->confidence);
            detect_obj_free (&obj);

           return 0;
       }
```

or

```c
       #include <chardet.h>

       int main (void) {
            Detect    * d;
            DetectObj * obj;

            if ( (d = detect_init ()) == NULL ) {
                 fprintf (stderr, "chardet handle initialize failed\n");
                 return CHARDET_MEM_ALLOCATED_FAIL;
            }

            // for loop
            //detect_reset (&d);

            if ( (obj = detect_obj_init ()) == NULL ) {
                 fprintf (stderr, "Memory Allocation failed\n");
                 return CHARDET_MEM_ALLOCATED_FAIL;
            }

            switch (detect_handledata (&d, "안녕하세요", &obj)) {
                 case CHARDET_OUT_OF_MEMORY :
                      fprintf (stderr, "On handle processing, occured out of memory\n");
                      detect_obj_free (&obj);
                      return CHARDET_OUT_OF_MEMORY;
                 case CHARDET_NULL_OBJECT :
                      fprintf (stderr,
                                "2st argument of chardet() is must memory allocation "
                                "with detect_obj_init API\n");
                      return CHARDET_NULL_OBJECT;
            }

            printf ("encoding: %s, confidence: %f\n", obj->encoding, obj->confidence);
            detect_obj_free (&obj);
            detect_destroy (&d);

           return 0;
       }
```

## APIs
  * PHP    - http://ftp.oops.org/pub/oops/php/extensions/mod_chardet/
  * PYTHON - http://ftp.oops.org/pub/oops/python/chardet/
  * PERL   - http://search.cpan.org/~jgmyers/Encode-Detect-1.01/Detect.pm
