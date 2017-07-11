



#include <lib.h>
#include "../lake.h";

//inherit LIB_LEADER;
inherit LIB_NPC;

static void create() {
   ::create();
   SetMorality(20);
   SetKeyName("garion");
   SetShort("Garion the young boy");
   SetId( ({ "garion","boy","young boy" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("Garion is a young boy who cleans all day, and meanwhile "
           "dreams of fishing in the lake. He does what his mother "
           "tells him, but wants to do other things." );
   SetClass("rogue");
//   SetTown("all");
   SetLimit(1);
   SetGender("male");
   SetRace("human");
   SetLevel(15);
   SetMorality (-100);
   SetAction(6,({ 
                "!emote sweeps the floor.",
                "!emote eyes you cautiously.",
      }) );
   SetInventory( ([
      LAKE_OBJ + "/smallknife" : "wield knife",
      ]) );
   
   }
