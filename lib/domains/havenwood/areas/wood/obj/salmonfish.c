//coded by Syra 8/97
#include <lib.h>
#include "../wood.h"

inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("silver salmon");
  SetShort("a silver salmon");
  SetFight(5);
  SetFood(HWD_OBJ + "/salmonmeal");
  SetMass(20);
  }


/* Approved by Amelia on Sun Sep 14 19:51:15 1997. */