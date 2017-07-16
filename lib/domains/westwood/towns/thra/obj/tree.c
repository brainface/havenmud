#include <lib.h>
#include <climb.h>
#include "../thra.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
  item::create();
  SetShort("a massive tree");
  SetId( ({ "tree" }) );
  SetAdjectives( ({ "massive" }) );
  SetLong(
    "This tree, while massive, is also studded with limbs making it an easy tree to <climb>."
    );
  SetClimb(THRA_ROOM + "center", CLIMB_UP);
}
