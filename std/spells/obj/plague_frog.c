//
// A brown rat
// created by Ranquest@Haven
// and altered for spell use 8th Dec 1998
//
// stolen by mahkefel for anteky plague of frogs
#include <lib.h>
#include <damage_types.h>
 inherit LIB_NPC;
 void RugRat();

static void create(){
  npc::create();
  SetShort("a slimy bullfrog");
  SetLong(
    "This slimy bullfrog is covered with warts and pondslime. "
    "His bulbous throat pulses as he inhales and croaks. Sinewy "
    "legs propel his fat body around in leaps and bounds, leaving "
    "trails of muck everywhere.");
  SetKeyName("frog");
    SetAdjectives( ({"slimy","bull"}) );
  SetId(({"frog","bullfrog"}));
  SetRace("lizard","frog");
  AddLimb("right frogleg","torso",2);
  AddLimb("left frogleg","torso",2);
  AddLimb("left foreleg","torso",2);
  AddLimb("right foreleg","torso",2);
  AddLimb("tongue","head",2);
  SetClass("bard");
  SetLevel(4);
  SetGender("male");
  SetSongBook( ([
    "debutant aria" : 100,
  ]) );
  SetAction(10, ({"!emote licks you."}) );
  SetCombatAction(10, ({"!sing debutant aria","!emote ribbits"}));
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("tongue");

}



void eventEnemyDied(object ob) {
  message("system",
  "%^BLUE%^A slimy bullfrog hops away.%^RESET%^",
  environment() );
  call_out( (: eventDestruct :), 0);
  ::eventEnemyDied(ob);
  }

// mahkefel 2015: refuse orders to prevent op rat armies
// (or, rather, further bug reports ^^)
mixed direct_command_liv_to_str() {
  if (GetOwner() == this_player()->GetKeyName() ) 
    return "It's just a frog, already doing the best it can.";
  return capitalize(GetKeyName() ) + " will not listen to you.";
}

