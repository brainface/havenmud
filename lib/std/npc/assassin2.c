/*
 * Second Assassin in the Beornwulf
 * bodyguard quest.
 * -Melchezidek June 2008
 *
 */
 
#include <lib.h>
#include <std.h>
#include "/domains/tairi/areas/ninja_tower/ninja.h"

inherit LIB_NPC;
void ThrowStuff();

static void create() {
::create();
SetKeyName("assassin");
SetShort("a masked assassin");
SetId( ({ "assassin", "lordb_quest" }) );
SetAdjectives( ({ "masked" }) );
SetLong("Tall and lithe, this assassin is cloaked in all black"
        " armour. His movements are subtle and graceful yet"
        " deadly efficient. His face is covered by a mask"
        " of black wood carved to resemble a wolf.");
SetRace("dark-elf");
SetGender("male");
SetClass("rogue");
SetClass("fighter");
SetMorality(-250);
SetLevel(55);
SetCombatStyleLevel("dirty tricks", 55);
SetCombatStyle("dirty tricks");
SetCombatAction(50, (: ThrowStuff :) );
SetInventory( ([
    N_STORE "mastershozoku" : "wear armour",
    N_STORE "jikatabi" : "wear 1st tabi on left leg and left foot",
    N_STORE "jikatabi2" : "wear 1st tabi on right leg and right foot",
    N_STORE "sleeve" : "wear 1st sleeve on left arm and left hand",
    N_STORE "sleeve2" : "wear 1st sleeve on right arm and right hand",
    N_STORE "boshuriken" : 2,
    N_STORE "hirashuriken" : 3,
    STD_ARMOUR "helmet/wolf_mask" : "wear mask",
    STD_WEAPON "knife/black_stiletto" : "wield 1st stiletto",
    STD_WEAPON "knife/stiletto" : "wield 1st stiletto",
    ]) );
  SetFirstCommands( ({
  "hide",
  "backstab lord",
  }) );
 }
 
 void ThrowStuff(object who) {
 object target = GetCurrentEnemy();
  
   eventForce("throw 1st shuriken at " + target->GetKeyName());
 }
 
 varargs int eventDie(object who) {
 object room;
 object assassin;
 room = environment(who);
 assassin = new("/std/npc/assassin3.c");
 
 assassin->eventMove(room);
 return npc::eventDie(who);
 }
 
