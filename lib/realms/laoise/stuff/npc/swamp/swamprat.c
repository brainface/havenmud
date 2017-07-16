// Hacked apart from Bal's original random npcs
// Isn't there a swamprat from the other r_npc?
// Maybe combine them

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create()
{
  npc::create();
  SetKeyName("swamprat");
  SetId( ({"rat","swamprat"}) );
  SetAdjectives( ({"swamp", "dirty", "filty"}) );
  SetShort("a swamprat");
  SetLong(
    "Approximately the size of a large beaver, the swamprat "
    "is covered in filth.");
  SetLevel(2);
  SetRace("rodent");

// Check on this class
      SetClass("valkyr");

  if(random(3))
    SetGender("male");
  else
    SetGender("female");
  SetAction(7,({ 
    "The swamprat noses around debris piles.",
    "The swamprat approaches you with a a gleam in its eyes. "
    "It seems to be saying, 'Love me?'",
  }) );

  SetSkinVars("pelt",250,2,15);
}

varargs int eventDie(object target)
{
  object ob;
  ob=new(GWONISH+"obj/generic_skin");

  ob->SetKeyName(GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetDamagePoints(GetProperty("durability"));
  ob->SetShort("a "+GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetLong("This is a "+
        GetProperty("skin_type")+" from a " +
        GetKeyName()+".");
  ob->SetID( ( {
    GetProperty("skin_type"),
    GetKeyName()+" "+GetProperty("skin_type")
      }) );
  ob->SetValue(GetProperty("skin_value"));
  ob->SetMass(GetProperty("skin_mass"));

  ob->eventMove(environment(this_object()));

  npc::eventDie(target);
}

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass)
{
  SetProperty("skin_type",skin_type);
  SetProperty("durability",durability);
  SetProperty("skin_value",skin_value);
  SetProperty("skin_mass",skin_mass);
}
