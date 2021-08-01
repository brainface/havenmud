//
// A fruit bat!
//
#include <lib.h>
#include <damage_types.h>
 inherit LIB_NPC;
 void RugRat();

static void create(){
  npc::create();
  SetShort("a fruit bat");
  SetLong(
    "This cute bat is a dark brown, with tan spots on its fleshy wings and "
    "a downy mane of orangish hair. Some hungry light in its eyes suggests "
    "that has mistaken you for a banana."
  );
  SetKeyName("bat");
    SetAdjectives( ({"fruit"}) );
  SetId(({"bat"}));
  SetRace("rodent");
  SetClass("animal");
  SetLevel(2);
  SetGender("female");
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("teeth");
}

void eventEnemyDied(object ob) {
  message("system",
  "%^BLUE%^A fruit bat flaps away.%^RESET%^",
  environment() );
  call_out( (: eventDestruct :), 0);
  ::eventEnemyDied(ob);
  }

// mahkefel 2015: refuse orders to prevent op rat armies
// (or, rather, further bug reports ^^)
mixed direct_command_liv_to_str() {
  if (GetOwner() == this_player()->GetKeyName() )
    return "The bat didn't sign up for that.";
  return capitalize(GetKeyName() ) + " will not listen to you.";
}

