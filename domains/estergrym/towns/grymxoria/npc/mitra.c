#include <lib.h>
#include "../grymxoria.h"
inherit LIB_HEALER;

static void create() 
{
  healer::create();
  SetKeyName("mitra");
  SetShort("mitra, the healer of Aberach");
  SetId( ({ "healer of aberach", "nosferatu", "healer", "mitra" }) );
  SetAdjectives( ({ "nosferatu", "aberach" }) );
  SetLong(
    "Mitra is the local healer. It is her job to make "
    "sure that anyone who can get up and fight again, "
    "does so, for a modest fee of course."
  );
  SetClass("priest");
  SetSkill("melee combat",2,1);
  SetLevel(40);  
  SetRace("nosferatu");
  SetGender("female");
  SetTown("Grymxoria");
  SetReligion("Aberach", "Aberach");
  SetMorality(-2000);
  SetCurrency("bloodgems", 4000);
  SetLocalCurrency("bloodgems");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetFriends( ({ "vyper", "wotan" }) );
  SetSpellBook( ([
  	"shield of faith" : 100,
  	"harm body"			  : 100,
  	"hellfire"        : 100,
  	]) );
  SetCombatAction(60, ({
  	"!cast shield of faith",
  	"!cast harm body",
  	"!cast hellfire",
  	}) );
}
