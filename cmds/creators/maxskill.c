#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(mixed cl) {
  int x;
  int tmpcl = cl;
  int level = 0;
  cl = to_int(cl);
 for(level = 150; level <= 255; level++) {

    if( level == 0 ) {
	this_player()->eventPrint(level + ":  200");
    }
    else {
	
	if( cl > 4 ) {
	    cl = 4;
	}
	if( cl < 1 ) {
	    cl = 4;
	}
	x = level;
       tmpcl = cl;
            while( tmpcl-- ) {
	    x *= level;
	}
	this_player()->eventPrint("Level " + level + ": " + (x * 400));
      }
  }
 return 1;
}

