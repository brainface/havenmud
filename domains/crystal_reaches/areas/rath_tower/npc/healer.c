#include <lib.h>
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("sychothan");
  SetShort("Sychothan the Mender of Breaks");
  SetId( ({ "mender", "sychothan" }) );
  SetAdjectives( ({ }) );
  SetTown("Gwonish");
  SetFees( ([
    "resurrect" : 500,
    "magic"     : 10,
    "stamina"   : 1,
    "health"    : 3,
    "restore"   : 50,
    ]) );
  SetLocalCurrency("rounds");
  SetRace("elf");
  SetGender("male");
  SetClass("priest");
  SetSkill("melee combat",1,2);
  SetBaseLanguage("Archaic");
  SetUndead(1);
  SetLevel(25);
  SetMorality(-750);
  SetLong("Sychothan is present to restore those in need of mending. "
          "He can \"resurrect\" you, \"restore <limb>\"s for you, \"heal\" "
          "either your <magic>, <health>, or <stamina>, or just talk to you. "
          "There is a fee for his services.");
  
  SetSpellBook( ([
    "aegis of the faithful" : 100,
    "jolt"                  : 100,
    "hellfire"              : 100,
     ]) );
  SetCombatAction(50, ({ 
  		"!cast jolt",
      "!cast hellfire",
      "!cast aegis of the faithful",
      }) );
  
}
