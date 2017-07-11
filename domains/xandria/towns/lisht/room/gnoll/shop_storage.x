//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("shop storage");
  SetExits( ([
    ]) );
}
