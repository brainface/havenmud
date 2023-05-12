// Millepede for Underland Guards to ride
// This is literally going to be an XP bank of legs...
// Atrus@HavenMud 2023

#include <lib.h>
#include "../underland.h"
inherit LIB_NPC;
inherit LIB_MOUNT;

static void create() {
   npc::create();
   SetKeyName("giant millipede");
   SetShort("a giant millipede");
   SetId( ({ "millipede" }) );
   SetAdjectives( ({ "giant" }) );
   SetLong("The sheer size of this diplopoda is absolutely staggering. "
           "The millipede does not see, but feels his way around with small "
           "fuzzy antennae. His segments are a shimmering black that looks "
           "oily. The carapace of the beast could easily deflect all but "
           "the most powerful of blows. It is long with many segments.");
   SetRace("millipede",1);
   SetGender("male");
   SetClass("animal");
   SetLevel(200);
   
   // Ok, time to handle the limbage
   // Main "Body" for this creature
   AddLimb("first collum",0,1,({ }) );

   // Gotta have a head
   AddLimb("head","first collum",1,({ }) );

   // Add a couple feelers
   AddLimb("right feeler","head",4,({ }) );
   AddLimb("left feeler","head",4,({ }) );
   
   // Body/trunk segments

   //turns out this segment of the body doesn't have legs
   //AddLimb("first right somite","first collum",5,({ }) );
   //AddLimb("first left somite","first collum",5,({ }) );

   AddLimb("second tergum","first collum",3,({ }) );
   AddLimb("second right somite","second tergum",5,({ }) );
   AddLimb("second left somite","second tergum",5,({ }) ); 

   //most of the rest usually have 4 legs per segment til the end
   AddLimb("third tergum","second tergum",3,({ }) );
   AddLimb("third inner right right somite","third tergum",5,({ }) );
   AddLimb("third right somite","third tergum",5,({ }) );
   AddLimb("third inner left somite","third tergum",5,({ }) );
   AddLimb("third left somite","third tergum",5,({ }) );

   AddLimb("fourth tergum","third tergum",3,({ }) );
   AddLimb("fourth right somite","fourth tergum",5,({ }) );
   AddLimb("fourth left somite","fourth tergum",5,({ }) );
   AddLimb("fourth inner right somite","fourth tergum",5,({ }) );
   AddLimb("fourth inner left somite","fourth tergum",5,({ }) );

   AddLimb("fifth tergum","fourth tergum",3,({ }) );
   AddLimb("fifth right somite","fifth tergum",5,({ }) );
   AddLimb("fifth left somite","fifth tergum",5,({ }) );
   AddLimb("fifth inner right somite","fifth tergum",5,({ }) );
   AddLimb("fifth inner left somite","fifth tergum",5,({ }) );

   AddLimb("sixth tergum","fifth tergum",3,({ }) );
   AddLimb("sixth right somite","sixth tergum",5,({ }) );
   AddLimb("sixth left somite","sixth tergum",5,({ }) );
   AddLimb("sixth inner right somite","sixth tergum",5,({ }) );
   AddLimb("sixth inner left somite","sixth tergum",5,({ }) );

   AddLimb("seventh tergum","sixth tergum",3,({ }) );
   AddLimb("seventh right somite","seventh tergum",5,({ }) );
   AddLimb("seventh left somite","seventh tergum",5,({ }) );
   AddLimb("seventh inner right somite","seventh tergum",5,({ }) );
   AddLimb("seventh inner left somite","seventh tergum",5,({ }) );

   AddLimb("eighth tergum","seventh tergum",3,({ }) );
   AddLimb("eighth right somite","eighth tergum",5,({ }) );
   AddLimb("eighth left somite","eighth tergum",5,({ }) );
   AddLimb("eighth inner right somite","eighth tergum",5,({ }) );
   AddLimb("eighth inner left somite","eighth tergum",5,({ }) );

   AddLimb("ninth tergum","eighth tergum",3,({ }) );
   AddLimb("ninth right somite","ninth tergum",5,({ }) );
   AddLimb("ninth left somite","ninth tergum",5,({ }) );
   AddLimb("ninth inner right somite","ninth tergum",5,({ }) );
   AddLimb("ninth inner left somite","ninth tergum",5,({ }) );

   AddLimb("tenth tergum","ninth tergum",3,({ }) );
   AddLimb("tenth right somite","tenth tergum",5,({ }) );
   AddLimb("tenth left somite","tenth tergum",5,({ }) );
   AddLimb("tenth inner right somite","tenth tergum",5,({ }) );
   AddLimb("tenth inner left somite","tenth tergum",5,({ }) );

   AddLimb("eleventh tergum","tenth tergum",3,({ }) );
   AddLimb("eleventh right somite","eleventh tergum",5,({ }) );
   AddLimb("eleventh left somite","eleventh tergum",5,({ }) );
   AddLimb("eleventh inner right somite","eleventh tergum",5,({ }) );
   AddLimb("eleventh inner left somite","eleventh tergum",5,({ }) );

   AddLimb("twelfth tergum","eleventh tergum",3,({ }) );
   AddLimb("twelfth right somite","twelfth tergum",5,({ }) );
   AddLimb("twelfth left somite","twelfth tergum",5,({ }) );
   AddLimb("twelfth inner right somite","twelfth tergum",5,({ }) );
   AddLimb("twelfth inner left somite","twelfth tergum",5,({ }) );
   
   // Last few segments do not have 4 legs, back down to 2
   AddLimb("thirteenth tergum","twelfth tergum",3,({ }) );
   AddLimb("thirteenth right somite","thirteenth tergum",5,({ }) );
   AddLimb("thirteenth left somite","thirteenth tergum",5,({ }) );

   AddLimb("fourteenth tergum","thirteenth tergum",3,({ }) );
   AddLimb("fourteenth right somite","fourteenth tergum",5,({ }) );
   AddLimb("fourteenth left somite","fourteenth tergum",5,({ }) );

   AddLimb("fifteenth tergum","fourteenth tergum",3,({ }) );
   AddLimb("fifteenth right somite","fifteenth tergum",5,({ }) );
   AddLimb("fifteenth left somite","fifteenth tergum",5,({ }) );
   // Should be longer but for sanity and memory, I'm going to cut it off here
   // Millipedes are notorious for being >100 segments
}
