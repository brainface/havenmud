#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("loli");  
  SetShort("a cute loli");
  SetId( ({ "loli" }) );
  SetAdjectives( ({ "cute" }) );
  SetLong("Desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu desu");
  SetRace("thing",1);  
  AddLimb("poofy body", 0, 1, ({ }) );
  AddLimb("right feeler", "poofy body", 4, ({ }) );
  AddLimb("left feeler", "poofy body", 4, ({ }) );
  SetStat("agility",12,3);
  SetStat("durability",8,5);
  SetStat("luck",20,1);
  SetStat("strength", 5, 5);
  SetStat("charisma", 60, 1);
  SetStat("intelligence", 2, 4);
  SetStat("wisdom", 5, 3);
  SetClass("fighter");
  SetLevel(1);
  SetMorality(750);
  SetGender("female");
  SetDie("Sage.");

  SetAction(10, ({
   "!bell melchezidek",
    }) );
  SetClass("animal");
 }  
