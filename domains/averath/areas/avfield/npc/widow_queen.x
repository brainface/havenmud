#include <lib.h>
#include "../avb.h"
#include <damage_types.h>

inherit LIB_FEAR;
inherit LIB_NPC;


static void create() {
   npc::create();
   SetProperty("queen",1);
   SetKeyName("bolehs");
   SetShort("Bolehs, the queen widow");
   SetId( ({"spider", "widow", "bolehs", "arachnid"}) );
   SetAdjectives( ({ "queen", "arachnid", "bolehs"}) );
   SetMorality(1000);
   SetLong("The spider is massive. Her body is the size of a small hut. "
           "Her legs tower her fifteen feet into the air and are covered "
           "in a thick black fur with dirty yellow spots laced through them. "
           "She also has two large pincers in front of her body that are "
           "used as arms. Her head is the size of a large boulder. She "
           "has fourteen eyes spread around her entire head, two of which are "
           "much larger then the others. They are all a solid pure red "
           "color. Her mouth has two massive fangs on each side of it as "
           "well as hundreds of small sharp teeth.");
   SetRace("arachnid");
   SetGender("female");
   SetClass("animal");
   SetFearType("pure horror that errupts from the terrifying image of the "
               "massive arachnid!");
   SetEncounter(500);
   SetResistLevel(100);
   SetFearLength(25);
   SetStat("agility",100,2);
   SetStat("charisma",30,2);
   SetStat("coordination",80,2);
   SetStat("durability",75,1);
   SetStat("intelligence",200,1);
   SetStat("luck",60,2);
   SetStat("speed",125,2);
   SetStat("strength",75,1);
   SetStat("wisdom",200,2);

   SetResistance(BLUNT,"med");
   SetResistance(SLASH,"low");
   SetResistance(PIERCE,"low");
   SetResistance(WATER,"low");
   SetResistance(SHOCK,"high");
   SetResistance(COLD,"high");
   SetResistance(HEAT,"immune");
   SetResistance(GAS,"immune");
   SetResistance(ACID,"med");
   SetResistance(MAGIC,"med");
   SetResistance(HUNGER,"weakness");
   SetResistance(DISEASE,"immune");
   SetResistance(POISON,"med");
   
   SetSkill("evokation",1,1);
   SetSkill("enchantment",1,1);
   SetSkill("natural magic",1,1);
   SetLevel(135);
   SetSpellBook( ([
      "animalistic protection"       : 100,
      "ice storm"  : 100,
      "soothe"          : 100,
      "lunar blast"        : 100,
      ]) );
   SetFirstCommands(({
//		"guard north"
                "cast animalistic protection",
                "cast animalistic protection",
                "cast animalistic protection",
                "cast soothe",
                   }));
   SetCombatAction(20, ({
      "!cast animalistic protection",
      "!cast lunar blast",
      "!cast soothe",
      "!cast ice storm",
       }) );

   AddLimb("first right leg","first segment",5,({ }) );
   AddLimb("first left leg","first segment",5,({ }) );
   AddLimb("second right leg","first segment",5,({ }) );
   AddLimb("second left leg","first segment",5,({ }) );
   AddLimb("second segment","second segment",3,({ }) );
   AddLimb("third right leg","second segment",5,({ }) );
   AddLimb("third left leg","second segment",5,({ }) );
   AddLimb("fourth right leg", "second segment",5,({ }) );
   AddLimb("fourth left leg", "second segment",5,({ }) );
}
