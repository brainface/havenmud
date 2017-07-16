#include "../inn.h"
#include <lib.h>
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("orc");
  SetShort("a fat orc");
  SetId( ({ "orc", "fat orc" }) );
  SetLong("This is a fat, middle aged orc.  His ample belly extends far "
          "beyond the limits of normalcy and his acne covered face is "
          "amazingly ugly, even for an orc.  Of course, where there is fat "
          "there must usually be muscle to carry it.  This orc could "
          "probably defend himself quite well against most people.");
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(10);
  SetCurrency("senones", random(70) );
  SetMorality(175);
  SetInventory( ([ I_OBJ + "/meansword" : "wield sword" ]) );
}

