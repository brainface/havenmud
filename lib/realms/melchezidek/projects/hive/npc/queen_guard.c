#include <lib.h>
#include <std.h>
#include "../hive.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("thri-kreen");
  SetGender("male");
  SetMorality(0);
  SetClass("fighter");
  SetSkill("pierce combat", 1,1);
  SetLevel(100);
  SetInventory( ([
       HIVE_OBJ "glaive"      : "wield glaive in upper left hand and upper right hand",
       HIVE_OBJ "big_axe"     : "wield axe in lower left hand and lower right hand",
       HIVE_ARM "armlet"      : "wear 1st armlet on upper left arm and upper left hand",
       HIVE_ARM "armlet2"     : "wear 1st armlet on upper right arm and upper right hand",
       HIVE_ARM "bodyarmour"  : "wear suit of armour on torso and upper left arm and"
                                " upper right arm and left leg and right leg",
       HIVE_ARM "plumehelmet" : "wear helmet",
       HIVE_ARM "redcloak"    : "wear cloak on torso",
            ]) );
 

  SetShort("a Queen's Guard");
  SetLong("This is a massive thri-kreen. He is roughly 10 feet tall"
          " and heavily armoured. His main objective in life is the"
          " preservation and safety of his mother, the Queen Matron.");
  SetId( ({ "guard", "queen_guard", "queen's guard"  }) );
  SetKeyName("guard");
}
