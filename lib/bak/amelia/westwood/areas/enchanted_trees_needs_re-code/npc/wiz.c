// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"

int CheckPerson();

static void create() {
   npc::create();
   SetProperty("enchforestnoleave",1);
   SetKeyName("wizard");
   SetId( ({ "old wizard","wizard" }) );
   SetShort("an old wizard");
   SetLong("Old and wrinkled, the golem wizard appears to have been "
           "fashioned long ago out of a hunk of wood.  He wears "
           "wrinkled, unkempt clothing and wields the branch of "
           "a tree.  Something about him suggests that he went "
           "insane long ago.");
   SetClass("evoker");
   SetSkill("blunt attack",1,1);
   SetLevel(random(2)+5);
   SetRace("golem");
   SetGender("male");
   SetInventory( ([
                    B_OBJ + "/branchc" : "wield branch",
                    B_OBJ + "/gleaf" : random(4),
                    B_OBJ + "/sleaf" : random(5),
               ]) );
   SetAction(5, ({ "The wizard cackles insanely.","The wizard mutters "
                   "something about his beautiful trees.","The wizard "
                   "looks around and growls at the floor." }) );
   SetCombatAction(10, ({ "The wizard screams insanely.","The wizard "
                          "yells at you to stay away from his trees!" }) );
   SetEncounter( (: CheckPerson :) );
   SetMorality(-175-random(50));
}

int CheckPerson() {
   if( (creatorp(this_player()))) return 0;
   if( (living(this_player())) && this_player()->GetLevel() >= 8) return 1;
   else return 0;
}
