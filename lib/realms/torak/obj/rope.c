#include <lib.h>
#include <climb.h>

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
  item::create();
  SetShort("a long hemp rope");
  SetLong("The rope dangles from the sky. Weird.");
  SetId( ({"rope"}) );
  SetClimb(
    "/domains/crystal_reaches/towns/gwonish/room/enclosement", CLIMB_UP
  );
  SetMaterials( ({"natural"}) );
  SetAdjectives( ({ "long","hemp" }) );
  SetKeyName("rope");
  SetPreventGet("The rope doesn't budge!");
}
