//A freaking chair, with sit IN code...

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  item::create();
  SetKeyName("chair");
  SetId( ({ "chair" }) );
  SetAdjectives( ({ "brown" }) );
  SetShort("a brown chair" );
  SetLong( "This chair has been made with strong and sturdy wood "
           "and a smooth leather exterior has been wrapped around "
           "it. Four equal sized pegs stand out from the bottom "
           "of the chair to support weight. It appears quite heavy "
           "and well crafted.");
  SetMass(80);
  SetMaterial( ({ "wood", "textile" }) );
  SetPreventGet("It is sealed to the floor!");
  SetMaxSitters(1);
}
