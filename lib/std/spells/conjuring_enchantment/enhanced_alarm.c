/* 
 * major_ward.c
 * ward spell for the Northern Kyfho religion
 * balishae@haven
 * 4/98
 * after the death of Khyfo, Dylanthalus@Haven makes these 
 * high level conjuring divination spells on approval of
 * Duuktsaryth  15 Dec 98
 * Renamed: enhanced ward
 */
 

#include <lib.h>
#include <magic.h>
#include <dirs.h>

inherit LIB_SPELL;

static void create()
{
        spell::create();
        SetSpell("alarm");
        SetSpellType(SPELL_OTHER);
        SetRules("");
        SetSkills( ([
          "conjuring" : 85,
          "enchantment" : 85,
                ]) );
        SetRequiredMagic(100);
        SetMagicCost(50,50);
        SetDifficulty(25);
   SetHelp(
                "This handy divination spell allows the caster to "
                "protect an area with an 'alarm.'  It will alert "
                "the caster to who is entering the area of casting "
                "even while the caster is not there.  This "
                "improved version of the original alarm spell "
                "reveals more information.");
}

int eventCast(object who, int level, string limb, object array targets)
{
        object ward;
        
        if(!(ward = new(DIR_SPELLS "/obj/e_alarm_ob.c")))
        return 0;
        
        ward->SetMaster(who->GetKeyName());
        ward->SetCountDown(10 + (who->GetLevel() * (random(20) + 20)));
        ward->eventMove(environment(who));
        message("ward message","You focus a bit of energy to watch "
                "this room.",who);
        
        return 1;
}


/* Approved by Dylanthalus on Wed Dec 16 04:31:56 1998. */
