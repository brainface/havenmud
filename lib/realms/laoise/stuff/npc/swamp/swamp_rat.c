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
  SetKeyName("swamp rat");
  SetId( ({"rat","swamprat"}) );
  SetAdjectives( ({"swamp", "brown", "large"}) );
  SetShort("a large brown swamprat");
  SetLong(
    "This swamp rat has dark brown fur over most of "
    "her body, blending in to a lighter golden-orange "
    "color on her underside. Despite her stature among "
    "rats, the swamp rat is still small enough to hide "
    "easily amongst the vegetation of the swamp."
  );
  SetLevel(2);
  SetRace("rodent");
  SetClass("animal");
  SetGender("female");
  SetAction(7,({ 
    "The swamp rat flexs her paws, revealing the webbing "
    "between her toes.",
    "The swamp rat approaches you with a a gleam in its eyes. "
    "She seems to be saying, 'Love me?'",
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
