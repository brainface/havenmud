#include <lib.h>
#include "parva.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetTown("Parva");
   SetKeyName("fisherman");
   SetProperty("parvanoleave",1);
   SetShort("a tall fisherman");
   SetId( ({ "fisher","man","fisherman" }) );
   SetAdjectives( ({ "fisher","fish","tall" }) );
   SetLong("The tall fisherman is a skinny human who is just "
           "slightly over the hill in years.  His hands and "
           "face are calloused from the salty spray of his "
           "years spent on fishing ships, but now he sits "
           "on the dock and fishes in his spare time.");
   SetClass("merchant");
   SetGender("male");
   SetRace("human");
   SetLevel(35);
   AddTrainingSkills("fishing");
   SetInventory( ([
                    P_OBJ + "/boots_fish" : "wear boots",
                    P_OBJ + "/pants_fish" : "wear pants",
                    P_OBJ + "/shirt_fish" : "wear shirt",
                    P_OBJ + "/pole_good" : "fish with pole",
                    P_OBJ + "/smallffood" : 5+random(6),
               ]) );
   SetAction(15, ({ "!fish with pole","!fish with pole",
                    "!fish with pole","!fish with pole",
                    "!emote whistles a little ditty to "
                    "himself","!fish with pole","!fish with "
                    "pole","!emote examines his pole.",
                    "!emote looks excited at a fake tug on "
                    "the line." }) );
   SetCombatAction(20, ({ "!speak Hey you fiend!  Get away!  "
                          "Stop trying to steal my fishing "
                          "spot!","!speak Stop that!",
                          "!speak Get away!  I mean it!",
                          "!speak Hey, Parva allows fishing!",
                          "!speak What are you doing?",
                          "!speak Fool!  Idiot!","!speak "
                          "Think of the years I've spent "
                          "training to be so good at fishing!  "
                          "You could learn a lot from me, kid!",
                          "!speak Get away!  Stop that!",
                          "!speak Help!  Help!","!yell Help!  "
                          "Help me!","!yell Someone's trying "
                          "to kill us innocent fisherman!",
                          "!speak You stay away from my pole!  "
                          "It's a good one!  Cost me a lot of "
                          "oros!" }) );
}
