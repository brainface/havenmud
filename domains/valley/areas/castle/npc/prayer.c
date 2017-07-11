#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("praying dwarf");
   SetShort("a praying dwarf");
   SetId( ({ "dwarf" }) );
   SetAdjectives( ({ "praying","old" }) );
   SetLong("A long white beard comes from the face of the old dwarf, "
           "whose peaceful frame almost generates an aura of "
           "protection around him.  He is old, however, and may have "
           "forgotten much.");
   SetGender("male");
   
   SetRace("dwarf");
   SetClass("enchanter");
   //SetClass("fighter");
   SetLevel(18);
   SetMorality(500);
   SetSpellBook( ([
      "buffer"   : 100,
      "missile"  : 100,
      "ice ball" :  40,
               ]) );
   SetAction(2, ({ 
                "!cast buffer",
                "!emote mutters some words of praise to his god under his breath.", 
                }) );
   SetCombatAction(80, ({ 
                "!cast missile",
                "!cast buffer",
                "!cast ice ball",
                }) );
}
