/*  Portia  11-6-98
   A town guard.
   ** Updated a little to not suck so much.
      -Melchezidek Oct 2009
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_TOWNGUARD;
int HelpHelp();
void CombatStuffs();

static void create() {
  ::create();
  SetKeyName("guard");
  SetShort("a large guard");
  SetId( ({"guard"}) );
  SetAdjectives( ({"large"}) );
  SetLong("This large guard looks like he might be fun to be "
         "around. Assuming you aren't a criminal. He seems to "
         "take his job protecting his town very seriously even if "
         "he does have a good time doing it.");
  SetGender("male");
  SetRace("dark-elf");
  SetTown("Malveillant");
  SetMorality(-200);
  SetClass("cavalier");
  SetLevel(60 + random(10));
  SetCurrency("roni",random(100) + 20);
  SetInventory( ([
    MAL_OBJ + "/weapons/elf_rapier"             : "wield rapier",
    MAL_OBJ + "/clothing/g_boots"                 : "wear boots",
    MAL_OBJ + "/clothing/g_pants"                 : "wear pants",
    MAL_OBJ + "/clothing/g_breastplate" : "wear plate",
    MAL_OBJ + "/clothing/g_medallion"   : "wear medallion",
   ]) );
  SetAction(6, ({
    "!emote laughs heartily.",
    "!emote idly checks the tip of his rapier.",
    "!speak I hear some Parvans have taken up bathing of late.",
    "!emote hums to himself.",
    "!emote looks around.",
    }) );
  SetCombatAction(55, (: CombatStuffs :) );
  if (random(5)) SetProperty("captain", 1);
  }
  
  
int HelpHelp() {
  object *guards = ({ });
  object who = this_player();
  int guard_num;
  string myroom = strip_colours(environment(who)->GetShort());
  
//  if !(who->GetProperty("captain")) return 0;
//  debug("Working HelpMe, Stage 1: " + who->GetKeyName());
  guards = filter(all_inventory(environment(who)), (: living($1) && $1->GetKeyName() == "guard" :));
  guard_num = sizeof(guards);
  //debug("guard_num: " + guard_num + "guards: " + sizeof(guards));
  if (sizeof(guards) > 4) return 0;
  switch(random(2)) {
        case 0:
         who->eventForce("yell Men! To me! To me!");
        break;
        case 1:
        who->eventForce("yell Guards! We have a situation in " + myroom +"!");
        break;
  }
  environment(who)->eventPrint("More guards shuffle into the area.");
//  debug("Working HelpMe, Stage 2");
  while(guard_num < 6) {
    new(MAL_NPC "support_guard")->eventMove(environment());
    guard_num++;
  }
  return 1;
}

void CombatStuffs() {
        switch (random(3)) {
                case 1:
                HelpHelp();
                break; 
                         
                case 2:
                this_player()->eventForce("disarm");
                break;
                
                case 3:
                this_player()->eventForce("disorient");
                break;
        }
}

