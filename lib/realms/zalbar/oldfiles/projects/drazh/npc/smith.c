// by Dahaka
// Aug 2004

#include <lib.h>
#include <vendor_types.h>
#include "../drazh.h"

inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("thannika");
  SetId( ({"thannika","smith","skaven"}) );
  SetShort("Thannika the smith");
  SetLong(
    "Thannika is a large and strong skaven. His large frame "
    "comes from countless days spent working in the forge "
    "that sits in the corner of the smithy. His face is "
    "covered with a black ash, giving a short smirk to "
    "those around him. He is willing to teach his trade "
    "if you ask him.");
  SetRace("skaven");
  SetGender("male");
  SetClass("merchant");
  SetSkill("melee combat",1,2);
  SetLevel(30);
  SetMorality(-1000);
  SetTown("Drazh");
  AddTrainingSkills("bargaining");
  AddTrainingSkills("wood working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("leather working");  
  AddTrainingSkills("metal working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("natural working");
  AddTrainingSkills("skinning");
}
