/* 
 * Replicate Spell for Soirin Clerics 
 * -Melchezidek July 18, 2008 
 */ 
 
#include <lib.h> 
#include <std.h> 
#include <damage_types.h> 
#include <daemons.h> 
#include <magic.h> 
 
inherit LIB_SPELL; 
 
static void create() { 
  ::create(); 
  SetSpell("replicate"); 
  SetSpellType(SPELL_OTHER); 
  SetSkills( ([ 
     "faith" : 50, 
     "necromancy" : 50, 
     ]) ); 
  SetMagicCost(300,300); 
  SetDifficulty(150); 
  SetHelp("Bleh Bleh Bleh"); 
} 
 
 
varargs int eventCast(object who, int level, mixed x) { 
    object replicant; 
 
    /* Get Settings from Caster and set to Replicant */ 
    replicant = new("/realms/melchezidek/obj/replicant"); 
    replicant->SetShort("A Replicant of " + who->GetShort()); 
    replicant->SetClass(who->GetClass()); 
    replicant->SetRace(who->GetRace()); 
    replicant->SetGender(who->GetGender()); 
    replicant->SetLevel(who->GetLevel()); 
} 
 
