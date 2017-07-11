#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("thri-kreen worker");
  SetRace("thri-kreen");
  SetId( ({ "thri-kreen", "worker" }) );
  SetAdjectives( ({ "thri-kreen" }) );
  SetGender(random(2) ? "male" : "female");
  SetClass("merchant");
  SetLevel(40 + random(20));
  SetShort("a thri-kreen worker");
  SetLong(
    "This pathetic creature is a mere drone worker here in the thri-kreen tunnels of Xandria."
    );
  SetInventory( ([
    "/std/obj/digging/shovel" : "wield shovel",
    "/std/clothing/body/loin" : "wear loincloth",
    ]) );
}