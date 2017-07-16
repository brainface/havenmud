/* Resize Armour */
// Used animate dead spell as basis
// Zalbar 8-08


#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
#include <size.h>
inherit LIB_SPELL;

//void CrumbleCorpse(object corpse);

static void create() {
  ::create();
  SetSpell("resize armour");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "enchantment" : 1,
    "conjuring"   : 1,
     ]) );
  SetMagicCost(100, 100);
  SetDifficulty(50);
  SetHelp("This spell allows an enchanter to change the size of armour "
          "increasing it for larger size races or decreasing it for smaller "
          "size races. This spell is a difficult spell to master and is "
          "known for destroying the armour that the enchanter wants to "
          "resize.");
}


varargs int CanCast(object who, int level, mixed x, object *targets) {

  foreach(object ob in targets) {
    if (ob->GetProperty("laoise flag")) {
      who->eventPrint(ob->GetShort() + " cannot be resized.");
      return 0;
    }
  }
  return ::CanCast(who, level, x, targets);
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object armour;
  object target = targets[0];
  


  
  foreach(object t in targets) {
    armour = new("/realms/zalbar/projects/obj/new_armour");
    
    armour->SetKeyName(t->GetKeyName());
    armour->SetId(t->GetId());
    armour->SetShort(t->GetShort());
    armour->SetLong(t->GetLong());
    armour->SetDamagePoints(t->GetDamagePoints());
    armour->SetValue(t->GetValue());
    armour->SetMass(t->GetMass());
    armour->SetMaterial(t->GetMaterials());
    armour->SetWarmth(t->GetWarmth());
    armour->SetRepairskills(t->GetRepairSkills());
    armour->SetVendor(t->GetVendorType());
    armour->SetSize(SIZE_TINY);
    armour->SetArmourType(t->GetArmourType());
    armour->SetArmourClass(t->GetArmourClass());
    armour->SetRestrictLimbs(t->GetRestrictLimbs());
    armour->SetProtectionBonus(t->GetProtectionBonus());
    if(t->GetProperties()) 
        armour->SetProperties(t->GetProperties()); 
   


   send_messages( ({ "summon", "force" }),
     "$agent_name $agent_verb%^RED%^BOLD%^ power%^RESET%^ from "
     "$agent_reflexive and $agent_verb $target_name into a" 
     "new size.", who, t, environment(t) );

     
   t->eventDestruct();
   armour->eventMove(environment(who));
   return 1;      
  }
}
