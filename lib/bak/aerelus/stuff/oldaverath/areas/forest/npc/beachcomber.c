// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("beach comber");
   SetShort("a beach comber");
   SetId( ({ "comber" }) );
   SetAdjectives( ({ "beach" }) );
   SetLong("Quirky eyes and an unruly beard characterize this young human male "
           "as an isolated recluse.  Some strength fills his body, but overall, "
           "he is a skinny beanpole.");
   SetGender("male");
   SetRace("human");
   SetClass("fighter");
   SetSkill("blunt attack",1,1);
   SetSkill("blunt defense",1,1);
   SetLevel(5);
   SetInventory( ([
                    FOREST_OBJ + "driftwood" : "wield driftwood",
                    FOREST_OBJ + "abalone" : 2,
                    FOREST_OBJ + "beachsandals" : "wear sandals",
                    FOREST_OBJ + "beachshorts" : "wear shorts",
                    FOREST_OBJ + "beachshirt" : "wear shirt",
                    FOREST_OBJ + "shellnecklace" : "wear necklace",
               ]) );
   SetCurrency("ducats",10);
   SetAction(1, ({ "!emote searches through the tide line.","!emote peers under a "
                   "clump of seaweed.","!emote examines a pile of driftwood.",
                   "!emote stares listlessly at the ocean." }) );
}
