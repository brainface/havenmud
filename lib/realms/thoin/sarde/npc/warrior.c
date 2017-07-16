//
//  Warrior for the tunnel
//  Created by: Rhakz@Haven -- Angel Cazares
//  For: Baria
//  Date: 06/04/99
//
#include <lib.h>
#include "../sarde.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("warrior");
  SetId( ({"warrior", "draconian"}) );
  SetAdjectives( ({"powerful", "dangerous"}) );
  SetShort("a powerful warrior");
  SetLong("This draconian warrior is protecting the massive black door "
          "to the north. His pitch black scales shine brightly with "
          "the light and emphasize his muscular body. He is extremely "
          "powerful and dangerous."
         );
  SetMorality(random(150) - 50);
  SetGender("male");
  SetRace("draconian");
  SetTown("Sarde");
  SetClass("fighter");
  SetLevel(50 + random(5));
  SetInventory( ([
          SARDE_OBJ + "ruby_sword" : "wield shortsword",
  ]) );
  SetCurrency( ([
     "chits" : 900 + random(900),
  ]) );
}

