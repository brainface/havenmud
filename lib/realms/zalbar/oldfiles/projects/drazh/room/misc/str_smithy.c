// by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../../drazh.h"

inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetPurgeInterval(2);
  SetInventory( ([
      V_OBJ + "glaive"      : 1,
	    V_OBJ + "face_mask"   : 2,
      V_OBJ + "scale_mail"  : 2,
	    V_OBJ + "guard_knife" : 2,
	    V_OBJ + "vest"        : 1,
	    V_OBJ + "tuck"        : 1,
	    V_OBJ + "tail_armour" : 2,
	    ]) );
}
