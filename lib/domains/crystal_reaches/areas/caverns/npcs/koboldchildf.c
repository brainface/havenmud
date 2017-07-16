/*  Female Kobold Child  -  Level #1 Caverns */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold child");
  SetId( ({ "kobold child", "child", "kobold" }) );
  SetAdjectives( ({ "kobold", "child", "dirty", "battered" }) );
  SetShort("a kobold child");

  SetLong("The kobold child appears battered and dirty.  There are two small "
          "bumps on her head where her small horns should be.  The rags she "
          "wears are scraps of an orange shirt and red pants.  She seems "
          "content to sit around and rest for the moment.");

  SetRace("kobold");
  SetClass("rogue");
  SetLevel(1);
  SetGender("female");
  SetMorality(0);
  SetDie("The kobold child dies without a sound.");

  SetAction(10, ({ "The Kobold Child plays with a piece of cloth.",
                   "The Kobold Child wimpers."
  }) );

  SetInventory( ([ OBJS + "/rags_kobold" : "wear rags",
  ]) );
}
