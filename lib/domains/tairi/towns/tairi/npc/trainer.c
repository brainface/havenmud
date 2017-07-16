#include <lib.h>
inherit LIB_TRAINER;
#include "../tairi.h"

static void create() {
        trainer::create();
        SetKeyName("yoshima");
        SetShort("Yoshima, Mistress of Balance");
        SetId( ({ "yoshima", "mistress"}) );
        SetClass("cavalier");
        SetClass("priest");
        SetReligion("Taisoka");
        SetTown("Tairi");
        SetSkill("healing", 1, 1);
        SetSkill("melee combat", 1, 1);
        SetLevel(70);
        AddTrainingSkills("slash combat");
        AddTrainingSkills("pierce combat");
        AddTrainingSkills("melee combat");
        AddTrainingSkills("pole combat"); 
        AddTrainingSkills("multi-weapon");
        AddTrainingSkills("projectile-combat");
        AddTrainingSkills("metal working");
        AddTrainingSkills("leather working");
        AddTrainingSkills("textile working");
        AddTrainingSkills("natural working");
        AddTrainingSkills("armour smithing");
        AddTrainingSkills("weapon smithing");     
        SetGender("female");
        SetRace("human");
        SetBaseLanguage("Tai");
        SetMorality(200);
        SetLong("This is Yoshima the Mistress of Balance. Her beauty is "
                "purely breathtaking. Her looks may be deadly, but her "
                "hands are far deadlier then anyone's features. One look "
                "into her steely eyes holds death.");
        SetInventory( ([
                        TAI_RI_OBJ + "katana" : 2,
                        TAI_RI_OBJ + "oyoroi" : "wear armour",
                        ]) );
  call_out( (: eventForce, "wield katanas" :), 0);
        }
