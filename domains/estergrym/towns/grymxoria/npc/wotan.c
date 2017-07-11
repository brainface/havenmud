#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("wotan");
  SetShort("wotan, the Prophet of Aberach");
  SetId( ({ "prophet", "wotan", "nosferatu", "cleric" }) );
  SetAdjectives( ({ "nosferatu", "aberach" }) );
  SetLong(
    "Wotan the Prophet, also known as Wotan the NeverBorn, "
    "strikes an imposing figure. He is eight feet tall "
    "and is garbed in the black and blood red regalia of "
    "the priesthood of Aberach. He is called the "
    "NeverBorn because he was created, out of the ether, "
    "by the Goddess Laoise, to bring the teachings of Aberach "
    "to the Nosferatu. It is to this man one must look "
    "to join the priesthood."
  );
  SetRace("nosferatu"); 
  SetClass("priest");
  SetLevel(65);
   
  SetGender("male");
  SetTown("Grymxoria");
  SetReligion("Aberach","Aberach");
  SetMorality(-2000);
  SetUniqueSkills(  ([
    "blunt combat" : 0,
    "slash combat" : 1,
  ]) );
  SetSpellBook(  ([
    "aura of terror"     : 100,
    "barrier of faith"   : 100,
    "divine retribution" : 100,
    "pain touch"         : 100,
    ])  );
  SetAction(20, ({
  }) );
  SetCombatAction(50, ({
    "!cast aura of terror",
    "!cast divine retribution",
    "!cast pain touch",
  	}) );
  SetInventory(  ([
    G_OBJ + "nosf_sword" : "wield sword",
  ])  );
  SetPlayerTitles(  ([
    "newbie"   : "the Initiate of Aberach", 
    "mortal"   : "the Priest of Aberach", 
    "hm"       : "Sir $N the Battle Priest of Aberach", 
    "legend"   : "Lord $N the Battle-Bishop of the Dark Goddess", 
    "avatar"   : "Warlord $N the Tyranical Enforcer of the Dark Goddess", 
    "cavalier" : "the Nefarious Champion of Aberach", 
    "fighter"  : "the Faithful Blade of Aberach",
  ])  );
  SetFreeEquip(  ([
    STD_SLASH + "sword" : 1,
  ])  );
  SetFirstCommands( ({ 
    "cast barrier of faith", 
    "cast barrier of faith", 
    "cast barrier of faith", 
    "cast barrier of faith",
    "cast barrier of faith",
  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast barrier of faith");
  }
}
