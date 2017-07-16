// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("shaggy dog");
   SetShort("a shaggy dog");
   SetId( ({ "shaggy dog","dog" }) );
   SetLong("This small dog is all fur, mostly a milk chocolate sort of "
           "brown.  Its legs are short and so it's the tiny remnant of "
           "a tail that is hidden by the long fur.  It seems to be near "
           "blind, probably from the hair in front of its eyes, and its "
           "nose is constantly sniffing--and sniffling--to make out "
           "its surroundings.");
   SetRace("dog");
   SetClass("animal");
   SetLevel(1);
   SetAction(1, ({
                   "!emote makes a sniffing noise.",
                   "!emote sneezes.",
                   "!emote whines for food.",
                }) );
   SetMorality(45);
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
