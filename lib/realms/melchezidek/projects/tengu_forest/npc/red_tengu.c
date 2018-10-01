#include <lib.h>
#include <std.h>
#include <armour_types.h>
#include "../tengu.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetId("tengu");
  SetKeyName("red tengu");
  SetShort("a small red tengu");
  SetLong("This small tengu has dark red feathers that"
          " are neatly packed onto its body. Her beak"
          " is a bright yellow color and her eyes are"
          " black orbs. She looks weak compared to other"
          " tengu, but more than capable of protecting"
          " her portion of the forest.");
  SetGender("female");
  SetRace("bird", "demon");
  SetBaseLanguage("Tai");
  SetClass("ninja");
  SetLevel(45);
  SetSkill("pole combat",94,1);
  SetInventory( ([
    TENG_OBJ "naginata" : "wield naginata",
  ]) );
  SetSpellBook( ([
     "tend wounds"       : 100,
     "full regeneration" : 100,
     ]) );
  SetCombatAction(35, ({
     "!emote squaks loudly.",
     "!disarm",
     "!disorient",
     "!cast tend wouds",
     "!cast full regeneration",
     "!disarm",
     }) );
   AddLimb("left claw", "left wing", 3,({A_WEAPON}) );
   AddLimb("right claw", "right wing", 3,({A_WEAPON}) );
}
