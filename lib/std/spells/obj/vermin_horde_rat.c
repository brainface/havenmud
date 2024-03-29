//
// A brown rat
// created by Ranquest@Haven
// and altered for spell use 8th Dec 1998
//
#include <lib.h>
#include <damage_types.h>
 inherit LIB_NPC;
 void RugRat();

static void create(){
  npc::create();
  SetShort("a brown rat");
  SetLong("This rodent is covered with dirt and mud. His feral eyes hold the"
    " gleam of madness generated by the fact that his will has been suborned,"
    " and his yellowing teeth are bared in an expression of rage and futile "
    " terror.");
  SetKeyName("rat");
    SetAdjectives( ({"vicious","mean"}) );
  SetId(({"rat"}));
  SetRace("rodent");
  SetClass("animal");
  SetLevel(2);
  SetGender("male");
  SetMeleeDamageType(PIERCE);
  SetMeleeAttackString("teeth");
}

void eventEnemyDied(object ob) {
  message("system",
  "%^BLUE%^A small rat scurries off to safety.%^RESET%^",
  environment() );
  call_out( (: eventDestruct :), 0);
  ::eventEnemyDied(ob);
  }

// mahkefel 2015: refuse orders to prevent op rat armies
// (or, rather, further bug reports ^^)
mixed direct_command_liv_to_str() {
  if (GetOwner() == this_player()->GetKeyName() ) 
    return "The rat is too dumb to take further orders.";
  return capitalize(GetKeyName() ) + " will not listen to you.";
}

