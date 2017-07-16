/*  Kobold Chief - Level #1 Telgo's Caverns */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold chief");
  SetId( ({ "kobold chief", "chief", "kobold" }) );
  SetAdjectives( ({ "kobold", "chief" }) );
  SetShort("the kobold chief");

  SetLong("Standing close to four feet tall, the Kobold Chief is taller than "
          "the normal kobold.  His scaly hide is a rusty black in color, and "
          "along with a pair of glowing, red eyes and two small, tan horns he "
          "has a devilish look to his dogform.  He smells of stagnant water "
          "and wet dog.");

  SetRace("kobold");
  SetClass("fighter");
  SetLevel(5);
  SetGender("male");
  SetMorality(-190);
  SetDie("As the Kobold Chief dies he takes one last futile reach towards "
         "your scalp, thinking to add it to his collection.");

  SetAction(10, ({ "The kobold cheif looks proudly at his collection of "
                  "scalps.",
                  "The Kobold Chief looks over at the kobold women over on "
                  "his bed and a wide smile spread across his face.",
  }) );

  SetCombatAction(20, ({ "!disorient",
                         "The Kobold Chief swings for your neck, in an "
                         "attempt to add your scalp to his walls.",
  }) );

  SetInventory( ([ OBJS + "/longsword_koboldish" : "wield longsword",
                   OBJS + "/handaxe_koboldish" : "wield axe",
                   OBJS + "/armour_leather1" : "wear leather",
                   OBJS + "/helmet_scalp" : "wear helmet",
  ]) );
}
