#include <lib.h>
inherit LIB_SENTIENT;

void HugSomeone(string someone);
void ComfortSomeone(string someone);

static void create() {
   sentient::create();
   SetKeyName("bright popple");
   SetShort("a bright popple");
   SetId( ({ "bright popple","popple","pet" }) );
   SetLong("This brightly colored popple has a body, two "
           "arms, two legs, a face and a pouch on its "
           "back.  Two floppy ears hang off either side of its head, and "
           "a round puff-ball sort of nose in the center of its face.  "
           "Small circular eyes peer out at the world, devoid of all "
           "intelligence.  Long eyelashes curl out, much like cute girl "
           "eyelashes.  A small collar circles the joining of the body "
           "head, giving directions to how to return it to its "
           "owner.  Its soft, cloth-like skin has patches of fur "
           "adding to its softness.  It has colors all over it, "
           "blots stuck here and there.");
   SetRace("popple",1);
   AddLimb("round body", 0, 1, ({ }) );
   AddLimb("left arm","round body", 3, ({ }) );
   AddLimb("right arm","round body", 3, ({ }) );
   AddLimb("right leg","round body", 2, ({ }) );
   AddLimb("left leg","round body", 2, ({ }) );
   AddLimb("head","round body",1, ({ }) );
   AddLimb("right floppy ear","head", 5, ({ }) );
   AddLimb("left floppy ear","head", 5, ({ }) );
   AddLimb("poofy nose","head", 5, ({ }) );
   SetStat("agility",25,1);
   SetStat("coordination",20,3);
   SetStat("durability",30,2);
   SetStat("luck",30,1);
   SetStat("charisma",30,1);
   SetStat("intelligence",5,5);
   SetStat("wisdom",5,5);
   SetStat("speed",25,2);
   SetClass("animal");
   SetLevel(1);
   SetAction(2, ({
                   "!emote makes a purring noise.",
                   "!emote looks around for someone to hold it.", 
                   "!emote scurries around.",
                   "!emote pulls itself into a ball and rolls "
                      "around for a while.", 
                   "!emote twitters excitedly for no apparent reason.",
                   "!emote sniffs something curiously.",
                   "!emote makes gushy noises at a bug.",
                   "!emote smiles brightly.",
              }) );
}

