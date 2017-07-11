#include <lib.h>
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("ulan");
  SetId( ({ "ulan", "rusenworth", "teacher" }) );
  SetAdjectives( ({ "ulan", "faithful" }) );
  SetShort("Ulan Rusenworth, Teacher of the Faithful");
  SetLong("Ulan Rusenworth is a faithful member of the Kylin "
          "religion. Her long devotion to the cause has led "
          "her to be considered one of the greatest clerics "
          "ever to have lived. She is always willing to carry "
          "her knowledge to others.");
  SetRace("elf");
  SetGender("female");
  SetClass("priest");
  SetSkill("faith",1,1);
  SetSkill("enchantment",1,1);
  SetSkill("healing",1,1);
  SetSkill("blunt combat",1,1);
  SetLevel(73);
  AddTrainingSkills("healing");
  
  SetTown("Haven");
  SetReligion("Kylin");
  SetMorality(1000);
  SetSpellBook( ([
     "smite"         	 : 100,
     "wrath"         	 : 100,
     "wall of force" 	 : 100,
     "heal"            : 100,
     "cure disease"  	 : 100,
     "regenerate limb" : 100,
     "dispel poison"   : 100,
     ]) );
  SetAction(15, ({
     "!emote looks you over kindly.",
     "!speak Would you like me to teach you, child of the Immortals?",
     "!speak Are you here for my help?",
     "!speak In Duuk, all things are revealed.",
     }) );
  SetCombatAction(40, ({
     "!cast wall of force",
     "!cast wrath",
     }) );
  SetCurrency("imperials", 750);
  SetInventory( ([
     STD_BLUNT + "war-hammer" : "wield hammer",
    ]) );
 }
