#include <lib.h>
#include <daemons.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("wotan");
  SetShort("Wotan, the Prophet of Saahagoth");
  SetId( ({ "prophet of saahagoth", "nosferatu", "prophet",
    "wotan", }) );
  SetLong(
    "Wotan the Prophet, also known as Wotan the NeverBorn, "
    "strikes an imposing figure. He is eight feet tall "
    "and is garbed in the black and blood red regalia of "
    "the priesthood of Saahagoth. He is called the "
    "NeverBorn because he was created, out of the ether, "
    "by the Dark Goddess, to bring the teachings of Saahagoth "
    "to the Nosferatu. It is to this man one must look "
    "to join the priesthood."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("cleric");
  SetSkill("evokation", 1, 2);
  SetLevel(65);
  SetTown("Grymxoria");
  SetReligion("Saahagoth","Saahagoth");
  SetInventory( ([
    G_OBJ + "nosf_mace" : "wield mace",
  ]) );
  SetFreeEquip( ([
    STD_BLUNT + "mace" : 1,
  ]) );
  SetUniqueSkills( ([
    "necromancy" : 1,
    "blunt attack" : 1,
    "healing" : 2,
    "enchantment" : 1,
    "blunt defense" : 2,
    "pole defense" : 2,
    "slash defense" : 3,
    "hack defense" : 3,
    "pierce defense" :3,
    "knife defense" : 3,
  ]) );
  SetSpellBook( ([
    "dispel poison" : 100,
    "divine magic" : 100,
    "divine magic fully" : 100,
    "divine mana" : 100,
    "blessed water" : 100,
    "battle touch" : 100,
    "incite violence" : 100,
    "skirmish touch" : 100,
    "bless" : 100,
    "revive" : 100,
    "phantom army" : 100,
    "mend" : 100,
    "disperse protections" : 100,
    "resurrect" : 100,
    "fog of war" : 100,
    "harm body" : 100,
    "ancient might" : 100,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Initiate of Saahagoth",
    "mortal" : "the Priest of Saahagoth",
    "hm"     : "the Saahagoth Battle Priest",
    "legend" : "the WarLord Bishop",
    "avatar" : "the Incarnate Battle",
    "cavalier" : "the Anti-Paladin",
    "fighter" : "the Dark Monk",
  ]) );
}
