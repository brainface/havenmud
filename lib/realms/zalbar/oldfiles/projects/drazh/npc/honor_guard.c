// Modified by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_NPC;

void DoCombatSomething();
int CheckWanted();
#include "../wanted.h"

static void create() {
  npc::create();
  SetKeyName("keeper");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"keeper","agent","skaven"}) );
  SetShort("keeper of the Temple");
  SetLong( 
   "This large well built skaven has light grey fur with a "
   "patch of black fur around the head. These stormvermin "
   "have been blessed by Melchezidek to be guarding his temple."
   );
  SetGender("male");
  SetRace("skaven");
  SetClass("fighter");
  SetClass("priest");
  AddSkill("poison magic",1,2);
  SetLevel(40);
  SetMorality(-1500);
  SetSpellBook( ([
     "shield of faith"  : 100,
     "poison weapon"    : 100,
     "poison arrow"     : 100,
     "stab in the dark" : 100,
     ]) );
  SetInventory( ([
     V_OBJ + "scale_armour" : 
       "wear armour on torso and left arm and left leg and right arm and right leg",
     V_OBJ + "a_longsword"  : "wield sword in right claw",
     V_OBJ + "wall_shield"  : "wear shield on left arm and left claw",
     ]) );
  SetFriends( ({
     "skaven","councilman","watchman","agent"
   }) );
  SetAction(1, ({
   "!say Melchezidek has blessed me!.",
   "!cast shield of faith",
   }) );
  SetCombatAction(10,
    (: DoCombatSomething :)
   );
  SetFirstCommands( ({
     "cast shield of faith",
     "cast shield of faith",
     }) );
}

void DoCombatSomething() {
object who = this_object();
int randnum = random(10);

if (!random(50)) {
  eventForce("say you will die!");
  }
  

  switch(random(8)) {
    case 0:
      eventForce("cast poison arrow");
      break;
    case 1:
      eventForce("disorient");
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast shield of faith");
      break;
    case 4:
      if((who->GetWielded() > 0) && (who->GetWielded() < 2))
        eventForce("cast poison weapon on " + who->GetWielded());
      if(who->GetWielded() > 1)
        eventForce("cast poison weapon on " + 
          (random(2) ? who->GetWielded("left claw") : who->GetWielded("right claw")));
      break; 
    default:
      eventForce("cast stab in the dark");
      break;
  }
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell Suffer, Criminal!");
     SetAttack(this_player());
    return 1;
  }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
  }
}
