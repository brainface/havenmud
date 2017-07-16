// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

int CallMommy();

static void create() {
   ::create();
   SetKeyName("baby bear");
   SetShort("a baby black bear");
   SetId( ({ "baby","bear" }) );
   SetAdjectives( ({ "baby","black" }) );
   SetLong("Dark fur sticks up all over this small bear's body, turning him into an "
           "adorable teddy bear of a mammal.  Of course, this teddy has real "
           "claws at the tip of his powerful limbs, and razor-sharp teeth in "
           "his mouth.");
   SetGender("male");
   SetRace("bear");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(8);
   SetMorality(100);
   SetInventory( ([
                    FOREST_OBJ + "elkleg" : 1+random(2),
               ]) );
   SetAction(2, ({ "!emote rolls around in the ivy.","!emote sniffs at a skeleton.",
                   "!emote growls at a tree.","!emote snarls.","!emote snorts.",
                   "!emote scratches up against a tree." }) );
   SetCombatAction(20, ({ (: CallMommy :) }) );
}

int CallMommy() {
   object mom, momroom;
   eventForce("emote mewls in distress.");
   if(base_name(environment(this_object())) == 
                 "/domains/averath/virtual/island/7,-6,0") {
      momroom = load_object(FOREST_ROOMS + "bearcave");
      if(mom = present("ameliamommybear",momroom) ) {
      mom->eventForce("go out");
      mom->eventMove(environment(this_object()));
      mom->eventForce("attack " + this_player()->GetKeyName());
      mom->eventForce("emote growls and snarls for her baby!");
      }
   }
   return 1;
}
