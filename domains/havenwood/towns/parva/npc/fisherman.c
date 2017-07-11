#include <lib.h>
#include "../parva.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetTown("Parva");
   SetKeyName("Louie Bacalao");
   SetShort("Louie Bacalao the fisherman");
   SetId( ({ "louie","bacalao", "fisher", "man", "fisherman" }) );
   SetAdjectives( ({ "louie", "fisher", "fish", "tall" }) );
   SetLong("The tall fisherman is a skinny human who is just "
           "slightly over the hill in years. His hands and "
           "face are calloused from the salty spray of his "
           "years spent on fishing ships, but now he sits "
           "on the dock and fishes in his spare time.");
   SetClass("merchant");
   SetGender("male");
   SetRace("human");
   SetLevel(5);
   SetMorality(-100);
   AddTrainingSkills("bargaining");
   AddTrainingSkills("fishing");
   AddTrainingSkills("lockpicking");
   AddTrainingSkills("navigation");
   AddTrainingSkills("stealing");
   AddTrainingSkills("sailing");
   AddTrainingSkills("stealth");
   SetInventory( ([
     PARVA_OBJ + "fisher_boots" : "wear boots",
     PARVA_OBJ + "fisher_pants" : "wear pants",
     PARVA_OBJ + "fisher_shirt" : "wear shirt",
     PARVA_OBJ + "fisher_pole"  : "wield pole",
     ]) );
   SetAction(15, ({
    "!fish with pole",
    "!fish with pole",
    "!fish with pole",
    "!fish with pole",
    "!emote whistles a little ditty to himself",
    "!emote examines his pole.",
    "!emote looks excited at a fake tug on the line.",
    }) );
}

