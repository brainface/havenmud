#include <lib.h>
#include <std.h>
#include <armour_types.h>
#include "../tengu.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetId("tengu");
  SetKeyName("black tengu");
  SetShort("a small black tengu");
  SetLong("This black tengu looks fiercy over confident."
          " His frame is much to large for the mottled feathers"
          " that cover it yet his face is very stern and intense."
          " He has a black beak to match his black feathers. His"
          " wings look small compared to the rest of his body,"
          " and while weak looking compared to other tengu,"
          " he looks more than capable of defending his part"
          " of the forest.");
  SetGender("male");
  SetRace("bird", "demon");
  SetBaseLanguage("Tai");
  SetClass("ninja");
  SetLevel(25+random(10));
  SetInventory( ([
    TENG_OBJ "yumi" : "wield yumi",
  ]) );
  SetSpellBook( ([
     "tend wounds"       : 100,
     ]) );
  SetCombatAction(35, ({
     "!emote squaks loudly.",
     "!disarm",
     "!disorient",
     "!cast tend wouds",
     "!disarm",
     }) );
   AddLimb("left claw", "left wing", 3,({A_WEAPON}) );
   AddLimb("right claw", "right wing", 3,({A_WEAPON}) );
}
