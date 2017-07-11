/*  Repair Skills Trainer for Haven Town */
#include <lib.h>
#include "../haven.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("pithian");
  SetShort("Pithian Sythal, a retired merchant");
  SetRace("elf");
  SetClass("merchant");
  SetLevel(22);
  SetMorality(100);
  SetStat("durability", 15, 4);
  SetId( ({ "pithian", "pithian sythal", "sythal", "merchant" }) );
  SetAdjectives( ({ "retired" }) );
  SetLong("Pithian is an old, retired elf with too much time on "
         "his hands. He mostly idles around Haven Town teaching "
         "what he knows.");
  SetGender("male");
  SetTown("Haven");
  SetCurrency("imperials", 200);
  AddTrainingSkills("metal working");
  AddTrainingSkills("skinning");
  AddTrainingSkills("textile working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("bargaining");
  AddTrainingSkills("fishing");
  AddTrainingSkills("knife combat");
  SetInventory( ([
      H_OBJ + "dagger" : "wield dagger",
      ]) );
  }
