#include <lib.h>
#include "../lodge.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Protector");
  SetRace("nosferatu");
  SetShort("a nosferatu protector");
  SetId( ({"nosferatu","protector"}) );
  SetAdjectives( ({"still","keen"}) );
  SetClass("cavalier");
  SetLevel(18);
  SetGender("female");
  SetMorality(-80);
  SetCurrency("crystals",random(150)+20);
  SetLong("This female protector is standing very still.  The way she is "
  "postured, shows a sense of keen hearing.  Her pale skin makes "
  "her blend in with the winter scene.  She moves ever so slightly, "
  "doing her best to remain unseen.  The expression that overthrows "
  "her face explains years of loyalty to whom ever she serves.  She"
  " seems to know what she is doing in her line of work.");
  
  SetAction(13, ({
  "!emote stops and turns her head in your direction.",
  "!emote glances around curiously.",
  "!say I wonder what you're up to.",
  "!grin",  
  }) );
  SetCombatAction(12, ({
  "!say I don't like to kill...much.",
  "!laugh",
  "!say I've dealt with your kind before, and I can do it again!",
  }) );
  SetInventory( ([
  L_OBJ + "axe" : "wield axe",
  L_OBJ + "vest" : "wear vest",
  L_OBJ + "pants" : "wear pants",
  ]) );
}


/* Approved by Duuktsaryth on Sat Feb 19 16:35:42 2000. */
