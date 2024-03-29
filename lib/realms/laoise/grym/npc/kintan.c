#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;

static void create()
{
  trainer::create();
  SetKeyName("kintan");
  SetShort("Kintan, the Blade Master");
  SetId( ({ "blade master", "nosferatu", "master",
    "kintan", }) );
  SetLong(
    "Kintan is a shady looking character. There is something "
    "about the way he carries himself that prevents trust. "
    "Kintan is, however, the finest bladesman in Grymxoria. "
    "It has also been rumored that whenever Gunthar summons "
    "Kintan into his presence, someone is surely to die "
    "under mysterious circumstances. If one is interrested "
    "in learning the skills Kintan uses, one need only ask."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("fighter");
  SetClass("rogue");
  SetLevel(49);
  SetCurrency("bloodgems", (random(2000) + 4000));
  SetTown("Grymxoria");
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
  ]) );
  AddTrainingSkills("pierce attack");
  AddTrainingSkills("pierce defense");
  AddTrainingSkills("slash attack");
  AddTrainingSkills("slash defense");
  AddTrainingSkills("blunt attack");
  AddTrainingSkills("blunt defense");
  AddTrainingSkills("melee attack");
  AddTrainingSkills("melee defense");
  AddTrainingSkills("projectile attack");
  AddTrainingSkills("projectile defense");
  AddTrainingSkills("pole attack");
  AddTrainingSkills("pole defense");
  AddTrainingSkills("knife attack");
  AddTrainingSkills("knife defense");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("multi-hand");
  AddTrainingSkills("stealth");
}
